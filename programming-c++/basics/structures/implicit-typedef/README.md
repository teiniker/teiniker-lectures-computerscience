# Implicit typedef of struct, union, and enum
C++ treats type tags as implicit typedef names. 

In C, when you want to use a struct, union, or enum, you have to assign a name to the 
type you’ve created using the `typedef` keyword.

_Example:_ Define and use a structure type
```C++
struct Resistor 
{
    uint32_t value;
    uint8_t tolerance;
};

Resistor r;
r.value = 470;  
r.tolerance = 1;  
```

This is more convenient and saves some typing.

Note the naming convention, in C++ we **capitalize types**.


## References

* Josh Lospinoso. **C++ Crash Course**. No Starch Press, 2019 
    * Chapter: Upgrading to Super C 

* [Naming Convention: W3 SChools C++ Tutorial](https://www.w3schools.com/cpp/default.asp)

*Egon Teiniker, 2020-2023, GPL v3.0*
