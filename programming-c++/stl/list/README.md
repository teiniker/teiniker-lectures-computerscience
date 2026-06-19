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


## Common Member Functions

| Function               | Description                                      |
|------------------------|--------------------------------------------------|
| `l.size()`             | Returns the number of elements.                  |
| `l.empty()`            | Checks whether the container is empty.           |
| `l.front()`            | First element.                                   |
| `l.back()`             | Last element.                                    |
| `l.push_back(val)`     | Appends `val` to the end.                        |
| `l.push_front(val)`    | Inserts `val` before the first element.          |
| `l.pop_back()`         | Removes the last element.                        |
| `l.pop_front()`        | Removes the first element.                       |
| `l.insert(it, val)`    | Inserts `val` before the element at `it`.        |
| `l.erase(it)`          | Removes the element at iterator position `it`.   |
| `l.remove(val)`        | Removes all elements equal to `val`.             |
| `l.clear()`            | Removes all elements (size becomes 0).           |
| `l.reverse()`          | Reverses the order of elements in place.         |
| `l.sort()`             | Sorts elements (stable, O(n log n)).             |
| `l.merge(other)`       | Merges sorted `other` into the list (both must   |
|                        | be sorted); `other` becomes empty afterwards.    |
| `l.splice(it, other)`  | Transfers all elements of `other` into the list  |
|                        | before `it`.                                     |
| `begin(), end()`       | Bidirectional iterators to first and             |
|                        | one-past-last element.                           |

`list` also supports equality operators (`==`, `!=`) and lexicographic
comparisons (`<`, `>`, `<=`, `>=`).


## Searching

`std::list` has no search member function. Searching is done with free
functions from `<algorithm>`.

### std::find()

`std::find()` performs a **linear search** and works on unsorted data.
It returns an iterator to the first matching element, or `end()` if the
value is not found:

```cpp
list<int> numbers = {7, 5, 16, 8};

list<int>::iterator it = find(numbers.begin(), numbers.end(), 16);
if (it != numbers.end())
{
    // element found, *it == 16
}
```

* **Complexity**: O(n) -- every element may be examined.

* **Requirement**: none, works on unsorted ranges.


### std::binary_search()

`std::binary_search()` requires the range to be sorted and returns a
`bool` indicating whether the value exists:

```cpp
list<int> numbers = {5, 7, 8, 16};   // must be sorted

bool found = binary_search(numbers.begin(), numbers.end(), 8);
// found == true
```

* **Complexity**: O(n) on a `std::list` -- although the algorithm is
    O(log n) in comparisons, it cannot jump to the midpoint because
    `std::list` provides only **bidirectional iterators**, not
    random-access iterators. Advancing to the middle requires stepping
    through nodes one by one, making the overall complexity O(n).

* **Requirement**: the range must be sorted.

For this reason, `std::binary_search` is rarely useful on a `std::list`.
Prefer `std::find()` for unsorted data, or consider using `std::set`
when fast lookup on sorted data is required.


## Sorting

Unlike `std::vector` and `std::array`, `std::list` cannot be sorted with
`std::sort()` from `<algorithm>` because `std::sort` requires
**random-access iterators** which `std::list` does not provide.

Instead, `std::list` has its own **member function** `sort()`, optimised
for linked lists:

```cpp
list<int> numbers = {7, 5, 16, 8};
numbers.sort();
// numbers == {5, 7, 8, 16}
```

A comparator function can be passed to sort in a custom order:

```cpp
bool compareDesc(int a, int b)
{
    return a > b;
}

numbers.sort(compareDesc);
// numbers == {16, 8, 7, 5}
```

* **Complexity**: O(n log n).
* **Stability**: `list::sort()` is a **stable sort** -- equal elements
    preserve their original relative order.


## References

* [C++ Reference: list](https://en.cppreference.com/w/cpp/container/list)


*Egon Teiniker, 2020-2026, GPL v3.0*
