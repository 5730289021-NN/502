// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from detection_interface:msg/Dect.idl
// generated code does not contain a copyright notice
#include "detection_interface/msg/detail/dect__rosidl_typesupport_fastrtps_cpp.hpp"
#include "detection_interface/msg/detail/dect__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace detection_interface
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_detection_interface
cdr_serialize(
  const detection_interface::msg::Dect & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: obj_class
  cdr << ros_message.obj_class;
  // Member: bound_coor
  cdr << ros_message.bound_coor;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_detection_interface
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  detection_interface::msg::Dect & ros_message)
{
  // Member: obj_class
  cdr >> ros_message.obj_class;

  // Member: bound_coor
  cdr >> ros_message.bound_coor;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_detection_interface
get_serialized_size(
  const detection_interface::msg::Dect & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: obj_class
  {
    size_t item_size = sizeof(ros_message.obj_class);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: bound_coor
  {
    size_t item_size = sizeof(ros_message.bound_coor);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_detection_interface
max_serialized_size_Dect(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: obj_class
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: bound_coor
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static bool _Dect__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const detection_interface::msg::Dect *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Dect__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<detection_interface::msg::Dect *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Dect__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const detection_interface::msg::Dect *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Dect__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_Dect(full_bounded, 0);
}

static message_type_support_callbacks_t _Dect__callbacks = {
  "detection_interface::msg",
  "Dect",
  _Dect__cdr_serialize,
  _Dect__cdr_deserialize,
  _Dect__get_serialized_size,
  _Dect__max_serialized_size
};

static rosidl_message_type_support_t _Dect__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Dect__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace detection_interface

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_detection_interface
const rosidl_message_type_support_t *
get_message_type_support_handle<detection_interface::msg::Dect>()
{
  return &detection_interface::msg::typesupport_fastrtps_cpp::_Dect__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, detection_interface, msg, Dect)() {
  return &detection_interface::msg::typesupport_fastrtps_cpp::_Dect__handle;
}

#ifdef __cplusplus
}
#endif
