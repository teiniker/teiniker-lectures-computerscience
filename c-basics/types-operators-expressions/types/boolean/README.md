# Boolean Values 
Since C99 a Boolean variable can be declared like `_Bool flag;` 
`_Bool` is an unsigned integer type but a _Bool variable can only be assigned 0 or 1.
C99 also provides a new header file **stdbool.h** which provides a macro `bool` that 
stands for `_Bool` as well as macros named `true` and `false` which stand for 1 and 0. 

```C
#include <stdbool.h> 
...
bool is_on = true; 
```


## References
K. N. King. **C Programming, A Modern Approach.** W. W. Norton & Company, inc. 2nd Edition 2008
 * Chapter 5: Selection Statements
 
*Egon Teiniker, 2020 - 2021, GPL v3.0* 
