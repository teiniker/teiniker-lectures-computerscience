# Structures 

In the C programming language, a `struct` (short for structure) is a **composite data type** 
that allows you to group variables of different types together under a single name: 
* The **members** of a structure can **have different types**.
* The **members** of a structure **have names**. To select a particular member, we specify 
    its name, not its position.

This capability is particularly useful for organizing data into a more meaningful and 
manageable format.
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

## Structure Operators

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


## Structures in C++

 Structures in C++ offer more advanced features compared to C. 
 
 Unlike C structures, C++ structures can have **member functions**, including 
 **constructors and destructors**, allowing them to behave more like classes. 
 
 Additionally, C++ structures support features like **access specifiers** (public, 
 private, protected), **inheritance**, and can utilize C++ specific principles like 
 polymorphism and encapsulation, making them more versatile and powerful than their 
 C counterparts.

[Read more...](../../../programming-c++/basics/structures/)


## References
* [YouTube (CS50): Structures](https://youtu.be/N5pA7RvvQDg)

* K. N. King. **C Programming, A Modern Approach.** W. W. Norton & Company, inc. 2nd Edition 2008. 
    * Chapter 16: Structures, Unions, and Enumerations
 
*Egon Teiniker, 2020-2023, GPL v3.0* 
