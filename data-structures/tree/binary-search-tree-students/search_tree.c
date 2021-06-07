#include <stdlib.h>

#include "search_tree.h"

node_t *node_new(student_t *value)
{
    node_t *node = malloc(sizeof(node_t));
    node->value = value;
    node->left_ptr = NULL;
    node->right_ptr = NULL;
    return node;
}

student_t *student_new(int id, char *first_name, char *last_name)
{
    student_t *student = malloc(sizeof(student_t));
    student->id = id;
    student->first_name = first_name;
    student->last_name = last_name;
    return student;

}

node_t *tree_insert(node_t *node_ptr, student_t *value, comparator_t cmp)
{
    if(node_ptr == NULL)
        return node_new(value);

    if(cmp(value, node_ptr->value) < 0)
        node_ptr->left_ptr = tree_insert(node_ptr->left_ptr, value, cmp);
    else 
        node_ptr->right_ptr = tree_insert(node_ptr->right_ptr, value, cmp);    

    return node_ptr;
}

node_t *tree_search(node_t *node_ptr, student_t *value, comparator_t cmp)
{
    if(node_ptr == NULL || cmp(value, node_ptr->value) == 0)
        return node_ptr;

    if(cmp(value, node_ptr->value) < 0)
        return tree_search(node_ptr->left_ptr, value, cmp);
    else 
        return tree_search(node_ptr->right_ptr, value, cmp);    
}


void tree_delete(node_t *node_ptr)
{
    if(node_ptr == NULL)
        return;

    tree_delete(node_ptr->left_ptr);
    tree_delete(node_ptr->right_ptr);
    free(node_ptr->value);
    free(node_ptr);
}

void tree_print(node_t *node_ptr)
{
    if(node_ptr == NULL)
        return;

    tree_print(node_ptr->left_ptr);
    printf("(%d,%s,%s) ", node_ptr->value->id, node_ptr->value->first_name, node_ptr->value->last_name);
    tree_print(node_ptr->right_ptr);
}
