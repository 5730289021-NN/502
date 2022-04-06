// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from detection_interfaces:msg/Dect.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "detection_interfaces/msg/detail/dect__rosidl_typesupport_introspection_c.h"
#include "detection_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "detection_interfaces/msg/detail/dect__functions.h"
#include "detection_interfaces/msg/detail/dect__struct.h"


// Include directives for member types
// Member `obj_class`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void Dect__rosidl_typesupport_introspection_c__Dect_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  detection_interfaces__msg__Dect__init(message_memory);
}

void Dect__rosidl_typesupport_introspection_c__Dect_fini_function(void * message_memory)
{
  detection_interfaces__msg__Dect__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember Dect__rosidl_typesupport_introspection_c__Dect_message_member_array[6] = {
  {
    "obj_class",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(detection_interfaces__msg__Dect, obj_class),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "bounding_x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(detection_interfaces__msg__Dect, bounding_x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "bounding_y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(detection_interfaces__msg__Dect, bounding_y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "bounding_w",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(detection_interfaces__msg__Dect, bounding_w),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "bounding_h",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(detection_interfaces__msg__Dect, bounding_h),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "bounding_d",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(detection_interfaces__msg__Dect, bounding_d),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers Dect__rosidl_typesupport_introspection_c__Dect_message_members = {
  "detection_interfaces__msg",  // message namespace
  "Dect",  // message name
  6,  // number of fields
  sizeof(detection_interfaces__msg__Dect),
  Dect__rosidl_typesupport_introspection_c__Dect_message_member_array,  // message members
  Dect__rosidl_typesupport_introspection_c__Dect_init_function,  // function to initialize message memory (memory has to be allocated)
  Dect__rosidl_typesupport_introspection_c__Dect_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t Dect__rosidl_typesupport_introspection_c__Dect_message_type_support_handle = {
  0,
  &Dect__rosidl_typesupport_introspection_c__Dect_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_detection_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, detection_interfaces, msg, Dect)() {
  if (!Dect__rosidl_typesupport_introspection_c__Dect_message_type_support_handle.typesupport_identifier) {
    Dect__rosidl_typesupport_introspection_c__Dect_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &Dect__rosidl_typesupport_introspection_c__Dect_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
