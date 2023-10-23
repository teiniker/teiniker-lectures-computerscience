# Variables

Most programs need to perform a series of calculations before producting output, and thus need a way to **store data temporarily** during program execution.
In C these storage locations are called **variables**.

## Declarations

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

## Assignment

A variable can be given a value by means of assignment.

_Example_: Assignments
```C
    int value;
    value = 7;
    float voltage = 0.3f;
```
Before a variable can be assigned a value, it must be declared.

A constant assigned to a `float` variable usually contains a decimal point.
It is best to append the letter `f` to a constant that contains a decimal point if the number is assigned to a `float` 
variable.

In general, the right side of an assignment can be a formular (**expression**) involving constants, variables, 
and operators.


## Printing the Value of a Variable
We can use the function `printf()`, which is part of the **C standard library** (declared in `stdio.h`) to display the curent value of a variable.

_Example_: Printing the value of an integer variable
```C
    int i = 7;
    printf("value =%d\n", i);
```
We use a placeholder `%d` to indicate where the value of `i` should be filled in as a **decimal number** during printing.
The special character `\n` will force `printf()` move into a new line.

There are also placeholders which allows us to print an integer number in **hexadecimal** `%x` or **octal** `%o`. For singned integer values we can use `%u`.


## References
K. N. King. **C Programming, A Modern Approach.** W. W. Norton & Company, inc. 2nd Edition 2008
 * Chapter 2: C Fundamentals
 
*Egon Teiniker, 2020-23, GPL v3.0* 
