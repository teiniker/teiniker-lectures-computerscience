#ifndef _SEARCH_TREE_H_
#define _SEARCH_TREE_H_

#include <stdio.h>

typedef struct student
{
    int id;
    char *first_name;
    char *last_name;  
} student_t;

typedef struct node 
{
    student_t *value;
    struct node *left_ptr;
    struct node *right_ptr;
} node_t;

typedef int (*comparator_t)(const void *, const void*);

extern student_t *student_new(int id, char *first_name, char *last_name);
extern node_t *tree_insert(node_t *node_ptr, student_t *value, comparator_t cmp);
extern node_t *tree_search(node_t *node_ptr, student_t *value, comparator_t cmp);
extern void tree_delete(node_t *node_ptr);

extern void tree_print(node_t *node_ptr);

#endif /* _SEARCH_TREE_H_ */