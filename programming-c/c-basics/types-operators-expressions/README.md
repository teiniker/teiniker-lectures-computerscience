# Types, Operators, and Expressions

Every variable must have a type, which specifies what kind of data it will hold.
C has a wide variety of types.
**Choosing the proper type is critical**, since the type affects how the variable is stored and what operations can be performed on the variable.

The type of a numeric variable determines the largest and smallest numbers that the variable can store, it also determines whether or not digits are allowed after the decimal point.

A variable of type `int` (**integer**) can store a whole number such as `0`, `1392` or `-2553`.
The range of possible values is limited. The largest `int` value is **typically 2 147 483 647 (32 bits)** but 
can by as **small as 32 767 (16 bits)**. 

A variable of type `float` (**floating-point**) can store much larger numbers than an `int` variable.
float variables can store numbers with digits after the decimal point, like `3.1415`.

`float` variables have **drawbacks**:
* Arithmetic on `float` numbers may be **slower** than arithmetic on int numbers.
* The value of a `float` variable is often just an aproximation of the number that was stored in it, 
    thanks to **rounding error**.


* [Variables and Constants](variables-and-constants/)

* [Formated Output](formated-output)

* [Data Types](types)
  * boolean
  * integer
  * floating-point 
  * characters 
  * strings 

* [Operators](operators) 

* [Expressions](expressions)

* [Type Conversions](type-conversions)
    * [Double Conversion](type-conversions/double-conversion)
    * [Rounding](type-conversions/rounding)
    * Exercise: [sensor-data](type-conversions/sensor-data-exercise), ([model solution](type-conversions/sensor-data))


## References
* K. N. King. **C Programming, A Modern Approach**. W. W. Norton & Company, inc. 2nd Edition 2008
  * Chapter 3: Formatted Input/Output 
  * Chapter 4: Expressions  
  * Chapter 7: Basic Types
  * Chapter 20: Low-Level Programming
  
*Egon Teiniker, 2020-2023, GPL v3.0* 
