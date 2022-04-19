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

class Init_Dect_y2
{
public:
  explicit Init_Dect_y2(::interfaces::msg::Dect & msg)
  : msg_(msg)
  {}
  ::interfaces::msg::Dect y2(::interfaces::msg::Dect::_y2_type arg)
  {
    msg_.y2 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::msg::Dect msg_;
};

class Init_Dect_x2
{
public:
  explicit Init_Dect_x2(::interfaces::msg::Dect & msg)
  : msg_(msg)
  {}
  Init_Dect_y2 x2(::interfaces::msg::Dect::_x2_type arg)
  {
    msg_.x2 = std::move(arg);
    return Init_Dect_y2(msg_);
  }

private:
  ::interfaces::msg::Dect msg_;
};

class Init_Dect_y1
{
public:
  explicit Init_Dect_y1(::interfaces::msg::Dect & msg)
  : msg_(msg)
  {}
  Init_Dect_x2 y1(::interfaces::msg::Dect::_y1_type arg)
  {
    msg_.y1 = std::move(arg);
    return Init_Dect_x2(msg_);
  }

private:
  ::interfaces::msg::Dect msg_;
};

class Init_Dect_x1
{
public:
  explicit Init_Dect_x1(::interfaces::msg::Dect & msg)
  : msg_(msg)
  {}
  Init_Dect_y1 x1(::interfaces::msg::Dect::_x1_type arg)
  {
    msg_.x1 = std::move(arg);
    return Init_Dect_y1(msg_);
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
  Init_Dect_x1 obj_class(::interfaces::msg::Dect::_obj_class_type arg)
  {
    msg_.obj_class = std::move(arg);
    return Init_Dect_x1(msg_);
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
