# Classes and Objects

## C Structures

Given a structure which can be modified with different functions.

```C
typedef struct 
{
    double re;
    double im;    
} complex_number_t;

complex_number_t *complex_number_new(double re, double im);
void complex_number_add(complex_number_t *self, ComplexNumber c);
void complex_number_sub(complex_number_t *self, ComplexNumber c);
```
We can define **multiple instances of this structure** and apply the **same 
functions** to each of these instances. We simply pass the pointer of the 
particular instance to a function.

```C
complex_number_t number = {1.0, 2.0};
complex_number_t c = {3.0, 4.0};

complex_number_add(&number,c);
```
This is a common implementation technique for data structures.
Real objects (e.g. user) can also be displayed in this form.
 
We cannot just create this structure on the stack. 
With the help of the functions **malloc()** and **free()** we can 
manage any number of *complex_number_t* instances on the heap.
 
```C
complex_number_t *c_ptr = complex_new(1.0, 2.0);
//...
free(c_ptr);
``` 

This procedure also has **disadvantages**:
* The data in the Structure *complex_number_t* is always accessible (public) 
and can be changed or read out at any time.
* Each function must define the pointer to the structure as the first 
parameter (`self` pointer).

In C ++, attempts have been made to eliminate these disadvantages by 
introducing classes.


## C++ Classes

Classes are the central feature of an **object-oriented language**. 

### Defining a Class

In C++ a **class** is a user-defined type that has **attributes** (data members) and 
**methods** (member functions). Both of them can be visible (public) or invisible
(private) to the code that uses instances of that class.

_Example_: C++ class declaration
```C++
class ComplexNumber 
{
    private:
        double _re;
        double _im;
   
    public:
        ComplexNumber(double re, double im);
        ~ComplexNumber();
        
        double real();
        void real(double re);
        double imag();
        void imag(double im);
        void add(ComplexNumber c);
        void sub(ComplexNumber c);
};
``` 
All members of a class (attributes and methods) are private per default.

We can separate the 
declaration and the implementation of methods (header and source file).
When we implement methods outside a class we use the **scope resolution :: operator**.

All the member functions defined inside the class definition are by 
default **inline**, but we can also make any non-class function inline 
by using keyword inline with them. 
Inline functions are actual functions, which are copied everywhere 
during compilation, like pre-processor macro, so the overhead of function 
calling is reduced.


To create **Objects** (instances of a class), we define variables of this type. 
Note that the methods can be called directly on these instances using the 
dot notation.

```C++
ComplexNumber number(1.0, 2.0); 
ComplexNumber c(3.0, 4.0);

number.add(c);
``` 
These objects are also created on the stack and go out of scope 
at the end of a method or function.

To objects on the heap we use the **new** operator. 
To delete objects from the heap, use the **delete operator**. 
Note that all objects on the heap must be deleted manually using delete.
```C++
ComplexNumber *c_ptr = new ComplexNumber(1.0, 2.0); 

//...

delete c_ptr;
``` 
The new operator returns a pointer to the created object, thus, the 
members of an object are accessed with the **arrow operator**, for example: 
**c_ptr->real()**.


### Constructor

**Constructors** are special class members which are called by the compiler 
every time an object of that class is instantiated. Constructors have the 
same name as the class and may be defined inside or outside the class 
definition.

```C++
// Default constructor
ComplexNumber()
{
    _re = 0.0;
    _im = 0.0;
}

// Parametrized constructors
ComplexNumber(double re, double im)
{
    _re = re;
    _im = im;
}
``` 
There are three different types of constructurs in C++:
* **Default Constructors:** 
    The default constructor is the constructor which doesn’t take any 
    argument (it has no parameters).
    If we do not define any constructor explicitly, the compiler will 
    automatically provide a default constructor implicitly.    
    _Example_: `ComplexNumber()`
    
* **Parameterized Constrcutors:**
    It is possible to pass arguments to constructors. These arguments 
    help initialize an object when it is created. Note that constructors 
    also can be overloaded.        
    _Example_: `ComplexNumber(double re, double im)`

* **Copy Constructors:**
    A copy constructor is a member function which initializes an object 
    using another object of the same class. 
    If we don’t define our own copy constructor, the C++ compiler 
    creates a default copy constructor for each class which does a 
    member-wise copy between objects (**shallow copy**) . 
    We need to define our own copy constructor only if an object has 
    pointers or any runtime allocation of the resource like file handle, 
    a network connection etc. (**deep copy**).        
    _Example_: `ComplexNumber(const ComplexNumber &number)`
    
    
### Destructor
Destructor is another special member function that is called when the 
**scope of the object ends** or the **delete operator** is called.

Destructors have same name as the class preceded by a tilde `~`, don’t 
take any argument, and don’t return anything.
Note that there can only be one destructor in a class.

```C++
~ComplexNumber() 
{            
    // Called before an object will be removed.
}
```     

If we do not write our own destructor in class, compiler creates a 
**default destructor** for us. The default destructor works fine unless 
we have dynamically allocated memory or pointer in class. 
When a class contains a pointer to memory allocated in class, we should 
write a destructor to release memory before the class instance is destroyed. 
This must be done to avoid memory leak.

## References
Bjarne Stroustrup. **The C++ Programming Language.** Pearson 4th Edition 2017
* Chapter 16: Classes
* Chapter 17: Construction, Cleanup, Copy, and Move 

[C++ Classes and Objects](https://www.geeksforgeeks.org/c-classes-and-objects/)

[Constructors in C++](https://www.geeksforgeeks.org/constructors-c/)

[Copy Constructor in C++](https://www.geeksforgeeks.org/copy-constructor-in-cpp/)

[Destructors in C++](https://www.geeksforgeeks.org/destructors-c/)

*Egon Teiniker, 2020-2022, GPL v3.0*
