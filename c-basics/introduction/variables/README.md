# Variables

Most programs need to perform a series of calculations before producting output, and thus need a way to **store data temporarily** during program execution.
In C these storage locations are called **variables**.

## Types
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
 
*Egon Teiniker, 2020-21, GPL v3.0* 
