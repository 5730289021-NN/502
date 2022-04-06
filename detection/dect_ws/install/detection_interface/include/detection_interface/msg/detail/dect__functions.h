// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from detection_interface:msg/Dect.idl
// generated code does not contain a copyright notice

#ifndef DETECTION_INTERFACE__MSG__DETAIL__DECT__FUNCTIONS_H_
#define DETECTION_INTERFACE__MSG__DETAIL__DECT__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "detection_interface/msg/rosidl_generator_c__visibility_control.h"

#include "detection_interface/msg/detail/dect__struct.h"

/// Initialize msg/Dect message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * detection_interface__msg__Dect
 * )) before or use
 * detection_interface__msg__Dect__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_detection_interface
bool
detection_interface__msg__Dect__init(detection_interface__msg__Dect * msg);

/// Finalize msg/Dect message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_detection_interface
void
detection_interface__msg__Dect__fini(detection_interface__msg__Dect * msg);

/// Create msg/Dect message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * detection_interface__msg__Dect__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_detection_interface
detection_interface__msg__Dect *
detection_interface__msg__Dect__create();

/// Destroy msg/Dect message.
/**
 * It calls
 * detection_interface__msg__Dect__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_detection_interface
void
detection_interface__msg__Dect__destroy(detection_interface__msg__Dect * msg);


/// Initialize array of msg/Dect messages.
/**
 * It allocates the memory for the number of elements and calls
 * detection_interface__msg__Dect__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_detection_interface
bool
detection_interface__msg__Dect__Sequence__init(detection_interface__msg__Dect__Sequence * array, size_t size);

/// Finalize array of msg/Dect messages.
/**
 * It calls
 * detection_interface__msg__Dect__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_detection_interface
void
detection_interface__msg__Dect__Sequence__fini(detection_interface__msg__Dect__Sequence * array);

/// Create array of msg/Dect messages.
/**
 * It allocates the memory for the array and calls
 * detection_interface__msg__Dect__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_detection_interface
detection_interface__msg__Dect__Sequence *
detection_interface__msg__Dect__Sequence__create(size_t size);

/// Destroy array of msg/Dect messages.
/**
 * It calls
 * detection_interface__msg__Dect__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_detection_interface
void
detection_interface__msg__Dect__Sequence__destroy(detection_interface__msg__Dect__Sequence * array);

#ifdef __cplusplus
}
#endif

#endif  // DETECTION_INTERFACE__MSG__DETAIL__DECT__FUNCTIONS_H_
