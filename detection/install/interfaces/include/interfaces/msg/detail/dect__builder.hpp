// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:msg/Dect.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__DECT__BUILDER_HPP_
#define INTERFACES__MSG__DETAIL__DECT__BUILDER_HPP_

#include "interfaces/msg/detail/dect__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace interfaces
{

namespace msg
{

namespace builder
{

class Init_Dect_rotation
{
public:
  explicit Init_Dect_rotation(::interfaces::msg::Dect & msg)
  : msg_(msg)
  {}
  ::interfaces::msg::Dect rotation(::interfaces::msg::Dect::_rotation_type arg)
  {
    msg_.rotation = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::msg::Dect msg_;
};

class Init_Dect_goal_point
{
public:
  explicit Init_Dect_goal_point(::interfaces::msg::Dect & msg)
  : msg_(msg)
  {}
  Init_Dect_rotation goal_point(::interfaces::msg::Dect::_goal_point_type arg)
  {
    msg_.goal_point = std::move(arg);
    return Init_Dect_rotation(msg_);
  }

private:
  ::interfaces::msg::Dect msg_;
};

class Init_Dect_obj_point
{
public:
  explicit Init_Dect_obj_point(::interfaces::msg::Dect & msg)
  : msg_(msg)
  {}
  Init_Dect_goal_point obj_point(::interfaces::msg::Dect::_obj_point_type arg)
  {
    msg_.obj_point = std::move(arg);
    return Init_Dect_goal_point(msg_);
  }

private:
  ::interfaces::msg::Dect msg_;
};

class Init_Dect_obj_class
{
public:
  Init_Dect_obj_class()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Dect_obj_point obj_class(::interfaces::msg::Dect::_obj_class_type arg)
  {
    msg_.obj_class = std::move(arg);
    return Init_Dect_obj_point(msg_);
  }

private:
  ::interfaces::msg::Dect msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::msg::Dect>()
{
  return interfaces::msg::builder::Init_Dect_obj_class();
}

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__DECT__BUILDER_HPP_
