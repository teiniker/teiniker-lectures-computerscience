# string.h

The C library provides a rich set of functions for performing operations on strings.
Prototypes for these functions can be found in the `string.h` header file.

## String Length Function
The function `strlen()` returns the length of a string s (the number of characters in s up
to but not including, the first null charachter).
```C
    size_t strlen(const char *s);
```
`strlen()` doesn't measure the length of the array itself, it returns the length of the string stored in the array.

## String Copy Function
The function `strcpy()` copies characters from `src` to `dest` up to and including the first null character in `src`.
`strcpy()` returns `dest` (a pointer to the destination string).
The string pointed to by `src` is not modified, so it is declared `const`.
```C
    char *strcpy(char *dest, const char *src);
```
**`strcpy()` has no way to check that the string pointed to by `src` will actually fit in the array 
pointed to by `dest`.**

## String Concatenation Function
The function `strcat()` appends the contents of the string `src` to the end of the string `dest`.
It returns `dest` (a pointer to the resulting string).
```C
    char *strcat(char *dest, const char *scr);
```
The effect of the call `strcat()` is undefined if the array pointed to by `dest` is not long enough
to accommodate the additional characters from `src`.

## String Comparison Function
The function `strcmp()` compares the strings `s1` and `s2`, returning a value less than, equal to, or
greater than 0, depending on whether `s1` is less than, equal to, or greater than `s2`.
```C
    int strcmp(cont char *s1, const char *s2);
```
By choosing the proper relational operator (`<`, `<=`, `>`, `>=`) or equality operator (`==`, `!=`),
we can test any possible relationship between `s1` and `s2`.

## References
* K. N. King. **C Programming, A Modern Approach.** W. W. Norton & Company, inc. 2nd Edition 2008
    Chapter 13.5: Using the C String Library

* [C <string.h>](https://www.programiz.com/c-programming/library-function/string.h) 
 
*Egon Teiniker, 2020-2021, GPL v3.0* 