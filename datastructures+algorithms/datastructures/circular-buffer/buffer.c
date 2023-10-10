#include <stdio.h>

#include "buffer.h"

circular_buffer_t *buffer_new(size_t size) 
{
    circular_buffer_t *buffer = (circular_buffer_t *)malloc(sizeof(circular_buffer_t));
    buffer->data = (int *)calloc(size, sizeof(int)); 
    buffer->head = 0;
    buffer->tail = 0;
    buffer->count = 0;
    buffer->size = size;
    return buffer;
}

void buffer_delete(circular_buffer_t *cb)
{
    free(cb->data);
    free(cb);
}

bool buffer_is_empty(circular_buffer_t* cb) 
{
    return cb->count == 0;
}

bool buffer_is_full(circular_buffer_t* cb) 
{
    return cb->count == cb->size;
}

void buffer_enqueue(circular_buffer_t* cb, int value) 
{
    if(!buffer_is_full(cb)) 
    {
        cb->data[cb->head] = value;
        cb->head = (cb->head + 1) % cb->size;
        cb->count++;
    }

}

int buffer_dequeue(circular_buffer_t* cb) 
{
    if(!buffer_is_empty(cb)) 
    {
        int data = cb->data[cb->tail];
        cb->tail = (cb->tail + 1) % cb->size;
        cb->count--;
        return data;
    }
    else 
    {
        fprintf(stderr, "Can't dequeue because buffer is empty!");
        return -1;
    } 
}

