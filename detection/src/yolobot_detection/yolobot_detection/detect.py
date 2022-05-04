#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image, CompressedImage
from cv_bridge import CvBridge, CvBridgeError
from interfaces.msg import Dect
import numpy as np
import torch
import cv2

model = torch.hub.load('ultralytics/yolov5', 'yolov5s')
# load model
# model = torch.hub.load('ultralytics/yolov5', 'yolov5m6')
model.conf = 0.5
bridge = CvBridge()

class FineDetect(Node):
    def __init__(self):
        super().__init__('camera_subscriber')
        self.publisher_ = self.create_publisher(Dect, 'detection/yolov5', 10)
        timer_period = 0.1  # seconds
        # self.timer = self.create_timer(timer_period, self.timer_callback)
        self.capture_index = 0
        self.subscription = self.create_subscription(Image,'rgb_cam/image_raw',self.camera_callback,10)
        self.subscription

    def camera_callback(self, data):
        img = bridge.imgmsg_to_cv2(data, "bgr8")
        # ret, frame = img.read()
        frame = img

        results = model(frame)
        names = model.names
        labels, cord = results.xyxyn[0][:,-1],results.xyxyn[0][:,:-1] 
        # labels, cord, frame = dectrun()
        n = len(labels)
        x_shape,y_shape = frame.shape[1],frame.shape[0]
        for i in range(n):
            row = cord[i]
            if row[4] >= 0.3:
                msg = Dect()
                msg.x1, msg.y1, msg.x2, msg.y2 = float(row[0]*x_shape), float(row[1]*y_shape), float(row[2]*x_shape), float(row[3]*y_shape)
                # msg.confidence = float(row[4])
                msg.obj_class = names[int(labels[i])]
                self.publisher_.publish(msg)
                self.get_logger().info('Publishing: "%s"' % msg.obj_class)
        # self.i += 1

def main(args=None):
    rclpy.init(args=args)
    camera_subscriber = FineDetect()
    rclpy.spin(camera_subscriber)
    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    rclpy.shutdown()
    rclpy.shutdown()


if __name__ == '__main__':
    main()