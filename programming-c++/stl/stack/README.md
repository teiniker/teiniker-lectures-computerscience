# std::stack

The `std::stack` class is a container adaptor that gives the programmer 
the functionality of a stack - specifically, a **LIFO (last-in, first-out)** 
data structure.

The class template acts as a wrapper to the underlying container - only 
a specific set of functions is provided. The stack pushes and pops the element 
from the back of the underlying container, known as the top of the stack.

## Common Member Functions

| Function          | Description                                        |
|-------------------|----------------------------------------------------|
| `s.size()`        | Returns the number of elements.                    |
| `s.empty()`       | Checks whether the container is empty.             |
| `s.top()`         | Access the top element (last inserted).            |
| `s.push(val)`     | Inserts `val` on top of the stack.                 |
| `s.emplace(args)` | Constructs an element in-place on top.             |
| `s.pop()`         | Removes the top element.                           |

Note: `std::stack` exposes no iterators and no random access - only
the top element is reachable at any time.

The `std::stack` container adapter in C++ does not provide a direct way to 
iterate over its elements because it is designed to provide only LIFO 
(Last In, First Out) access to its elements, which means you can 
**only directly access the top element** of the stack.

## Examples

### Basic LIFO usage

```cpp
#include <stack>

std::stack<int> s;

s.push(10);     // stack (bottom->top): 10
s.push(20);     // stack (bottom->top): 10 20
s.push(30);     // stack (bottom->top): 10 20 30

s.top();        // 30  (last inserted)
s.pop();        // removes 30, stack: 10 20
s.top();        // 20
```

Elements come back in reverse insertion order -- the defining property
of a LIFO structure.

### Reversing a sequence

Because a stack reverses the order of elements pushed onto it, it is a
natural tool for reversing a sequence:

```cpp
std::vector<int> v = {1, 2, 3, 4, 5};
std::stack<int> s;

for (int x : v)
{
    s.push(x);
}

while (!s.empty())
{
    std::cout << s.top() << " ";  // prints: 5 4 3 2 1
    s.pop();
}
```

### Checking balanced parentheses

A classic use case: verify that every opening bracket has a matching
closing bracket in the correct order.

```cpp
bool isBalanced(const std::string& expr)
{
    std::stack<char> s;

    for (char c : expr)
    {
        if (c == '(' || c == '[' || c == '{')
        {
            s.push(c);
        }
        else if (c == ')' || c == ']' || c == '}')
        {
            if (s.empty())
            {
                return false;
            }
            s.pop();
        }
    }
    return s.empty();
}
```

### Choosing the underlying container

The default underlying container is `std::deque`. Any sequence container
that provides `back()`, `push_back()`, and `pop_back()` can be used:

```cpp
#include <vector>

std::stack<int, std::vector<int>> s;  // vector-backed stack
```

A `std::vector`-backed stack avoids the chunk-allocation overhead of
`std::deque` when the maximum size is roughly known in advance.


## References

* [C++ Reference: stack](https://en.cppreference.com/w/cpp/container/stack)


*Egon Teiniker, 2020-2026, GPL v3.0*