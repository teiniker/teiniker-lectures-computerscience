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
    node_t *ptr = queue->head_ptr;
    if(ptr != NULL)
    {
        while(ptr->next_ptr != NULL)
        {
            node_t *rm = ptr;
            ptr = ptr->next_ptr;
            free(rm);
        }
        free(ptr);
    }    
    free(queue);
}

bool queue_is_empty(queue_t *queue)
{
    return (queue->head_ptr == NULL && queue->tail_ptr == NULL);
}

void queue_enqueue(queue_t *queue, int value)
{
    node_t *ptr = node_new(value);

    if(queue->tail_ptr == NULL)
    {
        queue->tail_ptr = ptr;
        queue->head_ptr = ptr;
    }
    else
    {
        queue->tail_ptr->next_ptr = ptr;
        queue->tail_ptr = ptr;   
    }    
}

int queue_dequeue(queue_t *queue)
{
    node_t *ptr = queue->head_ptr;
    if(ptr != NULL)
    {       
        int value = ptr->value;
        queue->head_ptr = ptr->next_ptr;
        free(ptr);

        if(queue->head_ptr == NULL)
            queue->tail_ptr = NULL; // queue is empty
        return value;
    }
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
