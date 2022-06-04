#!/usr/bin/env python3

from housem8_aruco.srv import Follow

import rclpy
from rclpy.node import Node

class FollowService(Node):
    def __init__(self):
        super().__init__('FollowServieNode')
        self.srv = self.create_service(Follow, 'followinghuman', self.following_callback)

    def following_callback(self, request, response):
        print(request.x)
        print(request.z)
        response.state = "running.............."
        return response

def main(args=None):
    rclpy.init(args=args)
    minimal_service = FollowService()
    rclpy.spin(minimal_service)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
