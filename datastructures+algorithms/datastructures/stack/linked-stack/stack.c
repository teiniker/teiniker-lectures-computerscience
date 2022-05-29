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
    while(!stack_is_empty(stack))
        stack_pop(stack);
    free(stack);
}

bool stack_is_empty(stack_t *stack)
{
    return (stack->first_ptr == NULL);

}

void stack_push(stack_t *stack, int value)
{
    node_t *ptr = node_new(value);
    ptr->next_ptr = stack->first_ptr;
    stack->first_ptr = ptr;   
}

int stack_pop(stack_t *stack)
{
    node_t *ptr = stack->first_ptr;
    int value = ptr->value;
    stack->first_ptr = ptr->next_ptr;
    free(ptr);
    return value;
}

int stack_top(stack_t *stack)
{
    return stack->first_ptr->value;
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
