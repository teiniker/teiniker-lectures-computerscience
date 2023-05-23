#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next_ptr;
} node_t;

node_t *new_node(int value)
{
    node_t *node_ptr = malloc(sizeof(node_t));
    node_ptr->value = value;
    node_ptr->next_ptr = NULL;
    return node_ptr;
}

int main()
{
    // setup linked list
    node_t *first_ptr;
    first_ptr = new_node(1);
    first_ptr->next_ptr = new_node(2);
    first_ptr->next_ptr->next_ptr = new_node(3);

    // navigate
    node_t *tmp = first_ptr;
    while(tmp != NULL)
    {
        printf("%d \n", tmp->value);
        tmp = tmp->next_ptr;
    }

    // teardown list
    free(first_ptr->next_ptr->next_ptr);
    free(first_ptr->next_ptr);
    free(first_ptr);

    return EXIT_SUCCESS;
}
