
# Housem8 Gazebo Simulation

### Build This Package on your ROS2 Workspace

Cloning respository

```
  cd ~/<colcon_ws>
  git clone https://github.com/5730289021-NN/502/housem8_robot.git
```

### Topics (Subscription)

| Parameter | Type     | Description                |
| :-------- | :------- | :------------------------- |
| `/housem8/cmd_vel` | `geometry_msgs/Twist.msg` | **Robot Twist** // *State = [Vx,Wz]* Base Controller |


### Topics (Publishing)

| Parameter | Type     | Description                |
| :-------- | :------- | :------------------------- |

| `/housem8/body_cam/image_raw` | `sensor_msgs/Image.msg` | **Body Camera** RGB Camera Array |
| `/housem8/body_cam/depth/image_raw` | `sensor_msgs/Range.msg` | **Body Camera** Depth Sensor Array |
| `/housem8/hand_cam/image_raw` | `sensor_msgs/Image.msg` | **Hand Camera** RGB Camera Array |
| `/housem8/hand_cam/depth/image_raw` | `sensor_msgs/Range.msg` | **Hand Camera** Depth Sensor Array |
| `/housem8/scan/front` | `sensor_msgs/LaserScan.msg` | **Front Lidar** Houkyo Lidar Laserscan |
| `/housem8/scan/back` | `sensor_msgs/LaserScan.msg` | **Hand Camera** Houkyo Lidar Laserscan |
| `/housem8/imu` | `sensor_msgs/Imu.msg` | **Hand Camera** Houkyo Lidar Laserscan |

| `/housem8/odom` | `nav_msgs/Odometry.msg` | **Hand Camera** Odometry of Housem8 Robot |

### Action (Server)

| Parameter | Type     | Description                |
| :-------- | :------- | :------------------------- |
| `/joint_trajectory_controller/follow_joint_trajectory` | `control_msgs/follow_joint_trajectory.action` | **Manipulator Position Trajecotry interface** // *State = ["Mani_J0", "Mani_J1", "Mani_J2" "Mani_J3", "Mani_J4", "Mani_J5", "Mani_J6"]* Manipulator Controller |

launch file to spawn the robot in Gazebo

```
  ros2 launch housem8_gazebo spawn_gazebo.launch.py
```



