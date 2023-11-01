# Bitwise Operators

C provides six bitwise operators, which operate on **integer data** at the **bit level**.

## Bitwise Complement, AND, OR, and Exclusive OR

The following operators perform Boolean operations on all bits in their operands.

| Symbol | Meaning|
|--------|-------|
| ~     | bitwise complement |
| &     | bitwise AND | 
| &#124; | bitwise OR |
| ^     | bitwise exclusive OR |

_Tip: Don't confuse the bitwise operators `&` and `|` with the logical operators `&&` and `||`._


## Bitwise Shift Operators

The bitwise shift operators can transform the binary representation of an integer by
shifting its bits to the left or right.

| Symbol | Meaning|
|--------|-------|
| <<     | left shift |
| \>>     | right shift |  

The operands for `<<` and `>>` may be of any integer type.

The bitwise shift operators have lower precedence than the arithmetic operators.
Example: `i << 2 + 1` means `i << (2 + 1)`

The value of `i << j` is the result when the bits in `i` are shifted left by `j` places. 
For each bit that is "shifted off" the left end of i, a zero bit enters at the right.

The value of `i >> j` is the result when `i` is shifted right by `j` places.
If `i` is of an unsigned type of  if the value of `i` is nonnegative, zeros are added at 
the left as needed.
If `i` is a negative number, the result is **implementation-defined** (some implementations add zeros
at the left end, while others preserve the sign bit by adding ones).

_Tip: As long as it is not absolutely necessary, shift operations should only be carried out 
with unsigned integer numbers._


## Common Single-Bit Operations

Assume that `word` is a 16 bit unsigned integer variable:
```C
#include <stdint.h>
...
uint16_t word;
```

* **Setting a bit**: The easiest way to set a bit is to `OR` the value of `word` with a mask that 
contains a 1 bit on the desired location `j`. Idiom: `word |= 1 << j; `

* **Clearing a bit**: To clear bit `j` of `word`, we use a mask with a 0 bit at position `j` and 1 bits everywhere else.
Idiom: `word &= ~(1 << j);`

* **Testing a bit**: To test whether bit j is set, we use the following statement.
Idiom: `if(word & 1 << j) {...}`


## References
K. N. King. **C Programming, A Modern Approach.** W. W. Norton & Company, inc. 2nd Edition 2008
 * Chapter 20: Low-Level Programming
 
*Egon Teiniker, 2020-2023, GPL v3.0* 