#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include <stdio.h>

typedef struct node 
{
    int value;
    struct node *next_ptr;
} node_t;

extern node_t *new_node(int value);
extern node_t* list_insert(node_t *list, int index, int value);
extern size_t list_size(node_t *list);
extern int list_get(node_t *list, int index);
extern node_t* list_remove(node_t *list, int index);
extern void list_remove_all(node_t *list);
extern void list_print(node_t *first);

#endif /* _LINKED_LIST_H_ */