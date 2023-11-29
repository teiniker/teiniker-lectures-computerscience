# Structures in C++

Structures in C and C++ share many similarities but also have notable differences.

## Structures in C vs. Structures in C++

While C structures are mainly used for grouping data, C++ structures are more versatile, 
supporting many features of object-oriented programming such as encapsulation, inheritance, 
and methods. 

Here are the major differences:

* **Initialization**:
    * C: In C, structures are typically initialized using designated initializers or by 
        manually setting each field.
    * C++: C++ structures can be initialized using **constructors**, allowing for more 
        complex initialization logic.

* **Functions and Methods**:
    * C: Structures in C cannot have functions or methods inside them. Functions operating 
        on structures are defined outside.
    * C++: C++ structures can have **member functions (methods)**, constructors, destructors, 
        and even friend functions.

* **Static Members**:
    * C: C structures cannot have static members.
    * C++: C++ structures can have static members, both variables, and functions.

* **Access Modifiers**:
    * C: All members of a structure in C are public by default. There is no concept of access 
        specifiers like private or protected in C.
    * C++: In C++, structures have **public access by default**, like in C, but they 
        **also support access specifiers (private, protected, public)**.

* **Inheritance**:
    * C: There is no concept of inheritance in C.
    * C++: Structures in C++ can **inherit from other structures or classes**, supporting the 
        object-oriented feature of inheritance.

_Example_: Date structure in C++
```C++
struct Date 
{
    // Constructor
    Date(int d, int m, int y)   
    {
        day = d;
        month = m;
        year = y;
    }

    // Public Fields
    int day;
    int month;
    int year;

    // Public Methods
    bool isLeapYear()
    {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
};
```
The given code defines a Date structure in C++ and demonstrates its use in a simple program:

* **Constructor**: `Date(int d, int m, int y)`: \
    * This is a constructor for the Date structure. 
        It initializes a Date object with the provided day `d`, month `m`, and year `y`. 
        This constructor is called when a `Date` object is created.
    * Inside the constructor, the parameters `d`, `m`, and `y` are assigned to the structure's 
        fields `day`, `month`, and `year`, respectively.

* **Public Fields**: `int day; int month; int year;`: \
    These lines declare three public integer fields within the `Date` structure, representing 
    the day, month, and year of a date, respectively.

* **Public Method**: `bool isLeapYear()`: \
    This is a public method of the `Date` structure. It returns `true` if the year stored in 
    the `Date` object is a leap year, and `false` otherwise. The leap year calculation follows 
    the standard rules: a year is a leap year if it is divisible by `4` but not by `100`, or 
    if it is divisible by `400`.

The `main()` function shows the application of the `Date` structure in C++:

```C++
int main(void)
{
    Date birthday(23, 6, 1912); // Alan Turing date of birth

    assert(birthday.day == 23);
    assert(birthday.month == 6);
    assert(birthday.year == 1912);

    assert(birthday.isLeapYear() == true);

    return 0;
}
```

* `Date birthday(23, 6, 1912);`: \
    This line creates an instance of the `Date` structure, named birthday, 
    representing the date June 23, 1912. The constructor of the Date structure 
    is called with 23, 6, and 1912 as arguments.

* `assert` Statements:\ 
    * These lines use `assert` to check that the birthday object's fields (day, month, year) 
    are correctly set to 23, 6, and 1912. 
    * It also checks that `birthday.isLeapYear()` returns `true` (1912 was a leap year). 

    If any of these assertions fail (i.e., the condition is false), the program will 
    terminate with an error message. Otherwise, the program continues.


## Structures vs. Classes in C++

In C++, both struct and class are used to define custom data types, but they have some 
differences primarily in their default access levels and typical usage:

* **Default Access Specifier**:
    * **Struct**: By default, **members of a struct are public**. This means that unless you 
        explicitly specify an access level (private or protected), the members and 
        methods of a struct can be accessed from outside the struct.
    * **Class**: By default, **members of a class are private**. we must explicitly declare 
        members as public if we want them to be accessible from outside the class.

* **Typical Usage**:
    * **Struct**: Structs are typically used for **passive data structures** that carry data 
        with little to no functionality (methods). This is more in line with traditional 
        C structs, though this is more of a convention than a rule.
    * **Class**: Classes are generally used for data structures that require both data and 
        functions to be encapsulated together, aligning with the principles of 
        **object-oriented programming**.


_Example_: Date class in C++ \

To convert the given C++ struct into a class with private fields, we need to make the 
following changes:
* Change the keyword `struct` to `class`.
* Move the fields `day`, `month`, and `year` to the `private` section.
* Provide `public` methods (getters and possibly setters) for accessing and manipulating 
these private fields.

Here's how the converted class would look:
```C++
class Date 
{
private:
    // Private Fields
    int day;
    int month;
    int year;

public:
    // Constructor
    Date(int d, int m, int y) : day(d), month(m), year(y) { }

    // Getters
    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    // Setters (if modification of date is required)
    void setDay(int d) { day = d; }
    void setMonth(int m) { month = m; }
    void setYear(int y) { year = y; }

    // Public Method
    bool isLeapYear(void) const {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
};
```

To adapt the `main()` function to work with the updated class definition where day, month, 
and year are private, we need to **use the getter methods instead of direct field access**. 
Also, since the setters are provided, we can use them if you need to modify the date. 
 
Here's how the revised `main()` function would look:

```C++
int main() 
{
    Date birthday(23, 6, 1912); // Alan Turing's date of birth

    // Using getter methods instead of direct field access
    assert(birthday.getDay() == 23);
    assert(birthday.getMonth() == 6);
    assert(birthday.getYear() == 1912);

    // Checking if the year is a leap year
    assert(birthday.isLeapYear() == true);

    // Example of using setter methods (if you need to modify the date)
    birthday.setDay(24);
    birthday.setMonth(7);
    birthday.setYear(1913);
    assert(birthday.getDay() == 24);
    assert(birthday.getMonth() == 7);
    assert(birthday.getYear() == 1913);

    return 0;
}
```

More information about C++ can be found in the [Programming C++](../../../programming-c++/) folder.
Note that the [Arduino framework](https://github.com/arduino/ArduinoCore-avr/tree/master) and 
numerous sensor libraries are written primarily in C++.


## References
* Josh Lospinoso. **C++ Crash Course**. No Starch Press, 2019. 
    * Chapter: User-Defined Types

*Egon Teiniker, 2020-2023, GPL v3.0* 