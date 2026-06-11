# Example: Book Class

The following example shows the implementation of a class `Book`, which can 
store the ISBN number, the authors and the title. In addition, a JSON 
representation of this data should be output as a string.


## Class Declaration 

The class is declared in the header file `book.h`:

```C++
#include <string>
```
* **Include Directive**: This line includes the C++ standard library header `<string>`, 
which provides the `std::string` class used for string manipulation.

```C++
class Book
{
public:
    Book(const std::string& isbn, const std::string& author, const std::string& title);
    //...
}
```
* **Class Declaration**: This declares a class named `Book`.

* **Public Access Specifier**: Members declared `public` are accessible from outside the class.

* **Constructor**: This is a constructor declaration for the `Book` class. It takes three 
    `std::string` parameters to initialize the isbn, author, and title of a book.

* **Destructor**: If a class does not have a user-defined destructor, the compiler will 
    automatically generate a default destructor for the class. This default destructor will 
    handle the destruction of the class members appropriately.

In the given example, the use of **object references** plays a crucial role in ensuring efficient 
and correct manipulation of `std::string` objects.
* **Parameters as References**: The constructor takes its parameters as `const string&` (constant 
    references to `std::string` objects).
    * **Efficiency**: Passing strings by reference avoids copying the entire string object, which 
        can be an expensive operation, especially for large strings. Instead, a reference to the 
        original string is passed, which is much more efficient.
    * **Const-correctness**: The `const` keyword ensures that the strings passed to the constructor 
        are not modified within the constructor. This guarantees that the original strings provided 
        by the caller remain unchanged, providing safety and clarity in the code.

* **Return by Value**: The getter methods return `std::string` objects by value.
    * **Returning by Value**: Returning by value ensures that the caller gets a copy of the string,
        which they can safely use and modify without affecting the original string stored in the 
        `Book` object. Modern C++ compilers often optimize return by value using 
        **Return Value Optimization (RVO)**, making this approach efficient.
    * **Const Methods**: The `const` keyword after the method signature indicates that these methods 
        do not modify the state of the object. This is important for maintaining const-correctness, 
        allowing these methods to be called on const instances of the `Book` class.

```C++
    std::string getIsbn() const;
    void setIsbn(const std::string& isbn);
```

* **Accessor Methods**:
    * `getIsbn() const`: This is a getter method that returns the `isbn` of the book. 
        of the class.
    * `setIsbn(const std::string& isbn)`: This is a setter method that sets the `isbn` of 
        the book to the given value.


```C++
    std::string toJson() const;
```

* **toJson() Method**: This method converts the `Book` object to a JSON string representation. 

```C++
private:
    std::string _isbn;
    std::string _author;
    std::string _title;
```

* **Private Access Specifier**: Members declared under this are only accessible from within 
    the class itself.

* **Member Variables**:
    * `_isbn`: Stores the ISBN of the `Book`.
    * `_author`: Stores the author of the `Book`.
    * `_title`: Stores the title of the `Book`.



## Class Implementation

The class is implemented in the `book.cpp` file:

```C++
#include <string>
#include <sstream>
#include "book.h"

using namespace std;
```
* **Includes**: The implementation file includes the `<string>` header for `std::string` 
    and the `<sstream>` header for `std::ostringstream`, which are part of the C++ Standard Library.

* **Header Include**: It includes the `book.h` header file, which contains the declaration of the 
    Book class.

* **Namespace**: `using namespace std;` is used to avoid prefixing `std::` before standard library 
    names like `string` and `ostringstream`.


```C++
Book::Book(const string& isbn, const string& author, const string& title)
    : _isbn(isbn), _author(author), _title(title)
{
}
```
* **Constructor**: The constructor initializes the `Book` object with the given `isbn`, `author`, 
    and `title` values.
* **Member Initialization List**: The member variables `_isbn`, `_author`, and `_title` are 
    initialized using an initialization list. This is more efficient than assigning values inside 
    the constructor body.

```C++
string Book::getIsbn() const
{
    return _isbn;
}

void Book::setIsbn(const string& isbn)
{
    _isbn = isbn;
}
```
* **Accessor Methods**:
    * `getIsbn()`: Returns the `isbn` value. The method is marked `const` to indicate that it 
        does not modify any member variables.
    * `setIsbn()`: Sets the `isbn` to the given value.

```C++
string Book::toJson() const
{
    ostringstream json;
    json << "{"
         << "\"isbn\":\"" << _isbn << "\","
         << "\"author\":\"" << _author << "\","
         << "\"title\":\"" << _title << "\""
         << "}";
    return json.str();
}
```

* **Method toJson()**: Converts the Book object to a JSON string representation.
    * **ostringstream**: An `ostringstream` object json is used to build the JSON string. `ostringstream` 
        is part of the C++ Standard Library and allows for efficient string construction.
    * **Stream Insertion Operator**: The `<< operator` is used to insert strings and variables into 
        the `ostringstream` object.
    * **JSON Formatting**: The method constructs a JSON-formatted string by inserting the `isbn`, 
        `author`, and `title` values.
    * **Return Value**: The `json.str()` method converts the contents of the `ostringstream` object 
        to a `std::string` and returns it.


## Testing the Book Class

To test the implementation of the `Book` class, the **Unity Testing Framework** is used.

```C++
#include <unity.h>
#include "book.h"

using namespace std;
```
* **Includes**: The test file includes the **Unity** framework header `unity.h` for unit testing 
    and the `book.h` header for the `Book` class.
* **Namespace**: `using namespace std;` is used to avoid prefixing `std::` before standard library 
    names like `string`.


**Test Case test_constructor()**: This test case verifies that the `Book` constructor 
correctly initializes the `isbn`, `author`, and `title` attributes.

```C++
void test_constructor(void)
{
    Book book("978-0131103627", "Brian W. Kernighan and Dennis Ritchie", "The C Programming Language");                         

    TEST_ASSERT_EQUAL_STRING("978-0131103627", book.getIsbn().c_str());
    TEST_ASSERT_TRUE("Brian W. Kernighan and Dennis Ritchie" == book.getAuthor());
    TEST_ASSERT_TRUE("The C Programming Language" == book.getTitle());
}
```

* A `Book` object is instantiated with specific values for `isbn`, `author`, and `title`.
* `TEST_ASSERT_EQUAL_STRING`: Checks if the `isbn` returned by `book.getIsbn().c_str()` matches 
    the expected value.
* `TEST_ASSERT_TRUE`: Checks if the `author` and `title` returned by `book.getAuthor()` and 
    `book.getTitle()` match the expected values using the `== operator` for `std::string`.

Note that this test cases shows two different ways to compare C++ `string` objects.


**Test Case test_constructor_with_new()**: This test case verifies the `Book` constructor when 
the `Book` object is created using dynamic memory allocation (`new` operator).

```C++
void test_constructor_with_new(void)
{
    Book *book = new Book("978-0131103627", "Brian W. Kernighan and Dennis Ritchie", "The C Programming Language");                         

    TEST_ASSERT_TRUE("978-0131103627" == book->getIsbn());
    TEST_ASSERT_TRUE("Brian W. Kernighan and Dennis Ritchie" == book->getAuthor());
    TEST_ASSERT_TRUE("The C Programming Language" == book->getTitle());

    delete book;
}
```
* A `Book` object is created dynamically using `new`.
* `TEST_ASSERT_TRUE`: Checks if the `isbn`, `author`, and `title` returned by 
    the getter methods match the expected values.
* The `Book` object is deleted using `delete` to free the allocated memory.


**Test Case test_json()**: This test case verifies that the `toJson()` method correctly 
converts the `Book` object to a JSON string.

```C++
void test_json(void)
{
    Book book("978-0131103627", "Brian W. Kernighan and Dennis Ritchie", "The C Programming Language");                         
    string json = book.toJson();

    string expected = "{\"isbn\":\"978-0131103627\",\"author\":\"Brian W. Kernighan and Dennis Ritchie\",\"title\":\"The C Programming Language\"}";
    TEST_ASSERT_TRUE(expected == json);
}
```
* A `Book` object is instantiated with specific values for `isbn`, `author`, and `title`.
* The `toJson()` method is called, and its result is stored in the JSON string.
* `TEST_ASSERT_TRUE`: Checks if the generated JSON string matches the expected JSON string.


*Egon Teiniker, 2020-2024, GPL v3.0*
