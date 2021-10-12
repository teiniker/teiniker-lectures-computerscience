# A Simple Program

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
The statement
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

## Variables and Assignment

Most programs need to perform a series of calculations before producting output, and thus need a way to **store data 
temporarily** during program execution.
In C these storage locations are called **variables**.

### Types
Every variable must have a type, which specifies what kind of data it will hold.
C has a wide variety of types.
Choosing the proper type is critical, since the type affects how the variable is stored 
and what operations can be performed on the variable.

The type of a numeric variable determines the largest and smallest numbers that the variable can
store, it also determines whether or not digits are allowed after the decimal point.

A variable of type `int` (**integer**) can store a whole number such as `0`, `1392` or `-2553`.
The range of possible values is limited. The largest `int` value is **typically 2 147 483 647 (32 bits)** but 
can by as **small as 32 767 (16 bits)**. 

A variable of type `float` (**floating-point**) can store much larger numbers than an `int` variable.
float variables can store numbers with digits after the decimal point, like `3.1415`.

`float` variables have **drawbacks**:
* Arithmetic on `float` numbers may be **slower** than arithmetic on int numbers.
* The value of a `float` variable is often just an aproximation of the number that was stored in it, 
    thanks to **rounding error**.

### Declarations

Variables must be declared **before they can be used**.
To declare a variable, we first specify the typ of the variable, then its name.

_Example_: Variable declarations
```C
    int value;
    float voltage;
```
Notice that each declaration ends with a semicolon.

Since C99, declarations don't have to come before statements.
Like in C++ or Java, we don't declare variables until they are first needed.

### Assignment

A variable can be given a value by means of assignment.

_Example_: Assignments
```C
    int value;
    value = 7;
    float voltage = 0.3f;
```
Before a variable can be assigned a value, it must be declared.

A constant assigned to a `float` valiable usually contains a decimal point.
It is best to append the letter `f` to a constant that contains a decimal point if the number is assigned to a `float` 
variable.

In general, the right side of an assignment can be a formular (**expression**) involving constants, variables, 
and operators.

## References
K. N. King. **C Programming, A Modern Approach.** W. W. Norton & Company, inc. 2nd Edition 2008
 * Chapter 2: C Fundamentals
 
*Egon Teiniker, 2020-21, GPL v3.0* 
