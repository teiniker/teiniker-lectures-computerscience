# std::list

`std::list` is a container that supports constant time insertion and removal 
of elements from anywhere in the container. 

Fast random access is not supported. 

It is usually implemented as a **doubly-linked list**.

* **Dynamic Size**: The size of `std::list` can change dynamically, and 
    efficiently handles frequent insertions and deletions of elements at 
    any point within the sequence.

* **Non-Contiguous Memory**: Unlike `std::vector` or `arrays`, `std::list` 
    does not store elements in contiguous memory locations. Each element 
    is linked to the next and previous elements, allowing efficient insertion 
    and removal without the need to reallocate or move other elements.

* **Bidirectional Iteration**: `std::list supports bidirectional iterators, 
    which means we can traverse the list in both forward and reverse directions.

* **Performance Considerations**: Accessing elements directly by position is 
    inefficient compared to `std::vector` or `std::deque`, as it requires 
    traversing the list from the beginning up to that position. 

    However, insertions and deletions are generally faster, especially in the 
    middle of the list, since they only involve changing a few pointer connections 
    without shifting elements.

Common Operations:

* **Insertion and Deletion**: We can insert or delete elements at any position in 
    the list without invalidating pointers, references, and iterators to other 
    elements (except those pointing to the element being removed).
* **Sorting and Merging**: `std::list` provides special member functions to sort 
    `sort()` and merge `merge()` lists. These operations are optimized for linked 
    lists and can be more efficient than equivalent operations on other sequence 
    containers.
* **Reverse**: Reversing the elements of a list can be done in linear time using 
    the `reverse()` member function, which is efficient due to the nature of linked 
    lists.
* **Splice**: The `splice()` operation is used to transfer elements from one list 
    to another without moving the actual data, but by simply rearranging the pointers. 
    This makes moving sections between lists very fast.

When to Use `std::list`: 
* `std::list` is particularly useful when we need constant time insertions 
    and deletions from any point in the list and do not require frequent direct 
    access to elements by their position. 

* It's ideal for situations where the container might be frequently reorganized, 
    such as in certain types of scheduling algorithms or when maintaining lists 
    of items with complex relational positioning requirements.


## References

* [C++ Reference: list](https://en.cppreference.com/w/cpp/container/list)


*Egon Teiniker, 2020-2024, GPL v3.0*
