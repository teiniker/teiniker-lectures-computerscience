#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef struct 
{
    size_t size;
    size_t dimension;
    int* array;
} array_list_t;


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


int list_get(array_list_t* list, int index)
{
    return list->array[index];
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


int main(void)
{    
    array_list_t *list = list_new(16);

    // Verify append
    list_append(list, 5);
    list_print(list);
    list_append(list, 3);
    list_print(list);
    list_append(list, 1);
    list_print(list);
    list_append(list, 7);
    list_print(list);
    list_append(list, 9);
    list_print(list);

    // Verify insert 
    list_insert(list, 0, 5);
    list_print(list);
    list_insert(list, 0, 3);
    list_print(list);
    list_insert(list, 0, 1);
    list_print(list);
    list_insert(list, 1, 7);
    list_print(list);
    list_insert(list, 3, 9);
    list_print(list);

    // Verify size
    printf("size = %ld\n", list_size(list));

    // Verify list_get()
    assert(1 == list_get(list, 0));
    assert(3 == list_get(list, 2));
    assert(5 == list_get(list, 4));

    // Verify remove 
    list_remove(list, 4);
    list_print(list);
    list_remove(list, 2);
    list_print(list);
    list_remove(list, 0);
    list_print(list);

    // verify remove_all 
    list_delete(list);

    return 0;
}
