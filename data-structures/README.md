# Data Structures

Organizing the data for processing is an essential step in the development of a computer program. 
Once the choice has been made, the necessary algorithms are simple.

**A data type is a set of values and a collection of operations on those values**.

A data structure is not a passive object: We also must consider the operations to be performed on it 
(and the algorithms used for these operations).

## Arrays
Perhaps the most fundamental data structure is the array, which is defined as a primitive in C and in most other
programming languages.

An array is a fixed collection of **same-type data** that are stored contiguously and that 
are **accessible by an index**.

## Linked Lists

**A linked list is a set of items where each item is part of a node that also contains a link to a node.**

We define **nodes** in terms of references to nodes, so linked lists are sometimes referred to as 
**self-referent structures**.

The primary advantage of linked lists over arrays is that the links provide us with the capability to rearrange 
the items efficiently.

Normally, we think of linked lists as implementing a sequential arrangement of a set of items: 
* Starting at a given node, we consider its item to be first in the sequence. 
* Then, we follow its link to another node, which gives us an item that we consider to be second in the 
    sequence, and so forth.

A linked list is either a **null link** or a link to a node that contains an item and a link to a linked list.

One of the most common operations that we perform on lists is to **traverse** them: We scan through the items 
on the list sequentially, performing some operation on each.


# Abstract Data Types
An **abstract data type (ADT)** is a data type (a set of values and a collection of operations on those values) 
that is accessed only through an **interface**. We refer to a program that uses an ADT as a **client**, and a 
program that specifies the data type as an **implementation**.


## Examples

* **Linked List**
    * Demo: [linked-list](https://github.com/teiniker/teiniker-lectures-computerscience/tree/master/data-structures/list/linked-list)
    * Demo: [linked-list (pointers-to-pointers](https://github.com/teiniker/teiniker-lectures-computerscience/tree/master/data-structures/list/linked-list2)
    * Demo: [linked-list (API structure)](https://github.com/teiniker/teiniker-lectures-computerscience/tree/master/data-structures/list/linked-list3)

* **Stack**
    * Exercise: [stack](https://github.com/teiniker/teiniker-lectures-computerscience/tree/master/data-structures/stack/linked-stack-exercise) 
            ([model solution](https://github.com/teiniker/teiniker-lectures-computerscience/tree/master/data-structures/stack/linked-stack))
            
* **Queue** 
    * Exercise: [linked-queue](https://github.com/teiniker/teiniker-lectures-computerscience/tree/master/data-structures/queue/linked-queue-exercise) 
            ([model solution](https://github.com/teiniker/teiniker-lectures-computerscience/tree/master/data-structures/queue/linked-queue))

* **Binary Tree**
    * Demo: [binary-tree](https://github.com/teiniker/teiniker-lectures-computerscience/tree/master/data-structures/tree/binary-tree)
    * Demo: [binary-search-tree](https://github.com/teiniker/teiniker-lectures-computerscience/tree/master/data-structures/tree/binary-search-tree)
    * Demo: [binary-search-tree (comparison function)](https://github.com/teiniker/teiniker-lectures-computerscience/tree/master/data-structures/tree/binary-search-tree2)
    * Exercise: [binary-search-tree-students](https://github.com/teiniker/teiniker-lectures-computerscience/tree/master/data-structures/tree/binary-search-tree-students-exercise) 
        ([model solution](https://github.com/teiniker/teiniker-lectures-computerscience/tree/master/data-structures/tree/binary-search-tree-students))

## References
* Robert Sedgewick. **Algorithms in C, Parts 1-4: Fundamentals, Data Structures, Sorting, Searching**. 
    Pearson Education, 1998 
    * Chapter 3: Elementary Data Structures
    * Chapter 4: Abstract Data Types
                 
                 
