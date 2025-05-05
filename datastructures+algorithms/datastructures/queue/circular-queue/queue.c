#include <stdio.h>

#include "queue.h"


circular_queue_t *queue_new(size_t size) 
{
    circular_queue_t *queue = (circular_queue_t *)malloc(sizeof(circular_queue_t));
    queue->data = (int *)calloc(size, sizeof(int)); 
    queue->head = 0;
    queue->tail = 0;
    queue->count = 0;
    queue->size = size;
    return queue;
}

void queue_delete(circular_queue_t *cb)
{
    free(cb->data);
    free(cb);
}

bool queue_is_empty(circular_queue_t* cb) 
{
    return cb->count == 0;
}

bool queue_is_full(circular_queue_t* cb) 
{
    return cb->count == cb->size;
}

bool queue_enqueue(circular_queue_t* cb, int value) 
{
    if (queue_is_full(cb)) 
    {
        fprintf(stderr, "Error: queue is full, cannot enqueue.\n");
        return false;
    }
    
    cb->data[cb->tail] = value;
    cb->tail = (cb->tail + 1) % cb->size;
    cb->count++;
    return true;
}

int queue_dequeue(circular_queue_t* cb) 
{
    if(queue_is_empty(cb)) 
    {
        fprintf(stderr, "Error: queue is empty, cannot dequeue.\n");
        return QUEUE_FULL;
    } 
    int data = cb->data[cb->head];
    cb->head = (cb->head + 1) % cb->size;
    cb->count--;
    return data;
}

void queue_print(circular_queue_t* cb) 
{
    if (queue_is_empty(cb)) 
    {
        printf("queue is empty.\n");
        return;
    }
    
    printf("Queue contents: ");
    for (size_t i = 0; i < cb->count; i++) 
    {
        printf("%d ", cb->data[(cb->head + i) % cb->size]);
    }
    printf("\n");
}
