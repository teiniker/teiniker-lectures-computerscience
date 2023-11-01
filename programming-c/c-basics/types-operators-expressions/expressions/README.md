# Expressions

The simplest expressions are variables and constants.
A **variable** represents a value to be computed as the program runs. 
A **constant** represents a value that doesn't change.

More complicated expressions apply **operators** to operands (which are themselves expressions).
Operators are the basic tool for building expressions, and C has a rich collection of them.

## Order of Expression Evaluation

The table below shows the precedence of the most important operators.

| Symbol | Meaning             | Precedence |
|--------|---------------------|------------|
| ++     | increment (postfix) | 1          |
| --     | decrement (postfix) | 1          |  
| ++     | increment (prefix)  | 2          |
| --     | decrement (prefix)  | 2          |
| +      | unary plus          | 2          | 
| -      | unary minus         | 2          | 
| * / %  | multiplicative      | 3          | 
| + -    | addidive            | 4          |
| =      | assignment          | 5          |

Note that we can always control the evaluation order with parentheses.

_Example_: Evaluation order of operators
```C
a = b += c++ - d + --e / -f
```
is equivalent to
```C
(a = (b += (((c++) - d) + ((--e) / (-f)))))
```

## References
* K. N. King. **C Programming, A Modern Approach**. W. W. Norton & Company, inc. 2nd Edition 2008
    * Chapter 4: Expressions

*Egon Teiniker, 2020-2023, GPL v3.0* 
