# Namespaces

C++ allows us to declare a `namespace` to create different **scopes for identifiers**.


_Example:_ Define a structure within a namespace.
```C++
namespace electronics
{
    struct Resistor 
    {
        uint32_t value;
        uint8_t tolerance;
    };
}

electronics::Resistor r;
r.value = 470; // in Ohm 
r.tolerance = 1; // in % 
printf("r = %d Ohm, %d%% tolerance\n", r.value, r.tolerance);
```
To use a type defined in a namespace, we must specify the **qualified name** 
`namespace::type`.

We can also employ a `using namespace` directive to import all the names in a `namespace`, 
so we would no longer need to use the fully qualified element name.

_Example:_ Import all names from a namespace.
```C++
namespace math
{
    struct Complex 
    {
        double re;
        double im;
    };
}

using namespace math;

Complex c;
c.re = 2.0;
c.im = 1.0;
printf("c = %3.2f + j%3.2f\n", c.re, c.im);
```

The `using namespace` enables us to omit the namespace qualification.

Use of a namespace is idiomatic C++ and is a **zero-overhead abstraction**. 
Just like the rest of a type’s identifiers, the namespace is erased by the 
compiler when emitting assembly code. 

In large projects, it’s incredibly helpful for **separating code in different libraries**.



## References

* Josh Lospinoso. **C++ Crash Course**. No Starch Press, 2019 
    * Chapter: Upgrading to Super C 

*Egon Teiniker, 2020-2023, GPL v3.0*
