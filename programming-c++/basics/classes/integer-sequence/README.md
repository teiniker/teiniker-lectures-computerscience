# Example: Static Members - Integer Sequence

**Static members** belong to the class itself rather than to any individual
instance. A static data member is shared across all objects of the class:
there is exactly one copy of it in memory, regardless of how many instances
exist. Static member functions can be called without creating an object,
using the class name and the scope resolution operator `::`.

Typical uses for static members include:
* **Shared state**: a counter that tracks how many objects have been created.
* **Class-wide configuration**: a value that all instances read from or
    write to.
* **Factory helpers**: static methods that produce or initialise values
    before any instance exists.


## Implementation

The `IntegerSequence` class uses a static member to maintain a shared
counter that auto-increments every time a new id is requested.

### Class Declaration

```C++
class IntegerSequence
{
    private:
        static int _value;  // static class variable
        int _id;

    public:
        IntegerSequence(void);

        static void init(int value);
        static int next(void);

        int id(void);
};
```

* **Static Data Member**: `static int _value` is declared inside the class
    but belongs to the class, not to any instance. All objects share the
    same `_value`.

* **Instance Member**: `int _id` is a regular (non-static) member. Each
    object gets its own copy, assigned once in the constructor.

* **Static Methods**: `init()` and `next()` are static member functions.
    They can be called without an object (`IntegerSequence::next()`) and
    may only access static members directly.


### Class Implementation

The static member must be defined outside the class body, in the `.cpp`
file:

```C++
int IntegerSequence::_value = 0;  // static
```

This definition allocates storage and sets the initial value to `0`. A
static member that is only declared inside the class has no storage until
this definition appears.

```C++
void IntegerSequence::init(int value)  // static
{
    _value = value;
}

int IntegerSequence::next(void)  // static
{
    return _value++;
}
```

* **init()**: Sets `_value` to a caller-supplied starting value. This
    resets the sequence, which is useful in tests to ensure a known state
    before each run.

* **next()**: Returns the current value and then increments it
    (post-increment). Each call yields the next integer in the sequence.

```C++
IntegerSequence::IntegerSequence(void)
{
    _id = IntegerSequence::next();
}
```

* **Constructor**: Each newly created object calls `next()` to claim the
    current counter value as its own id. Because `_value` is shared, every
    object receives a unique, monotonically increasing id.


## Test Cases

`setUp()` resets the shared counter to `1` before each test so that both
tests are independent of each other.

**test_static_members**: Calls `next()` three times directly via the class
and verifies that the returned values form a consecutive sequence starting
at the value set by `init()`.

```C++
void test_static_members(void)
{
    TEST_ASSERT_EQUAL(1, IntegerSequence::next());
    TEST_ASSERT_EQUAL(2, IntegerSequence::next());
    TEST_ASSERT_EQUAL(3, IntegerSequence::next());
}
```

**test_instances**: Creates three `IntegerSequence` objects and checks that
each object received a unique id assigned automatically by the constructor.

```C++
void test_instances(void)
{
    IntegerSequence obj1;
    IntegerSequence obj2;
    IntegerSequence obj3;

    TEST_ASSERT_EQUAL(1, obj1.id());
    TEST_ASSERT_EQUAL(2, obj2.id());
    TEST_ASSERT_EQUAL(3, obj3.id());
}
```

*Egon Teiniker, 2020-2026, GPL v3.0*
