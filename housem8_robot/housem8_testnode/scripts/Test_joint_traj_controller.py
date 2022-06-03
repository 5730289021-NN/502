#!/usr/bin/python3

import sys
import rclpy
from rclpy.duration import Duration
from rclpy.action import ActionClient
from rclpy.node import Node
from control_msgs.action import FollowJointTrajectory
from trajectory_msgs.msg import JointTrajectoryPoint
# ros2 action list -t
# ros2 action info /joint_trajectory_controller/follow_joint_trajectory -t
# ros2 interface show control_msgs/action/FollowJointTrajectory

class Joint_Trajectory(Node):

    def __init__(self):
        super().__init__('Joint_Trajectory')
        self._action_client = ActionClient(self, FollowJointTrajectory, '/joint_trajectory_controller/follow_joint_trajectory')

    def send_goal(self, angle):
        goal_msg = FollowJointTrajectory.Goal()

        # Fill in data for trajectory
        joint_names = [ "Mani_J0",
                        "Mani_J1",
                        "Mani_J2",
                        "Mani_J3",
                        "Mani_J4",
                        "Mani_J5",
                        "Mani_J6"]

        points = []
        point1 = JointTrajectoryPoint()
        point1.positions = [0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0]

        point2 = JointTrajectoryPoint()
        point2.time_from_start = Duration(seconds=3, nanoseconds=0).to_msg()
        point2.positions = [0.65, 0.2, 0.0, angle, angle, angle, angle]

        points.append(point1)
        points.append(point2)
        # print(points)
        goal_msg.goal_time_tolerance = Duration(seconds=1, nanoseconds=0).to_msg()
        goal_msg.trajectory.joint_names = joint_names
        goal_msg.trajectory.points = points

        self._action_client.wait_for_server()
        self._send_goal_future = self._action_client.send_goal_async(goal_msg, feedback_callback=self.feedback_callback)

        self._send_goal_future.add_done_callback(self.goal_response_callback)
    
    def goal_response_callback(self, future):
        goal_handle = future.result()
        print(goal_handle)
        if not goal_handle.accepted:
            self.get_logger().info('Goal rejected :(')
            return

        self.get_logger().info('Goal accepted :)')

        self._get_result_future = goal_handle.get_result_async()
        self._get_result_future.add_done_callback(self.get_result_callback)
    
    def get_result_callback(self, future):
        result = future.result().result
        self.get_logger().info('Result: '+str(result))
        rclpy.shutdown()

    def feedback_callback(self, feedback_msg):
        feedback = feedback_msg.feedback
        #self.get_logger().info('Received feedback:'+str(feedback))

    

def main(args=None):
    
    rclpy.init()

    action_client = Joint_Trajectory()

    # angle = float(sys.argv[1])
    angle = -0.4
    future = action_client.send_goal(angle)

    rclpy.spin(action_client)


if __name__ == '__main__':
    main()