# Formated Output

The `printf()` functionis designed to display the contents of a sting, known as the **format string**, with values possibly inserted at specified points in the string.

The values displayed can be constants, variables, or more complicated expressions.

The format string may contain both ordinary characters and **conversion specifications**, which begin with the `%` character.
A conversion specification is a placeholder representing a value to be filled in during printing.
The information that follows the % character specifies how the value is converted from its internal form (binary) to printed form (characters).

```C
int printf(const char *format, ...)
```

* `format`: This is the string that contains the text to be written to stdout.  It can optionally contain embedded format tags (conversion specifications) that are replaced by the values specified in subsequent additional arguments and formatted as requested.

* If successful, the total number of characters written is returned. On failure, a negative number is returned.


## References

* [C library function - printf()](https://www.tutorialspoint.com/c_standard_library/c_function_printf.htm)

* K. N. King. **C Programming, A Modern Approach.** W. W. Norton & Company, inc. 2nd Edition 2008
    * Chapter 3: Formatted Input/Output
 
*Egon Teiniker, 2020-2021, GPL v3.0* 