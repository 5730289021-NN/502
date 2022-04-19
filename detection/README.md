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
 
 1. copy files inside models directory to .gazebo <br/>
 2. ros2 launch yolobot_gazebo yolobot_launch.py <br/>
 3. go to /yolobot/src/yolobot_recognition/scripts/ <br/>
 4. run python3 ros_recognition_yolo.py </br>
 
 I did try to make a yolobot_recognition executable with ros2 run command. Unfortunately, I can't, but still able to publish data
 
 ros_recognition_yolo.py publish detection: x1,y1,x2,y2, and obj_class
