#ifndef NT_BUFFER_H
#define NT_BUFFER_H

#include <stddef.h>

typedef struct nt_buffer nt_buffer;

typedef enum
{
    NT_BUFFER_SUCCESS = 0,
    NT_BUFFER_FAILURE_MALLOC,
    NT_BUFFER_FAILURE_INVALID_ARGUMENT
} nt_buffer_return_code;

nt_buffer            *nt_buffer_new(size_t capacity, size_t element_size, void (*destructor)(void *));
nt_buffer_return_code nt_buffer_add(nt_buffer *buf, const void *elt);
void                  nt_buffer_remove(nt_buffer *buf, size_t i);
void                  nt_buffer_clear(nt_buffer *buf);

size_t nt_buffer_get_count(const nt_buffer *buf);
size_t nt_buffer_get_element_size(const nt_buffer *buf);
size_t nt_buffer_get_capacity(const nt_buffer *buf);

#endif
