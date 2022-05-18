# Detection on Gazebo

detection <br />
--src (source code)  <br />
> --yolobot_control  <br />
  --yolobot_description  <br />
  --yolobot_gazebo   <br />
  >> --launch <br />
  >>> --yolobot_launch.py  <br />
 
 > --yolobot_recognition <br />
  >>--scripts  <br />
  >>> --ros_recognition_yolo.py  <br />
  
 -- models (gazebo model) <br />
 
 ## Setup
 1. copy files inside models directory to .gazebo <br/>
 2. ros2 launch yolobot_gazebo yolobot_launch.py <br/>
 3. go to /yolobot/src/yolobot_recognition/scripts/ <br/>
 4. run python3 ros_recognition_yolo.py </br>


# unit run

open gazebo<br/>
ros2 launch yolobot_gazebo yolobot_launch.py

run node<br/>
ros2 run yolobot_detection detect_talker
