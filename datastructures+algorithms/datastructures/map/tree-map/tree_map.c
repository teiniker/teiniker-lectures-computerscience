#include "tree_map.h"
#include <stdlib.h>

// Private functions (forward declarations)

node_t* node_put(node_t* root, int key, int value);
int node_get(node_t* root, int key);
bool node_contains(node_t* root, int key);
node_t* node_remove(node_t* root, int key);
void node_print(node_t* root);
void node_delete(node_t* root);


map_t* map_new(void) 
{
    map_t* map = (map_t*)malloc(sizeof(map_t));
    map->tree = NULL;
    return map;
}

void map_delete(map_t* map) 
{
    if (map == NULL) 
        return;
    node_delete(map->tree);
    free(map);
}

void map_put(map_t* map, int key, int value) 
{
    if (map == NULL) 
    {
        map = map_new();
    }
    map->tree = node_put(map->tree, key, value);
}

int map_get(map_t* map, int key) 
{
    if (map==NULL || map->tree == NULL) 
    {
        fprintf(stderr, "Key not found\n");
        exit(EXIT_FAILURE);
    }
    return node_get(map->tree, key);
}

bool contains_key(map_t* map, int key) 
{
    if (map == NULL || map->tree == NULL) 
        return false;
    return node_contains(map->tree, key);
}

void map_remove(map_t* map, int key) 
{
    if (map==NULL || map->tree == NULL) 
        return;
    map->tree = node_remove(map->tree, key);
}

void map_print(map_t* map) 
{
    if (map == NULL || map->tree == NULL) 
        return;
    node_print(map->tree);
}


// Private functions

node_t* node_new(int key, int value) 
{
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    new_node->key = key;
    new_node->value = value;
    new_node->left_ptr = NULL;
    new_node->right_ptr = NULL;
    return new_node;
}

node_t* node_put(node_t* root, int key, int value) 
{
    if(root == NULL) 
    {
        return node_new(key, value);
    }

    if(key < root->key) 
    {
        root->left_ptr = node_put(root->left_ptr, key, value);
    } 
    else if(key > root->key) 
    {
        root->right_ptr = node_put(root->right_ptr, key, value);
    } 
    else 
    {
        root->value = value;
    }

    return root;
}

int node_get(node_t* root, int key) 
{
    if(root == NULL) 
    {
        fprintf(stderr, "Key not found\n");
        return -1;
        //exit(EXIT_FAILURE);
    }

    if(key < root->key) 
    {
        return node_get(root->left_ptr, key);
    } 
    else if(key > root->key) 
    {
        return node_get(root->right_ptr, key);
    } 
    else 
    {
        return root->value;
    }
}

bool node_contains(node_t* root, int key) 
{
    if(root == NULL) 
        return false;

    if(key < root->key) 
    {
        return node_contains(root->left_ptr, key);
    } 
    else if(key > root->key) 
    {
        return node_contains(root->right_ptr, key);
    } 
    else 
    {
        return true;
    }
}

node_t* find_min(node_t* node) 
{
    while(node != NULL && (node->left_ptr) != NULL) 
    {
        node = node->left_ptr;
    }
    return node;
}

node_t* node_remove(node_t* root, int key) 
{
    if(root == NULL) 
        return NULL;

    if(key < root->key) 
    {
        root->left_ptr = node_remove(root->left_ptr, key);
    } 
    else if(key > root->key) 
    {
        root->right_ptr = node_remove(root->right_ptr, key);
    } 
    else 
    {
        if ((root->left_ptr) == NULL) 
        {
            node_t* temp = root->right_ptr;
            free(root);
            return temp;
        } 
        else if((root->right_ptr) == NULL) 
        {
            node_t* temp = root->left_ptr;
            free(root);
            return temp;
        }

        node_t* temp = find_min(root->right_ptr);
        root->key = temp->key;
        root->value = temp->value;
        root->right_ptr = node_remove(root->right_ptr, temp->key);
    }

    return root;
}

void node_print(node_t* root) 
{
    if (root == NULL) 
        return;
    
    node_print(root->left_ptr);
    printf("%d: %d\n", root->key, root->value);
    node_print(root->right_ptr);
}

void node_delete(node_t* root) 
{
    if (root == NULL) 
        return;

    node_delete(root->left_ptr);
    node_delete(root->right_ptr);
    free(root);
}
