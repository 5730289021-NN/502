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

class Init_Dect_cam_z
{
public:
  explicit Init_Dect_cam_z(::interfaces::msg::Dect & msg)
  : msg_(msg)
  {}
  ::interfaces::msg::Dect cam_z(::interfaces::msg::Dect::_cam_z_type arg)
  {
    msg_.cam_z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::msg::Dect msg_;
};

class Init_Dect_cam_y
{
public:
  explicit Init_Dect_cam_y(::interfaces::msg::Dect & msg)
  : msg_(msg)
  {}
  Init_Dect_cam_z cam_y(::interfaces::msg::Dect::_cam_y_type arg)
  {
    msg_.cam_y = std::move(arg);
    return Init_Dect_cam_z(msg_);
  }

private:
  ::interfaces::msg::Dect msg_;
};

class Init_Dect_cam_x
{
public:
  explicit Init_Dect_cam_x(::interfaces::msg::Dect & msg)
  : msg_(msg)
  {}
  Init_Dect_cam_y cam_x(::interfaces::msg::Dect::_cam_x_type arg)
  {
    msg_.cam_x = std::move(arg);
    return Init_Dect_cam_y(msg_);
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
  Init_Dect_cam_x obj_class(::interfaces::msg::Dect::_obj_class_type arg)
  {
    msg_.obj_class = std::move(arg);
    return Init_Dect_cam_x(msg_);
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
