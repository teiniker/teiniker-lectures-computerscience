#include <stdlib.h>
#include <stdio.h>
#include "hash_table.h"

// Hash function: simple modulo
size_t hash_value(size_t dimension, int key) 
{
    return (size_t)(abs(key) % dimension);
}

// Create a new hash table
table_t *table_new(size_t dimension) 
{
    table_t *table = (table_t *)malloc(sizeof(table_t));
    table->dimension = dimension;
    table->array = (node_t *)calloc(dimension, sizeof(node_t));

    // Initialize all list heads to NULL
    for (size_t i = 0; i < dimension; i++) 
    {
        table->array[i].next_ptr = NULL;
    }

    return table;
}

// Delete the entire hash table
void table_delete(table_t* table) 
{
    for (size_t i = 0; i < table->dimension; i++) 
    {
        node_t *current = table->array[i].next_ptr;
        while (current) 
        {
            node_t *temp = current;
            current = current->next_ptr;
            free(temp);
        }
    }
    free(table->array);
    free(table);
}

// Add or update a key-value pair
size_t table_put(table_t* table, int key, int value) 
{
    size_t index = hash_value(table->dimension, key);
    
    // Update value if key exists
    node_t *current = table->array[index].next_ptr;
    while (current) 
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
    new_node->next_ptr = table->array[index].next_ptr;
    table->array[index].next_ptr = new_node;

    return index;
}

// Get value by key
int table_get(table_t* table, int key) 
{
    size_t index = hash_value(table->dimension, key);
    node_t *current = table->array[index].next_ptr;

    while (current) 
    {
        if (current->key == key) 
        {
            return current->value;
        }
        current = current->next_ptr;
    }

    return -1; // Not found
}

// Find if key exists (1 = yes, 0 = no)
bool contains_key(table_t* table, int key) 
{
    size_t index = hash_value(table->dimension, key);
    node_t *current = table->array[index].next_ptr;

    while (current) 
    {
        if (current->key == key) 
            return true;    // Found
        current = current->next_ptr;
    }

    return false; // Not found
}

// Remove key-value pair
void table_remove(table_t* table, int key) 
{
    size_t index = hash_value(table->dimension, key);
    node_t *current = table->array[index].next_ptr;
    node_t *prev = NULL;

    while (current) 
    {
        if (current->key == key) 
        {
            if (prev) 
            {
                prev->next_ptr = current->next_ptr;
            } 
            else 
            {
                table->array[index].next_ptr = current->next_ptr;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next_ptr;
    }
}

// Print contents of the hash table
void table_print(table_t* table) 
{
    for (size_t i = 0; i < table->dimension; i++) 
    {
        printf("Bucket %zu:", i);
        node_t *current = table->array[i].next_ptr;
        while (current) 
        {
            printf(" (%d => %d)", current->key, current->value);
            current = current->next_ptr;
        }
        printf("\n");
    }
}
