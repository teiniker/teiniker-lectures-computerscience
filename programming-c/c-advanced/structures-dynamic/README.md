# Structures on the Heap


## Instances on the Heap 

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