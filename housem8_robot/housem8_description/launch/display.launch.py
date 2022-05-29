#!/usr/bin/env python3
import os
from time import time
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, SetEnvironmentVariable
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
import sys
import time 

def generate_launch_description():
    # Get the launch directory
    housem8_dir = get_package_share_directory('housem8_description')
    rviz_file_name = 'urdf_config.rviz'
    rviz_file_path = os.path.join(housem8_dir, 'rviz', rviz_file_name)
    stdout_linebuf_envvar = SetEnvironmentVariable('RCUTILS_LOGGING_BUFFERED_STREAM', '1')

    use_sim_time = LaunchConfiguration('use_sim_time', default='false')
    # urdf_file_name = 'urdf/findchessbot.urdf'
    # urdf = os.path.join(
    #     get_package_share_directory('findchessbot'),
    #     urdf_file_name)
    # with open(urdf, 'r') as infp:
    #     robot_desc = infp.read()

    pkg_share = get_package_share_directory('housem8_description')
    urdf_dir = os.path.join(pkg_share, 'robots')
    urdf_file = os.path.join(urdf_dir, 'housem8.xarco')
    with open(urdf_file, 'r') as infp:
        robot_desc = infp.read()

    params = {'robot_description': robot_desc}

    rviz_Node = Node(
        package='rviz2',
        executable='rviz2',
        name='rviz',
        arguments=['-d', rviz_file_path],
        output='screen')

    robot_state_publisher = Node(package='robot_state_publisher',
                                  executable='robot_state_publisher',
                                  output='screen',
                                  parameters=[params])

    joint_state_publisher = Node(package='joint_state_publisher',
                                    executable='joint_state_publisher',
                                    name='joint_state_publisher'
    )
    joint_state_publisher_gui = Node(package='joint_state_publisher_gui',
                                        executable='joint_state_publisher_gui',
                                        name='joint_state_publisher_gui'
    )

    # print(robot_state_publisher)
    ld = LaunchDescription()
    ld.add_action(stdout_linebuf_envvar)

    ld.add_action(joint_state_publisher)

    ld.add_action(robot_state_publisher)

    ld.add_action(joint_state_publisher_gui)
    # time.sleep(1)
    ld.add_action(rviz_Node)



    return ld


def main(args=None):
    try:
        generate_launch_description()
    except KeyboardInterrupt:
        # quit
        sys.exit()


if __name__ == '__main__':
    main()
    