#include <cstddef>
#include <cstdlib>
#include <cstdio>

#include "stack.h"

Stack::Stack()
{
    first_ptr = NULL;
}

Stack::~Stack()
{
    while(!isEmpty())
        pop();
}

bool Stack::isEmpty()
{
    return first_ptr == NULL;
}

void Stack::push(int value)
{
    Node *ptr = new Node(value);
    ptr->next_ptr = first_ptr;
    first_ptr = ptr;   
}

int Stack::pop()
{
    Node *ptr = first_ptr;
    int value = ptr->value;
    first_ptr = ptr->next_ptr;
    delete ptr;
    return value;
}

int Stack::top()
{
    return first_ptr->value;
}

void Stack::print()
{
    printf("first_ptr -->[ ");
    for(Node *ptr = first_ptr; ptr != NULL; ptr = ptr->next_ptr)
    {
        printf("%d ", ptr->value);       
    }
    printf("]\n");
}