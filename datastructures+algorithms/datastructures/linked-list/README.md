# Linked-Lists

A linked list is a **linear data structure** composed of nodes, where 
each node contains two parts:

* **Data**: Holds the actual information.

* **Pointer**: Stores the memory address of the next node.

_Example:_ Node of a linked list.

```C
typedef struct node
{
    int value;
    struct node *next_ptr;
} node_t;
```

Unlike arrays, **linked lists don't store data in contiguous memory 
locations**. Instead, they **link individual nodes using pointers**. 
This allows linked lists to grow or shrink dynamically.

_Example:_ Create a new node in memory. 
```C
node_t *new_node(int value)
{
    node_t *node_ptr = (node_t *)malloc(sizeof(node_t));
    node_ptr->value = value;
    node_ptr->next_ptr = NULL;
    return node_ptr;
}
```

_Example:_ Linke nodes together. 
```C
    node_t *first_ptr;
    first_ptr = new_node(1);
    first_ptr->next_ptr = new_node(2);
    first_ptr->next_ptr->next_ptr = new_node(3);
```

_Example:_ Remove nodes from memory. 
```C
    free(first_ptr->next_ptr->next_ptr);
    free(first_ptr->next_ptr);
    free(first_ptr);
```

Common types of Linked Lists are:

* **Singly Linked List**: Nodes point in one direction (forward).

* **Doubly Linked List**: Nodes point in both directions (forward and backward).

* **Circular Linked List**: Last node points back to the first node.


## References

* [CS50 - Singly-Linked Lists](https://youtu.be/zQI3FyWm144)

*Egon Teiniker, 2020-2025, GPL v3.0*  
