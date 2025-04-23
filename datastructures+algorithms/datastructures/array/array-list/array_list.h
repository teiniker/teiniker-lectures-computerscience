#ifndef _ARRAY_LIST_H_
#define _ARRAY_LIST_H_

#include <stdio.h>

typedef struct array_list
{
    size_t size;
    size_t dimension;
    int* array;
} array_list_t;

extern array_list_t *list_new(size_t dimension);
extern void list_delete(array_list_t* list);

extern size_t list_size(array_list_t *list);
extern int list_get(array_list_t* list, int index);
extern int list_find(array_list_t *list, int value);
extern void list_append(array_list_t* list, int value);
extern void list_insert(array_list_t* list, int index, int value);
extern void list_remove(array_list_t* list, int index);
extern void list_print(array_list_t* list);

#endif 