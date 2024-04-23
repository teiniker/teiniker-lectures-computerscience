# Error Handling in C

Most of the C or even Unix function calls return `-1` or `NULL` in case of any error and set an error code `errno`. It is set as a global variable and indicates an error occurred during any function call. We can find various error codes defined in `error.h` header file.

So a C programmer can **check the returned values** and can take appropriate action depending on the return value. It is a good practice, to **set errno to 0 at the time of initializing a program**. A value of 0 indicates that there is no error in the program.

The C programming language provides two functions which can be used to display the text message associated with `errno`:
* The `perror()` function displays the string you pass to it, followed by a colon, a space, and then the textual representation of the current errno value.
* The `strerror()` function (from `string.h`), which returns a pointer to the textual representation of the current errno value.

_Example_: Using `errno` and `strerror()` to report an error
```C
    fp = fopen("unknown.txt", "r");
    if (fp == NULL) 
    {
        fprintf(stderr, "Error opening file: %d - %s\n", errno, strerror(errno));
        return EXIT_FAILURE;
    }
    else
    {
        return EXIT_SUCCESS;
    }
```

In case of program coming out after a **successful operation**, it is a common practice to exit with a value of `EXIT_SUCCESS` which is a macro and it is defined as `0`.

If we have an **error condition** in your program and we are coming out then we should exit with 
a status `EXIT_FAILURE` which is defined as `-1`.

## References

* [C - Error Handling](https://www.tutorialspoint.com/cprogramming/c_error_handling.htm)

* [errno.h](https://www2.hs-fulda.de/~klingebiel/c-stdlib/sys.errno.h.htm)


*Egon Teiniker, 2020-2022, GPL v3.0* 