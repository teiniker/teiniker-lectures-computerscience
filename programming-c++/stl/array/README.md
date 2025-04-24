# sdt::array

The `std::array` container in C++ STL is a wrapper around a static array, 
providing the benefits of STL containers (like iterators, size checks, 
etc.) while maintaining the performance and memory layout of built-in arrays.

* `std::array` is a **modern, safe** replacement for raw C-style arrays.

* `std::array` has **fixed size**, unlike `std::vector`.

* The size is part of the type.

    _Example_: `std::array<int, 3>` is a **different type** from `std::array<int, 5>`.

* Elements are stored **contiguously**, so it's compatible with C-style APIs.


## Common Member Functions

| Function             | Description                           |
|----------------------|---------------------------------------|
| `arr.size()`         | Returns the number of elements.       |
| `arr.empty()`            | Checks whether the container is empty. | 
| `arr[i]`             | Access element at index `i` (no check). |
| `arr.at(i)`          | Returns element at index `i` with bounds checking. |
| `arr.front()`        | First element.                        |
| `arr.back()`         | Last element.                         |
| `arr.fill(value)`    | Sets all elements to `value`.         |
| `arr.data()`         | Returns pointer to the raw array.     |
| `begin(), end()`     | Iterators to start and end.           |

`array` also supports equality operators (`==`, `!=`) and other comparisons.


## References

* [C++ Reference: array](https://en.cppreference.com/w/cpp/container/array)

*Egon Teiniker, 2020-2025, GPL v3.0*