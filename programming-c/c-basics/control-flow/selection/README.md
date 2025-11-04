# Selection Statements


## The `if` Statement

The if statement allows a program to choose between two alternatives by 
testing the value of an expression.
```C
    if (expression)
    {
       statements
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
       statements
    }
    else
    {
       statements
    }
```

Note that we can **nest multiple `if-else` statements** inside one another:
```C
    if(yyyy % 400 == 0)
    {
        is_leap_year = true;
    }
    else
    { 
        if(yyyy % 100 == 0)
        {
            is_leap_year = false;
        } 
        else
        { 
            if(yyyy % 4 == 0)
            {
                is_leap_year = true;
            }
            else 
            {
                is_leap_year = false;
            }
        }
    }
```

Such nested constructions can lead to **hard-to-read code**.
Therefore, consider carefully whether you can achieve an equivalent implementation
by using logical combinations of expressions:

```C
    if((yyyy % 400 == 0) || (yyyy % 4 == 0) && (yyyy % 100 != 0))
    {
        is_leap_year = true;
    }
    else
    {
        is_leap_year = false;     
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
 

## The switch Statement

We often need to compare an expression against a series of values to see 
which one it currently matches.
This can be implemented in cascaded `if else` statements.
As an alternative we can use the switch statement.
```C
switch (expression)
{
    case constant-expression: statements 
    ...
    case constant-expression: statements
    default : statements
} 
```

The keyword `switch` must be followed by an integer expression (char is treated 
as integers in C). Floating-point numbers and strings are not working.
A **constant expression** is much like an ordinary expression except that it can't
contain variables of function calls. Note that no braces are required around the 
**statements**. The last statement in each group is normally `break`.
The order of the cases doesn't matter. In particular, the `default` case doesn't 
need to come last.

Unfortunately, there is no way to write a case label that specifies a range of values.
But when the last statement in the case has been executed, control **falls through** to the
first statement of the following case. Without break, control will flow from one case 
into the next.

```C
   switch(grade)
    {
        case 1:
        case 2:
        case 3:
        case 4:
            printf("positiv\n");
            break;
        case 5:
            printf("negativ\n");
            break;
    }
	return 0;
```

**Forgetting to use break is also a common error!** 


## References
* [YouTube: CS50 - Conditional Statements](https://youtu.be/1wsaV5nVC7g)

* K. N. King. **C Programming, A Modern Approach.** W. W. Norton & Company, inc. 2nd Edition 2008
   * Chapter 5: Selection Statements
 
*Egon Teiniker, 2020-2025, GPL v3.0* 
