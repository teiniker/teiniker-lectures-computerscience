#ifndef _TREE_MAP_H_
#define _TREE_MAP_H_

#include <stdio.h>
#include <stdbool.h>

typedef struct node 
{
    int key;
    int value;
    struct node *left_ptr;
    struct node *right_ptr;
} node_t;

typedef struct table
{
    node_t* tree;
} table_t;    

extern table_t *table_new();
extern void table_delete(table_t* table);

extern void table_put(table_t* table, int key, int value);
extern int table_get(table_t* table, int key);
extern bool contains_key(table_t* table, int key);
extern void table_remove(table_t* table, int key);
extern void table_print(table_t* table);

#endif /* _TREE_MAP_H_ */