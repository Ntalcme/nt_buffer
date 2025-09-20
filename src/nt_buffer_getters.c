#include "nt_buffer_internal.h"

/**
 * Retrieves a pointer to the element at the specified index in the buffer.
 *
 * @param buf Pointer to the nt_buffer.
 * @param i Index of the element to retrieve.
 * @return A const pointer to the element at the specified index,
 *         or NULL if the buffer is invalid or the index is out of bounds.
 *
 * @note The returned pointer should be cast to the appropriate element type.
 *       The element must not be modified through this pointer.
 */
const void *nt_buffer_get_element(const nt_buffer *buf, size_t i)
{
    if (!buf || !buf->data || i >= buf->element_count)
        return (NULL);

    return (void *)((unsigned char *)buf->data + (i * buf->element_size));
}

/**
 * Retrieves a pointer to the internal data array.
 *
 * @param buf Pointer to the nt_buffer.
 * @return A const void pointer to the internal data array,
 *         or NULL if the buffer is invalid.
 *
 * @note The returned pointer should be cast to the appropriate element type.
 *       The caller must not modify the data through this pointer.
 */
const void *nt_buffer_get_data(const nt_buffer *buf)
{
    if (!buf)
        return (NULL);
    return (buf->data);
}

/**
 * Gets the number of elements currently stored in the buffer.
 *
 * @param buf Pointer to the nt_buffer.
 * @return The number of elements, or 0 if the buffer is NULL.
 */
size_t nt_buffer_get_count(const nt_buffer *buf)
{
    if (!buf)
        return (0);
    return (buf->element_count);
}

/**
 * Gets the size in bytes of each element stored in the buffer.
 *
 * @param buf Pointer to the nt_buffer.
 * @return The element size in bytes, or 0 if the buffer is NULL.
 */
size_t nt_buffer_get_element_size(const nt_buffer *buf)
{
    if (!buf)
        return (0);
    return (buf->element_size);
}

/**
 * Gets the total capacity of the buffer (i.e how many elements can be stored without reallocating).
 *
 * @param buf Pointer to the nt_buffer.
 * @return The buffer's capacity, or 0 if the buffer is NULL.
 */
size_t nt_buffer_get_capacity(const nt_buffer *buf)
{
    if (!buf)
        return (0);
    return (buf->capacity);
}