# string.h

The C library provides a rich set of functions for performing **operations on strings**.
Prototypes for these functions can be found in the `string.h` header file.

## String Length Function
The function **strlen()** returns the length of a string s (the number of characters in s up
to but not including, the first null charachter).
```C
    size_t strlen(const char *s);
```
`strlen()` doesn't measure the length of the array itself, it returns the length of the string stored in the array.

## String Copy Functions
The functions in this category copy characters from one place in memory (the _source_) to another (the _destination_).
Each function requires that the first argument point to the destination and the second point to the source.
All copy functions return the first argument (a pointer to the destination).

The function **strcpy()** copies characters from `src` to `dest` up to and including the first null character in `src`.
`strcpy()` returns `dest` (a pointer to the destination string).
The string pointed to by `src` is not modified, so it is declared `const`.
```C
    char *strcpy(char *dest, const char *src);
```
`strcpy()` has no way to check that the string pointed to by `src` will actually fit in the array 
pointed to by `dest`.

**strncpy()** is similar to `strcpy()`, but it will not copy more than `n` characters, where `n` is the function's 
third argument.
```C
    char *strncpy(char *dest, const char *src, size_t n);
```
 If `strncpy()` encounters a null character in the source, it adds null characters to the destination until it has 
 written a total on `n` characters.
 Note that if `n` is too small, `strncpy()` will not be able to copy a terminating null character.
 
_Secure Coding Tip_: **Don't use strcpy() - use strncpy() whenever possible!!**  


## String Concatenation Functions
These functions add characters to the end of a string.

The function **strcat()** appends the contents of the string `src` to the end of the string `dest`.
It returns `dest` (a pointer to the resulting string).
```C
    char *strcat(char *dest, const char *src);
```
The effect of the call `strcat()` is undefined if the array pointed to by `dest` is not long enough
to accommodate the additional characters from `src`.

**strncat()** is the same as `strcat()`, except that its third argument limits the number of characters it will copy.
```C
    char *strncat(char *dest, const char *src, size_t n);
```
The third parameter `n` is the maximum number of characters to be appended.
This function returns a pointer to the resulting string `dest`.


## String Comparison Functions
These functions compares character arrays.

The function **strcmp()** compares the strings `s1` and `s2`, returning a value less than, equal to, or
greater than 0, depending on whether `s1` is less than, equal to, or greater than `s2`.
```C
    int strcmp(cont char *s1, const char *s2);
```
By choosing the proper relational operator (`<`, `<=`, `>`, `>=`) or equality operator (`==`, `!=`),
we can test any possible relationship between `s1` and `s2`.

**strncmp()** compares the first `n` bytes of s1 and s2.
```C
    int strncmp(const char *s1, const char *s2, size_t n);
```

## Reading and Writing Strings (Console) 
Writing a string is easy using either the `printf()` or `puts()` functions.
Reading strings is a bit harder, primarily because of the possibility that the input string may be longer than 
the string variable into which it's being stored.


### Writing Strings
The `%s` conversion specification in the format string allows **printf()** to write a string.
`printf()` writes the characters in a string one by one until it encounters a null character.

To **print just a part of a string**, we can use the conversion specification `%.ps`, 
where `p` is the number of characters to be displayed.

A string can be printed within a field.
The `%ms` conversion will **display a string in a field** of size `m`.
(A string with more than `m` characters will be printed in full, not truncated).
If the string has fewer than `m` characters, it will be **right-justified** within the field.
To force **left justification** instead, we can put a minus sign in front of `m`. 

The `m` and `p` values can be used in combination: a conversion specification of the form `%m.ps` causes the first `p`
characters of a string to be displayed in a field of size `m`.

_Secure Coding Tip_: **Don't use a untrusted string instead of a format string!!**
```C
    void print_string(const char *s)
    {
        printf(s);          // Don't do that!!!
        
        printf("%s", s);    // OK
    }
```
An untrusted string (comming from a user input) could contain any conversion specification and can therefore be 
used to read data from the stack.

The C library also provides **puts()**, which has only one argument (the string to be printed).
After writing the string, puts() always writes an additional new-line character.
```C
    int puts(const char *s) 
```
 
### Reading Strings

To read a string in a single step, we can either use `scanf()` or `gets()`.
As they read characters into an array, `scanf()` and `gets()` have no way to detect when it is full.
Consequently, they may store characters past the end of the array, causing undefined behavior.

_Secure Coding Tip_: **Don't use gets() at all!!**

**scanf()** can be made safer by using the conversion specification `%ns` instead of `%s`, where `n` is an 
integer indicating the maximum number of characters to be stored.
```C
    int scanf(const char *format, ...);  
```

Fortunately, there is an alternative to `gets()`.
The C library function **fgets()**, declared in `stdio.h`, reads a line from the specified stream and stores it into the string pointed 
to by `s`. It stops when either `(n-1)` characters are read, the newline character is read, or the end-of-file 
is reached.
```C
    char *fgets(char *s, int n, FILE *stream) 
```
On success, the function returns the same `s` parameter. 
If the End-of-File is encountered and no characters have been read, the contents of `s` remain unchanged and a null 
pointer is returned.

If we use `fgets()` to read a string from the **console window**, we can use the pre-defined **stdin** file stream.


## String I/O

The following finctions, declared in stdio.h, allow us to **read and write data using a string**.
 
The `sprintf()` and `sscanf()` functions write charachers into a string while the sscanf() function reads
characters from a string.

### Writing into a String
The **sprintf()** function is similar to printf, except that it writes output into a character array (pointed
to by its first argument).
The second argument is a format string identical to that used by **printf()**.
```C
    int sprintf(char *s, const char *format, ...);
```
When it is finished writing into a string, sprintf() adds a null character and returns the number of 
characters stored (not counting the null character).

`sprintf()` has a variety of uses:
* We can **format data** for output without actually writing it.
* It is convinient for **converting numbers** to character form.

The `snprintf()` function is the same as `sprintf()`, except for the additional parameter `n`.
No more than `n-1` characters will be written to the string, not counting the terminating null character, 
which is always written unless `n` is zero.

### Reading from a String

The **sscanf()** function is similar to `scanf()`, except that it reads from a string (pointed to by its first argument).
The second argument is a format string identical to that used by `scanf()`.
```C
    int sscanf(const char *s, const char *format, ...);
```
Like the `scanf()` function, `sscanf()` returns the number of data items successfully read and stored.
`sscanf()` returns `EOF` if it reaches the end of the string (marked by a null character) before finding the first item.

`sscanf()` is handy for **extracting data from a string** that war read by another input function.

One advantage of using `sscanf()` instead of `scanf()` is that we can examine an input line as many times as needed, 
not just once.
 

## References
* K. N. King. **C Programming, A Modern Approach.** W. W. Norton & Company, inc. 2nd Edition 2008
    * Chapter 13.5: Using the C String Library
    * Chapter 22.8: String I/O
    * Chapter 23.6: The <string.h> Header: String Handling
    
* [C Library - <string.h>](https://www.tutorialspoint.com/c_standard_library/string_h.htm) 
 
*Egon Teiniker, 2020-2021, GPL v3.0* 
