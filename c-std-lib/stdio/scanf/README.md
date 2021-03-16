# The `scanf()` Functions

`scanf()` read data items from an input stream, using a **format string** to indicate the layout of the input. 
After the format string, **any number of pointers** follow as additional arguments.
```C
int scanf(const char * format, ...);
```
`scanf()` reads from stdin (the standard input stream) and returns the number of data items that
were read and assigned to objects. It returns EOF if an input failure occurs before any data items
can be read.

_Example_: Read an integer value from stdin
```C
#include <stdio.h>

int main(void)
{
    int a;
    printf("int a = ");
    scanf("%d", &a);

    //...
    return 0;
}
```


## References

* [C library function - scanf()](https://www.tutorialspoint.com/c_standard_library/c_function_scanf.htm)

* K. N. King. **C Programming, A Modern Approach.** W. W. Norton & Company, inc. 2nd Edition 2008. 
Chapter 22: Input/Output
 
*Egon Teiniker, 2020-2021, GPL v3.0* 