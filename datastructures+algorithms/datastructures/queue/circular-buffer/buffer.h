#ifndef _CIRCULAR_BUFFER_H_
#define _CIRCULAR_BUFFER_H_

#include <stdbool.h>
#include <stdlib.h>

typedef struct 
{
    int *data;
    int head;
    int tail;
    size_t count;
    size_t size;
} circular_buffer_t;

extern circular_buffer_t *buffer_new(size_t size);
extern void buffer_delete(circular_buffer_t *cb);
extern bool buffer_is_empty(circular_buffer_t* cb);
extern bool buffer_is_full(circular_buffer_t* cb);
extern void buffer_enqueue(circular_buffer_t* cb, int data); 
extern int buffer_dequeue(circular_buffer_t* cb); 

#endif