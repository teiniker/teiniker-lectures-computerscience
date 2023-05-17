#ifndef _STACK_H_
#define _STACK_H_

struct Node 
{
    Node(int initialValue)
    {
        value = initialValue;
        next_ptr = NULL;
    }

    int value;
    Node *next_ptr;
};


class Stack    
{
   public:
        Stack();
        ~Stack();
        
        bool isEmpty();
        void push(int value);
        int pop();
        int top();
        void print();

    private:
        Node *first_ptr;
};

#endif /* _STACK_H_ */