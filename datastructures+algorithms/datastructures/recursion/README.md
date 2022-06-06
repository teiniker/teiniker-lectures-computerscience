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
    A terminating condition defines the state at which a recursive function should return instead of making another 
    recursive call.
    Every recursive funstion must have at least one terminating condition, otherwise, the winding phase never terminates.

* Once the winding phase is complete, the process enters the **unwinding phase**, in which previous instances of the 
    function are revisited in reverse order.
    This phase continues until the original call returns, at which point the recursive process is complete.

## Function Execution in C 
To understand how recursion really works, it helps to look at the way functions are executed in C.

When a function is called in a C program, a block of storage is allocated on the **stack memory segment** of a process
to keep track of information associated with the call. 
The block of storage placed on the stack is called a **stack frame** and consists of incoming parameters, local variables, 
space for a return value, and the return address.

The stack is a great solution to storing information about function calls because its **last-in, first-out** behavior is 
well suited to the order in which functions are called and terminated. 

However, stack usage does have a few drawbacks:
* Maintaining information about every function call until it returns takes a considerable amount of **memory space**.
* Generating and destroying stack frames takes **CPU time**. Thus, if the overhead associated with these concerns becomes 
too great, we may need to consider an iterative approach (loops).



## References
* [Youtube: CS50 - Recursion](https://youtu.be/mz6tAJMVmfM)

* [Youtube: CS50 - Call Stacks](https://youtu.be/aCPkszeKRa4)

* Kyle Loudon. Mastering Algorithms with C. O'Reilly,1999
    * Chapter 3: Recursion
