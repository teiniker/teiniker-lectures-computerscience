#ifndef _ARRAY_STACK_H_
#define _ARRAY_STACK_H_

#include <cstddef>


class ArrayStack
{
    public:
        ArrayStack(size_t size);
        ~ArrayStack();

        bool isEmpty();
        void push(int value);
        int  pop();
        int  top();
        void print();

    private:
        size_t  _size;
        size_t  _top;
        int    *_buffer;
};

#endif /* _ARRAY_STACK_H_ */
