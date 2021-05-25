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
    size_t size=0;
    node_t *tmp = first_ptr;   
    while(tmp != NULL)
    {
        tmp = tmp->next_ptr;
        size++;
    }   
    return size;
}


int list_get(node_t *first_ptr, int index)
{
    node_t *tmp = first_ptr;    
    for(int i=0; i<index; i++)
    {
        tmp = tmp->next_ptr;
    }
    return tmp->value;
}

extern node_t* list_append(node_t *first_ptr, int value)
{
    if(first_ptr == NULL)
    {
        first_ptr =  node_new(value);
    }
    else
    {    
        node_t *tmp = first_ptr;
        while(tmp->next_ptr != NULL)
        {
            tmp = tmp->next_ptr;
        }
        tmp->next_ptr = node_new(value);
    }
    return first_ptr;
}

node_t* list_insert(node_t *first_ptr, int index, int value)
{
    node_t *node = node_new(value);

    if(index == 0)
    {
        node->next_ptr = first_ptr;
        return node;
    }
    
    node_t *tmp = first_ptr;
    for(int i=0; i<index-1; i++)
    {
        if(tmp != NULL)
            tmp = tmp->next_ptr;
    }    
    node->next_ptr = tmp->next_ptr;
    tmp->next_ptr = node;
    
    return first_ptr;
}


node_t* list_remove(node_t *first_ptr, int index)
{
    if(index == 0)
    {
        node_t *rm_ptr = first_ptr;     
        first_ptr = first_ptr->next_ptr;
        free(rm_ptr);
        return first_ptr;
    }
    
    node_t *tmp = first_ptr;
    for(int i=0; i<index-1; i++)
    {
        if(tmp != NULL)
            tmp = tmp->next_ptr;
    }
    node_t *rm = tmp->next_ptr; 
    tmp->next_ptr = tmp->next_ptr->next_ptr;
    free(rm);
    
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
    for(node_t *p = first_ptr; p != NULL; p = p->next_ptr)
    {
        printf("%d ", p->value);       
    }
    printf("]\n");
}
