#include <stdlib.h>

#include "linked_list.h"

node_t *node_new(int value)
{
    node_t *node = malloc(sizeof(node_t));
    node->value = value;
    node->next_ptr = NULL;
    return node;
}

size_t list_size(node_t *first_ptr)
{
    // TODO
    return 0;
}


int list_get(node_t *first_ptr, int index)
{
    // TODO
    return 0;
}

node_t* list_append(node_t *first_ptr, int value)
{
    if(first_ptr == NULL)
    {
        first_ptr =  node_new(value);
    }
    else
    {    
        node_t *ptr = first_ptr;
        while(ptr->next_ptr != NULL)
        {
            ptr = ptr->next_ptr;
        }
        ptr->next_ptr = node_new(value);
    }
    return first_ptr;
}

node_t* list_insert(node_t *first_ptr, int index, int value)
{
    // TODO
    return first_ptr;
}


node_t* list_remove(node_t *first_ptr, int index)
{
    // TODO
    return first_ptr;
}

void list_delete(node_t *first_ptr)
{
    while(first_ptr->next_ptr != NULL)
    {
        node_t *rm = first_ptr;
        first_ptr = first_ptr->next_ptr;
        free(rm);
    }
    free(first_ptr);
}

void list_print(node_t *first_ptr)
{
    printf("[ ");
    for(node_t *ptr = first_ptr; ptr != NULL; ptr = ptr->next_ptr)
    {
        printf("%d ", ptr->value);       
    }
    printf("]\n");
}
