#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

#include <stdio.h>

typedef struct 
{
    char *ISBN;
    char *author;
    char *title;
} book_t;

typedef struct node 
{
    book_t *value;
    struct node *left_ptr;
    struct node *right_ptr;
} node_t;

extern node_t *node_new(book_t *value);
extern void node_delete(node_t *node_ptr);
extern node_t *tree_insert_left(node_t *node_ptr, book_t *value);
extern node_t *tree_insert_right(node_t *node_ptr, book_t *value);

extern void tree_traversal_preorder(node_t *node_ptr);
extern void tree_traversal_inorder(node_t *node_ptr);
extern void tree_traversal_postorder(node_t *node_ptr);

#endif 