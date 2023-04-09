# Structures

The only data structure we have discussed so far is the array.
The properties of a **structure** are quite different from those of an array.
* The **members** of a structure can **have different types**.
* The **members** of a structure **have names**. To select a particular member, we specify its name, not its position.

When we need to store a collection of related data items, a structure is a logical choice.

## Structure Variables

To create variables that can store different members, we can use a struct declaration.
A **struct variable declaration** has the same form as other variable declarations in C: 
`struct{...}` specifies a type, while the following name is the name of the variable.

To **initialize a structure**, we prepare a list of values to be stored in the structure and enclose it in braces.
The values in the initializer must appear in the same order as the members of the structure.

_Example_: Struct variable
```C
    struct 
    {
        int day;
        int month;
        int year;
    } birthday = {23, 6, 1912}; // Alan Turing date of birth
```
The structure variable `birthday` has three members (`day`, `month`, and `year`).

The members of a structure are **stored in memory** in the order in which they are declared.

**Each structure represents a new scope**. Any names declared in that scope will not conflict with other names in a program.
We can say that each structure has a separate **namespace** for its members.

## Structure Types
Suppose that a program needs to declare several structure variables with identical members.
If we need to declare the structure variables at different points in the program, we will quickly run into problems:
* Repeating the structure information will bloat the program.
* Changing the program later will be risky, since we can't guarantee that the declarations will remain consistent.

To avoid these difficulties, we need to be able to define a **name that represents a type of a structure**, not a 
particular structure variable.
Wen can either declare a structure tag or use typedef to define a type name.

### Defining a Structure Tag
A structure tag is a name used to identify a particular kind of structure.

_Example_: Structure tag
```C
    struct date 
    {
        int day;
        int month;
        int year;
    };
    
    struct date birthday = {23, 6, 1912}; // Alan Turing date of birth
```
Since structure tags are not recognized unless preceded by the keyword `struct`, they don't conflict with other
names used in a program.


### Defining a Structure Type 

As an alternative to declaring a structure tag, we can use `typedef` to define a genuine type name.

_Example_: Structure type using typedef
```C
   typedef struct
    {
        int day;
        int month;
        int year;
    } date_t;

    date_t birthday = {23, 6, 1912}; // Alan Turing date of birth
```
Note that the name of the type must come at the end, not after the keyword `struct`.
We can use the new defined type in the same way as the build-in types to declare variables.

## Structure Operations

### The `.` Operator
The most common operation on a structure is **selecting one of its members**.
To access a member within a structure, we write the name of the structure first then a period, then the name of the member.
The **period** that we use to access a structure member is actually a C operator.

_Example_: Accessing structure members
```C
    struct 
    {
        int day;
        int month;
        int year;
    } birthday;

    birthday.day = 23;
    birthday.month = 6;
    birthday.year = 1912;    

    assert(birthday.day == 23);
    assert(birthday.month == 6);
    assert(birthday.year == 1912);
```

### The `=` Operator
Another structure operation is **assignment**.
Since arrays can't be copied using the `= operator`, it comes as something of a surprise to discover that structures can.
The `= operator` can be used only with structures of compatible types.

_Example_: Structure assignment
```C
    date_t day = {23, 6, 1912}; // Alan Turing date of birth
    date_t birthday = day;
    assert(birthday.day == 23);
    assert(birthday.month == 6);
    assert(birthday.year == 1912);
```

The `= operator` is also used when we pass structures as function parameters or return types.

**Passing a structure to a function and returning a structure from a function** both require making a copy of all members 
in the structure (**call by value**).
As a result, these operations impose a fair amount of overhead an a program, especially if the structure is large.
  
To avoid this overhead, it is sometimes advisable to **pass a pointer to a structure** instead of passing the structure 
itself (**call by reference**).
Similarly, we might have a function return a pointer to a structure instead of returning an actual structure.

### The `->` Operator
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
    * Chapter 17: Advanced Uses of Pointers    
 
*Egon Teiniker, 2020-2022, GPL v3.0* 
