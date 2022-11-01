# math.h

The `math.h` header defines various mathematical functions and one macro. All the functions available in this library take `double` as an argument and return `double` as the result.

* **double pow(double x, double y)**\
    Returns x raised to the power of y.

* **double sqrt(double x)**\
    Returns the square root of x.

* **double ceil(double x)**\
    Returns the smallest integer value greater than or equal to x.

* **double fabs(double x)**\
    Returns the absolute value of x.

* **double floor(double x)**\
    Returns the largest integer value less than or equal to x.

* **double fmod(double x, double y)**\
    Returns the remainder of x divided by y.

* **double modf(double x, double *integer)**\
    The returned value is the fraction component (part after the decimal), and sets integer to the integer component.

* ...

To add the math.h functions to our programm we have to link the libm.a library:
```C
$ gcc -std=c99 -g -Wall program.c -o program -lm
```

## References
* K. N. King. **C Programming, A Modern Approach.** W. W. Norton & Company, inc. 2nd Edition 2008
    Chapter 24: Error Handling

* [C library - math.h](https://www.tutorialspoint.com/c_standard_library/math_h.htm)
 
*Egon Teiniker, 2020-2021, GPL v3.0* 