# C Debugging

Debugging is the process in which a developer (who could be the author or not of the code he is trying to debug), 
using various tools available to him, makes an effort to change part of a previously written code in order 
**to get rid of an error** that was not caught at the compile (or syntax checking) time.

There are many different ways people perform debugging:
* **Print Statements**: We use `printf()` to output some values while running the code. 
  This is possibly the easiest way to start debugging anything. 
  It is also the most clumsy and time taking way. It is **clumsy** because we can very easily leave all those 
  (or part of those) `printf()` statements behind us in the code once we are done, causing an unclean code. 
  It is **time taking** because we have to write all the `printf()` statements and then have to monitor them while 
  the program is being executed.

* **Interactive (Symbolic) Debugger**: There are tools available in your own development machines, which give us 
  an all-powerful access to the program at runtime in an interactive mode and let you perform very low level 
  (and high level) investigation on a running piece of code. 
  The advantage of this kind of debugging is that it does not need from our part any extra effort to start 
  debugging the code. We just fire-up the debugger and point it to the executable - we are in the middle of a 
  running program but we also have all the power to investigate (and even change if needed) it in realtime.

* **assert Statements**: Using `assert` statements, we can write **self-checking code**. We can define 
  conditions in the program code that are **evaluated during runtime**. 
  If a condition does not apply (`assert(false)`) the program execution is aborted.
  The advantage over the interactive debugger is the **automation**. `assert` statements are evaluated 
  automatically, while the debugger forces us to check the variable values manually.  
  The evaluation of the assert statements can be **switched off** with the help of the `NDEBUG` macro. 
  It is therefore important to ensure that assert staments do not have any side effects.  
  `assert.h` is part if the C standard library.
    
## Examples
* Demo: [for-loop](for_loop.c)   
* Demo: [functions](function.c)
        
 
## References:
* [An introduction to Debugging](https://towardsdatascience.com/an-introduction-to-debugging-in-c-and-lldb-part-i-e3c51991f83a)
* [How to use assertions in C](https://ptolemy.berkeley.edu/~johnr/tutorials/assertions.html)       

*Egon Teiniker, 2020-2024, GPL v3.0* 
