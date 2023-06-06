#include <cstddef>
#include <cstdlib>
#include <cstdio>

#include "stack.h"

Stack::Stack(size_t size)
{
    _size = size;
    _top = 0;
    _buffer = new int[size];
}

Stack::~Stack()
{
    delete _buffer;
}

bool Stack::isEmpty()
{
     return _top == 0;
}

void Stack::push(int value)
{
    if(_top == _size-1)
        return;  
    
    _top++;
    _buffer[_top] = value;
}

int Stack::pop()
{
    if(isEmpty())
        return EXIT_FAILURE;

    int value = top();
    _top--;
    return value;
}

int Stack::top()
{
    if(isEmpty())
        return EXIT_FAILURE;

    return _buffer[_top];
}

void Stack::print()
{
    printf("-->[ ");
    for(size_t i = 0; i <= _top; i++)
    {
        printf("%d ", _buffer[i]);       
    }
    printf("]\n");
}