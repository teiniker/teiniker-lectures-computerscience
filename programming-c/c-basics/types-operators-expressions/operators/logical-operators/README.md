# Logical Operators

Several of C's statements, including the if statement, must test the value 
of an expression to see if it is `true` or `false`. 
In C a comparison such as `i < 10` yields an integer: either `0` (false) or `1` (true).

## Logical Operators
More complicated logical expressions can be build from simpler ones by using the logical operators: AND, OR, and NOT.

| Symbol | Meaning|
|--------|-------|
| !      | logical negation |
| &&     | logical AND |
| &#124;&#124;   | logical OR |

The logical operators produce either `0` or `1` as their result.

Both `&&` and `||` perform **short-circuit evaluation** of their operands.
These operators first evaluate the left operand, then the right operand.
If the value of the expression can be deduced from the value of the left 
operand alone, then the right operand is not evaluated. 


## Relational Operators
The relational operators can be used to **compare integers and floating-point
numbers**, with operands of mixed types allowed.

| Symbol | Meaning|
|--------|-------|
| <      | less than |
| \>      | greater than|
| <=     | less than or equal to |
| \>=     | greater than or equal to |


## Equality Operators
The equality operators produce either `0` (false) or `1` (true) 
as their result.

| Symbol | Meaning|
|--------|-------|
| ==     | equal to |
| !=     | not equal to |  


## References
K. N. King. **C Programming, A Modern Approach.** W. W. Norton & Company, inc. 2nd Edition 2008
 * Chapter 5: Selection Statements
 
*Egon Teiniker, 2020-2021, GPL v3.0* 
