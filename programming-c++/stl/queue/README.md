# std::queue

The `std::queue` class is a container adaptor that gives the programmer 
the functionality of a queue - specifically, a **FIFO (first-in, first-out)** 
data structure.

The class template acts as a wrapper to the underlying container - only a specific 
set of functions is provided. The queue pushes the elements on the back of the 
underlying container and pops them from the front.


## Common Member Functions

| Function          | Description                                         |
|-------------------|-----------------------------------------------------|
| `q.size()`        | Returns the number of elements.                     |
| `q.empty()`       | Checks whether the container is empty.              |
| `q.front()`       | Access the oldest element (next to be removed).     |
| `q.back()`        | Access the newest element (last inserted).          |
| `q.push(val)`     | Inserts `val` at the back of the queue.             |
| `q.emplace(args)` | Constructs an element in-place at the back.         |
| `q.pop()`         | Removes the element at the front (oldest element).  |

Note: `std::queue` intentionally exposes no iterators and no random
access - only the front and back elements are reachable at any time.


## Examples

```cpp
#include <queue>

std::queue<int> q;

q.push(10);     // queue: 10
q.push(20);     // queue: 10 20
q.push(30);     // queue: 10 20 30

q.front();      // 10  (oldest)
q.back();       // 30  (newest)

q.pop();        // removes 10, queue: 20 30
q.front();      // 20
```

The underlying container defaults to `std::deque`. A different sequence
container (e.g. `std::list`) can be selected as the second template
parameter:

```cpp
#include <list>

std::queue<int, std::list<int>> q;
```


## References

* [C++ Reference: queue](https://en.cppreference.com/w/cpp/container/queue)


*Egon Teiniker, 2020-2026, GPL v3.0*