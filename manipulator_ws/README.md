# Manipulator Section of HouseM8 Project

## Tested Environment
Ubuntu 20.04 with ROS Noetic

## Build
`catkin build`

## Running Standalone
1. [Terminal A] Launch simulation with `roslaunch housem8_moveit_config gazebo.launch`
2. [Terminal B] Launch planner interface aka. move_group by `roslaunch housem8_moveit_config move_group.launch`
3. [Terminal C] To move arm/gripper with RViz, run `roslaunch housem8_moveit_config moveit_rviz.launch`
4. [Terminal D] To run the manipulator server, run `rosrun housem8_manipulator_server housem8_manipulator_server_node`

## housem8_manipulator_server_node
A node that communicates with planner interface directly with move_group C++ API.

### Services
1) `/plan_arm` (std_srvs/Trigger) [Untested]
2) `/execute_arm` (std_srvs/Trigger) [Untested]
3) `/close_gripper` (std_srvs/Trigger) [Tested]
4) `/open_gripper` (std_srvs/Trigger) [Tested]

### Subscriber
1) `/target_object` (geometry_msgs/Pose) [Untested]
