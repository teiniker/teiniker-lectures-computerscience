#include <stdlib.h>

#include "stack.h"

stack_t *stack_new(size_t dimension)
{
    stack_t *stack = (stack_t*)malloc(sizeof(stack_t));
    stack->dimension = dimension;
    stack->top = -1;
    stack->buffer = (void**)calloc(dimension, sizeof(void*));
    return stack;
}

void stack_delete(stack_t *stack)
{
    free(stack->buffer);
    free(stack);
}

bool stack_is_empty(stack_t *stack)
{
    return stack->top == -1;

}

bool stack_is_full(stack_t *stack)
{
    return stack->top == (int)(stack->dimension - 1);
}

void stack_push(stack_t *stack, void *value)
{
    if(stack_is_full(stack))
        return;         // stack is full
    
    stack->top++;
    stack->buffer[stack->top] = value;
}

void *stack_top(stack_t *stack)
{
    if(stack_is_empty(stack))
        return NULL;    // stack is empty

    return stack->buffer[stack->top];
}

void *stack_pop(stack_t *stack)
{
    if(stack_is_empty(stack))
        return NULL;    // stack is empty

    void *value = stack_top(stack);
    stack->top--;
    return value;
}

