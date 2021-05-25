#include <stdlib.h>

#include "queue.h"

node_t *node_new(int value)
{
    node_t *node = malloc(sizeof(node_t));
    node->value = value;
    node->next_ptr = NULL;
    return node;
}

queue_t *queue_new()
{
    queue_t *queue = malloc(sizeof(queue_t));
    queue->head_ptr = NULL;
    queue->tail_ptr = NULL;
    return queue;
}

void queue_delete(queue_t *queue)
{
    // TODO
}

bool queue_is_empty(queue_t *queue)
{
    // TODO
    return false;
}

void queue_enqueue(queue_t *queue, int value)
{
    // TODO
}

int queue_dequeue(queue_t *queue)
{
    // TODO
    return 0;
}

void queue_print(queue_t *queue)
{
    printf("head_ptr-->[ ");
    
    for(node_t *ptr = queue->head_ptr; ptr != NULL; ptr = ptr->next_ptr)
    {
        printf("%d ", ptr->value);       
    }
    printf("]<--tail_ptr\n");
}
