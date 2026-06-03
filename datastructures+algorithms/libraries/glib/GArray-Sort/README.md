# GLib: Sorting Arrays

The `g_array_sort()` function provides an efficient way to sort GArray elements 
using a custom comparison function. This enables sorting of any data type stored 
in a GArray.

```C
void g_array_sort(GArray *array, GCompareFunc compare_func);
```

- **`array`**: A pointer to the GArray to be sorted.
- **`compare_func`**: A comparison function that determines the sort order.


The **comparison function** must have the following signature:

```C
gint (*GCompareFunc)(gconstpointer a, gconstpointer b);
```

The comparison function receives pointers to two array elements and should return:
- **Negative value** (< 0): if `a` should come before `b` (a < b)
- **Zero** (0): if `a` and `b` are equal
- **Positive value** (> 0): if `a` should come after `b` (a > b)

`g_array_sort()` uses the **qsort()** function from the C standard library, 
which typically implements a variant of quicksort or introsort (quicksort 
with fallback to heapsort for worst-case scenarios). The exact algorithm 
is implementation-dependent, but it generally provides:

- **Average time complexity**: O(n log n)
- **Worst-case time complexity**: O(n²) for standard qsort, or O(n log n) for introsort variants
- **Space complexity**: O(log n) due to recursion
- **Stability**: Not guaranteed (equal elements may be reordered)

The sort is performed **in-place**, modifying the original array.


## Examples 

This example demonstrates sorting two different data types: integers and strings.

### Test Case 1: Sorting Integers

```C
void test_sort(void)
{
    // Setup: Create unsorted array 
    GArray *array = NULL;
    array = g_array_new(FALSE, FALSE, sizeof(int));
    int values[] = {50, 10, 40, 20, 30};
    g_array_append_vals(array, values, 5);
    
    // Exercise: Sort using g_array_sort with custom compare function
    g_array_sort(array, compare_int);
    
    // Verify: Check sorted order
    TEST_ASSERT_EQUAL(10, g_array_index(array, int, 0));
    TEST_ASSERT_EQUAL(20, g_array_index(array, int, 1));
    // ... and so on
    
    g_array_free(array, TRUE);
}
```

- **Array Creation**: `g_array_new(FALSE, FALSE, sizeof(int))`
   - First `FALSE`: Don't NULL-terminate the array
   - Second `FALSE`: Don't clear (zero-initialize) elements
   - `sizeof(int)`: Size of each element

- **Adding Elements**: `g_array_append_vals(array, values, 5)`
   - Appends 5 integer values from the `values` array

- **Compare Function**: `compare_int`
   ```C
   gint compare_int(gconstpointer a, gconstpointer b)
   {
       int int_a = *(const int *)a;
       int int_b = *(const int *)b;
       
       if (int_a < int_b)
           return -1;
       else if (int_a > int_b)
           return 1;
       else
           return 0;
   }
   ```
   - **Cast and dereference**: `*(const int *)a` converts `void*` to `int*` then dereferences
   - **Return logic**: Returns negative/zero/positive based on comparison

- **Sorting**: `g_array_sort(array, compare_int)`
   - Sorts the array in ascending order using the provided comparator

- **Verification**: Uses `g_array_index(array, int, i)` to access elements
   - This macro provides type-safe element access


### Test Case 2: Sorting Strings

```C
void test_sort_strings(void)
{
    // Setup: Create unsorted array of strings
    GArray *array = NULL;
    array = g_array_new(FALSE, FALSE, sizeof(char*));
    
    char *strings[] = {"Elephant", "Apple", "Zebra", "Banana", "Mango", "Cherry"};
    g_array_append_vals(array, strings, 6);
    
    // Exercise: Sort using g_array_sort with string compare function
    g_array_sort(array, compare_string);
    
    // Verify: Check alphabetical order
    TEST_ASSERT_EQUAL_STRING("Apple", g_array_index(array, char*, 0));
    TEST_ASSERT_EQUAL_STRING("Banana", g_array_index(array, char*, 1));
    // ... and so on
    
    g_array_free(array, TRUE);
}
```

- **Element Size**: `sizeof(char*)` 
   - The array stores **pointers to strings**, not the strings themselves
   - Each element is a `char*` pointer

- **String Compare Function**: `compare_string`
   ```C
   int compare_string(gconstpointer a, gconstpointer b)
   {
       const char *str_a = *(const char **)a;
       const char *str_b = *(const char **)b;
       
       return g_strcmp0(str_a, str_b);
   }
   ```
   - **Double dereference**: `*(const char **)a` is needed because:
     - The array stores `char*` (pointers to strings)
     - The comparison function receives `void*` (pointers to array elements)
     - So we have `void*` → `char**` → `char*`
   - **g_strcmp0()**: GLib's NULL-safe string comparison function
     - Returns negative if str_a < str_b (lexicographically)
     - Returns 0 if strings are equal
     - Returns positive if str_a > str_b

- **Memory Management**:
   - The array only stores pointers, not copies of strings
   - String literals ("Apple", "Banana", etc.) are stored in read-only memory
   - Only the pointers are rearranged during sorting, not the string data


## References

* [GLib Reference Manual: Arrays](https://docs.gtk.org/glib/struct.Array.html)
* [C Standard Library: qsort](https://en.cppreference.com/w/c/algorithm/qsort)

*Egon Teiniker, 2020-2026, GPL v3.0* 
