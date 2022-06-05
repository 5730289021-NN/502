#!/usr/bin/env /home/bet/.virtualenvs/cv/bin/python
from cmath import pi
import sys
import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32MultiArray,UInt16MultiArray
from std_srvs.srv import Trigger
from geometry_msgs.msg import Twist
from housem8_aruco.msg import Custom
from interfaces.msg import Dect

# from aruco.srv import Follow
import numpy as np
from mbse.srv import Mani
class Plan_armClient(Node):
    def __init__(self):
        super().__init__('/Maniclient/Plan_arm')
        self.cli = self.create_client(Trigger, '/plan_arm')       # CHANGE
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')                          # CHANGE
class Execute_armClient(Node):
    def __init__(self):
        super().__init__('/Maniclient/Execute_arm')
        self.cli = self.create_client(Trigger, '/execute_arm')       # CHANGE
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')                          # CHANGE
class Close_gripperClient(Node):
    def __init__(self):
        super().__init__('/Maniclient/Close_gripper')
        self.cli = self.create_client(Trigger, '/close_gripper')       # CHANGE
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')                          # CHANGE
class Open_gripperClient(Node):
    def __init__(self):
        super().__init__('/Maniclient/Open_gripper')
        self.cli = self.create_client(Trigger, '/open_gripper')       # CHANGE
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')                          # CHANGE

class Corescheduler(Node):
    def __init__(self,plan_arm,execute_arm,close_gripper,open_gripper):
        super().__init__('Detection_CoreScheduler')
        self.srv = self.create_service(Mani, '/Core/Mani', self.core_callback)  # CHANGE
        self.task = 0
        self.plan_arm = plan_arm
        self.execute_arm = execute_arm
        self.close_gripper = close_gripper
        self.open_gripper = open_gripper

    def core_callback(self, request,response):
        if request.task == 1:
            self.get_logger().info('Detecting command')  # CHANGE
            self.get_logger().info('Task detected : Get the umbrella')
            response.response = 1
            return response
        elif request.task == 2:
            self.get_logger().info('Detecting command: Finding object')
            self.task = 2
            while rclpy.ok():
                rclpy.spin_once(self.minimal_subscriber)
                rclpy.spin_once(self.fine_subscriber)
                if 2 in self.minimal_subscriber.id:
                    response.response = 1
                    response.objectx = self.minimal_subscriber.translationVector[0]
                    response.objecty = self.minimal_subscriber.translationVector[1]
                    return response

def main(args=None):
    rclpy.init(args=args)
    plan_arm_client = Plan_armClient()
    execute_arm_client = Execute_armClient()
    close_gripper_client = Close_gripperClient()
    open_gripper_client = Open_gripperClient()
    linktocore = Corescheduler(plan_arm_client,execute_arm_client,close_gripper_client,open_gripper_client)
    rclpy.spin(linktocore)
    try:
        while rclpy.ok():
            rclpy.spin(linktocore)
    except KeyboardInterrupt:
        print('stopped')
    except BaseException:
        print('exception')
        raise
    finally:
        plan_arm_client.destroy_node()
        execute_arm_client.destroy_node()
        close_gripper_client.destroy_node()
        open_gripper_client.destroy_node()
        rclpy.shutdown()

    # rclpy.spin(minimal_subscriber)
    # fine_subscriber.destroy_node()
    # minimal_subscriber.destroy_node()
    # rclpy.shutdown()


if __name__ == '__main__':
    main()