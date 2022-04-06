// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from detection_interfaces:msg/Dect.idl
// generated code does not contain a copyright notice

#ifndef DETECTION_INTERFACES__MSG__DETAIL__DECT__STRUCT_H_
#define DETECTION_INTERFACES__MSG__DETAIL__DECT__STRUCT_H_

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

// Struct defined in msg/Dect in the package detection_interfaces.
typedef struct detection_interfaces__msg__Dect
{
  rosidl_runtime_c__String obj_class;
  double bounding_x;
  double bounding_y;
  double bounding_w;
  double bounding_h;
  double bounding_d;
} detection_interfaces__msg__Dect;

// Struct for a sequence of detection_interfaces__msg__Dect.
typedef struct detection_interfaces__msg__Dect__Sequence
{
  detection_interfaces__msg__Dect * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} detection_interfaces__msg__Dect__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DETECTION_INTERFACES__MSG__DETAIL__DECT__STRUCT_H_
