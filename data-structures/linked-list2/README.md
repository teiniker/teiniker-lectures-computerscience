# Pointers to Pointers

The concept of "pointers to pointers" pops up frequently in the context of linked 
data structures.
In particular, when an argument to a function is a pointer variable, and we want the 
function to be able to modify the variable by making it point to somewhere else.

**Pointers, like all arguments are passed by value**.

To solve this problem, we use of a pointer to a pointer as function argument.

_Example_: Insert into a linked list
```C
void list_insert(node_t **list, int index, int value)
{
    node_t *node = node_new(value);

    if(index == 0)
    {
        node->next_ptr = *list;
        *list = node; 
        return;
    }
    
    node_t *ptr = *list;
    for(int i=0; i<index-1; i++)
    {
        if(ptr != NULL)
            ptr = ptr->next_ptr;
    }    
    node->next_ptr = ptr->next_ptr;
    ptr->next_ptr = node;
}
```
If we insert a node at the first position (`index==0`), the function has to
modify the list pointer itself.
Thus, we pass a pointer to the `list` pointer. 

When we define an **API for a data structure**, we try to uniform the usage of
functions, thus, we generally use the argument `node_t **list`.

## References
* K. N. King. **C Programming, A Modern Approach.** W. W. Norton & Company, inc. 2nd Edition 2008. 
  Chapter 17.6: Pointers to Pointers
      
 
*Egon Teiniker, 2020, GPL v3.0* 