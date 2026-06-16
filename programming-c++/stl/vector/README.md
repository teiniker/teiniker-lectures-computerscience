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


## Searching

`std::vector` has no search member function. Searching is done with free
functions from `<algorithm>`.

### std::find()

`std::find()` performs a **linear search** and works on unsorted data.
It returns an iterator to the first matching element, or `end()` if the
value is not found:

```cpp
vector<int> numbers = {7, 5, 16, 8};

vector<int>::iterator it = find(numbers.begin(), numbers.end(), 16);
if (it != numbers.end())
{
    // element found, *it == 16
}
```

Comparing the returned iterator to `end()` is the standard way to check
whether the search succeeded. Dereferencing the iterator with `*it`
gives the found value.

* **Complexity**: O(n) -- every element may be examined.
* **Requirement**: none, works on unsorted ranges.


### std::binary_search()

`std::binary_search()` performs a **binary search** and returns a `bool`
indicating whether the value exists in the range:

```cpp
vector<int> numbers = {5, 7, 8, 16};   // must be sorted

bool found = binary_search(numbers.begin(), numbers.end(), 8);
// found == true
```

* **Complexity**: O(log n) -- far faster than linear search for large
    vectors.
* **Requirement**: the range **must be sorted** in ascending order
    before calling `binary_search()`.


## Sorting

`std::vector` has no `sort()` member function. Sorting is done with the
free function `std::sort()` from `<algorithm>`, which operates on any
range defined by two random-access iterators.

### Default order

Without a comparator, `std::sort` uses `operator<` and sorts in
**ascending order**:

```cpp
#include <algorithm>

vector<int> numbers = {7, 5, 16, 8};
sort(numbers.begin(), numbers.end());
// numbers == {5, 7, 8, 16}
```

### Explicit comparators

The default ascending order can be expressed explicitly using the
standard function object `std::less<int>()` from `<functional>`:

```cpp
#include <functional>

sort(numbers.begin(), numbers.end(), less<int>());
// numbers == {5, 7, 8, 16}
```

For descending order, use `std::greater<int>()`:

```cpp
sort(numbers.begin(), numbers.end(), greater<int>());
// numbers == {16, 8, 7, 5}
```

A named comparator function can also be passed as the third argument:

```cpp
bool compareDesc(int a, int b)
{
    return a > b;
}

sort(numbers.begin(), numbers.end(), compareDesc);
// numbers == {16, 8, 7, 5}
```

## References

* [C++ Reference: vector](https://en.cppreference.com/w/cpp/container/vector)


*Egon Teiniker, 2020-2026, GPL v3.0*
