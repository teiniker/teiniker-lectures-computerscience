#ifndef _ARRAY_STACK_H_
#define _ARRAY_STACK_H_

#include <stdio.h>
#include <stdbool.h>


typedef struct  
{
    size_t dimension;
    int top;
    void **buffer;  // pointer to an array of void pointers
} stack_t;

extern stack_t *stack_new(size_t dimension);
extern void stack_delete(stack_t *stack);

extern bool stack_is_empty(stack_t *stack);
extern void stack_push(stack_t *stack, void *value);
extern void *stack_pop(stack_t *stack);
extern void *stack_top(stack_t *stack);

#endif /* _ARRAY_STACK_H_ */