#ifndef _STACK_H_
#define _STACK_H_



class Stack    
{
   public:
        Stack(size_t size);
        ~Stack();
        
        bool isEmpty();
        void push(int value);
        int pop();
        int top();
        void print();

    private:
        size_t _size;
        size_t _top;
        int *_buffer;
};

#endif