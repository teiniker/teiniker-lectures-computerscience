# A Simple C Program

A Simple C program has the following form:

```C
<<directives>>

int main(void)
{
    <<statements>>
}
```

Even the simplest C program rely on three key language features:
* **Directives**: Commands that modify the program prior to compilation.
* **Functions**: Named blocks of executable code, of which `main()` is an example. 
* **Statements**: Commands to be performed when the program is run.

## Directives
Before a C program is compiled, it is first edited by a **preprocessor**.
Comments intended for the preprocessor are called **directives**.
The most used one is the `#include` directive.

_Example_: `#include <stdio.h>`
This directive states that the information in `stdio.h` is to be included into the 
program before it is compiled. `stdio.h` contains information about C's **standard I/O library**.

Directives always begin with a # character, which distinguishes them from other items in a C program.
By default, directives are only one line long. There is no semicolon or other special marker at the end of a directive.


## Functions

The term function comes from mathematics, where a function is a rule for computing a value when given one or more 
argutemts. C uses the term function more loosely.
In C, a function is simply a series of statements that have been grouped together and given a name.
Some functions compute a value, some don't.
A function that computes a value uses the `return` statement to specify what value it returns.

Functions fall into two categories which are either
* **written by the programmer** or
* **provided as part of the C implementation**. 
  We refer them as **library functions**, since they belong to a library of functions that are supplied with the compiler.

Although a C program may consist of many functions, only the `main()` function is **mandatory**.
`main()` is special: **it gets called automatically when the program is executed**.

The word `void` in parentheses indicates that `main()` has no arguments.

`main()` **returns a status code** that is given to the operating system when the program terminates.
The statement:
```C
    return 0;
```
has two effects:
* it causes the `main()` function to terminate.
* it indicates that the `main()` function returns a value of 0, which means no error.


## Statements 
A statement is a command to be executed when the program runs.
C requires that each statement end with a semicolon.

Note that **function calls** are also statements.
`printf()` is a powerful function used to **display string literals** and values of variables.


## Comments

The symbols `/*` marks the beginning of a comment and the symbol `*/` marks the end.

Comments may appear almost **anywhere in a program**, either on separate lines or on the same line as other program text.
Comments may extend **more than one line**.

C99 provides a second kind of comment, which begins with `//`.
This style of comment ends automatically at the end of a line. 


## References
K. N. King. **C Programming, A Modern Approach.** W. W. Norton & Company, inc. 2nd Edition 2008
 * Chapter 2: C Fundamentals
 
*Egon Teiniker, 2020-2022, GPL v3.0* 
