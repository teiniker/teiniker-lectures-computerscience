# Example: Bubble Sort with Comparator Function

## Function Pointer

A **function pointer** is a variable that stores the address of a function. Just like regular pointers hold memory addresses of data, function pointers hold memory addresses of executable code. This enables powerful programming techniques like callbacks, dynamic function selection, and strategy patterns.

### Concept

In C, every function resides at a specific memory address. A function pointer allows you to:
- Store a reference to a function
- Pass functions as arguments to other functions
- Return functions from other functions
- Create arrays or structures containing functions
- Select which function to call at runtime

### Syntax

The syntax for declaring a function pointer can be complex:

```c
// Basic syntax: return_type (*pointer_name)(parameter_types)

// Example: Pointer to a function that takes two ints and returns int
int (*operation)(int, int);

// We can assign it to a function with matching signature
int add(int a, int b) { return a + b; }
operation = add;  

// Call through the pointer
int result = operation(5, 3);  // or (*operation)(5, 3);
```

### The comparator_t Type

In this implementation, we define a function pointer type for comparator functions:

```c
typedef int (*comparator_t)(const void *a, const void *b);
```

- `typedef` - Creates a type alias
- `int` - The function returns an integer
- `(*comparator_t)` - The type name is `comparator_t`, and it's a pointer to a function
- `(const void *a, const void *b)` - The function takes two `const void*` parameters

**Return value convention:**
- **Positive value** (> 0): First argument is greater than second (`a > b`)
- **Negative value** (< 0): First argument is less than second (`a < b`)
- **Zero** (0): Arguments are equal (`a == b`)

This convention follows the standard C library's `qsort()` function, making it familiar to C programmers.

**Why `void*` parameters?**
Using `void*` makes the comparator type-agnostic. The same function pointer type can be used for comparing any data type (integers, doubles, strings, structs). The implementation must cast the void pointers to the appropriate type.

**Benefits:**
- **Type safety**: Using `typedef` creates a named type that documents the function signature
- **Readability**: `comparator_t compare` is clearer than `int (*compare)(const void*, const void*)`
- **Maintainability**: If you need to change the signature, update it in one place


## Bubble Sort Implementation 

The `array_bubble_sort()` function implements the bubble sort algorithm with a customizable comparison strategy through a function pointer.

### Function Signature

```c
void array_bubble_sort(int data[], int n, comparator_t compare)
```

- `int data[]` - The array to sort
- `int n` - The number of elements in the array
- `comparator_t compare` - Function pointer that defines the sorting order

### Implementation Details

```c
void array_bubble_sort(int data[], int n, comparator_t compare)
{
    for (int i = 0; i < n - 1; i++)
    {
        array_print(data, n);
        for (int j = 0; j < n - i - 1; j++)
        {
            // Use comparator function to compare elements
            if (compare(&data[j], &data[j + 1]) > 0)
            {
                swap(&data[j], &data[j + 1]);
            }
        }
    }
}
```

**Key aspects:**

1. **Outer loop** (`i` loop): Controls the number of passes through the array. After each pass, the largest (or smallest, depending on comparator) element "bubbles" to its correct position.

2. **Inner loop** (`j` loop): Compares adjacent elements and swaps them if needed. The range decreases with each pass (`n - i - 1`) because the last `i` elements are already sorted.

3. **Comparator usage**: 
   ```c
   if (compare(&data[j], &data[j + 1]) > 0)
   ```
   - Calls the comparator function with **addresses** of adjacent elements
   - If the result is positive, the first element is "greater" (according to the comparator's definition)
   - The swap occurs when elements are out of order

4. **Flexibility**: The same sorting algorithm works for:
   - Ascending order (with `compare_ascending`)
   - Descending order (with `compare_descending`)
   - Any custom ordering (with a custom comparator)

**Comparison with hardcoded version:**

Without comparator:
```c
if (data[j] > data[j + 1])  // Hardcoded ascending order only
```

With comparator:
```c
if (compare(&data[j], &data[j + 1]) > 0)  // Flexible ordering
```

This abstraction separates the sorting algorithm from the comparison logic, following the **Strategy Pattern**.


## Test Cases 

### Implementation of compare_ascending()

The `compare_ascending()` function defines ascending order (smallest to largest):

```c
int compare_ascending(const void *a, const void *b) 
{
    int *value_a = (int*)a;
    int *value_b = (int*)b;     
    return (*value_a - *value_b);    
}
```

**How it works:**

* **Parameters**: Receives `void*` pointers to the elements being compared
* **Type casting**: Converts `void*` to `int*` to access the actual integer values
* **Dereferencing**: Uses `*value_a` and `*value_b` to get the integer values
* **Comparison logic**: 
   - If `*value_a > *value_b`: Returns positive (`*value_a - *value_b > 0`)
   - If `*value_a < *value_b`: Returns negative (`*value_a - *value_b < 0`)
   - If `*value_a == *value_b`: Returns zero (`0`)

**Example:**
- Comparing 5 and 3: `5 - 3 = 2` (positive) → 5 is "greater", so swap happens
- Comparing 2 and 8: `2 - 8 = -6` (negative) → 2 is "less", so no swap
- Comparing 4 and 4: `4 - 4 = 0` (zero) → equal, no swap

### Implementation of compare_descending()

For descending order (largest to smallest):

```c
int compare_descending(const void *a, const void *b) 
{
    int value_a = *(int*)a;
    int value_b = *(int*)b;     
    return (value_b - value_a);  // Note: reversed subtraction
}
```

The key difference is `value_b - value_a` instead of `value_a - value_b`, which reverses the comparison logic.

### Usage of Comparator in array_bubble_sort()

**Test case for ascending order:**

```c
void test_bubble_sort_ascending(void)
{
    int data[N] = { 5, 1, 4, 2, 8 };
    
    // Pass compare_ascending as the comparator function
    array_bubble_sort(data, N, compare_ascending);
    
    array_print(data, N);
    int expected[N] = { 1, 2, 4, 5, 8 };
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, data, N);
}
```

**Test case for descending order:**

```c
void test_bubble_sort_descending(void)
{
    int data[N] = { 5, 1, 4, 2, 8 };
    
    // Pass compare_descending as the comparator function  
    array_bubble_sort(data, N, compare_descending);
    
    array_print(data, N);
    int expected[N] = { 8, 5, 4, 2, 1 };
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, data, N);
}
```

**Key observations:**

* **Function names as pointers**: In C, a function name automatically converts to a function pointer, so you can pass `compare_ascending` directly (no `&` needed).

* **Same algorithm, different behavior**: The sorting algorithm code remains unchanged, but the behavior changes based on which comparator is passed.

* **No code duplication**: We don't need separate `bubble_sort_ascending()` and `bubble_sort_descending()` functions.


*Egon Teiniker, 2020-2026, GPL v3.0*      