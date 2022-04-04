#!/usr/bin/env python3

import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import Command, FindExecutable, LaunchConfiguration
from launch_ros.actions import Node
import xacro

def generate_launch_description():
    # xarco_path = os.path.join(
    # get_package_share_directory('panda_description'))

    # xacro_file = os.path.join(xarco_path,
    #                           'robots',
    #                           'panda_arm.urdf.xacro')
    # doc = xacro.parse(open(xacro_file))
    # xacro.process_doc(doc)
    # params = {'robot_description': doc.toxml()}

    franka_xacro_file = os.path.join(get_package_share_directory('panda_description'), 'robots',
                                    'panda_arm.urdf.xacro')
    robot_description = Command(
        [FindExecutable(name='xacro'), ' ', franka_xacro_file])
    print(robot_description)
    rviz_file = os.path.join(get_package_share_directory('panda_description'), 'rviz',
                             'panda_visualize.rviz')
    # print(params)
    node_robot_state_publisher = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        output='both',
        parameters=[{'robot_description': robot_description}],
    )
    node_joint_state_publisher_gui = Node(
        package='joint_state_publisher_gui',
        executable='joint_state_publisher_gui',
        name='joint_state_publisher_gui'
        ),
    node_rviz = Node(package='rviz2',
             executable='rviz2',
             name='rviz2',
             arguments=['--display-config', rviz_file])

    return LaunchDescription([
        node_robot_state_publisher,
        node_joint_state_publisher_gui,
        node_rviz,
    ])
