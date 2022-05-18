#!/usr/bin/env python3
from cv2 import Rodrigues
import rclpy
from rclpy.node import Node
import rosidl_runtime_py
from sensor_msgs.msg import Image, CompressedImage
import random
from cv_bridge import CvBridge, CvBridgeError
from interfaces.msg import Dect
import numpy as np
import torch
import cv2
import numpy as np

model = torch.hub.load('ultralytics/yolov5', 'yolov5s')
# load model
# model = torch.hub.load('ultralytics/yolov5', 'yolov5m6')
model.conf = 0.5
bridge = CvBridge()


class FineDetect(Node):
    def __init__(self):
        super().__init__('camera_subscriber')
        self.publisher_ = self.create_publisher(Dect, '/detection/yolov5', 10)
        # self.timer = self.create_timer(timer_period, self.timer_callback)
        self.capture_index = 0
        self.color = self.create_subscription(Image,'rgb_cam/image_raw',self.camera_callback,10)
        self.color
        self.depth = self.create_subscription(Image,'rgb_cam/points',self.camera_callback_depth,10)
        self.depth
        self.depth_img = 0

    def get_mid_pos(self,box,depth_data,randnum):
        distance_list = []
        mid_pos = [(box[0] + box[2])//2, (box[1] + box[3])//2] #确定索引深度的中心像素位置
        min_val = min(abs(box[2] - box[0]), abs(box[3] - box[1])) #确定深度搜索范围
        #print(box,)
        for i in range(randnum):
            bias = random.randint(-min_val//4, min_val//4)
            dist = depth_data[int(mid_pos[1] + bias), int(mid_pos[0] + bias)]
            #print(int(mid_pos[1] + bias), int(mid_pos[0] + bias))
            if dist:
                distance_list.append(dist)
        distance_list = np.array(distance_list)
        distance_list = np.sort(distance_list)[randnum//2-randnum//4:randnum//2+randnum//4] #冒泡排序+中值滤波
        #print(distance_list, np.mean(distance_list))
        return np.mean(distance_list)
    
    def camera_callback_depth(self,data):
        self.depth_img = np.asanyarray(data)

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
                depth = self.get_mid_pos(row,self.depth_img,24)
                msg.cam_x, msg.cam_y = float((row[0]+row[2])*x_shape/2), float((row[1]+row[3])*y_shape/2)
                msg.obj_class = names[int(labels[i])]
                self.publisher_.publish(msg)
                self.get_logger().info(msg.obj_class + ": " + str(depth/1000)[:4])

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