# Datastructure: List 

A list is a **linear data structure** that stores a collection of
elements. Lists can be implemented using arrays or linked lists.

## List Operations
The following operations are commonly performed on lists:

* **Checking Size**: Finding out how many elements the list currently holds.

* **Insertion**: Adding a new element into the list.
    - Insert at beginning: Add an element at the start.
    - Insert at end: Append an element at the end.
    - Insert at position: Insert an element at a specific position.

* **Deletion**: Removing an existing element from the list.
    - Delete at beginning: Remove the first element.
    - Delete at end: Remove the last element.
    - Delete by position: Remove an element at a particular index.
    - Delete by value: Remove an element matching a particular value.

* **Access**: Retrieving an element.
    - Retrieving an element by its position (index).

* **Traversal**: Visiting each element of the list sequentially 
    (often for printing, searching, or processing).

* **Search**: Finding an element within the list.

* **Update**: Changing the value of an existing element at 
    a given position.

* **Reversal**: Reversing the order of elements in the list.


## Linked Lists
A linked list is a **linear data structure** composed of nodes, where 
each node contains two parts:

* **Data**: Holds the actual information.

* **Pointer**: Stores the memory address of the next node.

Unlike arrays, **linked lists don't store data in contiguous memory 
locations**. Instead, they **link individual nodes using pointers**. 
This allows linked lists to grow or shrink dynamically.

Common types of Linked Lists are:

* **Singly Linked List**: Nodes point in one direction (forward).

* **Doubly Linked List**: Nodes point in both directions (forward and backward).

* **Circular Linked List**: Last node points back to the first node.


## Array List 

Note that these operaions can also be implemented using an **array-based list**.

A list implemented using an array cannot grow as easily as a linked list.
Inserting and deleting elements is also more complex because elements have 
to be copied. However, accessing the i-th element is very efficient.

**Complexity (Big-O notation) of List Operations**:

|Operation | Array-based Lists | Linked Lists |
|----------|-------------------|--------------|
|Insertion | O(n) | O(1) (if position known)|
|Deletion | O(n) | O(1) (if position known)|
|Access | O(1) (random access) | O(n) (sequential access only)|
|Search | O(n), O(log n) if sorted | O(n)|
|Traversal | O(n) | O(n)|
|Update | O(1) | O(n) (sequentially finding first) |


## References

* [CS50 - Singly-Linked Lists](https://youtu.be/zQI3FyWm144)

*Egon Teiniker, 2020-2025, GPL v3.0*  
