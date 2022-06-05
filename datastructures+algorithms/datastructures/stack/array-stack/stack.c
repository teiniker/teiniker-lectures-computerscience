#include <stdlib.h>

#include "stack.h"

stack_t *stack_new(size_t size)
{
    stack_t *stack = malloc(sizeof(stack_t));
    stack->size = size;
    stack->top = 0;
    stack->buffer = calloc(size, sizeof(int));
    return stack;
}

void stack_delete(stack_t *stack)
{
    free(stack->buffer);
    free(stack);
}

bool stack_is_empty(stack_t *stack)
{
    return stack->top == 0;

}

bool stack_is_full(stack_t *stack)
{
    return stack->top >= stack->size;
}

void stack_push(stack_t *stack, int value)
{
    if(stack_is_full(stack))
        return;    // stack is full
    
    stack->buffer[stack->top] = value;
    stack->top++;    
}

int stack_top(stack_t *stack)
{
    if(stack_is_empty(stack))
        return EXIT_FAILURE;

    return stack->buffer[stack->top - 1];
}

int stack_pop(stack_t *stack)
{
    if(stack_is_empty(stack))
        return EXIT_FAILURE;

    int value = stack_top(stack);
    stack->top--;
    return value;
}

void stack_print(stack_t *stack)
{
    printf("-->[ ");
    for(int i=0; i < stack->top; i++)
    {
        printf("%d ", stack->buffer[i]);       
    }
    printf("]\n");
}
