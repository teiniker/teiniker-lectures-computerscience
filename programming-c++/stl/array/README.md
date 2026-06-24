# sdt::array

The `std::array` container in C++ STL is a wrapper around a static array, 
providing the benefits of STL containers (like iterators, size checks, 
etc.) while maintaining the performance and memory layout of built-in arrays.

* `std::array` is a **modern, safe** replacement for raw C-style arrays.

* `std::array` has **fixed size**, unlike `std::vector`.

* The size is part of the type.

    _Example_: `std::array<int, 3>` is a **different type** from `std::array<int, 5>`.

* Elements are stored **continuously**, so it's compatible with C-style APIs.


## Common Operations

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


## Iterator

An **iterator** is an object that points to an element inside a container
and can be advanced to the next element. It is the standard interface
between STL containers and STL algorithms: every algorithm accepts
a pair of iterators defining a range `[first, last)`, so the algorithm
is independent of the concrete container type.

`std::array` provides **random-access iterators**, which support:

* incrementing (`++it`) and decrementing (`--it`)
* arbitrary offset (`it + n`, `it - n`)
* element access via dereference (`*it`) and subscript (`it[n]`)
* comparison (`==`, `!=`, `<`, `>`, `<=`, `>=`)

The two key member functions are:

* `begin()`: returns an iterator to the first element.
* `end()`: returns an iterator one past the last element.

### Declaring an Iterator

```cpp
std::array<int, 5> a = {10, 20, 30, 40, 50};

std::array<int, 5>::iterator it = a.begin();
// or, more concisely:
auto it2 = a.begin();
```

### Traversing with an Iterator

```cpp
std::array<int, 5> a = {10, 20, 30, 40, 50};

for (auto it = a.begin(); it != a.end(); ++it)
{
    std::cout << *it << "\n";
}
```

The dereference operator `*it` reads the value the iterator points to.
Incrementing with `++it` advances to the next element.

### Use Cases

**Range-based for loop** (syntactic sugar over iterators):

```cpp
for (int v : a)
{
    std::cout << v << "\n";
}
```

**Passing a sub-range to an algorithm**:

```cpp
// reverse only the first three elements
std::reverse(a.begin(), a.begin() + 3);
```

## Searching

`std::array` has no search member function. Searching is done with free
functions from `<algorithm>`.

### std::find()

`std::find()` performs a **linear search** and works on unsorted data.
It returns an iterator to the first matching element, or `end()` if the
value is not found:

```cpp
std::array<int, 5> a = {10, 20, 30, 40, 50};

std::array<int, 5>::iterator it = std::find(a.begin(), a.end(), 30);
if (it != a.end())
{
    // element found, *it == 30
}
```

Comparing the returned iterator to `end()` is the standard way to check
whether the search succeeded. Dereferencing the iterator with `*it`
gives the found value.

* **Complexity**: O(n) - every element may be examined.

* **Requirement**: None, works on unsorted ranges.


### std::binary_search()

`std::binary_search()` performs a **binary search** and returns a `bool`
indicating whether the value exists in the range:

```cpp
std::array<int, 5> a = {10, 20, 30, 40, 50};  // must be sorted

bool found = std::binary_search(a.begin(), a.end(), 40);
// found == true
```

* **Complexity**: O(log n) - far faster than linear search for large
    arrays.

* **Requirement**: The range **must be sorted** in ascending order
    before calling `binary_search()`.


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

*Egon Teiniker, 2020-2026, GPL v3.0*