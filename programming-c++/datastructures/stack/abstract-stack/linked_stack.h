#ifndef _LINKED_STACK_H_
#define _LINKED_STACK_H_

#include "stack.h"


struct Node
{
    Node(int initialValue)
    {
        value = initialValue;
        next_ptr = NULL;
    }

    int   value;
    Node *next_ptr;
};


class LinkedStack : public Stack
{
    public:
        LinkedStack();
        ~LinkedStack();

        bool isEmpty();
        void push(int value);
        int pop();
        int top();
        void print();

    private:
        Node *first_ptr;
};

#endif /* _LINKED_STACK_H_ */
