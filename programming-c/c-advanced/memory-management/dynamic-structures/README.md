# Structures on the Heap

We can't just reserve memory on the heap for primitive types. We can also 
**allocate memory for structures using the sizeof operator**.

This happens so often that there is a separate operator for dealing with pointers 
on structures.


## Structure Instances on the Heap 

The given function is used to create a new `date_t` structure dynamically on the heap 
and initialize it with specific values for `day`, `month`, and `year`. 

_Example_: Creating and using a structure on the heap
```C 
date_t * new_date(int day, int month, int year)
{
    date_t * date = (date_t *)malloc(sizeof(date_t));
    date->day = day;
    date->month = month;
    date->year = year;
    return date;
}
``` 

* `malloc(sizeof(date_t))`: This function call allocates memory on the heap that is 
    large enough to hold a `date_t` structure. The `sizeof(date_t)` part calculates 
    the size of the `date_t` type.

* `date->day`, `date->month`, and `date->year` are accessing the `day`, `month`, 
    and `year` members of the `date_t` structure respectively and assigning them 
    the values passed to the function.

* The function returns the pointer to the newly allocated and initialized `date_t` 
    structure. This allows the function's caller to use this dynamically allocated 
    date structure elsewhere in their program. It is important for the caller to 
    ensure that this memory is eventually freed to avoid memory leaks.


## The `->` Operator
Accessing a member of a structure using a pointer is so common that C  provides a special operator for this purpose.
This operator, known as **right arrow selection**, is a minus followed by `>`.

Using the `->` operator, we can write: `marge->id = 7;` instead of: `(*marge).id = 7;`

_Example_: Creating and using a structure on the heap
```C 
    user_t *marge = malloc(sizeof(user_t));
    marge->id = 7;              
    marge->username = "marge";    
    marge->password = "LoveMy3Kids!";

    assert(marge->id == 7);         
    assert(strcmp("marge", marge->username) == 0);
    assert(strcmp("LoveMy3Kids!", marge->password) == 0);
    free(marge);
```
The `->` operator is a combination of the `*` and `.` operators.
It performs indirection on `marge` to locate the structure that it points to, then selects the `id` member of the 
structure. 


## References
* [YouTube (CS50): Structures](https://youtu.be/N5pA7RvvQDg)

* K. N. King. **C Programming, A Modern Approach.** W. W. Norton & Company, inc. 2nd Edition 2008. 
    * Chapter 16: Structures, Unions, and Enumerations
 
*Egon Teiniker, 2020-2024, GPL v3.0* 