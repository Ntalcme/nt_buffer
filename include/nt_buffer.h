#ifndef NT_BUFFER_H
#define NT_BUFFER_H

typedef nt_buffer nt_buffer;

typedef enum
{
    NT_BUFFER_SUCCESS = 0,
    NT_BUFFER_FAILURE_MALLOC,
    NT_BUFFER_FAILURE_INVALID_ARGUMENT
} nt_buffer_return_code;

#endif
