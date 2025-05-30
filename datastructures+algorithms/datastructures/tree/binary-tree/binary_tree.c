#include <stdlib.h>

#include "binary_tree.h"

node_t *node_new(int value)
{
    node_t *node = malloc(sizeof(node_t));
    node->value = value;
    node->left_ptr = NULL;
    node->right_ptr = NULL;
    return node;
}

node_t *tree_insert(node_t *node_ptr, int value)
{
    if(node_ptr == NULL)
        return node_new(value);

    if(value < node_ptr->value)
    {
        node_ptr->left_ptr = tree_insert(node_ptr->left_ptr, value);
    }
    else if (value > node_ptr->value)
    {
        node_ptr->right_ptr = tree_insert(node_ptr->right_ptr, value);    
    }
    else 
    {
        node_ptr->value = value;
    }
    return node_ptr;
}

void tree_delete(node_t *node_ptr)
{
    if(node_ptr == NULL)
        return;

    tree_delete(node_ptr->left_ptr);
    tree_delete(node_ptr->right_ptr);
    free(node_ptr);
}

void tree_traversal_preorder(node_t *node_ptr)
{
    if(node_ptr == NULL)
    {
        return;
    }
    else 
    {
        printf("%d ", node_ptr->value);
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
        printf("%d ", node_ptr->value);
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
        printf("%d ", node_ptr->value);
    }
}
