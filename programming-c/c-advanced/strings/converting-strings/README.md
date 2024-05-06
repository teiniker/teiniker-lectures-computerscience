# Converting Strings 

In C, we can convert between strings and integers or doubles using several library 
functions. Two commonly used functions for this purpose are `atoi()`, `atol()`, `atoll()` 
(for integers) and `atof()` (for doubles), along with their counterparts for converting 
integers or doubles to strings (`itoa()`, `ltoa()`, `lltoa()`, `sprintf()` for integers 
and doubles).

These operations are declared in the `stdlib.h` header file.

## Converting Strings to Integers

* **int atoi(const char *nptr)** (ASCII to Integer): 
    Converts a string representing an integer in decimal notation to an integer.

* **long atol(const char *nptr)** (ASCII to Long Integer): 
    Converts a string representing a long integer in decimal notation to a long integer.

* **long long atoll(const char *nptr)** (ASCII to Long Long Integer): 
    Converts a string representing a long long integer in decimal notation to a long long integer.

All these operations return the converted value or `0` on error.


## Converting Strings to Doubles

* **double atof(const char *nptr)** (ASCII to Float): 
    Converts a string representing a floating-point number to a double.

Note that `atof()` does not detect errors.


## Converting Integers/Doubles to Strings

* **int sprintf(char *str, const char *format, ... )** (String Print Formatted): 
    Formats and writes data to a string. It supports conversion of integers, 
    doubles, and other data types to strings using format specifiers.

    On success, the total number of characters written is returned.
    On failure, a negative number is returned.

These functions provide basic functionality for converting between strings and numeric 
types in C. 

However, it's important to handle error cases, such as invalid input strings or buffer 
overflow, when using these functions in production code. Additionally, when converting doubles 
to strings, consider the precision requirements and potential loss of precision due to rounding.


## References

* K. N. King. **C Programming, A Modern Approach.** W. W. Norton & Company, inc. 2nd Edition 2008
    * Chapter 13.5: Using the C String Library
    * Chapter 22.8: String I/O
    
*Egon Teiniker, 2020-2024, GPL v3.0* 