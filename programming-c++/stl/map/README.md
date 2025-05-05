# std::map

The `std::map` container from the C++ Standard Template Library (STL) 
is an **associative container** used for storing **key-value pairs** in 
**sorted order**.

* Internally implemented as a **self-balancing binary search tree** 
    (usually Red-Black Tree).

* Ensures unique keys — no duplicates allowed.

* Keys are always sorted (by default, in ascending order using < operator).

* Logarithmic time **O(log n)** for **insert**, **delete**, and **search** 
    (thanks to Red-Black Tree).

## Common Operations

| Operation             | Description                                      |
|------------------------|--------------------------------------------------|
| `m[key] = value`       | Insert or update a key-value pair                |
| `m.at(key)`            | Access value (throws if key not found)           |
| `m.find(key)`          | Returns iterator to key or `end()` if not found  |
| `m.erase(key)`         | Remove a key-value pair                          |
| `m.size()`             | Returns number of elements                       |
| `m.empty()`            | Checks if the map is empty                       |
| `m.clear()`            | Removes all elements                             |
| `m.begin(), m.end()`   | Iterators to traverse the map                    |



## References

* [C++ Reference: map](https://en.cppreference.com/w/cpp/container/map)

*Egon Teiniker, 2020-2025, GPL v3.0*
