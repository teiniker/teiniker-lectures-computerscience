# string.h (mem Functions)

In the `string.h` header file there also functions that operate on character arrays that aren't necessarily 
null-terminated.
These functions have names that begin with `mem`, to suggest that these functions deal with blocks of memory 
rather than strings.

These memory blocks may contain data of any type, hence the arguments to the `mem` functions have type `void *` rather
than `char *`.

## Memory Set Function
The function **memset()** stores multiple copies of a character in  a specified area of memory.

This function returns a pointer to the memory area `str`.
```C
    void *memset(void *str, int c, size_t n);
```
`memset()` returns its first argument (a pointer).

One use case of `memset()` is initializing an array to zero bits.
_Example_: Initialize an array
```C
    char s[STR_LEN + 1];
    memset(s, '\0', sizeof(s));
```

 

## References
* K. N. King. **C Programming, A Modern Approach.** W. W. Norton & Company, inc. 2nd Edition 2008
    * Chapter 23.6: The <string.h> Header: String Handling
    
* [C Library - <string.h>](https://www.tutorialspoint.com/c_standard_library/string_h.htm) 
 
*Egon Teiniker, 2020-2021, GPL v3.0* 
