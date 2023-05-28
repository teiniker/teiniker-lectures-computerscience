# auto Initialization
C often requires you to repeat type information more than once. 
In C++, you can express a variable’s type information just once by utilizing the `auto` keyword. 
The compiler will know the variable’s type because it knows the type of the value being used to 
initialize the variable.

_Example:_ Defining a variable
```C++
    auto pi = 3.141592653589793;    // double constant
    printf("pi = %f\n", pi);
```
With `auto`, the compiler deduces the type on the right side of the equal 
sign `=` and sets the variable’s type to the same.

_Example:_ Result of a function call
```C++
    auto result = fibonacci(5);
    for(auto i = 0; i < 5; i++)
    {
        printf("fibonacci[%d] = %d\n", i, result[i]);
    }
    free(result);
```


The `auto` keyword is easier to read and is more amenable to **code refactoring** 
than explicitly declaring a variable’s type.
The `auto` keyword makes the compiler do all the work of type deduction for us.


## References

* Josh Lospinoso. **C++ Crash Course**. No Starch Press, 2019 
    * Chapter: Upgrading to Super C 

*Egon Teiniker, 2020-2023, GPL v3.0*