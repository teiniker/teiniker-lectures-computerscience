# Example: Abstract Base-Class - Stack

## Abstract Base-Class: Stack

An abstract base class defines an **interface**, a **set of operations that every
concrete implementation must provide**, without committing to any particular
data structure. Declaring each method as `pure virtual` (`= 0`) forces every
subclass to supply its own implementation, and a `virtual` destructor ensures
that deleting an object through a base-class pointer calls the correct
destructor.

```cpp
class Stack
{
    public:
        virtual ~Stack() {}

        virtual bool isEmpty() = 0;
        virtual void push(int value) = 0;
        virtual int  pop() = 0;
        virtual int  top() = 0;
        virtual void print() = 0;
};
```

Because `Stack` contains at least one pure virtual method, it **cannot be
instantiated** directly. Client code works exclusively with `Stack` pointers or
references and remains independent of the chosen implementation strategy. This
is the classic application of the **Strategy** pattern: The algorithm (here,
the internal storage layout) is encapsulated behind a stable interface and can
be swapped without touching the calling code.


## Concrete Sub-Classes: ArrayStack and LinkedStack

Both subclasses inherit publicly from `Stack` and provide a concrete body for
every pure virtual method.

**ArrayStack** stores elements in a fixed-size heap-allocated array. The
constructor receives the capacity and allocates the buffer; the destructor
releases it with `delete[]`. An index `_top` tracks the number of stored
elements (0 means empty).

```cpp
class ArrayStack : public Stack
{
    public:
        ArrayStack(size_t size);
        ~ArrayStack();
        bool isEmpty(); void push(int value); int pop(); int top(); void print();
    private:
        size_t _size;
        size_t _top;
        int   *_buffer;
};
```

**LinkedStack** stores elements in a singly-linked list of `Node` objects. Each
`push` prepends a new node at the head; each `pop` removes the head node and
frees its memory. Because the list is dynamic, no capacity limit needs to be
specified at construction time.

```cpp
class LinkedStack : public Stack
{
    public:
        LinkedStack();
        ~LinkedStack();
        bool isEmpty(); void push(int value); int pop(); int top(); void print();
    private:
        Node *first_ptr;
};
```

Both classes override `print()` with a label (`ArrayStack` or `LinkedStack`)
so the output makes the active implementation visible during testing.

The compiler enforces completeness: if either subclass omits any of the five
methods inherited from `Stack`, the build fails with an error about
instantiating an abstract class.


## Test Cases

Each test case declares a local `Stack *` pointer and assigns it a freshly
created concrete instance. This is the key **polymorphism** idiom: the pointer type
is the abstract base class, while the object on the heap is a concrete subclass.

```cpp
void test_array_stack_pop(void)
{
    Stack *stack = new ArrayStack(10);
    stack->push(1);
    stack->push(3);
    stack->push(5);

    TEST_ASSERT_EQUAL(5, stack->pop());
    TEST_ASSERT_EQUAL(3, stack->pop());
    TEST_ASSERT_EQUAL(1, stack->pop());

    delete stack;
}
```

The call `stack->pop()` resolves at runtime to `ArrayStack::pop()` (or
`LinkedStack::pop()`) through the virtual dispatch mechanism, the caller does
not need to know which concrete type is behind the pointer.

The same four logical test cases (`isEmpty`, `isNotEmpty`, `pop`, `top`) are
written twice: once for `ArrayStack` and once for `LinkedStack`. Naming each
function after its implementation (`test_array_stack_*`, `test_linked_stack_*`)
makes it immediately clear in the Unity output which implementation a failing
test belongs to.

Because each test function manages its own object lifetime (`new` at the top,
`delete` at the bottom), `setUp` and `tearDown` are empty stubs required only
to satisfy the Unity framework.


*Egon Teiniker, 2020-2026, GPL v3.0*    