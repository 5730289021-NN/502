// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:msg/Dect2.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__DECT2__BUILDER_HPP_
#define INTERFACES__MSG__DETAIL__DECT2__BUILDER_HPP_

#include "interfaces/msg/detail/dect2__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace interfaces
{

namespace msg
{

namespace builder
{

class Init_Dect2_cam_z
{
public:
  explicit Init_Dect2_cam_z(::interfaces::msg::Dect2 & msg)
  : msg_(msg)
  {}
  ::interfaces::msg::Dect2 cam_z(::interfaces::msg::Dect2::_cam_z_type arg)
  {
    msg_.cam_z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::msg::Dect2 msg_;
};

class Init_Dect2_cam_y
{
public:
  explicit Init_Dect2_cam_y(::interfaces::msg::Dect2 & msg)
  : msg_(msg)
  {}
  Init_Dect2_cam_z cam_y(::interfaces::msg::Dect2::_cam_y_type arg)
  {
    msg_.cam_y = std::move(arg);
    return Init_Dect2_cam_z(msg_);
  }

private:
  ::interfaces::msg::Dect2 msg_;
};

class Init_Dect2_cam_x
{
public:
  Init_Dect2_cam_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Dect2_cam_y cam_x(::interfaces::msg::Dect2::_cam_x_type arg)
  {
    msg_.cam_x = std::move(arg);
    return Init_Dect2_cam_y(msg_);
  }

private:
  ::interfaces::msg::Dect2 msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::msg::Dect2>()
{
  return interfaces::msg::builder::Init_Dect2_cam_x();
}

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__DECT2__BUILDER_HPP_
