# Selection Statements

## Logical Expressions
Several of C's statements, including the if statement, must test the value 
of an expression to see if it is `true` or `false`. 
In C a comparison such as `i < 10` yields an integer: either `0` (false) or `1` (true).

### Relational Operators
The relational operators can be used to **compare integers and floating-point
numbers**, with operands of mixed types allowed.

| Symbol | Meaning|
|--------|-------|
| <      | less than |
| \>      | greater than|
| <=     | less than or equal to |
| \>=     | greater than or equal to |
 
### Equality Operators
The equality operators produce either `0` (false) or `1` (true) 
as their result.

| Symbol | Meaning|
|--------|-------|
| ==     | equal to |
| !=     | not equal to |  

### Logical Operators
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

## The `if` Statement
The if statement allows a program to choose between two alternatives by 
testing the value of an expression.
```C
    if (expression)
    {
       statement(s)
    }
```
When an if statement is executed, the expression in the parenthesis is evaluated.
If the value of the expression is `true` (nonzero), the statement is executed.

**Don't confuse == (equality) with = (assignment)**

### The `else` Clause
The statement that follows the keyword `else` is executed if the expression in 
parentheses has the value `false` (zero).
```C
    if (expression)
    {
       statement(s)
    }
    else
    {
       statement(s)
    }
```

## Conditional Expressions
C also provides an operator that allows an expression to produce
one of two values depending on the value of the condition.
```C
    expr1 ? expr2 : expr3
```
If `expr1` is `true` (nonzero) then `expr2` else `expr3`.

The expression is evaluated in stages: `exp1` is evaluated first.
* If its value is `true` (nonzero), then `expr2` is evaluated, and its value
is the value of the entire conditional expression.
* If the value of `expr1` is `false` (zero), then the value of `expr3` is the 
value of the conditional.   

Conditional expressions tend to make programs shorter but **harder to 
understand** - try to avoid them. 
They are common in certain kinds of macro definitions.
 
### Boolean Values 


## The switch Statement



## References
K. N. King. **C Programming, A Modern Approach.** W. W. Norton & Company, inc. 2nd Edition 2008
 * Chapter 5: Selection Statements
 
*Egon Teiniker, 2020, GPL v3.0* 
