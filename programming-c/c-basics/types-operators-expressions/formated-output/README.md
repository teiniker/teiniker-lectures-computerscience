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

Common **conversion specifications** are:

* `%c` Character value.
* `%d` Signed decimal integer value.
* `%e` Scientific notation (mantissa/exponent).
* `%f` Decimal floating point value.
* `%o` Signed octal value.
* `%s` String of characters.
* `%u` Unsigned decimal integer value.
* `%x` Unsigned hexadecimal integer value.
* `%p` Pointer address.
* `%%` Character `%` 

In addition to conversion specifications, we can use the following **flags and width** descriptions:

* `-` Left-justify within the given field width (right justification is the default).
* `+` Forces to precede the result with a plus or minus sign (+ or -) even for positive numbers. By default, only negative numbers are preceded with a `-` sign.
* `#` Used with `o` or `x` specifiers the value is preceded with `0` or `0x` respectively for values different than zero.
* `0` Left-pads the number with zeroes `0` instead of spaces, where padding is specified.


* number Minimum number of characters to be printed. If the value to be printed is shorter than this number, the result is padded with blank spaces. The value is not truncated even if the result is larger.

* .number For integer specifiers (`d`, `o`, `u`, `x`) .number specifies the minimum number of digits to be written. If the value to be written is shorter than this number, the result is padded with leading zeros. The value is not truncated even if the result is longer.\
For `e` and `f` specifiers − this is the number of digits to be printed after the decimal point.\
For `s` − this is the maximum number of characters to be printed. By default all characters are printed until the ending null character is encountered. 


_Example_: Using `printf()` for integer values
```C
    short i = 1;
    int j = -999;
    unsigned long k = 123L;
    unsigned int h = 0xffd2;
    unsigned int o = 01234;

    printf("%-02d\n", i);
    printf("%7d\n", j);
    printf("%07u\n", k);

    printf("%08xf\n", h);
    printf("%8o\n", o);
```


## References

* [C library function - printf()](https://www.tutorialspoint.com/c_standard_library/c_function_printf.htm)

* K. N. King. **C Programming, A Modern Approach.** W. W. Norton & Company, inc. 2nd Edition 2008
    * Chapter 3: Formatted Input/Output
 
*Egon Teiniker, 2020-2022, GPL v3.0* 
