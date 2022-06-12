# Quick Sort in the C Standard Library

Standard C library provides `qsort()` that can be used for sorting an array. 

As the name suggests, the function uses **QuickSort algorithm** to sort the given array. 

Following is prototype of `qsort()`:
```C
void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*))
```

_Parameters_:
* `base`: This is the pointer to the first element of the array to be sorted.
* `nitems`: This is the number of elements in the array pointed by base.
* `size`: This is the size in bytes of each element in the array.
* `compar`: This is the function that compares two elements.

_Return value_: This function does not return any value.

The key point about `qsort()` is the **comparator function**. 
The comparator function takes two arguments and contains logic to decide their relative order in sorted output. 

The idea is to provide flexibility so that `qsort()` can be used for any type (including user defined types) and can be used to obtain any desired order (increasing, decreasing or any other).

The comparator function takes two pointers as arguments (both type-casted to const void*) and defines the order of the elements by returning :
```
    <0 The element pointed by p1 goes before the element pointed by p2
    0  The element pointed by p1 is equivalent to the element pointed by p2
    >0 The element pointed by p1 goes after the element pointed by p2
```



## References

* [GeeksforGeeks: Comparator function of qsort() in C](https://www.geeksforgeeks.org/comparator-function-of-qsort-in-c/)

* [cplusplus: qsort()](https://cplusplus.com/reference/cstdlib/qsort)

* Kyle Loudon. **Mastering Algorithms with C**. O'REILLY, 1999
 
*Egon Teiniker, 2020-2022, GPL v3.0* 