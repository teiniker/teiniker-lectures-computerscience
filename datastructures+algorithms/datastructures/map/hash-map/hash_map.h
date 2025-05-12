#ifndef _HASH_MAP_H_
#define _HASH_MAP_H_

#include <stdlib.h>
#include <stdbool.h>

typedef struct node 
{
    int key;
    int value;
    struct node *next_ptr;
} node_t;

typedef struct map
{
    size_t dimension;
    node_t* array;
} map_t;

extern size_t hash_code(size_t dimension, int key); 

extern map_t *map_new(size_t dimension);
extern void map_delete(map_t* map);

extern size_t map_put(map_t* map, int key, int value);
extern int map_get(map_t* map, int key);
extern bool contains_key(map_t* map, int key);
extern void map_remove(map_t* map, int key);
extern void map_print(map_t* map);

#endif // _HASH_MAP_H_