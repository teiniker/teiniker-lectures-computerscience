#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node
{
    int value;  
    struct node *next_ptr;  
} node_t;

node_t *node_new(const int value);
void list_print(node_t *first_ptr);
node_t *list_append(node_t *first_ptr, const int value);
int list_size(node_t *first_ptr);
int list_get(node_t *first_ptr, const int index);
void list_update(node_t *first_ptr, const int index, const int value);
void list_delete(node_t *first_ptr);


int main(void)
{
    // Setup
    // -->[3]-->[7]-->[9]-->[NULL]
    node_t *first_ptr = NULL;
    first_ptr = list_append(first_ptr, 3);
    first_ptr = list_append(first_ptr, 7);
    first_ptr = list_append(first_ptr, 9);
    list_print(first_ptr);

    // Test number of nodes 
    assert(3 == list_size(first_ptr));

    // Test get node 
    assert(3 == list_get(first_ptr, 0));
    assert(7 == list_get(first_ptr, 1));
    assert(9 == list_get(first_ptr, 2));

    // Test update node
    list_update(first_ptr, 0, 100);
    assert(100 == list_get(first_ptr, 0));
    list_update(first_ptr, 1, 200);
    assert(200 == list_get(first_ptr, 1));
    list_update(first_ptr, 2, 300);
    assert(300 == list_get(first_ptr, 2));
    list_print(first_ptr);

    // Teardown
    list_delete(first_ptr);

    return 0;
}

node_t *node_new(const int value)
{
    node_t *ptr = malloc(sizeof(node_t));
    ptr->value = value;
    ptr->next_ptr = NULL;
    return ptr;
}

int list_size(node_t *first_ptr)
{
    int number = 0;
    for(node_t *ptr=first_ptr; ptr != NULL; ptr = ptr->next_ptr)
    {
        number++;
    }
    return number;
}

void list_print(node_t *first_ptr)
{
    printf("[ ");
    node_t *ptr = first_ptr;
    while(ptr != NULL)
    {
        printf("%d ", ptr->value);
        ptr = ptr->next_ptr;
    }
    printf("]\n");
}


int list_get(node_t *first_ptr, const int index)
{
    int i = 0;
    for(node_t *ptr=first_ptr; ptr != NULL; ptr = ptr->next_ptr)
    {
        if(i == index)
            return ptr->value;
        i++;
    }
    return 0;   // index out of range
}

void list_update(node_t *first_ptr, const int index, const int value)
{
    int i = 0;
    for(node_t *ptr=first_ptr; ptr != NULL; ptr = ptr->next_ptr)
    {
        if(i == index)
        {
            ptr->value = value;
            return;
        }
        i++;
    }
}


node_t *list_append(node_t *first_ptr, const int value)
{
    if(first_ptr == NULL)
    {
        first_ptr =  node_new(value);
        return first_ptr;
    }

    node_t *ptr = first_ptr;
    while(ptr->next_ptr != NULL)
    {
        ptr = ptr->next_ptr;
    }
    ptr->next_ptr = node_new(value);
    return first_ptr;
}

void list_delete(node_t *first_ptr)
{
    if(first_ptr == NULL)
        return;

    while(first_ptr->next_ptr != NULL)
    {
        node_t *ptr = first_ptr;
        first_ptr = first_ptr->next_ptr;
        free(ptr);
    } 
    free(first_ptr);     
}
