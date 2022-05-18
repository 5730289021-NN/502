// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interfaces:msg/Dect.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__DECT__STRUCT_H_
#define INTERFACES__MSG__DETAIL__DECT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'obj_class'
#include "rosidl_runtime_c/string.h"

// Struct defined in msg/Dect in the package interfaces.
typedef struct interfaces__msg__Dect
{
  rosidl_runtime_c__String obj_class;
  double cam_x;
  double cam_y;
  double robot_x;
  double robot_y;
  double robot_yaw;
} interfaces__msg__Dect;

// Struct for a sequence of interfaces__msg__Dect.
typedef struct interfaces__msg__Dect__Sequence
{
  interfaces__msg__Dect * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaces__msg__Dect__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERFACES__MSG__DETAIL__DECT__STRUCT_H_
