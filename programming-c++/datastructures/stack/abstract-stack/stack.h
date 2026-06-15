#ifndef _STACK_H_
#define _STACK_H_

#include <cstddef>


class Stack
{
    public:
        virtual ~Stack() {}

        virtual bool isEmpty() = 0;
        virtual void push(int value) = 0;
        virtual int pop() = 0;
        virtual int top() = 0;
        virtual void print() = 0;
};

#endif /* _STACK_H_ */
