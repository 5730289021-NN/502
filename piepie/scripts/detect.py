#!/usr/bin/env /home/bet/.virtualenvs/cv/bin/python
from cmath import pi
import sys
import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32MultiArray,UInt16MultiArray
from geometry_msgs.msg import Twist
from housem8_aruco.msg import Custom
from interfaces.msg import Dect
# from aruco.srv import Follow
import numpy as np
from mbse.srv import Detect
ArucoTopic = '/housem8/aruco'
FineTopic = '/detection'
class FineimageSubscriber(Node):
    def __init__(self):
        super().__init__('sub_imagefromfinedetection')
        self.subscription = self.create_subscription(Dect, FineTopic, self.listener_callback, 10)
    def listener_callback(self,msg):
        self.get_logger().info(msg.obj_class.data + ": " + str(msg.obj_point.data) + str(msg.rotation.data))
class ArucoSubscriber(Node):

    def __init__(self):
        super().__init__('sub_arucoANDfollowing_human')

        self.subscription = self.create_subscription(Custom, ArucoTopic, self.listener_callback, 10)

        # #following human client
        # self.cli = self.create_client(Follow, 'followinghuman')
        # while not self.cli.wait_for_service(timeout_sec=1.0):
        #     self.get_logger().info('service not available, waiting again...')
        # self.req = Follow.Request()

        # publish cmd_vel
        self.publisher = self.create_publisher(Twist, "/housem8/cmd_vel", 10)

    def send_request(self):
        self.req.x = self.followX
        self.req.z = self.followZ
        self.future = self.cli.call_async(self.req)

    def listener_callback(self, msg):
        move = Twist()
        self.id = (msg.id.data).tolist()
        self.tvec = (msg.tvec.data).tolist()
        self.eul = (msg.eul.data).tolist()
        self.qua = (msg.qua.data).tolist()

        # collect message to list
        # id = [1,2,3,...]
        # translationVector = [[x1,y1,z1],[x2,y2,z2],[x3,y3,z3],...]
        # eulerAngle = [[r1,p1,y1],[r2,p2,y2],[r3,p3,y3],...]
        # quaternion = [[qx1,qy1,qz1,qw1],[qx2,qy2,qz2,qw2],[qx3,qy3,qz3,qw3],...]
        self.translationVector = []
        self.eulerAngle = []
        self.quaternion = []
        if self.id != []:
            for i in range(len(self.id)):
                x = self.tvec[(3 * i) + 0]
                y = self.tvec[(3 * i) + 1]
                z = self.tvec[(3 * i) + 2]
                self.translationVector.append([x, y, z])

                r = self.eul[(3 * i) + 0] * 180 / pi
                p = self.eul[(3 * i) + 1] * 180 / pi
                y = self.eul[(3 * i) + 2] * 180 / pi
                self.eulerAngle.append([r, p, y])

                qx = self.qua[(4 * i) + 0]
                qy = self.qua[(4 * i) + 1]
                qz = self.qua[(4 * i) + 2]
                qw = self.qua[(4 * i) + 3]
                self.quaternion.append([qx, qy, qz, qw])

        # self.followX = x
        # self.followZ = z
        self.forward = 0.0
        self.rotate = 0.0
        if 1 in self.id:
            print("found human")
            self.forward, self.rotate = self.FollowingHuman(self.id, x, z)
        print(self.forward)
        print(self.rotate)
        move.linear.x = self.forward
        move.linear.y = 0.0
        move.linear.z = 0.0
        move.angular.x = 0.0
        move.angular.y = 0.0
        move.angular.z = self.rotate
        self.publisher.publish(move)
        self.get_logger().info("Found " + str(len(self.id)) + " Marker(s)")
        print("*************************************************\nID = ")
        print(self.id)
        print("*************************************************\nTranslation Vector = ")
        print(self.translationVector)
        print("*************************************************\nEuler Angle = ")
        print(self.eulerAngle)
        print("*************************************************\nQuaternion = ")
        print(self.quaternion)

    def FollowingHuman(self,id,x,z):
        forward = 0.0
        rotate = 0.0
        if x < -0.2:
            rotate = 0.2
        elif x > 0.2:
            rotate = -0.2
        else:
            rotate = 0.0
            if z > 0.5:
                forward = 0.2
            elif z <= 0.1:
                forward = -0.2
            else:
                forward = 0.0
        return forward,rotate
class Corescheduler(Node):
    def __init__(self,minimal_subscriber,fine_subscriber):
        super().__init__('Detection_CoreScheduler')
        self.srv = self.create_service(Detect, '/Core/Detect', self.core_callback)  # CHANGE
        self.task = 0
        self.minimal_subscriber = minimal_subscriber
        self.fine_subscriber = fine_subscriber
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
    minimal_subscriber = ArucoSubscriber()
    fine_subscriber = FineimageSubscriber()
    linktocore = Corescheduler(minimal_subscriber,fine_subscriber)
    rclpy.spin(linktocore)
    try:
        while rclpy.ok():
            rclpy.spin_once(minimal_subscriber)
            rclpy.spin_once(fine_subscriber)

    except KeyboardInterrupt:
        print('stopped')
    except BaseException:
        print('exception')
        raise
    finally:
        minimal_subscriber.destroy_node()
        fine_subscriber.destroy_node()
        rclpy.shutdown()

    # rclpy.spin(minimal_subscriber)
    # fine_subscriber.destroy_node()
    # minimal_subscriber.destroy_node()
    # rclpy.shutdown()


if __name__ == '__main__':
    main()