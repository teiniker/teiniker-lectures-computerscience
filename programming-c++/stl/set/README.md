# std::set

`std::set` is an associative container that stores **unique elements**
in **sorted order**.

* Internally implemented as a **self-balancing binary search tree**
    (usually a Red-Black Tree).

* Every element acts as its own key -- there are no separate key-value
    pairs as in `std::map`.

* **Duplicates are silently ignored**: inserting a value that is already
    present leaves the set unchanged.

* Elements are always kept in **ascending order** (by default, using
    `operator<`).

* There is **no random access** -- `operator[]` and `at()` do not exist.

The complexity of common operations is as follows:

* **Insert, erase, find**: logarithmic O(log n) thanks to the tree
    structure.

* **Iteration**: linear O(n).


## Common Operations

| Function           | Description                                        |
|--------------------|----------------------------------------------------|
| `s.size()`         | Returns the number of elements.                    |
| `s.empty()`        | Checks whether the container is empty.             |
| `s.insert(val)`    | Inserts `val`; ignored if already present.         |
| `s.erase(val)`     | Removes the element with value `val`.              |
| `s.find(val)`      | Returns an iterator to `val`, or `end()` if not   |
|                    | found. O(log n).                                   |
| `s.count(val)`     | Returns 1 if `val` is present, 0 otherwise.        |
| `s.clear()`        | Removes all elements (size becomes 0).             |
| `begin(), end()`   | Bidirectional iterators to first and               |
|                    | one-past-last element (in sorted order).           |

`set` also supports equality operators (`==`, `!=`) and lexicographic
comparisons (`<`, `>`, `<=`, `>=`).


## Searching

`std::set` provides its own **member function** `find()`, which
exploits the tree structure and runs in **O(log n)**:

```cpp
std::set<int> s = {10, 20, 30, 40, 50};

std::set<int>::iterator it = s.find(30);
if (it != s.end())
{
    // element found, *it == 30
}
```

Prefer the member `find()` over the free function `std::find()` from
`<algorithm>`: the free function does not know about the tree layout
and performs a **linear O(n)** scan.

`count()` is a concise alternative when only membership needs to be
checked (not the iterator position):

```cpp
if (s.count(30) > 0)
{
    // 30 is in the set
}
```

Because `std::set` stores only unique elements, `count()` always
returns either 0 or 1.


## Sorting

Elements in a `std::set` are **always sorted**, the container
maintains ascending order automatically on every insert and erase.
There is no separate sort step.

By default, elements are ordered by `operator<` (ascending):

```cpp
std::set<int> s = {30, 10, 50, 20, 40};

// iterating yields: 10 20 30 40 50
for (int v : s)
{
    std::cout << v << " ";
}
```

A custom comparator can be passed as the second template parameter
to sort in a different order:

```cpp
#include <functional>

std::set<int, std::greater<int>> s = {30, 10, 50, 20, 40};

// iterating yields: 50 40 30 20 10
for (int v : s)
{
    std::cout << v << " ";
}
```

Note: `std::sort()` from `<algorithm>` cannot be used on a `std::set`
because `std::set` provides only **bidirectional iterators**, not
random-access iterators.


## References

* [C++ Reference: set](https://en.cppreference.com/w/cpp/container/set)


*Egon Teiniker, 2020-2026, GPL v3.0*
