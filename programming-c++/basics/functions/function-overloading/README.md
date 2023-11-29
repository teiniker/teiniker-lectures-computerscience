# Function Overloading

In C, each function must have a unique name. 

But **in C++ functions can share names as long as their arguments differ**, this is called **function overloading**.


_Example:_ Overloading the function `print()`
```C++
void print(int i);
void print(double d);
void print(const char *s);

print(7);
print(3.1415);
print("Homer Simpson");
```
The data type of the argument in each of the functions differs, so the C++ compiler has enough information from the arguments passed into toa to call the correct function.

This is more convenient than defining separately named functions, because we just 
need to remember one name and the compiler figures out which function to call.



## References

* Josh Lospinoso. **C++ Crash Course**. No Starch Press, 2019 
    * Chapter: Upgrading to Super C 

*Egon Teiniker, 2020-2023, GPL v3.0*
