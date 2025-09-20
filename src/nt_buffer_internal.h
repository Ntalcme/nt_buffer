#ifndef NT_BUFFER_INTERNAL_H
#define NT_BUFFER_INTERNAL_H

#include "nt_buffer.h"
#include <stddef.h>

// Définition complète de la structure
struct nt_buffer
{
    void  *data;
    size_t element_count;
    size_t capacity;
    size_t element_size;
    void (*destructor)(void *);
};

#endif  // NT_BUFFER_INTERNAL_H
