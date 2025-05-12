# Standard Template Library (STL) 

The C++ Standard Template Library (STL) is a powerful set of C++ template classes 
designed to provide general-purpose classes and functions with templates that 
implement many popular and commonly used data structures and algorithms.

The STL provides implementations of commonly used data structures.


## Containers
These are data structures that store objects and data. STL containers can be 
divided into several categories:

* **Sequence Containers**: Maintain the order of elements.
    - **vector**: Dynamic array (like an array that can resize).
    - **deque**: Double-ended queue; efficient insertions/removals at both ends.
    - **list**: Doubly-linked list; fast insertions/removals anywhere.

    - _Examples:_
        * [array](array/)
        * [vector](vector/)
        * [list](list/)

* **Associative Containers**: Automatically sort elements and provide fast 
    retrieval using keys.
    - **set**: Stores unique elements in sorted order.
    - **multiset**: Allows duplicate elements in sorted order.
    - **map**: Key-value pairs with unique keys, sorted by key.
    - **multimap**: Key-value pairs with duplicate keys allowed.

    - _Examples:_
        * [map](map/)


* **Unordered Associative Containers**: Use hash tables for faster average 
    access times (no sorting).
    - **unordered_set**: Stores unique elements in no particular order.
    - **unordered_multiset**: Allows duplicate elements in no particular order.
    - **unordered_map**: Key-value pairs with unique keys, no particular order.
    - **unordered_multimap**: Key-value pairs with duplicate keys allowed, no particular order.

    - _Examples:_
        * [unordered_map](unordered_map/)


* **Container Adapters**: Provide restricted interfaces based on existing containers.
    - **stack**: LIFO (Last In, First Out).
    - **queue**: FIFO (First In, First Out).
    - **priority_queue**: A heap-based structure for accessing the highest priority element.

    - _Examples:_
        * [stack](stack/)
        * [queue](queue/)



## Iterators
Provide a generic way to access container elements.

* Act like pointers to traverse containers.
* Types: `input_iterator`, `output_iterator`, `forward_iterator`, `bidirectional_iterator`, 
    `random_access_iterator`.


## Algorithms
Operate on containers via iterators.

* _Examples:_ `sort()`, `find()`, `binary_search()`, `reverse()`, `accumulate()` 
    (from `<numeric>`), etc.

* These are **generic algorithms** that work on any container using iterators.


##  Function Objects (Functors)

Objects that can be called as if they were functions. 
Often used for custom sorting or filtering.



## References 

* [Containers library](https://en.cppreference.com/w/cpp/container)
* [Iterator library](https://en.cppreference.com/w/cpp/iterator)
* [Algorithms library](https://en.cppreference.com/w/cpp/algorithm)

*  David R. Musser, Atul Saini. **STL Tutorial & Reference Guide: C++ Programming With the Standard Template Library**. Addison-Wesley, 2nd edition, 2001.

*Egon Teiniker, 2020-2025, GPL v3.0*