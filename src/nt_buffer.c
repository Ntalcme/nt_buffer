#include "nt_buffer.h"
#include <stddef.h>

struct nt_buffer
{
    void  *data;
    size_t element_count;
    size_t capacity;
    size_t element_size;
    void (*destructor)(void *);
};

nt_buffer *nt_buffer_new(size_t capacity, size_t element_size, void (*destructor)(void *))
{
    nt_buffer *res = malloc(sizeof(nt_buffer));

    if (!res)
        return (NULL);

    if (nt_buffer_init(res, capacity, element_size, destructor) != NT_BUFFER_SUCCESS)
    {
        free(res);
        return (NULL);
    }

    return (res);
}
static nt_buffer_return_code
nt_buffer_init(nt_buffer *buf, size_t capacity, size_t element_size, void (*destructor)(void *))
{
    if (!buf || element_size == 0)
        return (NT_BUFFER_FAILURE_INVALID_ARGUMENT);

    buf->data = NULL;

    if (capacity > 0)
    {
        buf->data = malloc(capacity * element_size);
        if (!buf->data)
            return (NT_BUFFER_FAILURE_MALLOC);
    }

    buf->capacity = capacity;
    buf->element_count = 0;
    buf->element_size = element_size;
    buf->destructor = destructor;

    return (NT_BUFFER_SUCCESS);
}