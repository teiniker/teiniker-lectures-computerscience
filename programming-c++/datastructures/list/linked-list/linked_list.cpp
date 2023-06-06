#include <cstddef>
#include <cstdlib>
#include <cstdio>

#include "linked_list.h"


LinkedList::LinkedList()
{
    first_ptr = NULL;
}

LinkedList::~LinkedList()
{
    Node *ptr = first_ptr;
    while(ptr->next_ptr != NULL)
    {
        Node *rm = ptr;
        ptr = ptr->next_ptr;
        delete(rm);
    }
    delete(ptr);
}


size_t LinkedList::size()
{
    size_t size=0;
    Node *ptr = first_ptr;   
    while(ptr != NULL)
    {
        ptr = ptr->next_ptr;
        size++;
    }   
    return size;
}


int LinkedList::get(int index)
{
    Node *ptr = first_ptr;    
    for(int i=0; i<index; i++)
    {
        ptr = ptr->next_ptr;
    }
    return ptr->value;
}


int LinkedList::find(int value)
{
    Node *ptr = first_ptr;
    int index = 0;
    while(ptr != NULL)
    {
        if(ptr->value == value)
            return index;
        index++;    
        ptr = ptr->next_ptr;    
    }
    return -1; // not found
}


void LinkedList::append(int value)
{
    if(first_ptr == NULL)
    {
        first_ptr =  new Node(value);
    }
    else
    {    
        Node *ptr = first_ptr;
        while(ptr->next_ptr != NULL)
        {
            ptr = ptr->next_ptr;
        }
        ptr->next_ptr = new Node(value);
    }
}
       
void LinkedList::print()
{
    printf("[ ");
    for(Node *ptr = first_ptr; ptr != NULL; ptr = ptr->next_ptr)
    {
        printf("%d ", ptr->value);       
    }
    printf("]\n");
}
