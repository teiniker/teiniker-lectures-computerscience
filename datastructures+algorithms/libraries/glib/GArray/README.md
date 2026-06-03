# GLib: Arrays

GArray provides a dynamic array data structure that can grow and shrink 
automatically. Unlike C's built-in arrays, GArray manages its own memory 
and can be resized without manual reallocation.

GArray is best used when we need a resizable array with O(1) random access 
and want automatic memory management. It's particularly useful for storing 
primitive types or structs.

## Key Features

- **Dynamic sizing**: Arrays grow automatically as elements are added.
- **Type-safe access**: Use `g_array_index()` macro for type-safe element access.
- **Efficient**: Contiguous memory storage provides cache-friendly O(1) random access.
- **Flexible**: Supports insertion, removal, and sorting operations.

## Main Functions

```C
    GArray *g_array_new()                  // Create a new array
    GArray *g_array_sized_new()            // Create with preallocated size
    void    g_array_free()                 // Free the array
    
    GArray *g_array_append_val()           // Add element at the end
    GArray *g_array_append_vals()          // Add multiple elements at the end
    GArray *g_array_prepend_val()          // Add element at the beginning
    GArray *g_array_prepend_vals()         // Add multiple elements at the beginning
    GArray *g_array_insert_val()           // Insert element at index
    GArray *g_array_insert_vals()          // Insert multiple elements at index
    
    GArray *g_array_remove_index()         // Remove element at index
    GArray *g_array_remove_index_fast()    // Remove element (doesn't preserve order)
    GArray *g_array_remove_range()         // Remove range of elements
    
    GArray *g_array_set_size()             // Set the size of the array
    guint   array->len                     // Current number of elements
    
    GArray *g_array_sort()                 // Sort the array
    GArray *g_array_sort_with_data()       // Sort with custom data
    
    #define g_array_index(array, type, i)  // Access element at index (type-safe)
```

## Usage Example

```C
// Create array for integers
GArray *array = g_array_new(FALSE, FALSE, sizeof(gint));

// Add elements
gint value = 42;
g_array_append_val(array, value);

// Access elements
gint element = g_array_index(array, gint, 0);

// Free when done
g_array_free(array, TRUE);
```

## References

* [GLib Reference Manual: Arrays](https://docs.gtk.org/glib/struct.Array.html)

*Egon Teiniker, 2020-2026, GPL v3.0* 
