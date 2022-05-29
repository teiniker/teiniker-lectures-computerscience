#include <stdlib.h>

#include "linked_list.h"

node_t *node_new(int value)
{
    node_t *node = malloc(sizeof(node_t));
    node->value = value;
    node->next_ptr = NULL;
    return node;
}

size_t list_size(node_t *first_ptr)
{
    // TODO
    return 0;
}

node_t* list_append(node_t *first_ptr, int value)
{
    // TODO:
    return NULL;
}

void list_print(node_t *first_ptr)
{
    // TODO:
}

void list_delete(node_t *first_ptr)
{
    // TODO:
}
