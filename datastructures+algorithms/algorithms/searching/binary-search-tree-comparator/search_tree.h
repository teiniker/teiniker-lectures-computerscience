#ifndef _SEARCH_TREE_H_
#define _SEARCH_TREE_H_

#include <stdio.h>

typedef struct node 
{
    int value;
    struct node *left_ptr;
    struct node *right_ptr;
} node_t;

typedef int (*comparator_t)(const void *, const void*);

extern node_t *tree_insert(node_t *node_ptr, int value, comparator_t cmp);
extern void tree_delete(node_t *node_ptr);
extern void tree_print(node_t *node_ptr);

extern node_t *tree_search(node_t *node_ptr, int value, comparator_t cmp);

#endif /* _SEARCH_TREE_H_ */