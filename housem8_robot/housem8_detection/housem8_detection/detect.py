#!/usr/bin/env python3
from cmath import sqrt
from turtle import right, shape
from cv2 import Rodrigues
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from std_msgs.msg import Float32MultiArray,String
import random
from cv_bridge import CvBridge, CvBridgeError
from housem8_interfaces.msg import Dect
import numpy as np
import torch
# import pcl
# import pcl_helper
import numpy as np
import math

model = torch.hub.load('ultralytics/yolov5', 'yolov5s')
# load model
# model = torch.hub.load('ultralytics/yolov5', 'yolov5m6')
model.conf = 0.5
bridge = CvBridge()

k = [[381.36246688113556, 0.0, 320.5],
     [0.0, 381.36246688113556, 240.5],
     [0.0, 0.0, 1.0]]


class FineDetect(Node):
    def __init__(self):
        super().__init__('camera_subscriber')
        self.publisher_ = self.create_publisher(Dect, '/detection', 10)
        # self.timer = self.create_timer(timer_period, self.timer_callback)
        self.capture_index = 0
        self.color = self.create_subscription(Image,'rgb_cam/image_raw',self.camera_callback,10)
        self.color
        self.depth = self.create_subscription(Image,'rgb_cam/depth/image_raw',self.camera_callback_depth,10)
        # self.depth = self.create_subscription(PointCloud2,'rgb_cam/points',self.camera_callback_depth,10)
        self.depth
        self.depth_img = 0

    def get_mid_pos(self,box,depth_data,randnum):
        # print(depth_data)
        # if (type(depth_data) != "int"):
        distance_list = []
        center = 0
        try:
            mid_pos = [(box[0].numpy() + box[2].numpy() )//2, (box[1].numpy()  + box[3].numpy() )//2] #确定索引深度的中心像素位置
            if mid_pos[0] == 320:
                center = 1
            min_val = min(abs(box[2].numpy()  - box[0].numpy() ), abs(box[3].numpy()  - box[1].numpy() )) #确定深度搜索范围
            # print(mid_pos)
            # print(depth_data)
            for i in range(randnum):
                bias = random.randint(-min_val//4, min_val//4)
                dist = depth_data[int(mid_pos[1] + bias), int(mid_pos[0] + bias)]
                if dist:
                    distance_list.append(dist)
            distance_list = np.array(distance_list)
            distance_list = np.sort(distance_list)[randnum//2-randnum//4:randnum//2+randnum//4] #冒泡排序+中值滤波
            depth = round(np.mean(distance_list),4)
            if center:
                return 0.0,0.0,0.0
            else:
                x,y,z = (mid_pos[0]-k[0][2])*depth/k[0][0], (mid_pos[1]-k[1][2])*depth/k[1][1], float(depth)
                return x,y,z
        except:
            return 0.0,0.0,0.0
    
    def get_rotation(self,coor):
        try:
            return [0.0,0.0, math.asin(coor[0]/coor[2])]
        except:
            return [0.0, 0.0, 0.0]

    def camera_callback_depth(self,data):
        # print(data.fields)
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
                msg.obj_point = Float32MultiArray()
                msg.obj_point.data = self.get_mid_pos(row,self.depth_img,24)
                msg.obj_class = String()
                msg.obj_class.data = names[int(labels[i])]
                msg.goal_point = Float32MultiArray()
                msg.goal_point.data = [0.0, 0.0, 0.0]
                msg.rotation = Float32MultiArray()
                msg.rotation.data = self.get_rotation(msg.obj_point.data)
                self.publisher_.publish(msg)
                self.get_logger().info(msg.obj_class.data + ": " + str(msg.obj_point.data) + str(msg.rotation.data))

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