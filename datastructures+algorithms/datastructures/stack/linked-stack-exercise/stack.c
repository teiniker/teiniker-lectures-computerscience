#include <stdlib.h>

#include "stack.h"

node_t *node_new(int value)
{
    node_t *node = malloc(sizeof(node_t));
    node->value = value;
    node->next_ptr = NULL;
    return node;
}

stack_t *stack_new()
{
    stack_t *stack = malloc(sizeof(stack_t));
    stack->first_ptr = NULL;
    return stack;
}

void stack_delete(stack_t *stack)
{
    // TODO
}

bool stack_is_empty(stack_t *stack)
{
    // TODO
    return false;

}

void stack_push(stack_t *stack, int value)
{
    // TODO
}

int stack_pop(stack_t *stack)
{
    // TODO
    return 0;
}

int stack_top(stack_t *stack)
{
    // TODO
    return 0;
}

void stack_print(stack_t *stack)
{
    printf("-->[ ");
    for(node_t *ptr = stack->first_ptr; ptr != NULL; ptr = ptr->next_ptr)
    {
        printf("%d ", ptr->value);       
    }
    printf("]\n");
}
