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
    size_t count;
    size_t size;
} circular_queue_t;

extern circular_queue_t *queue_new(size_t size);
extern void queue_delete(circular_queue_t *cb);

extern bool queue_is_empty(circular_queue_t* cb);
extern bool queue_is_full(circular_queue_t* cb);
extern bool queue_enqueue(circular_queue_t* cb, int data); 
extern int queue_dequeue(circular_queue_t* cb); 

extern void queue_print(circular_queue_t* cb);

#endif