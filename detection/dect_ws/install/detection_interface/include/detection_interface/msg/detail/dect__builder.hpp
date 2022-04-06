// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from detection_interface:msg/Dect.idl
// generated code does not contain a copyright notice

#ifndef DETECTION_INTERFACE__MSG__DETAIL__DECT__BUILDER_HPP_
#define DETECTION_INTERFACE__MSG__DETAIL__DECT__BUILDER_HPP_

#include "detection_interface/msg/detail/dect__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace detection_interface
{

namespace msg
{

namespace builder
{

class Init_Dect_bound_coor
{
public:
  explicit Init_Dect_bound_coor(::detection_interface::msg::Dect & msg)
  : msg_(msg)
  {}
  ::detection_interface::msg::Dect bound_coor(::detection_interface::msg::Dect::_bound_coor_type arg)
  {
    msg_.bound_coor = std::move(arg);
    return std::move(msg_);
  }

private:
  ::detection_interface::msg::Dect msg_;
};

class Init_Dect_obj_class
{
public:
  Init_Dect_obj_class()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Dect_bound_coor obj_class(::detection_interface::msg::Dect::_obj_class_type arg)
  {
    msg_.obj_class = std::move(arg);
    return Init_Dect_bound_coor(msg_);
  }

private:
  ::detection_interface::msg::Dect msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::detection_interface::msg::Dect>()
{
  return detection_interface::msg::builder::Init_Dect_obj_class();
}

}  // namespace detection_interface

#endif  // DETECTION_INTERFACE__MSG__DETAIL__DECT__BUILDER_HPP_
