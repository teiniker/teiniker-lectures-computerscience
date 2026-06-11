# From C Structures to C++ Classes

## C Structures

Given a C structure which can be used with different functions.

```C
typedef struct 
{
    int day;
    int month;
    int year;
} date_t;

date_t *date_new(int d, int m, int y);
void date_delete(date_t *date);
bool isLeapYear(date_t *date);
```
We can create **multiple instances of this structure** and apply the **same 
functions** to each of these instances. We simply pass the pointer of the 
particular instance to a function.

```C
void test_is_leap_year(void)
{
    date_t birthday = {23, 6, 1912};
    
    TEST_ASSERT_TRUE(isLeapYear(&birthday));
}
```
This is a common implementation technique for data structures like this `data_t` 
example.
 
We can create this **structure on the stack**. 
```C
   date_t birthday = {23, 6, 1912};
```

With the help of the functions **malloc()** and **free()** we can also 
manage any number of `date_t` **instances on the heap**.
 
```C
void test_constructor_with_new(void)
{
    date_t *birthday = date_new(23, 6, 1912); 
    // ...
    date_delete(birthday);
}
``` 

However, this implementation in C has some **disadvantages**:
* The data in the structure `book_t` is always accessible (public) 
    and can be changed or read out at any time.
* Each function must define the pointer to the structure as the first 
    parameter (`self` pointer).

In C ++, attempts have been made to eliminate these disadvantages by 
introducing classes.


## C++ Classes

Classes are the central feature of an **object-oriented language**. 

### Class Declaration

In C++ a **class** is a user-defined type that has **attributes** (data members) and 
**methods** (member functions). Both of them can be visible (public) or invisible
(private) to the code that uses instances of that class.

_Example_: C++ class declaration
```C++
class Date 
{
    public:
        Date(int d, int m, int y);   
        ~Date();

        int getDay() const;
        void setDay(const int d);
        
        int getMonth() const; 
        void setMonth(const int m);
        
        int getYear() const;
        void setYear(const int y);

        bool isLeapYear();

    private:
        int _day;
        int _month;
        int _year;
};
``` 
All members of a class (attributes and methods) are private per default.

### Constructor

**Constructors** are special class members which are called by the compiler 
every time an object of that class is instantiated. Constructors have the 
same name as the class and may be defined inside or outside the class 
definition.
 
There are three different types of constructurs in C++:
* **Default Constructors:** 
    The default constructor is the constructor which doesn’t take any 
    argument (it has no parameters).
    If we do not define any constructor explicitly, the compiler will 
    automatically provide a default constructor implicitly.    
    _Example_: `Date()`
    
* **Parameterized Constrcutors:**
    It is possible to pass arguments to constructors. These arguments 
    help initialize an object when it is created. Note that constructors 
    also can be overloaded.        
    _Example_: `Date(int d, int m, int y)`

* **Copy Constructors:**
    A copy constructor is a member function which initializes an object 
    using another object of the same class. 
    If we don’t define our own copy constructor, the C++ compiler 
    creates a default copy constructor for each class which does a 
    member-wise copy between objects (**shallow copy**) . 
    We need to define our own copy constructor only if an object has 
    pointers or any runtime allocation of the resource like file handle, 
    a network connection etc. (**deep copy**).        
    _Example_: `Date(const Date &date)`
    
    
### Destructor
Destructor is another special member function that is called when the 
**scope of the object ends** or the **delete operator** is called.

Destructors have same name as the class preceded by a tilde `~`, 
**don’t take any argument, and don’t return anything**.
Note that there can only be one destructor in a class.

```C++
    ~Date();
```     

If we do not write our own destructor in class, compiler creates a 
**default destructor** for us. The default destructor works fine unless 
we have dynamically allocated memory or pointer in class. 
When a class contains a pointer to memory allocated in class, we should 
write a destructor to release memory before the class instance is destroyed. 
This must be done to avoid memory leak.


### Class Implementation

We separate the declaration and the implementation of methods (header 
and source file).

_Example_: C++ class implementation
```C++
Date::Date(int day, int month, int year) : _day(day), _month(month), _year(year)   
{
}

Date::~Date() 
{
}

int Date::getDay() const { return _day; }
void Date::setDay(const int day) { _day = day; }

int Date::getMonth() const { return _month; }
void Date::setMonth(const int month) { _month = month; }

int Date::getYear() const { return _year; }
void Date::setYear(const int year) { _year = year; }

bool Date::isLeapYear()
{
    return (_year % 4 == 0 && _year % 100 != 0) || (_year % 400 == 0);
}
```

When we implement methods outside a class we use the **scope resolution :: operator**.

All the member functions defined inside the class declaration are by default 
**inline**, but we can also make any non-class function inline by using keyword 
`inline` with them. 
Inline functions are actual functions, which are copied everywhere during compilation, 
like pre-processor macro, so the overhead of function calling is reduced.

To create **Objects** (instances of a class), we define variables of this type. 
Note that the methods can be called directly on these instances using the 
dot notation.

```C++
void test_constructor(void)
{
    Date birthday(23, 6, 1912); // Alan Turing's date of birth                        

    TEST_ASSERT_EQUAL(23, birthday.getDay());
    TEST_ASSERT_EQUAL(6, birthday.getMonth());
    TEST_ASSERT_EQUAL(1912, birthday.getYear());
}
``` 
These objects are also created on the stack and go out of scope at the end of a method 
or function.

To objects on the heap we use the **new** operator. To delete objects from the heap, 
we use the **delete operator**. 
Note that all objects on the heap must be deleted manually using delete.

```C++
void test_constructor_with_new(void)
{
    Date *birthday = new Date(23, 6, 1912); 

    TEST_ASSERT_EQUAL(23, birthday->getDay());
    TEST_ASSERT_EQUAL(6, birthday->getMonth());
    TEST_ASSERT_EQUAL(1912, birthday->getYear());

    delete birthday;
}
``` 

The new operator returns a pointer to the created object, thus, 
the members of an object are accessed with the **arrow operator**.


## References
Bjarne Stroustrup. **The C++ Programming Language.** Pearson 4th Edition 2017
* Chapter 16: Classes
* Chapter 17: Construction, Cleanup, Copy, and Move 

[C++ Classes and Objects](https://www.geeksforgeeks.org/c-classes-and-objects/)

[Constructors in C++](https://www.geeksforgeeks.org/constructors-c/)

[Copy Constructor in C++](https://www.geeksforgeeks.org/copy-constructor-in-cpp/)

[Destructors in C++](https://www.geeksforgeeks.org/destructors-c/)

*Egon Teiniker, 2020-2024, GPL v3.0*
