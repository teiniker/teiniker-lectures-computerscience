#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include <stdio.h>

typedef struct node 
{
    int value;
    struct node *next_ptr;
} node_t;

extern size_t list_size(node_t **list);
extern int list_get(node_t **list, int index);
extern void list_append(node_t **list, int value);
extern void list_insert(node_t **list, int index, int value);
extern void list_remove(node_t **list, int index);
extern void list_delete(node_t **list);
extern void list_print(node_t **first);

#endif /* _LINKED_LIST_H_ */