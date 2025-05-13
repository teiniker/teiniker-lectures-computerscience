# File Handling

When dealing with files in C, there are two types of files we should know about:

* **Text files**: 
    When we open those files, we will see all the contents within the file as plain text. We can easily edit or delete the contents.

* **Binary files**:
    They store the content in binary form (0's and 1's).
    They can hold a higher amount of data, are not readable easily.


## Working with Files

### File Pointer
When working with files, you need to declare a **pointer of type FILE**. 
This declaration is needed for communication between the file and the program.
```C
    FILE *fp;
```

The inner structure of the `FILE` type is actually implementation-dependent, 
which means its structure may vary across different compilers or platforms. 
The exact details of the FILE structure are not specified by the C standard.

However, the `FILE` structure typically contains various fields that store 
information about the associated file stream. These fields may include:

1. **File Descriptor**: A file descriptor is an integer value that represents 
the file opened by the `FILE` structure. It is used by the operating system to 
identify the file when performing file-related operations.

2. **Buffering Information**: The `FILE` structure may contain information about 
buffering, such as a buffer for input or output operations. Buffering improves 
performance by reducing the number of system calls to read or write data.

3. **Current Position**: The `FILE` structure usually maintains the current 
position within the file, which keeps track of the next character to be read 
from or written to.

4. **Error and End-of-File Indicators**: There are typically fields that store 
information about error conditions and end-of-file status. These indicators help 
in detecting and handling errors or determining if the end of the file has been reached.

5. **File Mode and Type**: The `FILE` structure may include information about 
the file's open mode (e.g., read, write, append) and file type (e.g., text or binary).

6. **Other Control Flags**: Various control flags might be present to manage 
the behavior of the file stream, such as flags for text/binary mode, buffering 
options, and more.

Keep in mind that the structure of `FILE` is typically considered an implementation detail and
it is recommended to use the provided functions and macros from the standard library, such 
as `fopen()`, `fread()`, `fwrite()' , etc., to interact with files through the `FILE` lpointers 
in a portable manner.


### Opening a File 

Opening a file is performed using the `fopen()` function defined in the `stdio.h` header file.

The syntax for opening a file in standard I/O is:
```C
    fp = fopen("filename","mode");
```

Possible opening **modes** in standard I/O are:

* `"r"` : Open for **reading in text mode**.
    If the file does not exist, `fopen()` returns `NULL`.

* `"rb"`: Open for **reading in binary mode**.
    If the file does not exist, `fopen()` returns `NULL`.

* `"w"` : Open for **writing in text mode**. 
    If the file exists, its contents are overwritten. If the file does not exist, it will be created.

* `"wb`: Open for **writing in binary mode**.
    If the file exists, its contents are overwritten. If the file does not exist, it will be created.

* `"a"` : Open for **append**. Data is added to the end of the file.
    If the file does not exist, it will be created.

* `"ab"`: Open for **append in binary mode**. Data is added to the end of the file.
    If the file does not exist, it will be created.

* `"r+"`: Open for both **reading and writing**.    
    If the file does not exist, `fopen()` returns `NULL`.

* `"rb+"`: Open for both **reading and writing in binary mode**.
    If the file does not exist, `fopen()` returns `NULL`.

* `"w+"`: Open for both **reading and writing**.
    If the file exists, its contents are overwritten. If the file does not exist, it will be created.

* `"wb+"`: Open for both **reading and writing in binary mode**.
    If the file exists, its contents are overwritten. If the file does not exist, it will be created.

* `"a+"`: Open for both **reading and appending**.
    If the file does not exist, it will be created.

* `"ab+"`: Open for both **reading and appending in binary mode**.
    If the file does not exist, it will be created.


### Closing a File
The file (both text and binary) should be closed after reading/writing.

Closing a file is performed using the `fclose()` function.
```C
    fclose(fp);
```
Here, `fp` is a `FILE` pointer associated with the file to be closed.


### Reading and Writing to a Text File

For reading and writing to a text file, we use the functions `fprintf()` and `fscanf()`.

They are just the file versions of `printf()` and `scanf()`. 
The only difference is that `fprintf()` and `fscanf()` expects a pointer to the structure `FILE`.

_Example_: Writing to a text file
```C
    fprintf(fp, "%5.3lf\n", value);
```

_Example_: Reading from a text file
```C
    fscanf(fp, "%lf", &value);
```

Other functions like `fgetchar()`, `fgets()`, `fputc()` etc. can be used in a similar way.


### Reading and Writing to a Binary File

Functions `fread()` and `fwrite()` are used for reading from and writing to a file on the disk respectively in case of binary files.

To **write into a binary file**, we need to use the `fwrite()` function. 
The functions take four arguments:
* address of `data` to be written to the disk
* sizeof() `data` to be written to the disk
* `NUMBER_OF_VALUES` number of such type of data
* `fp` pointer to the file we want to write to.


_Example_: Writing to a binary file
```C
    fwrite(data, sizeof(double), NUMBER_OF_VALUES, fp);
```

To read data from a binary file, we use the function `fread()` 
which also takes the same four arguments:
* address of `data` to be read from disk
* `sizeof()` data to be read from disk
* `NUMBER_OF_VALUES` number of such type of data
* `fp` pointer to the file we want to read from.

_Example_: Reading from a binary file
```C
    for(int i=0; i< NUMBER_OF_VALUES; i++)
    {
        fread(&data[i], sizeof(double), 1, fp);
        printf("%2d  %lf\n", i, data[i]);
    }
```

If we have many records inside a file and need to **access a record at 
a specific position**, we need to loop through all the records before 
it to get the record.

An easier way to get to the required data can be achieved using `fseek()`
which seeks the cursor to the given record in the file, and takes the following 
parameters:
* pointer to the file 
* offset which defines the position of the record to be found
* specifies the location where the offset starts:
    * `SEEK_SET`: Starts the offset from the beginning of the file.
    * `SEEK_END`: Starts the offset from the end of the file.
    * `SEEK_CUR`: Starts the offset from the current location of the cursor in the file.


_Example_: Using `fseek()` to move the cursor to the 5th element (starting with 0) in the file
```C
    fseek(fp, sizeof(double) * 5, SEEK_SET);
```


## References

* [C File Handling](https://www.programiz.com/c-programming/c-file-input-output)

* [YouTube (CS50): File Pointers](https://youtu.be/bOF-SpEAYgk)

* [YouTube (Jacob Sorber): Reading and Writing Files in C, two ways (fopen vs. open)](https://youtu.be/BQJBe4IbsvQ)

*Egon Teiniker, 2020-2023, GPL v3.0* 
