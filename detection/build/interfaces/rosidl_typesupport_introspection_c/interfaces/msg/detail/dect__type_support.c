// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from interfaces:msg/Dect.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "interfaces/msg/detail/dect__rosidl_typesupport_introspection_c.h"
#include "interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "interfaces/msg/detail/dect__functions.h"
#include "interfaces/msg/detail/dect__struct.h"


// Include directives for member types
// Member `obj_class`
#include "std_msgs/msg/string.h"
// Member `obj_class`
#include "std_msgs/msg/detail/string__rosidl_typesupport_introspection_c.h"
// Member `obj_point`
// Member `goal_point`
// Member `rotation`
#include "std_msgs/msg/float32_multi_array.h"
// Member `obj_point`
// Member `goal_point`
// Member `rotation`
#include "std_msgs/msg/detail/float32_multi_array__rosidl_typesupport_introspection_c.h"

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
  interfaces__msg__Dect__init(message_memory);
}

void Dect__rosidl_typesupport_introspection_c__Dect_fini_function(void * message_memory)
{
  interfaces__msg__Dect__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember Dect__rosidl_typesupport_introspection_c__Dect_message_member_array[4] = {
  {
    "obj_class",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(interfaces__msg__Dect, obj_class),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "obj_point",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(interfaces__msg__Dect, obj_point),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "goal_point",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(interfaces__msg__Dect, goal_point),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "rotation",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(interfaces__msg__Dect, rotation),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers Dect__rosidl_typesupport_introspection_c__Dect_message_members = {
  "interfaces__msg",  // message namespace
  "Dect",  // message name
  4,  // number of fields
  sizeof(interfaces__msg__Dect),
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

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, interfaces, msg, Dect)() {
  Dect__rosidl_typesupport_introspection_c__Dect_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, String)();
  Dect__rosidl_typesupport_introspection_c__Dect_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Float32MultiArray)();
  Dect__rosidl_typesupport_introspection_c__Dect_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Float32MultiArray)();
  Dect__rosidl_typesupport_introspection_c__Dect_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Float32MultiArray)();
  if (!Dect__rosidl_typesupport_introspection_c__Dect_message_type_support_handle.typesupport_identifier) {
    Dect__rosidl_typesupport_introspection_c__Dect_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &Dect__rosidl_typesupport_introspection_c__Dect_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
