#include <stdio.h>

#include "queue.h"


queue_t *queue_new(size_t dimension) 
{
    queue_t *queue = (queue_t *)malloc(sizeof(queue_t));
    queue->data = (int *)calloc(dimension, sizeof(int)); 
    queue->head = 0;
    queue->tail = 0;
    queue->size = 0;
    queue->dimension = dimension;
    return queue;
}

void queue_delete(queue_t *cb)
{
    free(cb->data);
    free(cb);
}

bool queue_is_empty(queue_t* cb) 
{
    return cb->size == 0;
}

bool queue_is_full(queue_t* cb) 
{
    return cb->size == cb->dimension;
}

bool queue_enqueue(queue_t* cb, int value) 
{
    if (queue_is_full(cb)) 
    {
        fprintf(stderr, "Error: queue is full, cannot enqueue.\n");
        return false;
    }
    
    cb->data[cb->tail] = value;
    cb->tail = (cb->tail + 1) % cb->dimension;
    cb->size++;
    return true;
}

int queue_dequeue(queue_t* cb) 
{
    if(queue_is_empty(cb)) 
    {
        fprintf(stderr, "Error: queue is empty, cannot dequeue.\n");
        return QUEUE_FULL;
    } 
    int data = cb->data[cb->head];
    cb->head = (cb->head + 1) % cb->dimension;
    cb->size--;
    return data;
}

void queue_print(queue_t* cb) 
{
    if (queue_is_empty(cb)) 
    {
        printf("queue is empty.\n");
        return;
    }
    
    printf("Queue contents: ");
    for (size_t i = 0; i < cb->size; i++) 
    {
        printf("%d ", cb->data[(cb->head + i) % cb->dimension]);
    }
    printf("\n");
}
