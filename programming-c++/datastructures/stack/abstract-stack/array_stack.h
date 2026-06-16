#ifndef _ARRAY_STACK_H_
#define _ARRAY_STACK_H_

#include <cstddef>

#include "stack.h"


class ArrayStack : public Stack
{
    public:
        ArrayStack(size_t size);
        ~ArrayStack();

        bool isEmpty();
        void push(int value);
        int pop();
        int top();
        void print();

    private:
        size_t _size;
        int    _top;
        int   *_buffer;
};

#endif /* _ARRAY_STACK_H_ */
