#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <stdlib.h>
#include <assert.h>

int *list_new(size_t dimension, size_t *size);
void list_delete(int *list, size_t *size);

void list_print(int *list, size_t dimension, size_t size);
int list_get(int *list, size_t dimension, size_t size, size_t index);
int list_find(int *list, size_t dimension, size_t size, int value);

void list_append(int *list, size_t dimension, size_t *size, int value);
void list_insert(int *list, size_t dimension, size_t *size, size_t index, int value);
void list_remove(int *list, size_t dimension, size_t *size, size_t index);


int main()
{
    // setup linked list
    size_t dimension = 10;
    size_t size;
    int *list = list_new(dimension, &size);
    
    // append values
    list_append(list, dimension, &size, 1);
    list_append(list, dimension, &size, 2);
    list_append(list, dimension, &size, 3);
    list_print(list, dimension, size);

    // get value
    assert(list_get(list, dimension, size, 2) == 3);
    assert(list_get(list, dimension, size, 1) == 2);
    assert(list_get(list, dimension, size, 0) == 1);
    
    // find value
    assert(list_find(list, dimension, size, 2) == 1);
    assert(list_find(list, dimension, size, 3) == 2);
    assert(list_find(list, dimension, size, 1) == 0);
    assert(list_find(list, dimension, size, 4) == -1);

    // insert value
    list_insert(list, dimension, &size, 1, 33);
    list_print(list, dimension, size);

    // remove value
    list_remove(list, dimension, &size, 2);
    list_print(list, dimension, size);

    // teardown list
    list_delete(list, &size);

    return EXIT_SUCCESS;
}

int *list_new(size_t dimension, size_t *size)
{
    if (dimension == 0)
    {
        fprintf(stderr, "Dimension must be greater than 0\n");
        exit(EXIT_FAILURE);
    }
    if (size == 0)
    {
        fprintf(stderr, "Size must be greater than 0\n");
        exit(EXIT_FAILURE);
    }

    int *list = (int *)malloc(sizeof(int) * dimension);
    if (list == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    *size = 0;
    return list;
}

void list_delete(int *list, size_t *size)
{
    free(list);
    *size = 0;
}

void list_print(int *list, size_t dimension, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", list[i]);
    }
    printf("\n");
}

int list_get(int *list, size_t dimension, size_t size, size_t index)
{
    if (index >= size)
    {
        fprintf(stderr, "Index out of bounds\n");
        return -1;
    }
    return list[index];
}

int list_find(int *list, size_t dimension, size_t size, int value)
{
    for (int i = 0; i < size; i++)
    {
        if (list[i] == value)
        {
            return i;
        }
    }
    return -1;
}

void list_append(int *list, size_t dimension, size_t *size, int value)
{
    if(*size >= dimension)
    {
        fprintf(stderr, "List is full\n");
        return;
    }
    list[*size] = value;
    (*size)++;
}

void list_insert(int *list, size_t dimension, size_t *size, size_t index, int value)
{
    if(*size >= dimension)
    {
        fprintf(stderr, "List is full\n");
        return;
    }
    if(index > *size)
    {
        fprintf(stderr, "Index out of bounds\n");
        return;
    }
    for(size_t i = *size; i > index; i--)
    {
        list[i] = list[i - 1];
    }
    list[index] = value;
    (*size)++;
}

void list_remove(int *list, size_t dimension, size_t *size, size_t index)
{
    if(index >= *size)
    {
        fprintf(stderr, "Index out of bounds\n");
        return;
    }
    for(size_t i = index; i < *size - 1; i++)
    {
        list[i] = list[i + 1];
    }
    (*size)--;
}
