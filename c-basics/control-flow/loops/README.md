# Loops

A **loop** is a statement whose job s to repeatedly execute some  other statement
(the **loop body**).

Every loop has a **controlling expression**. 
Each time the loop body is executed (an iteration of the loop), the controlling 
expression is evaluated: 
if the expression is **true** (has a value that is not zero) the loop continues to execute.

C provides three iteration statements:
* The **while** statement is used for loops whose controlling expression is tested _before_ the loop body is executed.
* The **do** statement is used if the expression is tested _after_ the loop body is executed.
* The **for** statement is convenient for loops that _increment_ or _decrement_ a counting variable.

## The while Statement
The _while_ statement is the simplest and most fundamental way to setup a loop in C.
```C
    while (expression)
    {
        loop body
    }
```
When a _while_ statement is executed, the controlling expression is evaluated first.
if its value is true (nonzero), the **loop body** is executed and the expression is tested again.

_Example_: Printing numbers from 0 to 9
```C
    int i = 0;
    while(i < 10)
    {
        printf("\t  i =%2d\n", i);
        i++;
    }
```

_Example_: Infinite loop
```C
    while(true)
    {
        // do someting forever
    }
```
A _while_ statement will not terminate if the controlling expression always has a _true_ 
(nonzero) value. 

## The do Statement
The _do_ statement is essentially just a while statement whose controlling expression 
is tested _after_ each execution of the loop body.
```C
    do
    {
       loop body
    }
    while (expression);
```
When a _do_ statement is executed, the loop body is executed first, then the controlling 
expression is evaluated.
If the value of the expression is _true_ (nonzero), the loop body is executed again and 
then the expression is evaluated once more.
Execution of the _do_ statement terminates when the controlling expression has the value 
_false_ (zero) after the loop body has been executed.  

_Example_: Printing numbers from 0 to 9
```C
    int i = 0;
    do
    {
        printf("\t  i =%2d\n", i);
        i++;
    } while(i < 10);
```
Note that the body of a _do_ statement is always executed at least once; 
the body of a _while_ statement is skipped entirely if the controlling 
expression is _false_ (zero) initially. 

## The for Statement
The for statement is ideal for loops that have a counting variable.
```C
    for (expr1 ; expr2 ; expr3 ) 
    {
       loop body
    }
```
The _for_ statement is closely related to the while statement, thus, a _for_
loop can be replaced by an equivalent _while_ loop:
```C
    expr1;
    while (expr2)
    {
        loop body
        expr3;
    }
```
_Example_: Printing numbers from 0 to 9
```C
    for(int i=0; i < 10; i++)
    {
        printf("\t  i =%2d\n", i);
    }
```
Since **C99**, the first expression in a for statement can be replaced by
a **variable declaration**.
A variable declared by a for statement can't be accessed outside the body 
of the loop - the variable is only **visible** inside the loop.

_Example_: Infinite loop
```C
    for(;;)
    {
        // do someting forever
    }
```
Some _for_ loops may not need all three expressions that normally control the loop.
C allows us to omit any or all of the expressions.
If the **second expression is missing**, it **defaults to a true**, so the for statement 
doesn't terminate.

## References
* [YouTube: CS50 - Loops](https://youtu.be/WgX8e_O7eG8)

* K. N. King. **C Programming, A Modern Approach.** W. W. Norton & Company, inc. 2nd Edition 2008
    * Chapter 6: Loops
 
*Egon Teiniker, 2020, GPL v3.0* 
