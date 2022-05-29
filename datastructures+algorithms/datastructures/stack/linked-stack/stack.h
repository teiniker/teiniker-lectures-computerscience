#ifndef _LINKED_STACK_H_
#define _LINKED_STACK_H_

#include <stdio.h>
#include <stdbool.h>

typedef struct node 
{
    int value;
    struct node *next_ptr;
} node_t;

typedef struct  
{
    node_t *first_ptr;
} stack_t;

extern stack_t *stack_new();
extern void stack_delete(stack_t *stack);

extern bool stack_is_empty(stack_t *stack);
extern void stack_push(stack_t *stack, int value);
extern int stack_pop(stack_t *stack);
extern int stack_top(stack_t *stack);

extern void stack_print(stack_t *stack);

#endif /* _LINKED_STACK_H_ */