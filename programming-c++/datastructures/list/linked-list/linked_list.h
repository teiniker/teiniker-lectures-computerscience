#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

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


class LinkedList    
{
   public:
        LinkedList();
        ~LinkedList();
        
        size_t size();
        int get(int index);
        int find(int value);
        void append(int value);
       
        void print();

    private:
        Node *first_ptr;
};

#endif 