#include <stdlib.h>

#include "binary_tree.h"

node_t *node_new(book_t *value)
{
    node_t *node = malloc(sizeof(node_t));
    node->value = value;
    node->left_ptr = NULL;
    node->right_ptr = NULL;
    return node;
}


node_t *tree_insert_left(node_t *node_ptr, book_t *value)
{
    node_t *ptr = node_new(value);
    if(node_ptr != NULL)
    {
        node_ptr->left_ptr = ptr;       
    }
    return ptr;
}

node_t *tree_insert_right(node_t *node_ptr, book_t *value)
{
    node_t *ptr = node_new(value);
    if(node_ptr != NULL)
    {
        node_ptr->right_ptr = ptr;       
    }
    return ptr;
}


void node_delete(node_t *node_ptr)
{
    free(node_ptr);
}

void print_book(book_t *value)
{
    printf("\t%s: %s - '%s'\n", value->ISBN, value->author, value->title);
}

void tree_traversal_preorder(node_t *node_ptr)
{
    if(node_ptr == NULL)
    {
        return;
    }
    else 
    {
        print_book(node_ptr->value);
        tree_traversal_preorder(node_ptr->left_ptr);
        tree_traversal_preorder(node_ptr->right_ptr);
    }
}

void tree_traversal_inorder(node_t *node_ptr)
{
    if(node_ptr == NULL)
    {
        return;
    }
    else 
    {
        tree_traversal_inorder(node_ptr->left_ptr);
        print_book(node_ptr->value);
        tree_traversal_inorder(node_ptr->right_ptr);
    }
}

void tree_traversal_postorder(node_t *node_ptr)
{
    if(node_ptr == NULL)
    {
        return;
    }
    else 
    {
        tree_traversal_postorder(node_ptr->left_ptr);
        tree_traversal_postorder(node_ptr->right_ptr);
        print_book(node_ptr->value);
    }
}
