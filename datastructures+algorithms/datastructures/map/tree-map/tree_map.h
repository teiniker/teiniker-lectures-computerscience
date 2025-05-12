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

typedef struct map
{
    node_t* tree;
} map_t;    

extern map_t *map_new();
extern void map_delete(map_t* map);

extern void map_put(map_t* map, int key, int value);
extern int map_get(map_t* map, int key);
extern bool contains_key(map_t* map, int key);
extern void map_remove(map_t* map, int key);
extern void map_print(map_t* map);

#endif /* _TREE_MAP_H_ */