#ifndef _HASH_TABLE_H_
#define _HASH_TABLE_H_

#include <stdbool.h>

typedef struct node 
{
    int key;
    int value;
    struct node *next_ptr;
} node_t;

typedef struct table
{
    size_t dimension;
    node_t* array;
} table_t;

extern size_t hash_value(size_t dimension, int key); 

extern table_t *table_new(size_t dimension);
extern void table_delete(table_t* table);
extern size_t table_put(table_t* table, int key, int value);
extern int table_get(table_t* table, int key);
extern bool contains_key(table_t* table, int key);
extern void table_remove(table_t* table, int key);
extern void table_print(table_t* table);

#endif 