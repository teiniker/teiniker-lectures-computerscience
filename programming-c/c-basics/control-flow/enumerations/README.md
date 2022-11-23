# Enumerations

In many programs, we will need variables that have only a small set of meaningful values.

C provides a special kind of type designed specifically for variables that 
have a small number of possible values.
An **enumerated type** is a type whose values are listed by the programmer, 
who must create a name (**enumeration constant**) for each of the values.

```C
enum day 
{
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};
```
**C treats enumeration varibles and constants as integers**.
By default, the comiler assigns the integers `0,1,2...` to the
constans in a particular enumeration.

We are free to choose different values for enumeration constants:
```C
enum day 
{
    MONDAY = 10,
    TUESDAY = 20,
    WEDNESDAY = 30,
    THURSDAY = 40,
    FRIDAY = 50,
    SATURDAY = 60,
    SUNDAY = 70
};
```
When no value is specified for an enumeration constant, its value is one
greater than the value of the previous constant.
 
## References
K. N. King. **C Programming, A Modern Approach.** W. W. Norton & Company, inc. 2nd Edition 2008
 * Chapter 16.5: Enumerations
 
*Egon Teiniker, 2020-2022, GPL v3.0* 