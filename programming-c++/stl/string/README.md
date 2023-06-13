# std::string 

The `std::string` class provides a convenient way to handle and manipulate 
strings of characters. 
It encapsulates various operations and functions for string handling, making 
it easier to work with text data.

The `std::string` class is defined in the `<string>` header file, and it is 
part of the `std` namespace. To use it, you typically include the `<string>` 
header and declare strings using the `std::string` type.

The `std::string` class is designed to handle strings dynamically, 
automatically managing memory and providing a high-level interface for 
string operations. 

It offers a safer and more convenient alternative to C-style strings `char*`, 
allowing for easier manipulation and avoiding common pitfalls like buffer overflows.


## Operations
Here are some key features and functions provided by the `std::string` class:

* String Creation and Assignment:
    * We can create a string object using various constructors, such as the 
        default constructor, copy constructor, or constructor that takes a 
        C-string or a portion of another string.
    * String objects can be assigned to one another using assignment 
        operators `=`, allowing you to easily copy or modify strings.

* String Manipulation:
    * The `std::string` class provides member functions for appending (append), 
        concatenating `+` or `+=`, inserting (insert), erasing (erase), replacing 
        (replace), and resizing strings.
    * You can access individual characters of a string using the indexing operator 
        `[]` or the `at()` member function.

* String Information and Access:
    * We can retrieve information about a string's length using the `length() or 
        `size()` member functions.
    * The `c_str()` member function returns a C-style null-terminated string 
        equivalent to the contents of the `std::string` object, allowing you to 
        interoperate with legacy C functions that expect C-strings.
    * The `std::string` object can be iterated over using iterators or with 
        range-based for loops.

* String Comparison and Searching:
    * The `std::string` class provides comparison operators `==`, `!=`, `<`,
    `>`, `<=`, `>=` to compare strings lexicographically.
    * We can search for substrings within a string using member functions like 
    `find()` and `rfind()`, which return the position of the found substring.

* Other Utility Functions:
    * The `std::string` class includes various utility functions, such as 
    `empty()` to check if a string is empty, `clear()` to remove all characters 
    from a string, and `swap()` to exchange the contents of two string objects 
    efficiently.


## References

* [C++ Reference: string](https://en.cppreference.com/w/cpp/string)

*Egon Teiniker, 2020-2023, GPL v3.0*