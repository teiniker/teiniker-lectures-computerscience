# File Handling

When dealing with files in C, there are two types of files we should know about:

* **Text files**: 
    When we open those files, we will see all the contents within the file as plain text. We can easily edit or delete the contents.

* **Binary files**:
    They store the content in binary form (0's and 1's).
    They can hold a higher amount of data, are not readable easily.


## Working with Files

### File Pointer
When working with files, you need to declare a **pointer of type file**. This declaration is needed for communication between the file and the program.
```C
    FILE *fptr;
```

### Opening a File 

Opening a file is performed using the `fopen()` function defined in the `stdio.h` header file.

The syntax for opening a file in standard I/O is:
```C
    fptr = fopen("filename","mode");
```

Possible opening **modes** in standard I/O are:

* `"r"` : Open for reading in text mode.
    If the file does not exist, `fopen()` returns `NULL`.

* `"rb"`: Open for reading in binary mode.
    If the file does not exist, `fopen()` returns `NULL`.

* `"w"` : Open for writing in text mode. 
    If the file exists, its contents are overwritten. If the file does not exist, it will be created.

* `"wb`: Open for writing in binary mode.
    If the file exists, its contents are overwritten. If the file does not exist, it will be created.

* `"a"` : Open for append. Data is added to the end of the file.
    If the file does not exist, it will be created.

* `"ab"`: Open for append in binary mode. Data is added to the end of the file.
    If the file does not exist, it will be created.

* `"r+"`: Open for both reading and writing.    
    If the file does not exist, `fopen()` returns `NULL`.

* `"rb+"`: Open for both reading and writing in binary mode.
    If the file does not exist, `fopen()` returns `NULL`.

* `"w+"`: Open for both reading and writing.
    If the file exists, its contents are overwritten. If the file does not exist, it will be created.

* `"wb+"`: Open for both reading and writing in binary mode.
    If the file exists, its contents are overwritten. If the file does not exist, it will be created.

* `"a+"`: Open for both reading and appending.
    If the file does not exist, it will be created.

* `"ab+"`: Open for both reading and appending in binary mode.
    If the file does not exist, it will be created.


### Closing a File
The file (both text and binary) should be closed after reading/writing.

Closing a file is performed using the `fclose()` function.
```C
    fclose(fptr);
```
Here, `fptr` is a file pointer associated with the file to be closed.


### Reading and Writing to a Text File

For reading and writing to a text file, we use the functions `fprintf()` and `fscanf()`.

They are just the file versions of `printf()` and `scanf()`. 
The only difference is that `fprintf()` and `fscanf()` expects a pointer to the structure `FILE`.

_Example_: Writing to a text file
```C
    fprintf(fptr, "%2d   %5.3lf\n", i, value);
```

_Example_: Reading from a text file
```C
    fscanf(fptr, "%d %lf", &i, &value);
```

Other functions like `fgetchar()`, `fputc()` etc. can be used in a similar way.


### Reading and Writing to a Binary File

Functions `fread()` and `fwrite()` are used for reading from and writing to a file on the disk respectively in case of binary files.

_Example_: Writing to a binary file
```C
    
```

_Example_: Reading from a binary file
```C
    
```








## References

* [C File Handling](https://www.programiz.com/c-programming/c-file-input-output)

* [YouTube (CS50): File Pointers](https://youtu.be/bOF-SpEAYgk)

* [YouTube (Jacob Sorber): Reading and Writing Files in C, two ways (fopen vs. open)](https://youtu.be/BQJBe4IbsvQ)

*Egon Teiniker, 2020-2022, GPL v3.0* 