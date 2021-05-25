#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "array_list.h"

array_list_t *list_new(size_t dimension)
{
    array_list_t *list = malloc(sizeof(array_list_t));
    list->size = 0;
    list->dimension = dimension;
    list->array = calloc(dimension, sizeof(int));
    return list;
}

size_t list_size(array_list_t *list)
{
    return list->size;
}

int list_get(array_list_t* list, int index)
{
    return list->array[index];
}

int list_find(array_list_t *list, int value)
{
    for(int i=0; i<list->size; i++)
    {
        if(list->array[i] == value)
            return i;
    }
    return -1;
}

void list_append(array_list_t* list, int value)
{
    if(list->size == 0)
    {
        list->array[0] = value;        
    }
    else
    {
        list->array[list->size] = value;
    }
    list->size++;  
}

void list_insert(array_list_t* list, int index, int value)
{
    if(list->size == 0)
    { 
        list->array[0] = value;
    }
    else 
    {
        // Move values one position to the right
        for(int i = list->size; i > index; i--)
        {
            list->array[i] = list->array[i-1];
        }
        list->array[index] = value;
    }
    list->size++;
}

void list_remove(array_list_t* list, int index)
{
    list->size--;
    for(int i = index; i < list->size; i++)
    {
        list->array[i] = list->array[i+1];
    }
}

void list_delete(array_list_t* list)
{
    free(list->array);
    free(list);
}


void list_print(array_list_t* list)
{
    printf("[ ");
    for(int i=0; i < list->size; i++)
    {
        printf("%d ", list->array[i]);       
    }
    printf("]\n");
}
