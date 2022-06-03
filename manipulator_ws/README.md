# Manipulator Section of HouseM8 Project

## Tested Environment
Ubuntu 20.04 with ROS Noetic

## Build & Source
1. `cd 502/manipulator_ws`
2. `catkin build`
3. `source ~/502/manipulator_ws/setup.bash`

## Running Standalone
1. [Terminal A] Launch simulation with `roslaunch housem8_moveit_config gazebo.launch`
2. [Terminal B] Launch planner interface aka. move_group by `roslaunch housem8_moveit_config move_group.launch`
3. [Terminal C] To move arm/gripper with RViz, run `roslaunch housem8_moveit_config moveit_rviz.launch`
4. [Terminal D] To run the manipulator server, run `rosrun housem8_manipulator_server housem8_manipulator_server_node`

## housem8_manipulator_server_node
A node that communicates with planner interface directly with move_group C++ API.

### Advertising Services
1. `/plan_arm` (std_srvs/Trigger) [Passed]
2. `/execute_arm` (std_srvs/Trigger) [Passed]
3. `/close_gripper` (std_srvs/Trigger) [Passed]
4. `/open_gripper` (std_srvs/Trigger) [Passed]

### Subscribing Topics
1. `/target_object` (geometry_msgs/Pose) [Passed]
2. `/preferred_direction` (std_msgs/Int8) [Passed]
3. `/camera` [*WIP*]

### Action API
1. `/arm_controller/follow_joint_trajectory` [Passed]
2. `/gripper_controller/follow_joint_trajectory` [Passed]

### Grasping Direction
(quaternions in (x,y,z,w) convention)
- Preferred Direction 0: UP --- q_ee = (-0.7071068, 0.7071068, 0, 0) * q_obj; [Passed]
- Preferred Direction 1. FRONT --- q_ee = (0.5, -0.5, -0.5, 0.5) * q_obj; [Passed]
- Preferred Direction 2. UP_FIXED --- q_ee = (-0.7071068, 0.7071068, 0, 0) [Passed]

## housem8_manipulator_server_node Test Procedure
1. `rosservice call /open_gripper "{}"`
2. `rosservice call /close_gripper "{}"`
3. `rostopic pub /target_object geometry_msgs/Pose "position:
  x: -0.5
  y: 0.0
  z: 0.5
orientation:
  x: 0.0
  y: 0.0
  z: 0.0
  w: 1.0"`
4. `rostopic pub /preferred_direction std_msgs/Int8 "data: 2"` ...Check on Grasping Direction
5. `rosservice call /plan_arm "{}"`
6. `rosservice call /execute_arm "{}"`
