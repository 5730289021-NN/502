#include <moveit/move_group_interface/move_group_interface.h>
#include <ros/ros.h>
#include <gazebo_msgs/ModelStates.h>
#include <geometry_msgs/Pose.h>
#include <std_msgs/String.h>
#include <string>
#include <map>

/*
Assumption:
 - The location of the object is known from "gazebo/model_states" topics with the name that sent from user
    - This in the future should be changed to one that provided from core module.
 - This action server will return false if object_name is not found.
 - This 
*/

std::map<std::string, geometry_msgs::Pose> obj_map;
moveit::planning_interface::MoveGroupInterface *arm_move_group_interface;
moveit::planning_interface::MoveGroupInterface *gripper_move_group_interface;

void gazebo_obj_cb(const gazebo_msgs::ModelStates::ConstPtr& msg) {
    if(msg->name.size() != msg->pose.size()) {
        ROS_ERROR("Input objeect size mismatched");
        return;
    }
    for(int i = 0; i < msg->name.size(); i++) {
        obj_map[msg->name[i]] = msg->pose[i];
    }
    // Render in RViz

}

void obj_to_grasp_cb(const std_msgs::String msg) {
    ROS_INFO("callback called");
    if(obj_map.count(msg.data) == 1) {
        //found
        ROS_INFO("Current Pose Quaternion w=%f,x=%f,y=%f,z=%f", arm_move_group_interface->getCurrentPose().pose.orientation.w
                                    , arm_move_group_interface->getCurrentPose().pose.orientation.x
                                    , arm_move_group_interface->getCurrentPose().pose.orientation.y
                                    , arm_move_group_interface->getCurrentPose().pose.orientation.z);

        geometry_msgs::Pose target_pose = obj_map[msg.data];


        target_pose.orientation.w = 0;
        target_pose.orientation.x = 1;
        target_pose.orientation.y = 0;
        target_pose.orientation.z = 0;
        
        arm_move_group_interface->setPoseTarget(target_pose);
        // arm_move_group_interface->setPositionTarget(target_pose.position.x, target_pose.position.y, target_pose.position.z);
        moveit::planning_interface::MoveGroupInterface::Plan my_plan;
        ROS_INFO("Planning...");
        if(arm_move_group_interface->plan(my_plan) == moveit::core::MoveItErrorCode::SUCCESS) {
            ROS_INFO("Plan to object successful");
        } else {
            ROS_INFO("Plan Failed");
        }
        ROS_INFO("Executing...");
        if(arm_move_group_interface->execute(my_plan) == moveit::core::MoveItErrorCode::SUCCESS) {
            ROS_INFO("Execution successful");
        } else {
            ROS_INFO("Execution Failed");
        }
    } else {
        ROS_INFO_STREAM("Object with the name " << msg.data << " not found");
    }
    

}


int main(int argc, char **argv) {
    ros::init(argc, argv, "manipulator_server");
    ros::NodeHandle nh("~");
    ROS_INFO("Manipulator Server Started");
    arm_move_group_interface = new moveit::planning_interface::MoveGroupInterface("arm");
    gripper_move_group_interface = new moveit::planning_interface::MoveGroupInterface("gripper");
    ros::Subscriber gazebo_obj = nh.subscribe<gazebo_msgs::ModelStates>("/gazebo/model_states", 1, gazebo_obj_cb);
    ros::Subscriber core_cmd = nh.subscribe<std_msgs::String>("/obj_to_grasp", 1, obj_to_grasp_cb);
    ros::Rate r(10);
    ros::AsyncSpinner spinner(0); // use a thread for each CPU core.
    spinner.start();
    ros::waitForShutdown();
}