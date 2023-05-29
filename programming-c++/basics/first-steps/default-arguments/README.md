# Default Arguments

In C++, functions can have default arguments, which are 
**values assigned to parameters** if the caller of the function 
does not provide a corresponding value.

Default arguments provide a convenient way to define functions with 
flexible parameters and improve user-friendliness by reducing the 
number of required arguments.

Using default arguments allows for more flexible function definitions, 
as the caller has the option to omit some or all of the arguments. 
**If the caller omits an argument, the function automatically uses the 
predefined default value**.

The syntax for setting default arguments is typically done in the function 
signature, where the parameter and its default value are specified.

_Example:_ Function with default argument
```C++
Resistor new_resistor(uint32_t value, uint8_t tolerance = 1)
{
    Resistor r = {value, tolerance};
    return r;
}

Resistor r = new_resistor(470); // tolerance = 1
```

It's important to note that default arguments are typically specified at 
the end of the parameter list. This means you need to first specify the 
parameters without default values, followed by the parameters with 
default values. 


## References

* [Default arguments](https://en.cppreference.com/w/cpp/language/default_arguments) 

*Egon Teiniker, 2020-2023, GPL v3.0*
