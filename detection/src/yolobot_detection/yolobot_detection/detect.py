#!/usr/bin/env python3
from cmath import sqrt
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
import math

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
        self.depth = self.create_subscription(Image,'rgb_cam/depth/image_raw',self.camera_callback_depth,10)
        self.depth
        self.depth_img = 0

    def get_mid_pos(self,box,depth_data,randnum):
        distance_list = []
        distance_list_right = []
        center = 0
        mid_pos = [(box[0].numpy() + box[2].numpy() )//2, (box[1].numpy()  + box[3].numpy() )//2] #确定索引深度的中心像素位置
        if mid_pos[0] == 320:
            center = 1
        min_val = min(abs(box[2].numpy()  - box[0].numpy() ), abs(box[3].numpy()  - box[1].numpy() )) #确定深度搜索范围
        # print(mid_pos)
        # print(depth_data)
        for i in range(randnum):
            bias = random.randint(-min_val//4, min_val//4)
            dist = depth_data[int(mid_pos[1] + bias), int(mid_pos[0] + bias)]
            try:
                dist_b = depth_data[int(right_pose[1] + bias), int(right_pose[0] + bias)]
            except:
                dist_b = depth_data[int(right_pose[1] + bias), int(right_pose[0] + bias)]
            #print(int(mid_pos[1] + bias), int(mid_pos[0] + bias))
            if dist:
                distance_list.append(dist)
            if dist_b:
                distance_list_right.append(dist_b)
        distance_list = np.array(distance_list)
        distance_list = np.sort(distance_list)[randnum//2-randnum//4:randnum//2+randnum//4] #冒泡排序+中值滤波
        if center:
            return round(np.mean(distance_list),4), 0
        distance_list_right = np.array(distance_list_right)
        distance_list_right = np.sort(distance_list_right)[randnum//2-randnum//4:randnum//2+randnum//4]
        depth = np.mean(distance_list)
        depth_x = np.mean(distance_list_right)
        #print(distance_list, np.mean(distance_list))
        if depth > depth_x:
            arc = math.acos(depth_x/depth)
        else:
            arc = math.acos(depth/depth_x)
        # print(arc, round(arc*(320-mid_pos[0])*180/math.pi,4))
        try:
            return round(np.mean(distance_list),4), round(arc*(320-mid_pos[0])*180/math.pi,4)
        except:
            return round(np.mean(distance_list),4), 0

    
    def camera_callback_depth(self,data):
        # self.depth_img = np.asanyarray(data)
        self.depth_img = bridge.imgmsg_to_cv2(data, "32FC1")

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
                msg.cam_x, msg.cam_y = float((row[0]+row[2])*x_shape/2), float((row[1]+row[3])*y_shape/2)
                # print(msg.cam_x, msg.cam_y)
                depth = self.get_mid_pos([row[0]*x_shape,row[1]*y_shape,row[2]*x_shape,row[3]*y_shape],self.depth_img,24)
                msg.obj_class = names[int(labels[i])]
                self.publisher_.publish(msg)
                self.get_logger().info(msg.obj_class + ": " + str(depth))

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