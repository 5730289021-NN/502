// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from detection_interfaces:msg/Dect.idl
// generated code does not contain a copyright notice

#ifndef DETECTION_INTERFACES__MSG__DETAIL__DECT__BUILDER_HPP_
#define DETECTION_INTERFACES__MSG__DETAIL__DECT__BUILDER_HPP_

#include "detection_interfaces/msg/detail/dect__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace detection_interfaces
{

namespace msg
{

namespace builder
{

class Init_Dect_bounding_d
{
public:
  explicit Init_Dect_bounding_d(::detection_interfaces::msg::Dect & msg)
  : msg_(msg)
  {}
  ::detection_interfaces::msg::Dect bounding_d(::detection_interfaces::msg::Dect::_bounding_d_type arg)
  {
    msg_.bounding_d = std::move(arg);
    return std::move(msg_);
  }

private:
  ::detection_interfaces::msg::Dect msg_;
};

class Init_Dect_bounding_h
{
public:
  explicit Init_Dect_bounding_h(::detection_interfaces::msg::Dect & msg)
  : msg_(msg)
  {}
  Init_Dect_bounding_d bounding_h(::detection_interfaces::msg::Dect::_bounding_h_type arg)
  {
    msg_.bounding_h = std::move(arg);
    return Init_Dect_bounding_d(msg_);
  }

private:
  ::detection_interfaces::msg::Dect msg_;
};

class Init_Dect_bounding_w
{
public:
  explicit Init_Dect_bounding_w(::detection_interfaces::msg::Dect & msg)
  : msg_(msg)
  {}
  Init_Dect_bounding_h bounding_w(::detection_interfaces::msg::Dect::_bounding_w_type arg)
  {
    msg_.bounding_w = std::move(arg);
    return Init_Dect_bounding_h(msg_);
  }

private:
  ::detection_interfaces::msg::Dect msg_;
};

class Init_Dect_bounding_y
{
public:
  explicit Init_Dect_bounding_y(::detection_interfaces::msg::Dect & msg)
  : msg_(msg)
  {}
  Init_Dect_bounding_w bounding_y(::detection_interfaces::msg::Dect::_bounding_y_type arg)
  {
    msg_.bounding_y = std::move(arg);
    return Init_Dect_bounding_w(msg_);
  }

private:
  ::detection_interfaces::msg::Dect msg_;
};

class Init_Dect_bounding_x
{
public:
  explicit Init_Dect_bounding_x(::detection_interfaces::msg::Dect & msg)
  : msg_(msg)
  {}
  Init_Dect_bounding_y bounding_x(::detection_interfaces::msg::Dect::_bounding_x_type arg)
  {
    msg_.bounding_x = std::move(arg);
    return Init_Dect_bounding_y(msg_);
  }

private:
  ::detection_interfaces::msg::Dect msg_;
};

class Init_Dect_obj_class
{
public:
  Init_Dect_obj_class()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Dect_bounding_x obj_class(::detection_interfaces::msg::Dect::_obj_class_type arg)
  {
    msg_.obj_class = std::move(arg);
    return Init_Dect_bounding_x(msg_);
  }

private:
  ::detection_interfaces::msg::Dect msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::detection_interfaces::msg::Dect>()
{
  return detection_interfaces::msg::builder::Init_Dect_obj_class();
}

}  // namespace detection_interfaces

#endif  // DETECTION_INTERFACES__MSG__DETAIL__DECT__BUILDER_HPP_
