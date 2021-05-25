#include <stdlib.h>

#include "linked_list.h"

node_t *node_new(int value)
{
    node_t *node = malloc(sizeof(node_t));
    node->value = value;
    node->next_ptr = NULL;
    return node;
}

list_t *list_new()
{
    list_t *list = malloc(sizeof(list_t));
    list->first_ptr = NULL;
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

extern void list_append(list_t *list, int value)
{
    if(list->first_ptr == NULL)
    {
        list->first_ptr =  node_new(value);
    }
    else
    {    
        node_t *ptr = list->first_ptr;
        while(ptr->next_ptr != NULL)
        {
            ptr = ptr->next_ptr;
        }
        ptr->next_ptr = node_new(value);
    }
}

void list_insert(list_t *list, int index, int value)
{
    node_t *node = node_new(value);

    if(index == 0)
    {
        node->next_ptr = list->first_ptr;
        list->first_ptr = node; 
        return;
    }
    
    node_t *ptr = list->first_ptr;
    for(int i=0; i<index-1; i++)
    {
        if(ptr != NULL)
            ptr = ptr->next_ptr;
    }    
    node->next_ptr = ptr->next_ptr;
    ptr->next_ptr = node;
}


void list_remove(list_t *list, int index)
{
    if(index == 0)
    {
        node_t *rm_ptr = list->first_ptr;     
        list->first_ptr = list->first_ptr->next_ptr;
        free(rm_ptr);
        return;
    }
    
    node_t *ptr = list->first_ptr;
    for(int i=0; i<index-1; i++)
    {
        if(ptr != NULL)
            ptr = ptr->next_ptr;
    }
    node_t *rm = ptr->next_ptr; 
    ptr->next_ptr = ptr->next_ptr->next_ptr;
    free(rm);
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
