# Example: Generic Array Stack

A **void pointer** (`void*`) is a special pointer type in C that can hold the address of any data type. Unlike regular typed pointers (e.g., `int*`, `char*`), a void pointer does not have an associated data type, making it a generic pointer.

**Key characteristics:**
- **Type-agnostic**: Can point to any data type (int, double, struct, etc.).
- **Cannot be dereferenced directly**: Must be cast to a specific pointer type before dereferencing.
- **Size-unaware**: The compiler doesn't know the size of the pointed-to data.

**Common use cases:**
- **Generic data structures**: Creating reusable containers (like stacks, queues, lists) that work with any data type.
- **Memory allocation**: Functions like `malloc()` return `void*` since they don't know what type will be stored.
- **Callback functions**: Passing arbitrary data to callback functions in a type-agnostic way.
- **Dynamic polymorphism**: Implementing generic algorithms that work with different data types.


## Generic Stack Implementation 

This implementation demonstrates a **generic stack** that can store pointers to any data type by using `void*` internally.

### Stack Structure
```c
typedef struct  
{
    size_t dimension;    // Maximum capacity of the stack
    int top;             // Index of the top element (-1 when empty)
    void **buffer;       // Array of void pointers
} stack_t;
```

The crucial element is `void **buffer`, which is a **pointer to an array of void pointers**. This allows the stack to store pointers to any type of data.

### Memory Allocation
```c
stack->buffer = (void**)calloc(dimension, sizeof(void*));
```
The buffer is allocated to hold `dimension` number of void pointers. Each element can then point to any type of data.

### Push Operation
```c
void stack_push(stack_t *stack, void *value)
{
    if(stack_is_full(stack))
        return;
    
    stack->top++;
    stack->buffer[stack->top] = value;  // Store the void pointer
}
```
The function accepts a `void *value` parameter, allowing any pointer type to be passed and stored directly in the buffer.

### Pop and Top Operations
```c
void *stack_pop(stack_t *stack)
{
    if(stack_is_empty(stack))
        return NULL;
    
    void *value = stack_top(stack);
    stack->top--;
    return value;  // Returns void pointer
}

void *stack_top(stack_t *stack)
{
    if(stack_is_empty(stack))
        return NULL;
    
    return stack->buffer[stack->top];  // Returns void pointer
}
```
Both functions return `void*`, which the caller must cast to the appropriate type to access the actual data.


## Using a Generic Stack

To use the generic stack, we must pass **addresses** of data (pointers) when pushing, and **cast the returned void pointers** back to the correct type when popping or peeking.

### Example 1: Stack of Integer Pointers

```c
void test_int_pop(void) 
{
    // Step 1: Declare variables
    int val1 = 1;
    int val2 = 3;
    int val3 = 5;
    
    // Step 2: Push addresses of integers onto the stack
    stack_push(stack, &val1);  // Push pointer to val1
    stack_push(stack, &val2);  // Push pointer to val2
    stack_push(stack, &val3);  // Push pointer to val3
    
    // Step 3: Pop and cast back to int pointer
    int *pop_val = (int*)stack_pop(stack);  // Cast void* to int*
    TEST_ASSERT_NOT_NULL(pop_val);
    TEST_ASSERT_EQUAL(5, *pop_val);         // Dereference to get value
    
    pop_val = (int*)stack_pop(stack);
    TEST_ASSERT_EQUAL(3, *pop_val);
    
    pop_val = (int*)stack_pop(stack);
    TEST_ASSERT_EQUAL(1, *pop_val);
}
```

- **Push**: Pass the address using `&val1` (converts `int` to `int*`, then implicitly to `void*`).
- **Pop**: Cast the returned `void*` to `int*` using `(int*)stack_pop(stack)`.
- **Access value**: Dereference the pointer with `*pop_val` to get the actual integer value.
- **Lifetime**: The original variables (`val1`, `val2`, `val3`) must remain valid while their addresses are stored in the stack.

### Example 2: Stack of String Pointers

```c
void test_string_pop(void)
{
    // Step 1: Declare string pointers (already pointers!)
    char *str1 = "Hello";   
    char *str2 = "World";
    char *str3 = "Stack";
    
    // Step 2: Push the string pointers directly
    stack_push(stack, str1);  // str1 (char*) implicitly converts to void*
    stack_push(stack, str2);
    stack_push(stack, str3);
    
    // Step 3: Pop and cast back to char pointer
    char *pop_str = (char*)stack_pop(stack);  // Cast void* to char*
    TEST_ASSERT_NOT_NULL(pop_str);
    TEST_ASSERT_EQUAL_STRING("Stack", pop_str);  // No dereference needed
    
    pop_str = (char*)stack_pop(stack);
    TEST_ASSERT_EQUAL_STRING("World", pop_str);
    
    pop_str = (char*)stack_pop(stack);
    TEST_ASSERT_EQUAL_STRING("Hello", pop_str);
}
```

- **Push**: String variables are already pointers (`char*`), so pass them directly (no `&` needed).
- **Pop**: Cast the returned `void*` to `char*` using `(char*)stack_pop(stack)`.
- **Access value**: The string can be used directly; no extra dereferencing needed since it's already a pointer.
- **String literals**: The string literals (`"Hello"`, etc.) are stored in read-only memory and remain valid throughout the program.


### Important Considerations

1. **Type Safety**: The compiler cannot verify that you're casting to the correct type. Casting to the wrong type leads to undefined behavior.

2. **Pointer Lifetime**: The stack stores **pointers only**, not copies of the data. The original data must remain valid while pointers to it exist in the stack.

3. **Memory Management**: This stack does **not** own the data. When you delete the stack, it only frees the pointer array, not the data pointed to. The caller is responsible for managing the lifetime of the actual data.

4. **Single vs Double Indirection**:
   - For primitive types (int, double): Use `&variable` to get the address
   - For pointers (char*, struct*): Pass the pointer directly


*Egon Teiniker, 2020-2026, GPL v3.0* 