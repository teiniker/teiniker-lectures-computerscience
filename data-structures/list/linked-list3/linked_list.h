#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include <stdio.h>

typedef struct node 
{
    int value;
    struct node *next_ptr;
} node_t;

typedef struct  
{
    node_t *first_ptr;
} list_t;

extern list_t *list_new();
extern void list_delete(list_t *list);

extern size_t list_size(list_t *list);
extern int list_get(list_t *list, int index);
extern int list_find(list_t *list, int value);
extern void list_append(list_t *list, int value);
extern void list_insert(list_t *list, int index, int value);
extern void list_remove(list_t *list, int index);
extern void list_print(list_t *first);

#endif /* _LINKED_LIST_H_ */