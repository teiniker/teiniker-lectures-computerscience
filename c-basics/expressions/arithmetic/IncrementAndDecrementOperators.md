# Increment and Decrement Operators

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
 
*Egon Teiniker, 2020, GPL v3.0* 