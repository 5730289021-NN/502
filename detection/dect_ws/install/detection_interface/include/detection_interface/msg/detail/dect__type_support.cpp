// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from detection_interface:msg/Dect.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "detection_interface/msg/detail/dect__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace detection_interface
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void Dect_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) detection_interface::msg::Dect(_init);
}

void Dect_fini_function(void * message_memory)
{
  auto typed_message = static_cast<detection_interface::msg::Dect *>(message_memory);
  typed_message->~Dect();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Dect_message_member_array[2] = {
  {
    "obj_class",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(detection_interface::msg::Dect, obj_class),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "bound_coor",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(detection_interface::msg::Dect, bound_coor),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Dect_message_members = {
  "detection_interface::msg",  // message namespace
  "Dect",  // message name
  2,  // number of fields
  sizeof(detection_interface::msg::Dect),
  Dect_message_member_array,  // message members
  Dect_init_function,  // function to initialize message memory (memory has to be allocated)
  Dect_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Dect_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Dect_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace detection_interface


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<detection_interface::msg::Dect>()
{
  return &::detection_interface::msg::rosidl_typesupport_introspection_cpp::Dect_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, detection_interface, msg, Dect)() {
  return &::detection_interface::msg::rosidl_typesupport_introspection_cpp::Dect_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
