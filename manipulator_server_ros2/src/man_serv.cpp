#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <string>
#include <map>

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/pose.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_srvs/srv/trigger.hpp"
#include "std_msgs/msg/int8.hpp"
#include "tf2_geometry_msgs/tf2_geometry_msgs.hpp"
#include "moveit/move_group_interface/move_group_interface.h"


using namespace std::chrono_literals;

/* This example creates a subclass of Node and uses std::bind() to register a
* member function as a callback from the timer. */

enum GraspingDirection { UP_FIXED, UP, FRONT, UNDEFINED };


class ManServ : public rclcpp::Node
{
  public:
    ManServ() : Node("man_serv")
    {
        std::shared_ptr<rclcpp::Node> tmp_ptr(this);
        this_ptr = tmp_ptr;
        arm_move_group_interface = new moveit::planning_interface::MoveGroupInterface(this_ptr, "arm");
        arm_move_group_interface->setEndEffectorLink("TipPoint");
        gripper_move_group_interface = new moveit::planning_interface::MoveGroupInterface(this_ptr, "gripper");

        target_object_sub = this->create_subscription<geometry_msgs::msg::Pose>("/target_object", 1, std::bind(&ManServ::target_obj_cb, this, std::placeholders::_1));
        preferred_dir_sub = this->create_subscription<std_msgs::msg::Int8>("/preferred_direction", 1, std::bind(&ManServ::preferred_dir_cb, this, std::placeholders::_1));
        plan_arm_srv = this->create_service<std_srvs::srv::Trigger>("/plan_arm", std::bind(&ManServ::plan_arm_cb, this, std::placeholders::_1, std::placeholders::_2));
        execute_arm_srv = this->create_service<std_srvs::srv::Trigger>("/execute_arm", std::bind(&ManServ::execute_arm_cb, this, std::placeholders::_1, std::placeholders::_2));
        close_gripper_srv = this->create_service<std_srvs::srv::Trigger>("/close_gripper", std::bind(&ManServ::close_gripper_cb, this, std::placeholders::_1, std::placeholders::_2));
        open_gripper_srv = this->create_service<std_srvs::srv::Trigger>("/open_gripper", std::bind(&ManServ::open_gripper_cb, this, std::placeholders::_1, std::placeholders::_2));
        timer_ = this->create_wall_timer(500ms, std::bind(&ManServ::timer_callback, this));
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Manipulator Server Started");
    }

  private:

    // void add(const std::shared_ptr<std_srvs::srv::Trigger::Request> request,
    //       std::shared_ptr<std_srvs::srv::Trigger::Response>      response)
    // {
    // response->sum = request->a + request->b;
    // RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Incoming request\na: %ld" " b: %ld",
    //                 request->a, request->b);
    // RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "sending back response: [%ld]", (long int)response->sum);
    // }

    void timer_callback()
    {
    //   auto message = std_msgs::msg::String();
    //   message.data = "Hello, world! " + std::to_string(count_++);
        geometry_msgs::msg::PoseStamped current_pose = arm_move_group_interface->getCurrentPose("TipPoint");
        RCLCPP_INFO(this->get_logger(), "Current EE Pose: %f, %f, %f | %f, %f, %f, %f", 
            current_pose.pose.position.x,
            current_pose.pose.position.y,
            current_pose.pose.position.z,
            current_pose.pose.orientation.x,
            current_pose.pose.orientation.y,
            current_pose.pose.orientation.z,
            current_pose.pose.orientation.w
        );
    //   publisher_->publish(message);
    }
    rclcpp::TimerBase::SharedPtr timer_;
    // rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    // size_t count_;

    void topic_callback(const std_msgs::msg::String::SharedPtr msg) const
    {
      RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg->data.c_str());
    }

    void target_obj_cb(const geometry_msgs::msg::Pose::SharedPtr msg) {
        target_pose = *msg;
    }

    void preferred_dir_cb(const std_msgs::msg::Int8::SharedPtr msg) {
        if(msg->data >= 0 && msg->data < UNDEFINED) {
            gd = (GraspingDirection) msg->data;
            RCLCPP_INFO(this->get_logger(), "Direction set to type %d", (int) gd);
        }
    }

    void plan_arm_cb(const std::shared_ptr<std_srvs::srv::Trigger::Request> req, std::shared_ptr<std_srvs::srv::Trigger::Response> res) {
        // https://www.andre-gaschler.com/rotationconverter/
        tf2::Quaternion q_obj, q_rot, q_ee;
        tf2::fromMsg(target_pose.orientation, q_obj);
        switch(gd)
        {
            case UP:
            {
                q_rot = tf2::Quaternion(-0.7071068, 0.7071068, 0, 0);
                q_ee = q_rot * q_obj;
                break;
            }

            case FRONT:
            {
                q_rot = tf2::Quaternion(-0.5, -0.5, 0.5, 0.5);
                q_ee = q_rot * q_obj;
                break;
            }
                    
            case UP_FIXED:
            default:
            {
                q_ee.setX(-0.7071068);
                q_ee.setY(0.7071068);
                q_ee.setZ(0);
                q_ee.setW(0);
                break;
            }
        }
        ;
        target_pose.orientation = tf2::toMsg(q_ee);
        arm_move_group_interface->setPoseTarget(target_pose);
        RCLCPP_INFO(this->get_logger(), "Planning... to (x,y,z | x,y,z,w) %f, %f, %f | %f, %f, %f, %f", 
                target_pose.position.x,
                target_pose.position.y,
                target_pose.position.z,
                q_ee.getX(),
                q_ee.getY(),
                q_ee.getZ(),
                q_ee.getW());
        if(arm_move_group_interface->plan(arm_plan) == moveit::core::MoveItErrorCode::SUCCESS) {
            res->success = true;
            res->message = "Planning type " + std::to_string((int) gd) + " successful.";
            RCLCPP_INFO_STREAM(this->get_logger(), "Planning type " + std::to_string((int) gd) + " successful.");
        } else {
            res->success = false;
            res->message = "Planning type " + std::to_string((int) gd) + " failed.";
            RCLCPP_ERROR_STREAM(this->get_logger(), "Planning type " + std::to_string((int) gd) + " failed.");
        }
    }

    void execute_arm_cb(const std::shared_ptr<std_srvs::srv::Trigger::Request> req, std::shared_ptr<std_srvs::srv::Trigger::Response> res) {
        RCLCPP_INFO(this->get_logger(), "Executing...");
        if(arm_move_group_interface->execute(arm_plan) == moveit::core::MoveItErrorCode::SUCCESS) {
            res->success = true;
            res->message = "Executing type " + std::to_string((int) gd) + " successful.";
            RCLCPP_INFO_STREAM(this->get_logger(), "Executing type " + std::to_string((int) gd) + " successful.");
        } else {
            res->success = false;
            res->message = "Executing type " + std::to_string((int) gd) + " failed.";
            RCLCPP_ERROR_STREAM(this->get_logger(), "Executing type " + std::to_string((int) gd) + " failed.");
        }
    }

    void open_gripper_cb(const std::shared_ptr<std_srvs::srv::Trigger::Request> req, std::shared_ptr<std_srvs::srv::Trigger::Response> res) {
        gripper_move_group_interface->setJointValueTarget(gripper_move_group_interface->getNamedTargetValues("open"));
        if(gripper_move_group_interface->move() == moveit::core::MoveItErrorCode::SUCCESS) {
            res->success = true;
            res->message = "Gripper open successful.";
            RCLCPP_INFO_STREAM(this->get_logger(), "Gripper open successful.");
        } else {
            res->success = false;
            res->message = "Gripper open failed.";
            RCLCPP_ERROR_STREAM(this->get_logger(), "Gripper open failed.");
        }
    }

    void close_gripper_cb(const std::shared_ptr<std_srvs::srv::Trigger::Request> req, std::shared_ptr<std_srvs::srv::Trigger::Response> res) {
        gripper_move_group_interface->setJointValueTarget(gripper_move_group_interface->getNamedTargetValues("close"));
        if(gripper_move_group_interface->move() == moveit::core::MoveItErrorCode::SUCCESS) {
            res->success = true;
            res->message = "Gripper close successful.";
            RCLCPP_INFO_STREAM(this->get_logger(), "Gripper close successful.");
        } else {
            res->success = false;
            res->message = "Gripper close failed.";
            RCLCPP_ERROR_STREAM(this->get_logger(), "Gripper close failed.");
        }
    }

    rclcpp::Subscription<geometry_msgs::msg::Pose>::SharedPtr target_object_sub;
    rclcpp::Subscription<std_msgs::msg::Int8>::SharedPtr preferred_dir_sub;
    
    
    rclcpp::Service<std_srvs::srv::Trigger>::SharedPtr service;
    rclcpp::Service<std_srvs::srv::Trigger>::SharedPtr plan_arm_srv;
    rclcpp::Service<std_srvs::srv::Trigger>::SharedPtr execute_arm_srv;
    rclcpp::Service<std_srvs::srv::Trigger>::SharedPtr close_gripper_srv;
    rclcpp::Service<std_srvs::srv::Trigger>::SharedPtr open_gripper_srv;

    std::shared_ptr<rclcpp::Node> this_ptr;
    std::map<std::string, geometry_msgs::msg::Pose> obj_map;
    moveit::planning_interface::MoveGroupInterface *arm_move_group_interface;
    moveit::planning_interface::MoveGroupInterface *gripper_move_group_interface;
    moveit::planning_interface::MoveGroupInterface::Plan arm_plan;
    GraspingDirection gd = UP_FIXED;
    geometry_msgs::msg::Pose target_pose;

};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ManServ>());
  
  rclcpp::shutdown();
  return 0;
}