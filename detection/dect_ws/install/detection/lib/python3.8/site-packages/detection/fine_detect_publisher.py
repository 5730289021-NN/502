#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from std_msgs.msg import String
import pyrealsense2 as rs
import os
import numpy as np
import torch
from detection_interfaces.msg import Dect

from .detection_lib import main_debug

class MinimalPublisher(Node):

    def __init__(self):
        super().__init__('minimal_publisher')
        self.publisher_ = self.create_publisher(Dect, 'topic', 10)
        timer_period = 0.5  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        # self.i = 0

        self.pipeline = rs.pipeline()
        self.config = rs.config()
        self.config.enable_stream(rs.stream.depth, 640, 480, rs.format.z16, 60)
        self.config.enable_stream(rs.stream.color, 640, 480, rs.format.bgr8, 60)
        # Start streaming
        self.pipeline.start(self.config)

    def timer_callback(self):

        frames = self.pipeline.wait_for_frames()
        depth_frame = frames.get_depth_frame()
        color_frame = frames.get_color_frame()
        if not depth_frame or not color_frame:
            pass
        boxs,dist = main_debug.dectrun(depth_frame, color_frame)
        for ind,box in enumerate(boxs):
            msg = Dect()
            # print(type(main_debug.dectrun(depth_frame, color_frame)[0]))
            msg.bounding_x = float(box[0])
            msg.bounding_y = float(box[1])
            msg.bounding_w = float(box[2])
            msg.bounding_h = float(box[3])
            msg.bounding_d = float(dist[ind])
            msg.obj_class = box[-1]
            # msg.data = 'Hello World: %d' % self.i
            self.publisher_.publish(msg)
            self.get_logger().info('Publishing: "%s"' % msg.obj_class)
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

