#include <moveit/move_group_interface/move_group_interface.h>
#include <ros/ros.h>
#include <geometry_msgs/Pose.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
#include <std_msgs/String.h>
#include <std_srvs/Trigger.h>
#include <std_msgs/Int8.h>
#include <string>
#include <map>

std::map<std::string, geometry_msgs::Pose> obj_map;
moveit::planning_interface::MoveGroupInterface *arm_move_group_interface;
moveit::planning_interface::MoveGroupInterface *gripper_move_group_interface;
moveit::planning_interface::MoveGroupInterface::Plan arm_plan;

enum GraspingDirection { UP_FIXED, UP, FRONT, UNDEFINED };
GraspingDirection gd = UP_FIXED;
geometry_msgs::Pose target_pose;

void target_obj_cb(const geometry_msgs::Pose::ConstPtr &msg) {
    target_pose = *msg;
}

void prefer_direction_cb(const std_msgs::Int8 &msg) {
    if(msg.data >= 0 && msg.data < UNDEFINED) {
        gd = (GraspingDirection) msg.data;
    }
}

bool plan_arm_cb(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res) {
    // https://www.andre-gaschler.com/rotationconverter/
    tf2::Quaternion q_obj, q_rot, q_ee;
    tf2::fromMsg(target_pose.orientation, q_obj);
    switch(gd)
    {
        case UP_FIXED:
        {
            q_ee.setX(0);
            q_ee.setY(-0.7071068);
            q_ee.setZ(0);
            q_ee.setW(0.7071068);
            break;
        }

        case FRONT:
        {
            q_rot = tf2::Quaternion(-0.5, -0.5, 0.5, -0.5);
            q_ee = q_rot * q_obj;
            break;
        }
                
        case UP:
        default:
        {
            q_rot = tf2::Quaternion(-0.7071068, 0.7071068, 0, 0);
            q_ee = q_rot * q_obj;
            break;
        }
    }
    ;
    target_pose.orientation = tf2::toMsg(q_ee);
    arm_move_group_interface->setPoseTarget(target_pose);
    ROS_INFO("Planning... to (x,y,z | x,y,z,w) %f, %f, %f | %f, %f, %f, %f", 
            target_pose.position.x,
            target_pose.position.y,
            target_pose.position.z,
            q_ee.getX(),
            q_ee.getY(),
            q_ee.getZ(),
            q_ee.getW());
    if(arm_move_group_interface->plan(arm_plan) == moveit::core::MoveItErrorCode::SUCCESS) {
        res.success = true;
        res.message = "Planning type " + std::to_string((int) gd) + " successful.";
        ROS_INFO_STREAM("Planning type " + std::to_string((int) gd) + " successful.");
    } else {
        res.success = false;
        res.message = "Planning type " + std::to_string((int) gd) + " failed.";
        ROS_ERROR_STREAM("Planning type " + std::to_string((int) gd) + " failed.");
    }
    return true;
}

bool execute_arm_cb(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res) {
    ROS_INFO("Executing...");
    if(arm_move_group_interface->execute(arm_plan) == moveit::core::MoveItErrorCode::SUCCESS) {
        res.success = true;
        res.message = "Executing type " + std::to_string((int) gd) + " successful.";
        ROS_INFO_STREAM("Executing type " + std::to_string((int) gd) + " successful.");
    } else {
        res.success = false;
        res.message = "Executing type " + std::to_string((int) gd) + " failed.";
        ROS_ERROR_STREAM("Executing type " + std::to_string((int) gd) + " failed.");
    }
    return true;
}

bool open_gripper_cb(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res) {
    gripper_move_group_interface->setJointValueTarget(gripper_move_group_interface->getNamedTargetValues("open"));
    if(gripper_move_group_interface->move() == moveit::core::MoveItErrorCode::SUCCESS) {
        res.success = true;
        res.message = "Gripper open successful.";
        ROS_INFO_STREAM("Gripper open successful.");
    } else {
        res.success = false;
        res.message = "Gripper open failed.";
        ROS_ERROR_STREAM("Gripper open failed.");
    }
    return true;
}

bool close_gripper_cb(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res) {
    gripper_move_group_interface->setJointValueTarget(gripper_move_group_interface->getNamedTargetValues("close"));
    if(gripper_move_group_interface->move() == moveit::core::MoveItErrorCode::SUCCESS) {
        res.success = true;
        res.message = "Gripper close successful.";
        ROS_INFO_STREAM("Gripper close successful.");
    } else {
        res.success = false;
        res.message = "Gripper close failed.";
        ROS_ERROR_STREAM("Gripper close failed.");
    }
    return true;
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "manipulator_server");
    ros::NodeHandle nh("~");
    ROS_INFO("Manipulator Server Started");
    arm_move_group_interface = new moveit::planning_interface::MoveGroupInterface("arm");
    gripper_move_group_interface = new moveit::planning_interface::MoveGroupInterface("gripper");

    ros::Subscriber target_object_sub = nh.subscribe<geometry_msgs::Pose>("/target_object", 1, target_obj_cb);
    ros::ServiceServer plan_arm_srv = nh.advertiseService("/plan_arm", plan_arm_cb);
    ros::ServiceServer execute_arm_srv = nh.advertiseService("/execute_arm", execute_arm_cb);
    ros::ServiceServer close_gripper_srv = nh.advertiseService("/close_gripper", close_gripper_cb);
    ros::ServiceServer open_gripper_srv = nh.advertiseService("/open_gripper", open_gripper_cb);

    ros::AsyncSpinner spinner(0); // use a thread for each CPU core.
    spinner.start();
    ros::Rate r(0.5);
    while(ros::ok()){
        geometry_msgs::PoseStamped current_pose = arm_move_group_interface->getCurrentPose();
        ROS_INFO("Current EE Pose: %f, %f, %f | %f, %f, %f, %f", 
            current_pose.pose.position.x,
            current_pose.pose.position.y,
            current_pose.pose.position.z,
            current_pose.pose.orientation.x,
            current_pose.pose.orientation.y,
            current_pose.pose.orientation.z,
            current_pose.pose.orientation.w
        );
        r.sleep();
    }
}