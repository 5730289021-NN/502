
# Fine Detection

In this stage, it will perform only object classification in real time, and object point & yaw identification respected to camera frame.
 


### Workspace Setting

Cloning respository

```
  cd ~/<your_workspace_path>
  git clone https://github.com/5730289021-NN/502/detection.git
```

Adding gazebo model into your gazebo Workspace
```
  cp -R ~/usr/GitHub/502/detection/gazebo_model/* ~/.gazebo/models/
```

### Topics (Subscription)

| Parameter | Type     | Description                |
| :-------- | :------- | :------------------------- |
| `rgb_cam/image_raw` | `uint array` | **Required**. webcam or depthcam |
| `rgb_cam/depth/image_raw` | `uint array` | **Required**. depthcam |

### Topics (Publishing)

| Parameter | Type     | Description                |
| :-------- | :------- | :------------------------- |
| `detection/obj_point` | `float32 array` | **camera frame** object 3D point |
| `detection/rotation` | `float32 array` | **camera frame** object 3D rotation |
| `detection/goal_point` | `float32 array` | **camera frame** goal 3D point |
| `detection/obj_class` | `string` | object class name |detection
**Camera frame: x (wide), y (high), z (depth)**

launch world

```
  ros2 launch yolobot_gazebo yolobot_launch.py
```

run ros2 node
```
  ros2 run yolobot_detection detect_talker
```

run only detection python file
```
  cd /502/detection/src/yolobot_detection/yolobot_detection
  python detect.py
```

Note: urdf of robot is in 
```
502/detection/src/yolobot_description/robot/
```


## Screenshots

![App Screenshot](https://github.com/5730289021-NN/502/blob/main/detection/Screenshot_from_2022-05-20_23-09-02.png)


