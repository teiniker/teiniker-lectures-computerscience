# Recursion

Recursion is a powerful principle that allows something to be defined in terms of smaller instances of itself.

In computing, recursion is supported via recursive functions.
A recursive function is a function that calls itself. 
Each successive call worls on a more refined set of inputs, bringing us closer and closer to the solution of a problem.

_Example_: Factorial of a number n
```C
int fact(int n)
{
    if(n < 0)
        return 0;
    else if(n == 0 || n == 1)
        return 1;
    else
    {
        return n * fact(n-1);
    }
}
```
The **factoral of n**, written **n!**, is the product of all numbers from `n` down to `1`.
Another way to look at this problem is to define n! as the product of smaller factorials. 
To do this, we define `n!` as n times the factorial of `(n-1)`.

There are two basic phases in a recursive process:
* In the **winding phase**, each recursive call preserve the recursion by making an additional recursive call itself.
    The winding phase terminates when one of the calls reaches a **terminating condition**.
    A terminating condition defines the state at which a recursive function sgould return instead of making another 
    recursive call.
    Every recursive funstion must have at least one terminating condition, otherwise, the winding phase never terminates.

* Once the winding phase is complete, the process enters the **unwinding phase**, in which previous instances of the 
    function are revisited in reverse order.
    This phase continues until the original call returns, at which point the recursive process is complete.



## References
* [Youtube: CS50 - Recursion](https://youtu.be/mz6tAJMVmfM)

* Kyle Loudon. Mastering Algorithms with C. O'Reilly,1999
    * Chapter 3: Recursion
