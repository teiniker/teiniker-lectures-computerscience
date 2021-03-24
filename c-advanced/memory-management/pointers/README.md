# Pointers

In computers, memory is divided into **bytes**, with each byte can store eight bits of information.
Each byte has a unique **address** to distinguish it from the other bytes in memory.

An executable program consists of both **code** and **data**. Each variable in the program occupies one or
more bytes of memory. The address of the first byte is said to be the **address of the variable**.

We can store addresses in **pointer variables** which is just a variable that can store an address.
A pointer variable is declared in the same way as an ordinary variable. The only difference is that the name
must be preceded by an asterisk:
```C
    int *i_ptr;     // Pointer declaration
```
This declaration states that `i_ptr` is a pointer variable capable of pointing to variables of type `int`.

C requires that every pointer variable point only to variables of a particular type - the **referenced type**:
```C
    int *i_ptr;     // points to an integer variable
    double *d_ptr;  // points to a double variable 
    char *c_ptr;    // points to a char variable
```
Note that a pointer variable can even point to another pointer.

To find the address of a variable, we use the `&` **address operator**. 
If `x` is a variable, then `&x` is the address of `x` in memory.

To gain access to the variable that a pointer points to, we use the `*` **indirection operator**.
if `p` is a pointer, then `*p `represents the variable to which `p` currently points.

We can think  of `*` as the inverse of `&`.

_Example_: Integer variable and integer pointer 
```C
    int i; 
    int *i_ptr = &i;    // address operator
```
![Pointer](figures/Pointer1.png)

C allows the use of the **assignment operator** to copy pointers, if they have the same type.

_Example_: Integer pointer assignment 
```C
    int *j_ptr;
    j_ptr = i_ptr;      // pointer assignment
```
![Pointer Assignement](figures/Pointer2.png)

In the given example, `i_ptr` and `j_ptr` point to the same variable `i`. 
Any number of pointer variables may point to the same variable.
 
## Pointer as Arguments
By default, C passes function arguments by value (**call by value**).

Pointers offer a solution to this problem: instead of passing a variable `i` as the argument to a function, 
we can supply `&i`, a pointer to `i` (**call by reference**).
```C
   i = 7;
   increment(&i, 10);   
```
We declare the corresponding parameter `i_ptr` to be a pointer.
```C
void increment(int *i_ptr, int offset)
{
    *i_ptr += offset;   
}
```
Each appearance of `*i_ptr` in the body of the function will be an indirect reference to `i`, allowing the function 
both to read `i` and modify it.


## Pointers as Return Values

We can not only pass pointers to functions but also write functions that return pointers.
A function can return a **pointer parameter**, a pointer to a **global variable** or a **local variable that has been 
declared static**.

_Example_: Parameter pointer as return value
```C
int *max(int *a, int *b)
{
    if(*a > *b)
        return a;
    else
        return b;
}
```

**Never return a pointer to a local variable!**
If we leave a function, local variables go out of scope so the pointer will be invalid.


## References
* K. N. King. **C Programming, A Modern Approach.** W. W. Norton & Company, inc. 2nd Edition 2008. Chapter 11: Pointers
* [Youtube: CS50 Pointers](https://youtu.be/XISnO2YhnsY)
 
*Egon Teiniker, 2020-2021, GPL v3.0* 
