#ifndef _CIRCULAR_QUEUE_H_
#define _CIRCULAR_QUEUE_H_

#include <stdbool.h>
#include <stdlib.h>

#define QUEUE_FULL -1

typedef struct 
{
    int *data;
    int head;
    int tail;
    size_t size;
    size_t dimension;
} queue_t;

extern queue_t *queue_new(size_t dimension);
extern void queue_delete(queue_t *cb);

extern bool queue_is_empty(queue_t* cb);
extern bool queue_is_full(queue_t* cb);
extern bool queue_enqueue(queue_t* cb, int data); 
extern int queue_dequeue(queue_t* cb); 

extern void queue_print(queue_t* cb);

#endif