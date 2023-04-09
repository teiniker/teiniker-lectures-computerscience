# Strings

## String Literals 

A **string literal** is a sequence of characters enclosed within **double quotes**:
```C
    "This is a string literal"
```
We have used string literals often in calls of `printf()` and `scanf()` functions. 

**C treats string literals as character arrays**.

When a C compiler encounters a string literal of length `N` in a program, it sets aside `N+1` bytes of memory
for the string.
This area of memory will contain the characters in the string plus one extra character - the 
**null character** - to mark the end of the string.
The null character is a byte whose bits are all zero `0x00`, so it is represented by the `'\0'` escape sequence. 

Since a string literal is stored as an array, the compiler treats it as a **pointer** of type `char *`.
In general, we can use a string literal wherever C allows a `char *` pointer.

_Example_: String literal
```C=
    char *s;
    s = "This is a string literal";

    assert(s[0] == 'T');
    assert(s[1] == 'h');
    assert(s[2] == 'i');
    //...
    assert(s[23] == 'l');
    assert(s[24] == '\0');
    assert(s[24] == 0x00);
```
Note that the assignment in the example doesn't copy the characters, it makes `s` point to the first character of 
the string literal.

**String literals are stored in the .text segment**, therefore, a program that tries to change a string
literal may crash or behave erratically.

A **string literal containing a single character** isn't the same as a character constant:
* The string literal "A" is represented by a pointer to a memory location that contains the character 'A' 
    (followed by a null character).
* The character constant 'A' is represented by an integer (the numerical code for the character).

_Example_: String literal containing a single character
```C
    char *c = "A";
    assert(c[0] == 'A');
    assert(c[1] == '\0');
```

A **string literal may be empty**. Thus, the string `""` is stored as a single null character.

_Example_: Empty string literal
```C
    char *e = "";
    assert(e[0] == '\0');
```


## String Variables
Any **one-dimensional array of characters** can be used to store a string, with the understanding that the string is
terminated by a null character.

_Example_: String variable (char array)
```C
    char s[STR_LEN + 1]  = "This is a string variable";

    assert(s[0] == 'T');
    assert(s[1] == 'h');
    assert(s[2] == 'i');
    //...
    assert(s[24] == 'e');
    assert(s[25] == '\0');
```
The compiler will put the characters from `"This is a string variable"` in the `s` array and adds a null character.
C views this assignment as an abbreviation for an array initializer:
```C
    char s[STR_LEN + 1]  = {'T','h','i','s',' ','i','s',' ','a',' ','s','t','r','i','n','g',' '
                           ,'v','a','r','i','a','b','l','e','\0'};
```
If the initializer is too short to fill the string variable, the compiler adds extra null characters.


This approach is simple, but has significant **difficulties**:
* It is sometimes hard to tell whether an array of chars is being used as a string.
* There is no faster way to determine the length of a string than a character-by-character search for 
    the null character.

When declaring an array of characters that will be used to hold a string, **always make the array one character
longer than the string**, because of the C convention that every string is terminated by a null character.

The **length of a string** depends on the position of the terminating null character, not on the length of the array
in which the string is stored.
An array of `N+1` characters can hold strings of various lengths, ranging from the empty string to strings of
length `N`.
```C
dump: 54 68 58 73 20 69 73 20 61 20 73 74 72 69 6e 67 20 76 61 72 69 61 62 6c 65 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
```

Let's compare the following string declarations:
```C
    char s[]  = "This is a string variable";    // declares an array 

    char *ptr = "This is a string variable";    // declares a pointer
```
Because of the close relationship between arrays and pointers, we can use either version as a string.
Any function expecting to be passed a character array or character pointer will accept both versions as an argument.

There are significant differences between the two:
* In the **array version**, the characters stored in `s[]` **can be modified** like the elements of an array.
* In the **pointer version**, `ptr` points to a string literal which **should not be modified**. 

If we need a string that can be modified, it is our responsibility to set up an array of characters in which to store
the string.
Another possibility is to make `ptr` point to a dynamic allocated string.

## Dynamic Allocated Strings
Dynamic storage allocation is often useful for working with strings because it can be hard to anticipate how long these 
arrays need to be.

The `malloc()` function allocates a block of size bytes und returns a pointer to it.
C guarantees that a `char` value requires exactly one byte of storage (`sizeof(char) == 1`).

_Example_: Dynamic allocated string
```C
    char *d = malloc(str_len+1);
    //...
    free(d);
```
Again, don't forget to include room for the null character.

## Examples

* [String Literals](string-literals)
* [String Variables](string-variables)    
* [Dynamic Allocated Strings](string-dynamic)    
* **Exercises**
    * [string-length](string-length-exercise) 
        ([Model Solution](string-length))
    * [string-number-of](string-number_of-exercise)
        ([Model Solution](string-number_of))
    * [string-operations](string-operations-exercise)
        ([Model Solution](string-operations))    
    * [string-base64](string-base64-exercise)
        ([Model Solution](string-base64))
    * [string-message](string-message-exercise)
        ([Model Solution](string-message))


## References
* K. N. King. **C Programming, A Modern Approach.** W. W. Norton & Company, inc. 2nd Edition 2008. 
    * Chapter 13: Strings
    * Chapter 17.2: Dynamically Allocated Strings
* [C Standard Library - string.h](https://github.com/teiniker/teiniker-lectures-computerscience/tree/master/c-std-lib/string)
    
*Egon Teiniker, 2020-2021, GPL v3.0* 
