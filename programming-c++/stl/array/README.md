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


## Sorting

`std::array` has no `sort()` member function. Sorting is done with the
free function `std::sort()` from `<algorithm>`, which operates on any
range defined by two random-access iterators.

### Sorting the whole array

The member functions `begin()` and `end()` return iterators to the first
element and one past the last element, defining the full range:

```cpp
#include <algorithm>

std::array<int, 5> a = {30, 10, 50, 20, 40};
std::sort(a.begin(), a.end());
// a == {10, 20, 30, 40, 50}
```

The free functions `std::begin()` and `std::end()` are an equivalent,
more generic form that also works on plain C arrays:

```cpp
std::sort(std::begin(a), std::end(a));
```

`data()` exposes the raw pointer to the underlying buffer, which can be
combined with pointer arithmetic:

```cpp
std::sort(a.data(), a.data() + a.size());
```

### Sorting a subarray

Passing any two iterators within the full range sorts only that
sub-range `[first, last)`, leaving the rest of the array untouched:

```cpp
std::array<int, 5> a = {30, 10, 50, 20, 40};
std::sort(a.begin() + 1, a.begin() + 4);
// a == {30, 10, 20, 50, 40}  (only indices 1, 2, 3 sorted)
```

The equivalent pointer form using `data()`:

```cpp
std::sort(a.data() + 1, a.data() + 4);
```


## References

* [C++ Reference: array](https://en.cppreference.com/w/cpp/container/array)

*Egon Teiniker, 2020-2025, GPL v3.0*