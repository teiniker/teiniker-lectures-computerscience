# Types, Operators, and Expressions

Every variable must have a type, which specifies what kind of data it will hold.
C has a wide variety of types.
**Choosing the proper type is critical**, since the type affects how the variable 
is stored and what operations can be performed on the variable.

The type of a numeric variable determines the largest and smallest numbers that 
the variable can store, it also determines whether or not digits are allowed after 
the decimal point.

A variable of type `int` (**integer**) can store a whole number such as `0`, `1392` 
or `-2553`.
The range of possible values is limited. The largest `int` value is 
**typically 2 147 483 647 (32 bits)** but can by as **small as 32 767 (16 bits)**. 

A variable of type `float` (**floating-point**) can store much larger numbers than 
an `int` variable.
`float` variables can store numbers with digits after the decimal point, like `3.1415`.

`float` variables have **drawbacks**:
* Arithmetic on `float` numbers may be **slower** than arithmetic on `int` numbers.
* The value of a `float` variable is often just an aproximation of the number that 
  was stored in it, thanks to **rounding error**.

The topics in this chapter are structured as follows:

* **Data Types**
  * [Boolean](types/boolean)\
      Since C99, we have the macros `bool`, `true` and `false`, which stand for `1` 
      and `0`, and can be used for Boolean variables.

  * [Integer Numbers](types/integer)\
      Each integer type represents a finite range of integer numbers. 
      * Unsigned integer types represent values that can be only zero or positive.
      * Signed integer types represent values that can ne negative, zero, or positive.
    
  * [Floating-Point Numbers](types/floating-point)\
      Floating-point is the most common representation for real numbers in computers.

  * [Characters](types/characters)\
      Character data include alphabethic symbols, punctuation marks, numeric digits, spaces, tabs, and so on.

  * [Strings](types/strings)\
      C uses character arrays to store strings.

  * [Variables and Constants](types/variables-and-constants/)

  * [Formated Output](types/formated-output)

  * [Pitfalls in Mapping Numbers](types/pitfalls/README.md)

* **Operators** 
    * [Arithmetic Operators](operators/arithmetic/)

    * [Logical Operators](operators/logical/)
    
    * [Assert Statements](operators/assert/)

    * [Bitwise Operators](operators/bitwise/)  

* [**Expressions**](expressions)
    * [Double Comparing](expressions/double-comparing/)
    * Exercise: [Resistor Circuit](expressions/resistor-exercise/)
        ([model solution](expressions/resistor/))
    * [Type Conversions](expressions/type-conversions/)
    * Exercise: [Mean Value](expressions/mean-value-exercise/)
        ([model solution](expressions/mean-value/))          
    * Exercise: [Sensor Data](expressions/sensor-data-exercise/)
        ([model solution](expressions/sensor-data/))          
    * Exercise: [Pythagoras](expressions/pythagoras-exercise)
        ([model solution](expressions/pythagoras))

## References
* [YouTube: CS50 - Data Types](https://youtu.be/Fc9htmvVZ9U)
* [YouTube: CS50 - Operators](https://youtu.be/f1xZf4iJDWE) 

* Online Converters
    * [Integers](https://www.rapidtables.com/convert/number/decimal-to-binary.html)
    * [IEEE754 float](https://www.binaryconvert.com/convert_float.html)
    * [Unicode, UTF-8](https://onlinedevtools.in/unicode-converter)

* [C Data Types (Programiz)](https://www.programiz.com/c-programming/c-data-types)

* [C Data Types (Tutorialspoint)](https://www.tutorialspoint.com/cprogramming/c_data_types.htm)

* K. N. King. **C Programming, A Modern Approach**. W. W. Norton & Company, inc. 2nd Edition 2008
  * Chapter 3: Formatted Input/Output 
  * Chapter 4: Expressions  
  * Chapter 7: Basic Types
  * Chapter 20: Low-Level Programming
  
*Egon Teiniker, 2020-2023, GPL v3.0* 
