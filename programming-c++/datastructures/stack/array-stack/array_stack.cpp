#include <cstddef>
#include <cstdlib>
#include <cstdio>

#include "array_stack.h"

ArrayStack::ArrayStack(size_t size)
{
    _size = size;
    _top = 0;
    _buffer = new int[size];
}

ArrayStack::~ArrayStack()
{
    delete[] _buffer;
}

bool ArrayStack::isEmpty()
{
    return _top == 0;
}

void ArrayStack::push(int value)
{
    if (_top == _size - 1)
        return;

    _top++;
    _buffer[_top] = value;
}

int ArrayStack::pop()
{
    if (isEmpty())
        return EXIT_FAILURE;

    int value = top();
    _top--;
    return value;
}

int ArrayStack::top()
{
    if (isEmpty())
        return EXIT_FAILURE;

    return _buffer[_top];
}

void ArrayStack::print()
{
    printf("-->[ ");
    for (size_t i = 1; i <= _top; i++)
    {
        printf("%d ", _buffer[i]);
    }
    printf("]\n");
}
