// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from detection_interfaces:msg/Dectt.idl
// generated code does not contain a copyright notice

#ifndef DETECTION_INTERFACES__MSG__DETAIL__DECTT__STRUCT_H_
#define DETECTION_INTERFACES__MSG__DETAIL__DECTT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/Dectt in the package detection_interfaces.
typedef struct detection_interfaces__msg__Dectt
{
  uint8_t obj_class;
  double bound_coor;
} detection_interfaces__msg__Dectt;

// Struct for a sequence of detection_interfaces__msg__Dectt.
typedef struct detection_interfaces__msg__Dectt__Sequence
{
  detection_interfaces__msg__Dectt * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} detection_interfaces__msg__Dectt__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DETECTION_INTERFACES__MSG__DETAIL__DECTT__STRUCT_H_
