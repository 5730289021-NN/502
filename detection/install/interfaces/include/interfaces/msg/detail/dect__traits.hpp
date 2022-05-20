// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from interfaces:msg/Dect.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__DECT__TRAITS_HPP_
#define INTERFACES__MSG__DETAIL__DECT__TRAITS_HPP_

#include "interfaces/msg/detail/dect__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'obj_class'
#include "std_msgs/msg/detail/string__traits.hpp"
// Member 'obj_point'
// Member 'goal_point'
// Member 'rotation'
#include "std_msgs/msg/detail/float32_multi_array__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<interfaces::msg::Dect>()
{
  return "interfaces::msg::Dect";
}

template<>
inline const char * name<interfaces::msg::Dect>()
{
  return "interfaces/msg/Dect";
}

template<>
struct has_fixed_size<interfaces::msg::Dect>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Float32MultiArray>::value && has_fixed_size<std_msgs::msg::String>::value> {};

template<>
struct has_bounded_size<interfaces::msg::Dect>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Float32MultiArray>::value && has_bounded_size<std_msgs::msg::String>::value> {};

template<>
struct is_message<interfaces::msg::Dect>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // INTERFACES__MSG__DETAIL__DECT__TRAITS_HPP_
