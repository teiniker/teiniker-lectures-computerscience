#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <stdlib.h>

typedef struct _node
{
    int value;
    struct _node *next_ptr;
} node;


node *new_node(int value)
{
    node *node_ptr = malloc(sizeof(node));
    node_ptr->value = value;
    node_ptr->next_ptr = NULL;
    return node_ptr;
}

int main()
{
    // setup linked list
    node *list_ptr;
    list_ptr = new_node(1);
    list_ptr->next_ptr = new_node(2);
    list_ptr->next_ptr->next_ptr = new_node(3);

    // navigate
    printf("1st node = %d\n", list_ptr->value);
    printf("2nd node = %d\n", list_ptr->next_ptr->value);
    printf("3th node = %d\n", list_ptr->next_ptr->next_ptr->value);
    
    free(list_ptr->next_ptr->next_ptr);
    free(list_ptr->next_ptr);
    free(list_ptr);

    return 0;
}

