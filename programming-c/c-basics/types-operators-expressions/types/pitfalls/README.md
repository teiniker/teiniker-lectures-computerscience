# Number Mapping Pitfalls 

**Number Theory** is the branch of mathematics that deals with the properties 
of and relationships between numbers.

The very basics of Number Theory involve defining key **number sets**.
Different number sets take on different characteristics, and if we know that 
a number lies within a specific set, then we know that it possesses the 
characteristics which define the set. This allows us to study numbers and 
how they work together more easily.


## Number Sets 

The most common sets of numbers are:

* **Natural Numbers**: These are the numbers we use for counting objects: 
    
    _Definition:_ $\mathbb{N} = {1, 2, 3, 4, 5, 6, \dots}$

    Sometimes we extend the natural numbers by `0`:
    
    _Definition:_ $\mathbb{N_0} = {0, 1, 2, 3, 4, \dots}$

* **Integers**: Integers include natural numbers, their negatives, and zero.

    _Definition:_ $\mathbb{Z} = {\dots, -3, -2, -1, 0, 1, 2, 3, \dots}$


* **Rational Numbers**: A number is rational if it can be expressed as a fraction:

    _Definition:_ $\mathbb{Q} = \frac{p}{q}, \text{ where } p, q \in \mathbb{Z} \text{ and } q \neq 0$

* **Irrational Numbers**: Numbers that **cannot** be written as a fraction of two integers.

    _Definition:_ $\mathbb{I} = \mathbb{R} - \mathbb{Q}$

    _Examples:_ $\sqrt{2}$, $\pi$, $e$

* **Real Numbers**: All rational and irrational numbers together.

    _Definition:_ $\mathbb{R} = \mathbb{Q} \cup \mathbb{I}$
 
* **Complex Numbers**: Numbers are defined in a two dimentional plane where the have a real and an imaginary parts: $z = a + bi, \quad \text{where } a,b \in \mathbb{R}$
    and the **Imaginary Unit** is defined as: $i^2 = -1$

    _Examples:_ $3 + 2i$, $-1 - 4i$, $-i$


## Number Sets vs. C Types

When mapping mathematical sets of numbers to types in C, problems often arise.

### Integer Numbers

* **Natural numbers (including zero)** are mapped to **unsigned integer** types 
    (e.g. `unsigned int`).

* **Integers (positive and negative values)** are mapped to **signed integer** 
    types (e.g. `int`).

The problems in the mapping mainly result from the limitations of the data types 
in terms of their size, value range and representation. 

Here are the main challenges in detail:

* **Limited range of values**: Every integer type in C has a fixed range of values, 
    which is determined by its bit width.

* **Overflow and underflow**: If a value is outside the displayable range, an 
    overflow or underflow occurs without reporting an error.   

* **Signed vs. unsigned types**: Choosing between signed and unsigned integers 
    can lead to unexpected behavior, especially in arithmetic operations and 
    comparisons.
    * **Comparisons between signed and unsigned types**: Can lead to unexpected 
        results because the signed type is converted to unsigned.
    * **Negative values ​​in unsigned types**: Are interpreted as large positive 
        numbers, which can lead to logical errors.

* **Varying sizes**: The size of integer types can vary depending on the compiler 
    and platform. For example, an `int` may be 16 bits in size on a 8-bit system, 
    while it may be 32 or 64 bits in size on a 64-bit system.


### Real Numbers

Mapping real numbers (floating-point numbers) to **floating-point types** (`float`, 
`double`, `long double`, etc.) in the C programming language presents several 
challenges and potential issues. These problems stem from the inherent limitations 
of representing continuous real numbers within the discrete, finite structures 
of computer memory.

* **Inexact representation of decimal fractions**: Many decimal fractions cannot 
    be represented exactly in binary floating-point formats.

    _Example_: The decimal number `0.1` cannot be precisely represented in binary,
        resulting in a stored value that is slightly different from `0.1`.

* **Limited precision**: Floating-point types in C have a finite number of bits 
    to represent numbers, which restricts their precision. 
    
    _Example_: `float` typically uses `32 bits`, providing about 7 decimal digits 
    of precision.

    Numbers requiring more precision than the type can provide will be **rounded**, 
    leading to representation errors.

* **Rounding during operations**: Arithmetic operations on floating-point numbers 
    often involve rounding, which can introduce small errors.

    In iterative calculations or operations involving many floating-point 
    computations, small rounding errors can accumulate, leading to significant 
    deviations from expected results.

* **Non-Associativity of floating-point arithmetic**: Floating-point arithmetic 
    is not associative, meaning that the order of operations affects the result.

* **Inexact comparisons**: Due to rounding errors, exact comparisons between 
    floating-point numbers are unreliable.    

* **Overflow and underflow**: 
    * **Overflow**: Occurs when a number exceeds the largest representable value    
        for a floating-point type, resulting in infinity
    * **Underflow**: Occurs when a number is closer to zero than the smallest 
        representable positive normalized number, resulting in denormalized 
        numbers or zero.    

* **Special values handling**: Floating-point types can represent special values 
    like
    * **NaN (Not a Number)**: Represents undefined or unrepresentable values.
        Use the `isnan(x)` function from `math.h`.

    * **Infinity (+∞, -∞)**: Represents values beyond the representable range.
        Use the `isinf(x)` function from `math.h`. 

* **Inconsistent Behavior Across Different C Standards and Compilers**: Different C
    standards (C89, C99, C11, C18) and compilers may handle floating-point arithmetic 
    and representations differently, leading to inconsistencies in behavior and results.

## References

* [SEI CERT C Coding Standard: Integers](https://wiki.sei.cmu.edu/confluence/pages/viewpage.action?pageId=87152052)

* [SEI CERT C Coding Standard: Floating Point](https://wiki.sei.cmu.edu/confluence/pages/viewpage.action?pageId=87152181)

*Egon Teiniker, 2020-2024, GPL v3.0* 
