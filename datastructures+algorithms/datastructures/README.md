# Data Structures

Organizing the data for processing is an essential step in the development 
of a computer program. Once the choice has been made, the necessary algorithms 
are simple.

A **data structure** is not a passive object: We also must consider the 
**operations** to be performed on it (and the algorithms used for these 
operations).


## Elementary Data Structures

To create complex data structures we use the following building blocks: 
Array and Linked Lists.

### Arrays
Perhaps the most fundamental data structure is the array, which is defined 
as a primitive in C and in most other programming languages.

An array is a fixed collection of **same-type data** that are stored 
contiguously and that are **accessible by an index**.

* Example: [dynamic-array](array/dynamic-array/)

### Linked Lists

> A **linked list** is a set of items where each item is part of 
> a node that also contains a link to a node.

We define **nodes** in terms of references to nodes, so linked lists 
are sometimes referred to as **self-referent structures**.

The primary advantage of linked lists over arrays is that the links 
provide us with the capability to rearrange the items efficiently.

Normally, we think of linked lists as implementing a sequential 
arrangement of a set of items: 
* Starting at a given node, we consider its item to be first in 
    the sequence. 
* Then, we follow its link to another node, which gives us an item 
    that we consider to be second in the sequence, and so forth.

A linked list is either a **null link** or a link to a node that 
contains an item and a link to a linked list.

One of the most common operations that we perform on lists is to 
**traverse** them: We scan through the items on the list sequentially, 
performing some operation on each.

* Example: [single-linked-list](linked-list/single-linked-list/)


## Abstract Data Types

An **abstract data type (ADT)** is a data type (a set of values and a 
collection of operations on those values) that is accessed only through 
an **interface**. We refer to a program that uses an ADT as a **client**, 
and a program that specifies the data type as an **implementation**.


## Examples and Exercises

* **List**
    * [Introduction](list/README.md)
    * Example: [array-list (first version)](list/array-list-version1/)
    * Example: [array-list](list/array-list)

    * Example: [linked-list (first version)](list/linked-list-version1/)
    * Example: [linked-list (second version)](list/linked-list-version2/) 
    * Example: [linked-list](list/linked-list/)

    * Exercise: [double-linked-list](list/double-linked-list-exercise/) ([model solution](list/double-linked-list))

* **Stack**
    * [Introduction](stack/README.md)
    * Example: [array-stack](stack/array-stack/)
    * Exercise: [stack](stack/linked-stack-exercise) 
            ([model solution](stack/linked-stack))
            
* **Queue** 
    * [Introduction](queue/README.md)
    * Exercise: [linked-queue](queue/linked-queue-exercise) 
            ([model solution](queue/linked-queue))
    * Example: [circular-queue](queue/circular-queue/)        

* **Map**

    * **Hash Map**
        * Example: [hash-map](map/hash-map/)

    * **Recursion**
        * [Introduction](recursion/)
        * Example: [factorial](recursion/factorial/)
        * Exercise: [sum-of-integers](recursion/sum-of-integers-exercise/) 
                ([model solution](recursion/sum-of-integers))
        * Exercise: [linked-list](recursion/linked-list-exercise/) 
                ([model solution](recursion/linked-list))

    * **Binary Tree**
        * [Introduction](tree/README.md)
        * Example: [binary-tree (first version)](tree/binary-tree-version1/)
        * Example: [binary-tree](tree/binary-tree)
        * Exercise: [binary-tree-books](tree/binary-tree-books-exercise/) 
                ([model solution](tree/binary-tree-books))

    * **Tree Map**: 
        * Example: [tree-map](map/tree-map/)


## Implementation in Embedded Systems

Abstract data structures can often be implemented differently (see: **arrays vs. linked lists**).

* In **embedded systems with limited memory** (e.g., 8-bit Arduino AVR microcontrollers), 
    **array-based implementations** are primarily used.

* In **single-board computers** (e.g., Raspberry Pi), **dynamic memory implementations** can 
    be used without restrictions.


## Data Structure Libraries

Data structures are widely used and are available in various implementations 
as **open source libraries**.


### C Library: GLib 

GLib provides several data structures for general use, including dynamically 
sized arrays (`GArray`), balanced binary trees (`GTree`), hash tables 
(`GHashTable`), linked lists (`GList` for doubly-linked lists and `GSList` 
for singly-linked lists), queues (`GQueue`), and more. 

see: [c-advanced/modular-programming/libraries/glib](../../programming-c/c-advanced/modular-programming/libraries/glib/)


### C++ Standard Template Library (STL)

The C++ Standard Template Library (STL) is a powerful set of **C++ template classes** designed 
to provide general-purpose classes and functions with templates that implement many popular 
and commonly used data structures and algorithms.

see: [programmingc++/stl](../../programming-c++/stl/)


## References
* [YouTube (CS50): Data Structures Summary](https://youtu.be/3uGchQbk7g8)
* [YouTube (CS50): Data Structures](https://youtu.be/0euvEdPwQnQ?si=6P1fqGo5zsP9WsZu)

* Robert Sedgewick. **Algorithms in C, Parts 1-4: Fundamentals, Data Structures, Sorting, Searching**. Pearson Education, 1998 
    * Chapter 3: Elementary Data Structures
    * Chapter 4: Abstract Data Types
                 
*Egon Teiniker, 2020-2025, GPL v3.0*                       
