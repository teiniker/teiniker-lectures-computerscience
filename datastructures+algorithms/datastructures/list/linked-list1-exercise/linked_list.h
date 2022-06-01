#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include <stdio.h>

typedef struct node 
{
    int value;
    struct node *next_ptr;
} node_t;

extern size_t list_size(node_t *first_ptr);
extern int list_get(node_t *first_ptr, int index);
extern int list_find(node_t *first_ptr, int value);
extern node_t* list_append(node_t *first_ptr, int value);
extern node_t* list_insert(node_t *first_ptr, int index, int value);
extern node_t* list_remove(node_t *first_ptr, int index);
extern void list_delete(node_t *first_ptr);
extern void list_print(node_t *first_ptr);

#endif /* _LINKED_LIST_H_ */