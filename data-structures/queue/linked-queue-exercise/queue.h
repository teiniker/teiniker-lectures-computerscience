#ifndef _LINKED_QUEUE_H_
#define _LINKED_QUEUE_H_

#include <stdio.h>
#include <stdbool.h>

typedef struct node 
{
    int value;
    struct node *next_ptr;
} node_t;

typedef struct  
{
    node_t *head_ptr;
    node_t *tail_ptr;
} queue_t;

extern queue_t *queue_new();
extern void queue_delete(queue_t *queue);

extern bool queue_is_empty(queue_t *queue);
extern void queue_enqueue(queue_t *queue, int value);
extern int queue_dequeue(queue_t *queue);

extern void queue_print(queue_t *queue);

#endif /* _LINKED_QUEUE_H_ */