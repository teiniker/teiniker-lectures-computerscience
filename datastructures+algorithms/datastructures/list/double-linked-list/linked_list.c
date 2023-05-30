#include <stdlib.h>

#include "linked_list.h"

node_t *node_new(int value)
{
    node_t *node = malloc(sizeof(node_t));
    node->value = value;
    node->next_ptr = NULL;
    node->prev_ptr = NULL;
    return node;
}

list_t *list_new()
{
    list_t *list = malloc(sizeof(list_t));
    list->first_ptr = NULL;
    list->last_ptr = NULL;
    return list;
}

size_t list_size(list_t *list)
{
   size_t size=0;
    node_t *ptr = list->first_ptr;   
    while(ptr != NULL)
    {
        ptr = ptr->next_ptr;
        size++;
    }   
    return size;
}


int list_get(list_t *list, int index)
{
    node_t *ptr = list->first_ptr;    
    for(int i=0; i<index; i++)
    {
        ptr = ptr->next_ptr;
    }
    return ptr->value;
}


void list_append(list_t *list, int value)
{
    node_t *ptr = node_new(value);
 
    if(list->last_ptr == NULL)
    {
        list->last_ptr= ptr;
        list->first_ptr= ptr;
    }
    else
    {
        ptr->prev_ptr = list->last_ptr;
        list->last_ptr->next_ptr = ptr;
        list->last_ptr = ptr;          
    }    
}

void list_prepend(list_t *list, int value)
{
    node_t *ptr = node_new(value);
 
    if(list->first_ptr == NULL)
    {
        list->last_ptr= ptr;
        list->first_ptr= ptr;
    }
    else
    {
        ptr->next_ptr = list->first_ptr;
        list->first_ptr->prev_ptr = ptr;
        list->first_ptr = ptr;          
    }    
}

void list_delete(list_t *list)
{
    node_t *ptr = list->first_ptr;
    while(ptr->next_ptr != NULL)
    {
        node_t *rm = ptr;
        ptr = ptr->next_ptr;
        free(rm);
    }
    free(ptr);
    free(list);
}

void list_print(list_t *list)
{
    printf("[ ");
    for(node_t *ptr = list->first_ptr; ptr != NULL; ptr = ptr->next_ptr)
    {
        printf("%d ", ptr->value);       
    }
    printf("]\n");
}
