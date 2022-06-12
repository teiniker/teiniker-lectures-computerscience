# Binary Search in the C Standard Library

The C library function bsearch() searches an array of nitems objects, the initial member of which is pointed to by base, for a member that matches the object pointed to, by key. The size of each member of the array is specified by size.

The contents of the array should be in ascending sorted order according to the comparison function referenced by compar.

Following is the declaration for `bsearch()`:
```C
void *bsearch(const void *key, const void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *))
```

_Parameters_:
* 'key': This is the pointer to the object that serves as key for the search, type-casted as a void*.
* 'base': This is the pointer to the first object of the array where the search is performed, type-casted as a void*.
* 'nitems': This is the number of elements in the array pointed by base.
* 'size': This is the size in bytes of each element in the array.
* 'compare': This is the function that compares two elements.

_Return value_: This function returns a pointer to an entry in the array that matches the search key. If key is not found, a NULL pointer is returned.

The **comparator function** takes two pointers as arguments (both type-casted to const void*) and defines the order of the elements by returning :
```
    <0 The element pointed by p1 goes before the element pointed by p2
    0  The element pointed by p1 is equivalent to the element pointed by p2
    >0 The element pointed by p1 goes after the element pointed by p2
```

## References
* [TutorialsPoint: C library function - bsearch()](https://www.tutorialspoint.com/c_standard_library/c_function_bsearch.htm)

* [cplusplus: qsort()](https://cplusplus.com/reference/cstdlib/qsort)


* Kyle Loudon. **Mastering Algorithms with C**. O'REILLY, 1999
 
*Egon Teiniker, 2020-2022, GPL v3.0* 