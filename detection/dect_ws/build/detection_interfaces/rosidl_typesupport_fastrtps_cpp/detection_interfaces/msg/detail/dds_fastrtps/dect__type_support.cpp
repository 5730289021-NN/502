// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from detection_interfaces:msg/Dect.idl
// generated code does not contain a copyright notice
#include "detection_interfaces/msg/detail/dect__rosidl_typesupport_fastrtps_cpp.hpp"
#include "detection_interfaces/msg/detail/dect__struct.hpp"

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

namespace detection_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_detection_interfaces
cdr_serialize(
  const detection_interfaces::msg::Dect & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: obj_class
  cdr << ros_message.obj_class;
  // Member: bounding_x
  cdr << ros_message.bounding_x;
  // Member: bounding_y
  cdr << ros_message.bounding_y;
  // Member: bounding_w
  cdr << ros_message.bounding_w;
  // Member: bounding_h
  cdr << ros_message.bounding_h;
  // Member: bounding_d
  cdr << ros_message.bounding_d;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_detection_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  detection_interfaces::msg::Dect & ros_message)
{
  // Member: obj_class
  cdr >> ros_message.obj_class;

  // Member: bounding_x
  cdr >> ros_message.bounding_x;

  // Member: bounding_y
  cdr >> ros_message.bounding_y;

  // Member: bounding_w
  cdr >> ros_message.bounding_w;

  // Member: bounding_h
  cdr >> ros_message.bounding_h;

  // Member: bounding_d
  cdr >> ros_message.bounding_d;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_detection_interfaces
get_serialized_size(
  const detection_interfaces::msg::Dect & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: obj_class
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.obj_class.size() + 1);
  // Member: bounding_x
  {
    size_t item_size = sizeof(ros_message.bounding_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: bounding_y
  {
    size_t item_size = sizeof(ros_message.bounding_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: bounding_w
  {
    size_t item_size = sizeof(ros_message.bounding_w);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: bounding_h
  {
    size_t item_size = sizeof(ros_message.bounding_h);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: bounding_d
  {
    size_t item_size = sizeof(ros_message.bounding_d);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_detection_interfaces
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

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: bounding_x
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: bounding_y
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: bounding_w
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: bounding_h
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: bounding_d
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
    static_cast<const detection_interfaces::msg::Dect *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Dect__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<detection_interfaces::msg::Dect *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Dect__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const detection_interfaces::msg::Dect *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Dect__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_Dect(full_bounded, 0);
}

static message_type_support_callbacks_t _Dect__callbacks = {
  "detection_interfaces::msg",
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

}  // namespace detection_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_detection_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<detection_interfaces::msg::Dect>()
{
  return &detection_interfaces::msg::typesupport_fastrtps_cpp::_Dect__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, detection_interfaces, msg, Dect)() {
  return &detection_interfaces::msg::typesupport_fastrtps_cpp::_Dect__handle;
}

#ifdef __cplusplus
}
#endif
