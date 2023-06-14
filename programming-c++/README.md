# Programming in C++

In the hands of a knowledgeable programmer, C++ can produce smaller, more efficient,
and more readable code than any other system programming language.

_Example_: [Hello World in C++](introduction/hello-world/)

As a descendant of C, C++ also takes **zero-overhead abstraction** and direct mapping 
to hardware very seriously. This commitment goes beyond just the C language features 
that C++ supports. 

Everything that C++ builds on top of C, including new language features, upholds these principles, and departures from either are made very deliberately. 
In fact, some C++ features imply even less overhead than corresponding C code.


## From C to C++ 

Modern C++ compilers will accommodate most of your C programming habits. 
This makes it easy to embrace a few of the tactical niceties that the C++ language 
affords us while deliberately avoiding the language’s deeper themes. 

This style of C++ - we can call it **Super C** - is important to discuss for several reasons: 
* First, seasoned C programmers can immediately benefit from applying simple, tactical-level 
  C++ concepts to their programs. 
* Second, Super C is not fully comprehensive C++. Simply sprinkling references and instances of 
  auto around a C program might make your code more robust and readable, but you’ll need 
  to learn other concepts to take full advantage of it. 
* Third, in some environments (embedded software and heterogeneous computing), the 
  available tool chains have incomplete C++ support.

It’s possible to benefit immediately from at least **some C++ idioms**:

* [Implicit typedef](basics/first-steps/implicit-typedef/)
* [Namespaces](basics/first-steps/namespaces/)
* [auto Initialization](basics/first-steps/auto-initialization/)
* [Function Overloading](basics/first-steps/function-overloading/)
* [Default Arguments](basics/first-steps/default-arguments/)
* [References](basics/first-steps/references/)


## Object-Oriented Programming (OOP)

OOP is a **programming paradigm** that organizes software design around objects, 
rather than functions and logic. An object has unique attributes and behavior. 

Here's a brief summary of the key concepts:

* [**Classes and Objects**](basics/classes/): In OOP, objects are instances 
of classes, which can be thought of as blueprints. 
Each object is an instance of a class and has state (attributes or properties) 
and behavior (methods or functions).

* **Encapsulation**: This is the principle of bundling the attributes and the 
methods that operate on the attributes into a single unit, which is called a class. 
This mechanism helps to hide the internal implementation details and protects the data 
from being accessed directly.

* **Inheritance**: This is a way to form new classes using classes that have 
already been defined. The new classes, known as derived classes, inherit attributes 
and behavior of the existing classes, which are referred to as base classes. 
Inheritance helps to promote code reusability and represents a **is-a** relationship.

* **Polymorphism**: This principle allows one interface to be used for a general 
class of actions. The specific action is determined by the exact nature of the 
situation. It provides a single interface to entities of different types.

* **Abstraction**: Abstraction is the concept of exposing only the required essential
characteristics and behavior with respect to a context. This simplifies the complexity 
by hiding unnecessary details from the user.

In essence, OOP allows for the clear structure of programs, making them easier to 
understand and manage. It also enhances code reusability and makes programs more 
modular and efficient.

### Data Structures 
One area of application where data and behavior can be combined into objecs are 
data structures.
We can very easily create C++ classes from the given data structure implementations:

* [Linked-List](datastructures/linked-list/)
* [Stack](datastructures/stack/)


## Standard Template Library (STL)

A huge benefit of learning C++ is that you gain access to the C++ Standard Library, the `stdlib`, free of charge. The stdlib is composed of three interlocking parts: **containers**, **iterators**, and **algorithms**.

### String Library
* [String](stl/string/)


### Containers Library
* Sequence Containers\
  Sequence containers implement data structures which can be accessed sequentially.
  * [Vector](stl/vector/)
  * [List](stl/list/)

* Container Adaptors\
  Container adaptors provide a different interface for sequential containers.

  * [Stack](stl/stack/)
  * [Queue](stl/queue/)


## Arduino Framework
If we look at the source code of the Arduino Framework, we will find many C++ features:

_Example:_ [C++ Features in the Arduino Core](arduino-framework/)


## References

* [YouTube (CppCon 2021): Back to Basics: Classic STL - Bob Steagall](https://youtu.be/tXUXl_RzkAk)

* [C++ Reference: Containers Library](https://en.cppreference.com/w/cpp/container)

* Josh. Lospinoso. **C++ Crash Course**. No Starch Press, 2019 

* Bjarne Stroustrup. **The C++ Programming Language.** Pearson 4th Edition 2017

*Egon Teiniker, 2020-2023, GPL v3.0*
