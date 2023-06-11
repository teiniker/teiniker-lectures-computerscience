# std::stack

The `std::stack` class is a container adaptor that gives the programmer 
the functionality of a stack - specifically, a **LIFO (last-in, first-out)** 
data structure.

The class template acts as a wrapper to the underlying container - only 
a specific set of functions is provided. The stack pushes and pops the element 
from the back of the underlying container, known as the top of the stack.




The `std::stack` container adapter in C++ does not provide a direct way to 
iterate over its elements because it is designed to provide only LIFO 
(Last In, First Out) access to its elements, which means you can 
**only directly access the top element** of the stack.


## References

* [C++ Reference: stack](https://en.cppreference.com/w/cpp/container/stack)


*Egon Teiniker, 2020-2023, GPL v3.0*