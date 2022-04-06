// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from detection_interfaces:msg/Dectt.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "detection_interfaces/msg/detail/dectt__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace detection_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void Dectt_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) detection_interfaces::msg::Dectt(_init);
}

void Dectt_fini_function(void * message_memory)
{
  auto typed_message = static_cast<detection_interfaces::msg::Dectt *>(message_memory);
  typed_message->~Dectt();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Dectt_message_member_array[2] = {
  {
    "obj_class",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(detection_interfaces::msg::Dectt, obj_class),  // bytes offset in struct
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
    offsetof(detection_interfaces::msg::Dectt, bound_coor),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Dectt_message_members = {
  "detection_interfaces::msg",  // message namespace
  "Dectt",  // message name
  2,  // number of fields
  sizeof(detection_interfaces::msg::Dectt),
  Dectt_message_member_array,  // message members
  Dectt_init_function,  // function to initialize message memory (memory has to be allocated)
  Dectt_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Dectt_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Dectt_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace detection_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<detection_interfaces::msg::Dectt>()
{
  return &::detection_interfaces::msg::rosidl_typesupport_introspection_cpp::Dectt_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, detection_interfaces, msg, Dectt)() {
  return &::detection_interfaces::msg::rosidl_typesupport_introspection_cpp::Dectt_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
