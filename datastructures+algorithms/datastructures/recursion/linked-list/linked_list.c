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
    if(first_ptr == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + list_size(first_ptr->next_ptr);
    }
}

node_t* list_append(node_t *first_ptr, int value)
{
    if(first_ptr == NULL)
    {
        return node_new(value);
    }
    else
    {    
        first_ptr->next_ptr = list_append(first_ptr->next_ptr, value);
        return first_ptr;
    }
}

void list_print(node_t *first_ptr)
{
    if(first_ptr == NULL)
    {
        printf("\n");
        return;
    }
    else 
    {
        printf("%d ", first_ptr->value);
        list_print(first_ptr->next_ptr); 
    }
}

void list_delete(node_t *first_ptr)
{
    if(first_ptr->next_ptr == NULL)
    {
        free(first_ptr);
    }
    else
    {
        node_t *ptr = first_ptr->next_ptr;
        free(first_ptr);
        list_delete(ptr);
    }
}