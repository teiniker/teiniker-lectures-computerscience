# Functions

Functions are the building blocks of C programs.
Using functions, we can divide a program into small pieces that are easier to understand and modify.

## Defining Functions 

```C
return-type function-name ( parameters )
{
    declarations
    statements
}
```

The **return-type** is the type of data that the function returns each time it is called.
**Functions may not return arrays**.
Specifying that the return type is `void` indicates that the function doesn't return a value.
Since C99, it is illegal to omit the return type of a function.

After the function name comes a list of **parameters**. Each parameter must have a type.
If a function has no parameters, we write the word `void` in parentheses.

The **body of a function** may include both declarations and statements.
Variables declared in the body of a function belong exclusively to that function. They can't be examined
or modified by other functions.
Since C99, variable declarations and statements can be mixed, as long as each variable is
declared prior to the first statement that uses the variable.

## Calling Functions
A **function call** consists of a function name followed by a list of arguments, enclosed in parenthesis.
A call to a void function is always followed by a semicolon to turn it into a statement.
```C
    print_binary(0xff);
```

A call to a non-void function produces a value that can be stored in a variable.
```C
    int result = serial(120, 470);
```

The value returned by a non-void function can always be discarded if it's not needed.

_Example_: `printf()` returns the number of characters that it prints.
```C
int printf (const char *__restrict __fmt, ...)
```

## Function Declaration

We have to arrange the C program so that the definition of each function call precedes all its calls
(**call-before-definition**). 
But, such an arrangement doesn't always exist, and even when it does, it may make the program 
hard to understand.
Fortunately, C offers a better solution: **declare each function before calling it**.

A function declaration resambles the first line of a function definition with a semicolon added at the end:
```C
return-type function-name ( parameters );
``` 
A function prototype doesn't have to specify the names of the function's parameter, as long as their
types are present.
Since C99, calling a function for which the compiler has not yet seen a declaration or definition is an error.

## Arguments

**Parameters** appear in function definitions. They are dummy names that represent values to be supplied when 
the function is called.

**Arguments** are expressions that appear in function calls. 

In C, **arguments are passed by value**: when a function is called, each argument is evaluated and its value assigned 
to the corresponding parameter.
Since the parameter contains a copy of the argument's value, any changes made to the parameter during the
execution of the function don't affect the argument.
Each parameter behaves like a variable that has been initialized to the value of the matching argument.

**Arrays** are often used as arguments.
```C
void vector_print(int a[])
{
    //...
}
``` 
C doesn't provide any easy way for a function to determin the length of an array passed to it.
Instead, we will have to supply the length as an additional argument.
```C
void vector_print(int n, int a[])
{
    //...
}
``` 
Note that a function has no way to check that we have passed it the correct array length!

Another important thing to know is that a function is allowed to change the elements of an array paremeter, and the 
change is reflected in the corresponding argument.


## The `return` Statement

A non-`void` function must use the `return` statement to specify what value it will return.
```C
    return expression ;
``` 
The **expression** is often just a constant or variable.
If the type of the expression in a `return` statement doesn't match the functions return type, the expression will be 
implicitly convert to the return type.

`return` statements may appear in functions whose return type is `void`, provided that no expression is given.
```C
    return ;
``` 
Using `return` in that case is unnecessary, since the function will return automatically after its last statement 
has been executed.

## Program Termination
Since `main()` is a function, it must have a return type.
Normally, the return type of `main()` is `int`.
Omitting the return type of a function isn't legal in C99.

The value returned by main is a status code that can be tested when the program terminates.
`main()` should **return 0 if the program terminates normally**.
To indicate abnormal termination, `main()` should return a value other than 0.

Another way to terminate a program is calling the `exit()` function, which belongs to `<stdlib.h>`
The argument passed to exit() has the same meaning as main()'s return value.
Both indicate the program's status at termination.

There are two macros defined in `<stdlib.h>` which can be used instead of 0 and 1: `EXIT_SUCCESS` and `EXIT_FAILURE`

The difference between return and `exit()` is that `exit()` causes program termination regardless of which function 
calls it. The `return` statement causes program termination only when it appears in the `main()` function.


## Functions in C++

Some additional mechanisms are available for functions in C++:

* [Function Overloading](../../../programming-c++/basics/functions/function-overloading/)
    Function overloading in C++ is a feature that allows **multiple functions to have the same name** 
    with **different parameters**, enabling different implementations based on the arguments passed 
    to them.

* [Default Arguments](../../../programming-c++/basics/functions/default-arguments/)
    Default parameters allow functions to be called with fewer arguments than they are defined with, 
    by **specifying default values for some parameters**.

* [References](../../../programming-c++/basics/functions/references/)
    In C++ functions, references are used as parameters to allow the function to 
    **modify the original argument** passed, or to **avoid copying large objects** for efficiency.

## References
* [YouTube: CS50 - Functions ](https://youtu.be/n1glFqt3g38)
* K. N. King. **C Programming, A Modern Approach.** W. W. Norton & Company, inc. 2nd Edition 2008
  * Chapter 9: Functions
 
*Egon Teiniker, 2020, GPL v3.0* 
