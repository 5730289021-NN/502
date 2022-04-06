// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from detection_interfaces:msg/Dectt.idl
// generated code does not contain a copyright notice

#ifndef DETECTION_INTERFACES__MSG__DETAIL__DECTT__TRAITS_HPP_
#define DETECTION_INTERFACES__MSG__DETAIL__DECTT__TRAITS_HPP_

#include "detection_interfaces/msg/detail/dectt__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<detection_interfaces::msg::Dectt>()
{
  return "detection_interfaces::msg::Dectt";
}

template<>
inline const char * name<detection_interfaces::msg::Dectt>()
{
  return "detection_interfaces/msg/Dectt";
}

template<>
struct has_fixed_size<detection_interfaces::msg::Dectt>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<detection_interfaces::msg::Dectt>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<detection_interfaces::msg::Dectt>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // DETECTION_INTERFACES__MSG__DETAIL__DECTT__TRAITS_HPP_
