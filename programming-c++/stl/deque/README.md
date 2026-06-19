# std::deque

`std::deque` (double-ended queue) is a sequence container that supports
**efficient insertion and removal at both ends**.

Unlike `std::vector`, a deque does not store all elements in a single
contiguous block. Instead it uses a sequence of fixed-size memory chunks,
which allows O(1) operations at the front without shifting elements.

Unlike `std::list`, a deque still supports **random access** in O(1)
via `operator[]`.

The complexity of common operations is as follows:

* **Random access**: constant O(1)

* **Insertion or removal at front or back**: amortized constant O(1)

* **Insertion or removal in the middle**: linear O(n)


## Common Member Functions

| Function            | Description                                        |
|---------------------|----------------------------------------------------|
| `d.size()`          | Returns the number of elements.                    |
| `d.empty()`         | Checks whether the container is empty.             |
| `d[i]`              | Access element at index `i` (no bounds check).     |
| `d.at(i)`           | Access element at index `i` with bounds checking.  |
| `d.front()`         | First element.                                     |
| `d.back()`          | Last element.                                      |
| `d.push_back(val)`  | Appends `val` to the end.                          |
| `d.push_front(val)` | Inserts `val` before the first element.            |
| `d.pop_back()`      | Removes the last element.                          |
| `d.pop_front()`     | Removes the first element.                         |
| `d.insert(it, val)` | Inserts `val` before the element at `it`.          |
| `d.erase(it)`       | Removes the element at iterator position `it`.     |
| `d.clear()`         | Removes all elements (size becomes 0).             |
| `begin(), end()`    | Random-access iterators to first and               |
|                     | one-past-last element.                             |

`deque` also supports equality operators (`==`, `!=`) and lexicographic
comparisons (`<`, `>`, `<=`, `>=`).

Note: unlike `std::vector`, `std::deque` has no `data()` member because
its storage is not contiguous.


## Searching

`std::deque` has no search member function. Searching is done with free
functions from `<algorithm>`.

### std::find()

`std::find()` performs a **linear search** and works on unsorted data.
It returns an iterator to the first matching element, or `end()` if the
value is not found:

```cpp
deque<int> numbers = {7, 5, 16, 8};

deque<int>::iterator it = find(numbers.begin(), numbers.end(), 16);
if (it != numbers.end())
{
    // element found, *it == 16
}
```

* **Complexity**: O(n) -- every element may be examined.

* **Requirement**: none, works on unsorted ranges.


### std::binary_search()

`std::binary_search()` performs a **binary search** and returns a `bool`
indicating whether the value exists in the range:

```cpp
deque<int> numbers = {5, 7, 8, 16};   // must be sorted

bool found = binary_search(numbers.begin(), numbers.end(), 8);
// found == true
```

* **Complexity**: O(log n) -- because `std::deque` provides
    random-access iterators, the algorithm can jump to the midpoint
    directly.
* **Requirement**: the range **must be sorted** in ascending order
    before calling `binary_search()`.


## Sorting

`std::deque` provides random-access iterators, so the free function
`std::sort()` from `<algorithm>` works directly:

```cpp
#include <algorithm>

deque<int> numbers = {7, 5, 16, 8};
sort(numbers.begin(), numbers.end());
// numbers == {5, 7, 8, 16}
```

Custom comparators are supported the same way as for `std::vector`:

```cpp
#include <functional>

sort(numbers.begin(), numbers.end(), greater<int>());
// numbers == {16, 8, 7, 5}
```


## References

* [C++ Reference: deque](https://en.cppreference.com/w/cpp/container/deque)


*Egon Teiniker, 2020-2026, GPL v3.0*
