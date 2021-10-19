# Expressions

The simplest expressions are variables and constants.
A **variable** represents a value to be computed as the program runs. 
A **constant** represents a value that doesn't change.
More complicated expressions apply operators to operands (which are themselves expressions).
Operators are the basic tool for building expressions, and C has a rich collection of them.

## Arithmetic Operators 

The arithmetic operators perform addition, subtraction, multiplication, and division.

The **unary operators** `plus +` and `minus -` require one operand:
```C
i = +1;  // unary + operator (does nothing)
j = -i;  // unary - operator
```

The binary operators require two operands:

| Symbol | Meaning|
|--------|-------|
| +     | addition |
| -     | subtraction | 
| *     | multiplication | 
| /     | division | 
| %     | remainder | 

The `/` and `%` operator requires special care:
* The `/` operator can produce surprising results. When both of its operands are integers, the `/` operator truncates the result by dropping the fractional part.

    _Example_: `1 / 2 = 0`

* The `%` operator requires integer operands. If either operand is not an integer, the program will not compile.
* Using zero as the right operand of either `/` or `%` causes undefined behavior.


## Assignment Operators

Once the value of an expression has been computed, we will often need to store it in a variable for later use.
The simple assignment operator `=` is used  for that purpose.

For updating a value already stored in a variable, C provides compound assignment operators.

### Simple Assignment 


### Compound Assignment




## Increment and Decrement Operators

Two of the most common operations on a variable are **incrementing (adding 1)** and 
**decrementing (subtracting 1)**.
```C
i = i + 1;  // increment
i = i - 1;  // decrement
```

The **compound assignment operators** allow us to reduce these statements a bit:
```C
i += 1;  // increment
i -= 1;  // decrement
```

But C allows increments and decrements to be shortened even further, using the **++ (increment)** and
**-- (decrement) operators**. 

Note that **++** and **--** can be used as **prefix operators** (++i and --i) or **postfix operators** 
(i++ and i--).

_Example_: Evaluating the expression ++i (pre-increment)
```C
int i = 1;
printf("i is %d\n", i);     // prints "i is 1"
printf("i is %d\n", ++i);   // prints "i is 2" (i is incremented before passed as an argument)
printf("i is %d\n", i);     // prints "i is 2"
```
**++i means: increment i immediately**

_Example_: Evaluating the expression i++ (post-increment)
```C
int i = 1;
printf("i is %d\n", i);     // prints "i is 1"
printf("i is %d\n", i++);   // prints "i is 1" (i is incremented after its value is passed as an argument)
printf("i is %d\n", i);     // prints "i is 2"
```
**i++ means: use the old value of i for now, but increment i later**

## References
K. N. King. **C Programming, A Modern Approach.** W. W. Norton & Company, inc. 2nd Edition 2008
 * Chapter 4: Expressions
 
*Egon Teiniker, 2020-2021, GPL v3.0* 