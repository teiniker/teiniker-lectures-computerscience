# Example: Hello World

## Program Structure 

Every C program consists of:
 * one or more **#include<>** statements and
 * at least one **function** called **main()**.

```C
#include <stdio.h>

int main(void)
{
    printf("Hello world!\n");
	return 0;
}
```
Include statements insert the content of **header files** into the program.
The **stdio.h** header file contains declarations of functions of the **C standard 
library** that are responsible for **input and output**:
```C
//...
extern int printf (const char *__restrict __format, ...);
extern int sprintf (char *__restrict __s, const char *__restrict __format, ...);
extern int fprintf (FILE *__restrict __stream, const char *__restrict __format, ...);
//...
``` 

Whenever we start a program, the **main()** function is executed. 
A **function in C** is similar to a mathematical function. It receives parameters and delivers a result.
In our example main() does not get any parameters (**void**) and returns a result of the type integer (**int**).
The implementation of main() calls the **printf()** function and returns the value **0** as the result.
The result of main() is used by the operating system to find out whether the program was successful or not.

## Compiling the Program
A C compiler takes a source file and converts it into an executable file:
```
$ gcc -o hello hello.c 
$ ./hello 
Hello world!
```
In fact, this is not just one task, but many individual steps.

### Preprocessing
The preprocessor executes all instructions in the source file that start with #. 
In our example, #include is executed in order to copy the content of the header file stdio.h into 
the source file.
We can make this step visible by explicitly calling the preprocessor:
```
$ cpp hello.c _hello.c
```
The generated file contains more than 700 lines of code.

### Compiling
In the next step, the C compiler generates the **assembly code** from the source code:
```
$ gcc -Wall -g -S _hello.c
```
So-called **compiler flags** can be set, which influence the compilation process. 
All warnings should be output (**-Wall**) and debugging information should be inserted (**-g**).
The **-S** option tells the compiler to output the assembly code.

A second tool, the **Assembler** **as**, converts the assembly code into a binary code - 
an **object file** (**hello.o**) is created.
```
$ as -o hello.o _hello.s
```
The object file is a binary file, but not yet executable.

### Linking
In the last step, one or more object files are linked together with the necessary **libraries** 
(at least the standard library).
```
$ gcc -o hello hello.o
```
Libraries in C consist of a number of precompiled object files. 
The linker fetches the necessary object files from the library and uses them to build the **executable**.
 
 ## References
K. N. King. **C Programming, A Modern Approach.** W. W. Norton & Company, inc. 2nd Edition 2008
 * Chapter 2: C Fundamentals

 
*Egon Teiniker, 2020, GPL v3.0* 