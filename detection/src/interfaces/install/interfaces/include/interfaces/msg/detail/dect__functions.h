// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from interfaces:msg/Dect.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__DECT__FUNCTIONS_H_
#define INTERFACES__MSG__DETAIL__DECT__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "interfaces/msg/detail/dect__struct.h"

/// Initialize msg/Dect message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * interfaces__msg__Dect
 * )) before or use
 * interfaces__msg__Dect__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaces
bool
interfaces__msg__Dect__init(interfaces__msg__Dect * msg);

/// Finalize msg/Dect message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaces
void
interfaces__msg__Dect__fini(interfaces__msg__Dect * msg);

/// Create msg/Dect message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * interfaces__msg__Dect__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaces
interfaces__msg__Dect *
interfaces__msg__Dect__create();

/// Destroy msg/Dect message.
/**
 * It calls
 * interfaces__msg__Dect__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaces
void
interfaces__msg__Dect__destroy(interfaces__msg__Dect * msg);


/// Initialize array of msg/Dect messages.
/**
 * It allocates the memory for the number of elements and calls
 * interfaces__msg__Dect__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaces
bool
interfaces__msg__Dect__Sequence__init(interfaces__msg__Dect__Sequence * array, size_t size);

/// Finalize array of msg/Dect messages.
/**
 * It calls
 * interfaces__msg__Dect__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaces
void
interfaces__msg__Dect__Sequence__fini(interfaces__msg__Dect__Sequence * array);

/// Create array of msg/Dect messages.
/**
 * It allocates the memory for the array and calls
 * interfaces__msg__Dect__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaces
interfaces__msg__Dect__Sequence *
interfaces__msg__Dect__Sequence__create(size_t size);

/// Destroy array of msg/Dect messages.
/**
 * It calls
 * interfaces__msg__Dect__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interfaces
void
interfaces__msg__Dect__Sequence__destroy(interfaces__msg__Dect__Sequence * array);

#ifdef __cplusplus
}
#endif

#endif  // INTERFACES__MSG__DETAIL__DECT__FUNCTIONS_H_
