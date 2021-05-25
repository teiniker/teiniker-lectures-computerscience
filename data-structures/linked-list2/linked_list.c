#include <stdlib.h>

#include "linked_list.h"

node_t *node_new(int value)
{
    node_t *node = malloc(sizeof(node_t));
    node->value = value;
    node->next_ptr = NULL;
    return node;
}

size_t list_size(node_t **list)
{
    size_t size=0;
    node_t *ptr = *list;   
    while(ptr != NULL)
    {
        ptr = ptr->next_ptr;
        size++;
    }   
    return size;
}


int list_get(node_t **list, int index)
{
    node_t *ptr = *list;    
    for(int i=0; i<index; i++)
    {
        ptr = ptr->next_ptr;
    }
    return ptr->value;
}

extern void list_append(node_t **list, int value)
{
    if(*list == NULL)
    {
        *list =  node_new(value);
    }
    else
    {    
        node_t *tmp = *list;
        while(tmp->next_ptr != NULL)
        {
            tmp = tmp->next_ptr;
        }
        tmp->next_ptr = node_new(value);
    }
}

void list_insert(node_t **list, int index, int value)
{
    node_t *node = node_new(value);

    if(index == 0)
    {
        node->next_ptr = *list;
        *list = node; 
        return;
    }
    
    node_t *ptr = *list;
    for(int i=0; i<index-1; i++)
    {
        if(ptr != NULL)
            ptr = ptr->next_ptr;
    }    
    node->next_ptr = ptr->next_ptr;
    ptr->next_ptr = node;
}


void list_remove(node_t **list, int index)
{
    if(index == 0)
    {
        node_t *rm_ptr = *list;     
        *list = (*list)->next_ptr;
        free(rm_ptr);
        return;
    }
    
    node_t *ptr = *list;
    for(int i=0; i<index-1; i++)
    {
        if(ptr != NULL)
            ptr = ptr->next_ptr;
    }
    node_t *rm = ptr->next_ptr; 
    ptr->next_ptr = ptr->next_ptr->next_ptr;
    free(rm);
}

void list_delete(node_t **list)
{
    node_t *ptr = *list;
    while(ptr->next_ptr != NULL)
    {
        node_t *rm = ptr;
        ptr = ptr->next_ptr;
        free(rm);
    }
    free(ptr);
}

void list_print(node_t **first)
{
    printf("[ ");
    for(node_t *ptr = *first; ptr != NULL; ptr = ptr->next_ptr)
    {
        printf("%d ", ptr->value);       
    }
    printf("]\n");
}
