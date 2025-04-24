# std::unordered_map 

In C++, the `unordered_map` is part of the Standard Template Library (STL) 
and is used to store **key-value pairs** like a dictionary or hash table. It 
is implemented **using a hash table**, which allows for average constant-time 
complexity **O(1)** for **insertions**, **deletions**, and **lookups**.

## Hash Table

A hash table is a data structure that stores **key-value pairs** and allows 
efficient insertion, deletion, and lookup operations. It achieves this 
efficiency by using a special function known as a **hash function**, which 
**maps keys to indices** within an array.

* **Hash Function**
    - Converts keys into numerical indices.
    - Must distribute keys uniformly across available slots (buckets).

* **Array of Buckets**
    - The storage area (array), where each position (bucket) can store data.
    - A bucket might be empty or hold one or more key-value pairs.

* **Collision Resolution**
    - Collisions occur when multiple keys hash to the same index.
    - Collision resolution methods handle such situations gracefully.
    - Chaining: 
        - Each bucket stores a linked list of entries.
        - Collisions are resolved by adding to the list at the bucket.

### Operations in a Hash Table:

* **Insert**: Adds a key-value pair.

* **Delete**: Removes a key-value pair by key.

* **Lookup/Search**: Retrieves a value associated with a given key.

### Complexity
A hash table’s efficiency primarily depends on the quality of the hash 
function and the collision-handling strategy used.

| Operation | Average Complexity | Worst-Case Complexity|
|-----------|--------------------|----------------------|
| Insert    | O(1)               | O(n)                 |
| Delete    | O(1)               | O(n)                 |
| Search    | O(1)               | O(n)                 |

Average complexity assumes a good hash function and minimal collisions.


## Common Member Functions

| Function                         | Description                                                                   |
|----------------------------------|-------------------------------------------------------------------------------|
| `insert({key, value})`           | Inserts a new key-value pair. Doesn't overwrite if key exists.                |
| `emplace(key, value)`            | Constructs and inserts a key-value pair in-place. More efficient than `insert`.|
| `operator[]` (`map[key]`)        | Inserts if key doesn't exist, else returns reference to value.                |
| `at(key)`                        | Returns value associated with key. Throws `std::out_of_range` if not found.   |
| `find(key)`                      | Returns iterator to key-value pair or `end()` if key not found.               |
| `erase(key)`                     | Removes element with the specified key.                                       |
| `clear()`                        | Removes all elements from the map.                                            |
| `size()`                         | Returns the number of elements in the map.                                    |
| `empty()`                        | Returns `true` if the map is empty.                                           |
| `begin(), end()`                 | Iterators to the beginning and end of the map.                                |
| `bucket_count()`                 | Returns the number of buckets in the hash table.                              |
| `load_factor()`                  | Returns average number of elements per bucket.                                |
| `max_load_factor()`              | Returns or sets the threshold for rehashing.                                  |
| `rehash(n)`                      | Sets the number of buckets to at least `n` and rehashes the map.             |
| `reserve(n)`                     | Reserves enough buckets to hold `n` elements without rehashing.               |
| `hash_function()`                | Returns a copy of the hash function used by the map.                          |
| `key_eq()`                       | Returns the equality predicate used for comparing keys.                       |



## References

* [C++ Reference: unordered_map](https://en.cppreference.com/w/cpp/container/unordered_map)

*Egon Teiniker, 2020-2025, GPL v3.0*