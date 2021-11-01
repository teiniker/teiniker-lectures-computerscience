# Assert Statements 

The **assert** macro, which is defined in the `assert.h` header, allows a program to monitor its own behavior 
and detect possible problems at an early stage.

```C
void assert ( expression );
```

Although `assert` is actually a macro, it is designed to be used like a function.
It has one argument, which must be an **expression** that we **expect to be true** under normal circumstances.

Each time `assert` is executed, it tests the value of its argument: 
* If the argument is **true** (has a nonzero value), assert does nothing. 
* If the argument's value is **false** (zero), assert writes a message to the stderr (standard error stream) and 
terminates the program execution.

On disadvantage of assert is, that it slightly increases the running time of a program because of the extra check it performs.

Many programmers use assert during testing, then disable it when the program is finished.
Disabling `assert` is easy: we need only define the macro `NDEBUG` prior to the include statement:
```C
#define NDEBUG
#include <assert.h>
```
Avoid putting an expression that has a **side effect** (including a function call) inside an `assert`.
If `assert` is disabled at a later date, the expression won't be evaluated.

## References
* K. N. King. **C Programming, A Modern Approach.** W. W. Norton & Company, inc. 2nd Edition 2008
    Chapter 24: Error Handling
* [How to use assertions in C](https://ptolemy.berkeley.edu/~johnr/tutorials/assertions.html)
* [How and When to Use C's assert() Macro](https://barrgroup.com/embedded-systems/how-to/use-assert-macro) 
 
*Egon Teiniker, 2020-2021, GPL v3.0* 