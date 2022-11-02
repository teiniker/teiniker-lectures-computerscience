# Type Conversion

Frequently, a value represented in one type (for example, float) must be 
represented in a different type (for example, int).

Values can be implicitly or explicitly converted from one type to another.

* We use the **cast operator** to perform **explicit conversions**.
  To perform a cast, place a type name in parentheses just before the expression.
  The result of the conversion migt not be equal to the original value.
  _Example_:  
```C
    double value = 3.8415;
    int value_cast = (int)value;
```

* **Implicit conversion** occurs **automatically** in expressions as required.
    The rules concerning witch values are implicity converted to which types are somewhat complicated and involve three concepts: integer conversion rank, integer promotions, and the usual arithmetic conversions.

## References

* Robert C. Seacord. Effective C. No Starch Press, 2020
    * Chapter 3: Arithmetic Types

*Egon Teiniker, 2020-2021, GPL v3.0* 