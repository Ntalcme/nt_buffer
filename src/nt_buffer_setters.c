#include "nt_buffer.h"
#include <stddef.h>

/**
 * Ensures the buffer has at least new_capacity.
 * If the current capacity is less, reallocates memory accordingly.
 *
 * @param buf Pointer to the nt_buffer.
 * @param new_capacity The minimum capacity to reserve.
 * @return NT_BUFFER_SUCCESS on success,
 *         NT_BUFFER_FAILURE_INVALID_ARGUMENT if buf is NULL,
 *         NT_BUFFER_FAILURE_MALLOC if memory allocation fails.
 */
nt_buffer_return_code nt_buffer_reserve(nt_buffer *buf, size_t new_capacity)
{
    void *new_data;

    if (!buf)
        return (NT_BUFFER_FAILURE_INVALID_ARGUMENT);

    if (new_capacity <= buf->capacity)
        return (NT_BUFFER_SUCCESS);

    new_data = realloc(buf->data, new_capacity * buf->element_size);
    if (!new_data)
        return (NT_BUFFER_FAILURE_MALLOC);

    buf->data = new_data;
    buf->capacity = new_capacity;

    return (NT_BUFFER_SUCCESS);
}