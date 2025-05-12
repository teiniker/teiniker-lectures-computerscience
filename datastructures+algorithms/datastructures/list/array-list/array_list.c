#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "array_list.h"

list_t *list_new(size_t dimension)
{
    list_t *list = malloc(sizeof(list_t));
    list->size = 0;
    list->dimension = dimension;
    list->array = calloc(dimension, sizeof(int));
    return list;
}

void list_delete(list_t* list)
{
    free(list->array);
    free(list);
}

size_t list_size(list_t *list)
{
    return list->size;
}

int list_get(list_t* list, int index)
{
    // Input validation
    if(index < 0 || index >= list->size)
    {
        fprintf(stderr, "Index out of bounds\n");
        exit(EXIT_FAILURE);
    }
    return list->array[index];
}

int list_find(list_t *list, int value)
{
    for(int i=0; i<list->size; i++)
    {
        if(list->array[i] == value)
            return i;
    }
    return -1;
}

void list_append(list_t* list, int value)
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

void list_insert(list_t* list, int index, int value)
{
    // Input validation
    if(index < 0 || index > list->size)
    {
        fprintf(stderr, "Index out of bounds\n");
        exit(EXIT_FAILURE);
    }

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

void list_remove(list_t* list, int index)
{
    // Input validation
    if(index < 0 || index >= list->size)
    {
        fprintf(stderr, "Index out of bounds\n");
        exit(EXIT_FAILURE);
    }
    
    list->size--;
    for(int i = index; i < list->size; i++)
    {
        list->array[i] = list->array[i+1];
    }
}

void list_print(list_t* list)
{
    printf("[ ");
    for(int i=0; i < list->size; i++)
    {
        printf("%d ", list->array[i]);       
    }
    printf("]\n");
}
