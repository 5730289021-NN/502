// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from detection_interfaces:msg/Dectt.idl
// generated code does not contain a copyright notice

#ifndef DETECTION_INTERFACES__MSG__DETAIL__DECTT__FUNCTIONS_H_
#define DETECTION_INTERFACES__MSG__DETAIL__DECTT__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "detection_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "detection_interfaces/msg/detail/dectt__struct.h"

/// Initialize msg/Dectt message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * detection_interfaces__msg__Dectt
 * )) before or use
 * detection_interfaces__msg__Dectt__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_detection_interfaces
bool
detection_interfaces__msg__Dectt__init(detection_interfaces__msg__Dectt * msg);

/// Finalize msg/Dectt message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_detection_interfaces
void
detection_interfaces__msg__Dectt__fini(detection_interfaces__msg__Dectt * msg);

/// Create msg/Dectt message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * detection_interfaces__msg__Dectt__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_detection_interfaces
detection_interfaces__msg__Dectt *
detection_interfaces__msg__Dectt__create();

/// Destroy msg/Dectt message.
/**
 * It calls
 * detection_interfaces__msg__Dectt__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_detection_interfaces
void
detection_interfaces__msg__Dectt__destroy(detection_interfaces__msg__Dectt * msg);


/// Initialize array of msg/Dectt messages.
/**
 * It allocates the memory for the number of elements and calls
 * detection_interfaces__msg__Dectt__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_detection_interfaces
bool
detection_interfaces__msg__Dectt__Sequence__init(detection_interfaces__msg__Dectt__Sequence * array, size_t size);

/// Finalize array of msg/Dectt messages.
/**
 * It calls
 * detection_interfaces__msg__Dectt__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_detection_interfaces
void
detection_interfaces__msg__Dectt__Sequence__fini(detection_interfaces__msg__Dectt__Sequence * array);

/// Create array of msg/Dectt messages.
/**
 * It allocates the memory for the array and calls
 * detection_interfaces__msg__Dectt__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_detection_interfaces
detection_interfaces__msg__Dectt__Sequence *
detection_interfaces__msg__Dectt__Sequence__create(size_t size);

/// Destroy array of msg/Dectt messages.
/**
 * It calls
 * detection_interfaces__msg__Dectt__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_detection_interfaces
void
detection_interfaces__msg__Dectt__Sequence__destroy(detection_interfaces__msg__Dectt__Sequence * array);

#ifdef __cplusplus
}
#endif

#endif  // DETECTION_INTERFACES__MSG__DETAIL__DECTT__FUNCTIONS_H_
