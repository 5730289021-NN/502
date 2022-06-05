#!/usr/bin/env /home/bet/.virtualenvs/cv/bin/python
import enum
import os
import sys
import rclpy
from rclpy.node import Node
from math import *
import numpy as np
import serial
import time
from mbse.srv import Mani , Navi , Detect
class State(enum.Enum):
    softwarecheck = 0
    waitfeedbacksoftware = 1
    hardwarecheck = 5
    waitfeedbackhardware = 6
    idle = 10
    sendtomani = 20
    waitfeedbackmani = 21
    resultmani = 22
    sendtonavi = 30
    waitfeedbacknavi = 31
    resultnavi = 32
    sendtodetect = 40
    waitfeedbackdetect = 41
    resultdetect = 42
    collisiondetect = 99
    Emergencybutton = 100
    task1_init = 101
    task1_gotograsp = 102
    task1_return = 103
class Response(enum.Enum):
    success = 1
    failure = 0
    inprogress = 2

class Order(enum.Enum):
    waitforcommand = 0
    doingtask1 = 1
    doingtask2 = 2

class DetectClient(Node):

    def __init__(self):
        super().__init__('Detection_clientfromcore')
        self.cli = self.create_client(Detect, '/Core/Detect')       # CHANGE
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')
        self.req = Detect.Request()                                   # CHANGE

    def send_request(self,task,objectclass = None,findingstate = None,graspstate = None,orderstate = None):
        self.req.task = task
        self.req.objectclass = objectclass
        self.req.findingstate = findingstate                 # CHANGE
        self.req.graspstate = graspstate
        self.req.orderstate = orderstate
        self.future = self.cli.call_async(self.req)

class ManiClient(Node):
    def __init__(self):
        super().__init__('Manipulator_clientfromcore')
        self.cli = self.create_client(Mani, '/Core/Mani')       # CHANGE
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')
        self.req = Mani.Request()                                   # CHANGE

    def send_request(self,task,objectpose = None,currentpose = None,headingdirection = None,graspstate = None,objectclass = None):
        self.req.task = task
        self.req.objectx = objectpose[0]
        self.req.objecty = objectpose[1]
        self.req.currentx = currentpose[0]
        self.req.currenty = currentpose[1]
        self.req.headingdirection = headingdirection
        self.req.graspstate = graspstate
        self.req.objectclass = objectclass
        self.future = self.cli.call_async(self.req)

class Core(Node):
    def __init__(self):
        super().__init__('Core')
        self.Navi = self.create_service(Navi, '/Core/Navi', self.Navi_callback)
        self.state = State.softwarecheck
        self.order = 0
        self.goalpose = [0,0]
        self.currentpose = [0,0]
        self.findingstate = 0
        self.findingarea = [['Umbrella',-2.5,-5]] # add object finding area ex: [Umbrella,10,10]
        self.detectionresponse = 0
        self.task = Response.inprogress
        self.naviresponse = 0
        self.graspstate = 0
        self.grasprange = 0
        self.objectpose = []
        self.graspresponse = Response.inprogress
    def Reinitialize(self):
        self.order = 0
        self.goalpose = [0, 0]
        self.currentpose = [0, 0]
        self.findingstate = 0
        self.findingarea = [['Umbrella', -2.5, -5]]  # add object finding area ex: [Umbrella,10,10]
        self.detectionresponse = 0
        self.naviresponse = 0
        self.task = Response.inprogress
        self.graspstate = 0
        self.grasprange = 0
        self.objectpose = []
        self.graspresponse = Response.inprogress
    def Initialize(self):
        # # run softwarecheck
        # self.state = State.waitfeedbacksoftware
        # while self.state != State.hardwarecheck:
        #     # get feedback
        #     self.state = State.hardwarecheck
        # # run hardwarecheck
        # self.state = State.waitfeedbackhardware
        # while self.state != State.idle:
        #     # get feedback
        self.state = State.idle

    def Detectingcommand(self,detect_client):
        detect_client.send_request(1)
        rclpy.spin_once(detect_client)
        if detect_client.future.done():
            try:
                response = detect_client.future.result()
            except Exception as e:
                detect_client.get_logger().info(
                    'Service call failed %r' % (e,))
            else:
                if response.response == 1:
                    detect_client.get_logger().info('Detecting task1: Get the umbrella')  # CHANGE
                    self.state = State.task1_init
    def Movetotarget(self,goalpose,navi_client):
        # call service to NAV2 node
        self.currentpose = []
        # self.naviresponse = Response.success or failure

    def Findingobject(self,detect_client,findingstate,objectclass):
        detect_client.send_request(2,objectclass,findingstate)
        rclpy.spin_once(detect_client)
        if detect_client.future.done():
            try:
                response = detect_client.future.result()
            except Exception as e:
                detect_client.get_logger().info(
                    'Service call failed %r' % (e,))
            else:
                if response.response == 1:
                    detect_client.get_logger().info('Find the object')  # CHANGE
                    self.objectpose = [response.objectx,response.objecty]
                    self.detectionresponse = Response.success

    def Ingraspingrange(self,objectpose,currentpose,mani_client):
        #call service to manipulator to check if object pose and current pose can grasp
        return Response.success # return can or cant

    def Findingobjectandmoving(self,objectclass,detect_client,navi_client):
        if self.findingstate == 0:
            self.Movetotarget(self.findingarea[objectclass][1:])             #call service to NAV2 = go to find area
            if self.currentpose[0:1] == self.findingarea[objectclass][1:]:
                self.findingstate = 1
        if self.findingstate == 1:
            #call service to NAV2 node = spin
            self.Findingobject(detect_client,self.findingstate,objectclass)                   #call service to Detection node = detect objectclass
            if self.detectionresponse == Response.success:
                self.findingstate = 0
                self.task = Response.success
            # if spin completely
            #     self.task = Response.failure

    def Pickingupobject(self,detect_client,navi_client,mani_client,objectclass):
        if self.graspstate == 0:
            self.Findingobject(detect_client,1,objectclass)                    #call service to Detection node = to return object pose
            self.grasprange = self.Ingraspingrange(self.objectpose,self.currentpose,mani_client)
            if self.grasprange == Response.failure:
                self.Movetotarget(self.objectpose,navi_client)
            else:
                self.Movetotarget(self.currentpose,navi_client)
                #call service to grasp object return with response
                pass
            if self.graspresponse == Response.success:
                self.graspstate = 1
def main(args = None):
    rclpy.init(args=args)
    detection_client = DetectClient()
    navi_client = 0
    mani_client = ManiClient()
    core_server = Core()
    core_server.Initialize()
    while rclpy.ok():
        if core_server.state == State.idle:
            core_server.Detectingcommand(detection_client)
        elif core_server.state == State.task1_init:
            core_server.Findingobjectandmoving(0,detection_client,navi_client)
            if core_server.task == Response.success:
                core_server.task = Response.inprogress
                core_server.state = State.task1_gotograsp
        elif core_server.state == State.task1_gotograsp:
            core_server.Pickingupobject(detection_client,navi_client,mani_client,0)
            if core_server.graspresponse == Response.success:
                core_server.state = State.task1_return
        elif core_server.state == State.task1_return:
            core_server.Movetotarget([0,0],navi_client)
            if core_server.naviresponse == 1:
                print('task 1 finished')
                core_server.Reinitialize()
                core_server.state = State.idle
if __name__ == '__main__':
    main()

# rclpy.spin_once(minimal_client)
# if minimal_client.future.done():
#     try:
#         response = minimal_client.future.result()
#     except Exception as e:
#         minimal_client.get_logger().info(
#             'Service call failed %r' % (e,))
#     else:
#         minimal_client.get_logger().info(
#             'Result of add_three_ints: for %d + %d + %d = %d' %  # CHANGE
#             (minimal_client.req.a, minimal_client.req.b, minimal_client.req.c, response.sum))  # CHANGE
#     break