# Dynamic Memory Allocation

Data structures in C are normally fixed in size.
For example, the number of elements in an array is fixed once the program has been compiled.
Fixed-size data structures can be a problem since we are forced to choose their sizes when writing a program.
We can't change the sizes without modifying the program and compiling it again.

Fortunately, C supports dynamic memory allocation, which is **the ability to allocate storage during program execution**.
Using dynamic memory allocation, we can implement data structures that grow (and shrink) as needed.

## Memory Allocation Functions
To allocate storage dynamically, we can use one of three memory allocation functions declared in the <stdlib.h> 
header file:

* `void *malloc(size_t size)` Allocates a block of memory but doesn't initialize it.

* `void *calloc(size_t nmemb, size_t size)` Allocates a block of memory and clears it.

* `void *realloc(void *ptr, site_t size)` Resizes a previously allocated block of memory.

`malloc()` is the most used. It is more efficient than `calloc()`, since it doesn't have to clear the memory block that 
it allocates. 

When we call a memory allocation function to request a block of memory, the function has no idea what type of data we
are planning to store in the block, so it can't return a pointer to an ordinary type such as int or char.
Instead, the function returns a value of type `void *`.
A `void *` value is a **generic pointer** - essentially, just a memory address.

When a memory allocation function is called, there is always a possibility that it will not be able to locate a block
of memory large enough to satisfy our request.
If that should happen, the function will return a **null pointer**. 
A null pointer is a "pointer to nothing" - a special value that can be distinguished from all valid pointers.
The null pointer is represented by a macro named **NULL** which is defined in six header files: 
`<stdlib.h>`, `<locale.h>`, `<stddef.h>`, `<stdio.h>`, `<string.h>`, and `<time.h>`.  
As long as one of these headers is included in a program, the compiler will recognize `NULL`.

## Dynamic Allocated Arrays

When we are writing a program, it is often difficult to estimate the proper size for an array.
C solves this problem by allowing a program to allocate space for an array during execution, then access the array 
through a pointer to its first element.

### Using the `malloc()` Function

Note that the elements of an array will not necessarily be one byte long, thus, we will need to use the `sizeof()`
operator to calculate the amount of space required for each element.
 
_Example_: Array of n integers 
```C
    int *a = malloc(n * sizeof(int));     

    a[0] = 100;
``` 
Once it points to a dynamic allocated block of memory, we can ignore the fact that `a` is a pointer and use it 
instead as an array name, thanks to the relationship between arrays and pointers.
We also have the option of using pointer arithmetic instead of indexing to access the elements of the array.

### Using the `calloc()` Function

`calloc()` allocates space for an array with `nmemb` elements, each of which is size bytes long.
It also returns a null pointer if the requested space is not available.

After allocating the memory, `calloc()` initializes it by **setting all bits to 0**.

_Example_: Array of n integers 
```C
    int *a = calloc(n, sizeof(int));     

    assert a[0] == 0;
``` 

### Using the `realloc()` Function

Once we have allocated memory for an array, we may later find it is too large or too small.
The `realloc()` function can resize the array to better suit our needs.

When `realloc()` is called, `ptr` must point to a memory block obtained by a previous call of `malloc()`, `calloc()`, 
or `realloc()`. The `size` parameter represents the new size of the block, which may be larger or smaller than the 
original size.

```C
    int *a = malloc(n * sizeof(int));
    
    // Resize existing array 
    int *b = realloc(a, 2*n * sizeof(int));
```

The C standard spells out a number of rules concerning the behavior of `realloc()`:
* When it expands a memory block, `realloc()` does **not initialize the bytes** that are added to the block.
* If `realloc()` **can't enlarge the memory block** as requested, it returns a null pointer. 
    The data in the old memory block is unchanged.
* If `realloc()` is called with a **null pointer as its first argument**, it behaves like `malloc()`.
* If `realloc()` is called with **0 as its second argument**, it frees the memory block.

If it is **not possible to enlarge the block** (because the bytes following the block are already in use for some other
purpose), `realloc()` will allocate a new block elsewhere, then copy the contents of the old block into the new one.
Once `realloc()` has returned, be sure to **update all pointers to the memory block**, since it is possible that 
`realloc()` has moved the block elsewhere.


## Deallocating Memory

All memory allocation functions obtain memory blocks from a storage pool known as the **heap**.
Calling these functions too often, or asking them for large blocks of memory, can exhaust the heap, causing the 
functions to return a null pointer.

To make matters worse, a program may allocate blocks of memory and then lose track of them, thereby wasting space.
A block of memory that is no longer accessible to a program is said to be **garbage**. 
A program that leaves garbage behind has a **memory leak**.

Each C program is responsible for recycling its own garbage by calling the `free()` function to **release unneded memory**.
The `free()` function has the following prototype in `<stdlib.h>`: 
```C
    void free(void *ptr);
```
Calling `free()` releases the block of memory that `ptr` points to.
This block is now available for reuse in subsequent calls of `malloc()` or other memory allocation function.
Note that `ptr` must be a pointer that was previously returned by a memory allocation function.
Passing `free()` a pointer to any other object causes undefined behavior.

Although the free() function allows us to reclaim memory that is no longer needed, using it leads to a new problem:
**dangling pointers**.
The call `free(ptr)` deallocates the memory block that `ptr` points to, but does not change `ptr` itself. 
If we forget that ptr no longer points to a valid memory block, chaos may take place.


## References

* K. N. King. **C Programming, A Modern Approach.** W. W. Norton & Company, inc. 2nd Edition 2008. 
    Chapter 17: Advanced Uses of Pointers.
* [Youtube: CS50 Dynamic Memory Allocation](https://youtu.be/9uhSYDY4sxA) 
 
*Egon Teiniker, 2020-2021, GPL v3.0* 
