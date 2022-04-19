#!/usr/bin/env python
import os, sys
import rclpy
import time
from rclpy.node import Node

from sensor_msgs.msg import Image, CompressedImage
from cv_bridge import CvBridge, CvBridgeError
import cv2

import numpy as np
import torch
from detection_interfaces.msg import Dect

from .detection_lib import ros_recognition_yolo

bridge = CvBridge()

class MinimalPublisher(Node):

    def __init__(self):
        super().__init__('camera_subscriber')
        self.publisher_ = self.create_publisher(Dect, 'topic', 10)
        self.subscription = self.create_subscription(
            Image,
            'rgb_cam/image_raw',
            self.camera_callback,
            10)
        self.subscription  # prevent unused variable warning
       

    def camera_callback(self, data):
        t0 = time.time()
        img= bridge.imgmsg_to_cv2(data, "bgr8")
        boxs,names = ros_recognition_yolo.dect_run(img)
        for ind,box in enumerate(boxs):
            msg = Dect()
            # # print(type(main_debug.dectrun(depth_frame, color_frame)[0]))
            # msg.x1 = float(box[0])
            # msg.y1= float(box[1])
            # msg.x2 = float(box[2])
            # msg.y2 = float(box[3])
            # # msg.bounding_d = float(dist[ind])
            # msg.obj_class = box[-1]
            # # msg.data = 'Hello World: %d' % self.i
            self.publisher_.publish(msg)
            self.get_logger().info('Publishing: "%s"' % boxs)
        # self.i += 1

def main(args=None):
    rclpy.init(args=args)
    minimal_publisher = MinimalPublisher()
    rclpy.spin(minimal_publisher)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    minimal_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
    # Configure depth and color streams
    
    # try:
    #     while True:
    #         # Wait for a coherent pair of frames: depth and color
    #         # box_dist, obj_class = dectrun(depth_frame, color_frame)
    #         minimal_publisher.message = str(main_debug.dectrun(depth_frame, color_frame))
    #         rclpy.spin(minimal_publisher)
    # finally:
    #     # Stop streaming
    #     pipeline.stop()
    #     minimal_publisher.destroy_node()
    #     rclpy.shutdown()

