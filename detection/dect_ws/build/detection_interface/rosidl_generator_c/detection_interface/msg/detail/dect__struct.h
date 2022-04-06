// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from detection_interface:msg/Dect.idl
// generated code does not contain a copyright notice

#ifndef DETECTION_INTERFACE__MSG__DETAIL__DECT__STRUCT_H_
#define DETECTION_INTERFACE__MSG__DETAIL__DECT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/Dect in the package detection_interface.
typedef struct detection_interface__msg__Dect
{
  uint8_t obj_class;
  double bound_coor;
} detection_interface__msg__Dect;

// Struct for a sequence of detection_interface__msg__Dect.
typedef struct detection_interface__msg__Dect__Sequence
{
  detection_interface__msg__Dect * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} detection_interface__msg__Dect__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DETECTION_INTERFACE__MSG__DETAIL__DECT__STRUCT_H_
