#!/usr/bin/env python3
import os
from re import X
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import ExecuteProcess, IncludeLaunchDescription, RegisterEventHandler
from launch.event_handlers import OnProcessExit
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
import xacro


def generate_launch_description():
    gazebo = IncludeLaunchDescription(
                PythonLaunchDescriptionSource([os.path.join(
                    get_package_share_directory('gazebo_ros'), 'launch'), '/gazebo.launch.py']),
             )
    # world_file_name = 'box_bot_empty.world'
    # world = os.path.join(get_package_share_directory('box_bot_gazebo'), 'worlds', world_file_name)

    # gazebo = ExecuteProcess(
    #         cmd=['gazebo', '--verbose', world, '-s', 'libgazebo_ros_init.so'],
    #         output='screen'),
    
    ###
    world_file_name = 'house.sdf'
    world = os.path.join(get_package_share_directory('housem8_gazebo'), 'world', world_file_name)

    gazebo = ExecuteProcess(cmd=['gazebo', '--verbose', world, '-s', 'libgazebo_ros_init.so', '-s', 'libgazebo_ros_factory.so'],output='screen')
    ###
    
    
    use_sim_time = LaunchConfiguration('use_sim_time', default='true')

    xacro_file = "housem8.urdf.xacro"
    package_description = "housem8_description"

    robot_desc_path = os.path.join(get_package_share_directory(
        package_description), "robots", xacro_file)

    robot_desc = xacro.process_file(robot_desc_path)
    xml = robot_desc.toxml()

    params = {'robot_description': xml}
    sim_time = {'use_sim_time': True}
    
    node_robot_state_publisher = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        output='both',
        parameters=[params,sim_time]
    )

    publish_robot_description = Node(
        package="panda_gazebo",
        executable='robot_description_publisher.py',
        name='robot_description_publisher',
        output='screen',
        arguments=['-xml_string', xml,
                   '-robot_description_topic', '/robot_description'
                   ]
    )

    joint_state_publisher = Node(
        package='joint_state_publisher',
        executable='joint_state_publisher',
        name='joint_state_publisher')

    spawn_entity = Node(package='gazebo_ros', executable='spawn_entity.py',
                        arguments=['-topic', 'robot_description',
                                   '-entity', 'housem8_robot'],
                        output='screen')

    load_joint_state_controller = ExecuteProcess(
        cmd=['ros2', 'control', 'load_controller', '--set-state', 'start',
             'joint_state_broadcaster'],
        output='screen'
    )

    arm_trajectory_controller = ExecuteProcess(
        cmd=['ros2', 'control', 'load_controller', '--set-state', 'start',
             'arm_controller'],
        output='screen'
    )

    hand_trajectory_controller = ExecuteProcess(
        cmd=['ros2', 'control', 'load_controller', '--set-state', 'start',
             'gripper_controller'],
        output='screen'
    )

    return LaunchDescription([
        # ExecuteProcess(
        #     cmd=['gazebo', '--verbose', world, '-s', 'libgazebo_ros_init.so'],
        #     output='screen'),

        RegisterEventHandler(
            event_handler=OnProcessExit(
                target_action=spawn_entity,
                on_exit=[load_joint_state_controller],
            )
        ),
        RegisterEventHandler(
            event_handler=OnProcessExit(
                target_action=load_joint_state_controller,
                on_exit=[arm_trajectory_controller],
            )
        ),
        RegisterEventHandler(
            event_handler=OnProcessExit(
                target_action=load_joint_state_controller,
                on_exit=[hand_trajectory_controller],
            )
        ),

        # publish_robot_description,
        # joint_state_publisher,
        gazebo,
        node_robot_state_publisher,
        spawn_entity

    ])
