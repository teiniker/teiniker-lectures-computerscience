#include "tree_map.h"
#include <stdlib.h>

// Private functions (forward declarations)

node_t* node_put(node_t* root, int key, int value);
int node_get(node_t* root, int key);
bool node_contains(node_t* root, int key);
node_t* node_remove(node_t* root, int key);
void node_print(node_t* root);
void node_delete(node_t* root);


table_t* table_new(void) 
{
    table_t* table = (table_t*)malloc(sizeof(table_t));
    table->tree = NULL;
    return table;
}

void table_delete(table_t* table) 
{
    if (table == NULL) 
        return;
    node_delete(table->tree);
    free(table);
}

void table_put(table_t* table, int key, int value) 
{
    if (table == NULL) 
    {
        table = table_new();
    }
    table->tree = node_put(table->tree, key, value);
}

int table_get(table_t* table, int key) 
{
    if (table==NULL || table->tree == NULL) 
    {
        fprintf(stderr, "Key not found\n");
        exit(EXIT_FAILURE);
    }
    return node_get(table->tree, key);
}

bool contains_key(table_t* table, int key) 
{
    if (table == NULL || table->tree == NULL) 
        return false;
    return node_contains(table->tree, key);
}

void table_remove(table_t* table, int key) 
{
    if (table==NULL || table->tree == NULL) 
        return;
    table->tree = node_remove(table->tree, key);
}

void table_print(table_t* table) 
{
    if (table == NULL || table->tree == NULL) 
        return;
    node_print(table->tree);
}


// Private functions

node_t* node_put(node_t* root, int key, int value) 
{
    if(root == NULL) 
    {
        node_t* node = (node_t*)malloc(sizeof(node_t));
        node->key = key;
        node->value = value;
        node->left_ptr = node->right_ptr = NULL;
        return node;
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
