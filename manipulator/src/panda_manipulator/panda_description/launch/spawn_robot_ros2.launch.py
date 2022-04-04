import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.substitutions import LaunchConfiguration

from launch_ros.actions import Node
import xacro
import random


def generate_launch_description():

    xacro_file = "panda_arm.urdf.xacro"
    package_description = "panda_description"

    robot_desc_path = os.path.join(get_package_share_directory(
        package_description), "robots", xacro_file)

    robot_desc = xacro.process_file(robot_desc_path)
    xml = robot_desc.toxml()

    publish_robot_description = Node(
        package="panda_gazebo",
        executable='robot_description_publisher.py',
        name='robot_description_publisher',
        output='screen',
        arguments=['-xml_string', xml,
                   '-robot_description_topic', '/robot_description'
                   ]
    )

    params = {'robot_description':xml}
    sim_time = {'use_sim_time': True}
    robot_state_publisher_node = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        parameters=[params,sim_time],
        output="screen"
    )

    joint_state_publisher_gui = Node(
        package='joint_state_publisher_gui',
        executable='joint_state_publisher_gui',
        name='joint_state_publisher_gui')


    rviz_config_dir = os.path.join(get_package_share_directory(
        package_description), 'rviz', 'panda_visualize.rviz')

    rviz_node = Node(
        package='rviz2',
        executable='rviz2',
        output='screen',
        name='rviz_node',
        parameters=[{'use_sim_time': True}],
        arguments=['-d', rviz_config_dir])

    return LaunchDescription(
        [

            publish_robot_description,
            robot_state_publisher_node,
            joint_state_publisher_gui,
            rviz_node
        ]
    )
