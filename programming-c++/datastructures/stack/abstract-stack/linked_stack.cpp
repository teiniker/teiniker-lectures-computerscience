#include <cstddef>
#include <cstdio>

#include "linked_stack.h"

LinkedStack::LinkedStack()
{
    first_ptr = NULL;
}

LinkedStack::~LinkedStack()
{
    while (!isEmpty())
        pop();
}

bool LinkedStack::isEmpty()
{
    return first_ptr == NULL;
}

void LinkedStack::push(int value)
{
    Node *ptr = new Node(value);
    ptr->next_ptr = first_ptr;
    first_ptr = ptr;
}

int LinkedStack::pop()
{
    Node *ptr = first_ptr;
    int value = ptr->value;
    first_ptr = ptr->next_ptr;
    delete ptr;
    return value;
}

int LinkedStack::top()
{
    return first_ptr->value;
}

void LinkedStack::print()
{
    printf("LinkedStack -->[ ");
    for (Node *ptr = first_ptr; ptr != NULL; ptr = ptr->next_ptr)
    {
        printf("%d ", ptr->value);
    }
    printf("]\n");
}
