#include <stdlib.h>

#include "linked_list.h"

node_t *node_new(int value)
{
    node_t *node = malloc(sizeof(node_t));
    node->value = value;
    node->next_ptr = NULL;
    return node;
}

size_t list_size(node_t *list)
{
    size_t size=0;
    while(list != NULL)
    {
        list = list->next_ptr;
        size++;
    }   
    return size;
}


int list_get(node_t *list, int index)
{
    for(int i=0; i<index; i++)
    {
        if(list != NULL)
            list = list->next_ptr;
    }
    return list->value;
}

extern node_t* list_append(node_t *list, int value)
{
    if(list == NULL)
    {
        list =  node_new(value);
    }
    else
    {    
        node_t *tmp = list;
        while(tmp->next_ptr != NULL)
        {
            tmp = tmp->next_ptr;
        }
        tmp->next_ptr = node_new(value);
    }
    return list;
}

node_t* list_insert(node_t *list, int index, int value)
{
    node_t *node = node_new(value);

    if(index == 0)
    {
        node->next_ptr = list;
        return node;
    }
    
    node_t *tmp = list;
    for(int i=0; i<index-1; i++)
    {
        if(tmp != NULL)
            tmp = tmp->next_ptr;
    }    
    node->next_ptr = tmp->next_ptr;
    tmp->next_ptr = node;
    
    return list;
}


node_t* list_remove(node_t *list, int index)
{
    if(index == 0)
    {
        node_t *rm_ptr = list;     
        list = list->next_ptr;
        free(rm_ptr);
        return list;
    }
    
    node_t *tmp = list;
    for(int i=0; i<index-1; i++)
    {
        if(tmp != NULL)
            tmp = tmp->next_ptr;
    }
    node_t *rm = tmp->next_ptr; 
    tmp->next_ptr = tmp->next_ptr->next_ptr;
    free(rm);
    
    return list;
}

void list_delete(node_t *list)
{
    while(list->next_ptr != NULL)
    {
        node_t *rm = list;
        list = list->next_ptr;
        free(rm);
    }
    free(list);
}

void list_print(node_t *first)
{
    printf("[ ");
    for(node_t *p = first; p != NULL; p = p->next_ptr)
    {
        printf("%d ", p->value);       
    }
    printf("]\n");
}
