# std::vector

`std::vector` is a sequence container that encapsulates **dynamic size arrays**.

The **elements are stored contiguously**, which means that elements can be accessed 
not only through iterators, but also using offsets to regular pointers to elements. 

The storage of the vector is handled automatically, being expanded as needed. 

Vectors usually occupy more space than static arrays, because more memory is allocated 
to handle future growth. This way a vector does not need to reallocate each time an 
element is inserted, but only when the additional memory is exhausted. 
The total amount of allocated memory can be queried using `capacity()` function.

Reallocations are usually costly operations in terms of performance. 
The `reserve()` function can be used to eliminate reallocations if the number of 
elements is known beforehand.

The complexity (efficiency) of common operations on vectors is as follows:
* Random access - constant O(1)
* Insertion or removal of elements at the end - amortized constant O(1)
* Insertion or removal of elements - linear in the distance to the end of the vector O(n)



## References

* [C++ Reference: vector](https://en.cppreference.com/w/cpp/container/vector)


*Egon Teiniker, 2020-2025, GPL v3.0*
