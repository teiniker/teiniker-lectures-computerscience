#include <stdlib.h>
#include <stdio.h>
#include "hash_map.h"

size_t hash_code(size_t dimension, int key) 
{
    return (size_t)(abs(key) % dimension);
}

map_t *map_new(size_t dimension) 
{
    map_t *map = (map_t *)malloc(sizeof(map_t));
    map->dimension = dimension;
    map->array = (node_t *)calloc(dimension, sizeof(node_t));

    // Initialize all list heads to NULL
    for (size_t i = 0; i < dimension; i++) 
    {
        map->array[i].next_ptr = NULL;
    }

    return map;
}

void map_delete(map_t* map) 
{
    for (size_t i = 0; i < map->dimension; i++) 
    {
        node_t *current = map->array[i].next_ptr;
        while(current != NULL) 
        {
            node_t *temp = current;
            current = current->next_ptr;
            free(temp);
        }
    }
    free(map->array);
    free(map);
}

size_t map_put(map_t* map, int key, int value) 
{
    size_t index = hash_code(map->dimension, key);
    
    node_t *current = map->array[index].next_ptr;
    while(current != NULL) 
    {
        if (current->key == key) 
        {
            current->value = value;
            return index;
        }
        current = current->next_ptr;
    }

    // Insert new node at the beginning
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->key = key;
    new_node->value = value;
    new_node->next_ptr = map->array[index].next_ptr;
    map->array[index].next_ptr = new_node;

    return index;
}

int map_get(map_t* map, int key) 
{
    size_t index = hash_code(map->dimension, key);
    node_t *current = map->array[index].next_ptr;

    while(current != NULL) 
    {
        if (current->key == key) 
        {
            return current->value;
        }
        current = current->next_ptr;
    }

    return -1; // Not found
}

bool contains_key(map_t* map, int key) 
{
    size_t index = hash_code(map->dimension, key);
    node_t *current = map->array[index].next_ptr;

    while (current) 
    {
        if (current->key == key) 
            return true;    // Found
        current = current->next_ptr;
    }

    return false; // Not found
}

void map_remove(map_t* map, int key) 
{
    size_t index = hash_code(map->dimension, key);
    node_t *current = map->array[index].next_ptr;
    node_t *prev = NULL;

    while(current != NULL) 
    {
        if (current->key == key) 
        {
            if (prev) 
            {
                prev->next_ptr = current->next_ptr;
            } 
            else 
            {
                map->array[index].next_ptr = current->next_ptr;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next_ptr;
    }
}

void map_print(map_t* map) 
{
    for (size_t i = 0; i < map->dimension; i++) 
    {
        printf("Bucket %zu:", i);
        node_t *current = map->array[i].next_ptr;
        while (current) 
        {
            printf(" (%d => %d)", current->key, current->value);
            current = current->next_ptr;
        }
        printf("\n");
    }
}
