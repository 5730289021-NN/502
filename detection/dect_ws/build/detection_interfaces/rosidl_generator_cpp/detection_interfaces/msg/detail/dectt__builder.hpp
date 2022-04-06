// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from detection_interfaces:msg/Dectt.idl
// generated code does not contain a copyright notice

#ifndef DETECTION_INTERFACES__MSG__DETAIL__DECTT__BUILDER_HPP_
#define DETECTION_INTERFACES__MSG__DETAIL__DECTT__BUILDER_HPP_

#include "detection_interfaces/msg/detail/dectt__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace detection_interfaces
{

namespace msg
{

namespace builder
{

class Init_Dectt_bound_coor
{
public:
  explicit Init_Dectt_bound_coor(::detection_interfaces::msg::Dectt & msg)
  : msg_(msg)
  {}
  ::detection_interfaces::msg::Dectt bound_coor(::detection_interfaces::msg::Dectt::_bound_coor_type arg)
  {
    msg_.bound_coor = std::move(arg);
    return std::move(msg_);
  }

private:
  ::detection_interfaces::msg::Dectt msg_;
};

class Init_Dectt_obj_class
{
public:
  Init_Dectt_obj_class()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Dectt_bound_coor obj_class(::detection_interfaces::msg::Dectt::_obj_class_type arg)
  {
    msg_.obj_class = std::move(arg);
    return Init_Dectt_bound_coor(msg_);
  }

private:
  ::detection_interfaces::msg::Dectt msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::detection_interfaces::msg::Dectt>()
{
  return detection_interfaces::msg::builder::Init_Dectt_obj_class();
}

}  // namespace detection_interfaces

#endif  // DETECTION_INTERFACES__MSG__DETAIL__DECTT__BUILDER_HPP_
