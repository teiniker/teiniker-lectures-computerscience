# Introduction to Test Automation

A testing framework such as **Unity** enforces a consistent structure 
for each unit test, ensuring the **four phases** (setup, exercise, 
verify, and teardown) are applied. 

This improves readability, reduces duplication, and makes tests more 
reliable and maintainable.

_Example_: The four test phases implemented in a single test function
```C
char buffer[81];

void test_A(void)
{
    // Setup
    memset(buffer, 0x00, sizeof buffer);
    
    // Exercise
    int len = sprintf(buffer,"Hello");
    
    // Verify
    TEST_ASSERT_EQUAL_STRING("Hello", buffer);
    TEST_ASSERT_EQUAL(5, len);
    
    // Teardown
}
```

To avoid code redundancies we can use explicit **setup()** 
and **teardown()** functions. 

_Example_: Setup and teardown implemented in separate functions 
```C
char buffer[81];

void setUp(void)
{
    // Setup
    memset(buffer, 0x00, sizeof buffer);
}

void tearDown(void)
{
    // Teardown 
}

void test_NoFormatString(void)
{
    // Exercise
    int len = sprintf(buffer,"Hello");
    
    // Verify
    TEST_ASSERT_EQUAL_STRING("Hello", buffer);
    TEST_ASSERT_EQUAL(5, len);
}
```
Note that in Unity we always need to provide `setUp()` and `tearDown()` 
functions, even when they contain no code. The framework expects these 
hooks to be defined for every test module to ensure consistent lifecycle 
handling.

The **Test Runner** executes `setUp()` before, and `tearDown()` after 
each test function.

_Example_: Execution order enforced by the test runner 
```C
Setup
Test_A
Teardown
unit_test.c:31:test_A:PASS

Setup
Test_B
Teardown
unit_test.c:32:test_B:PASS

-----------------------
2 Tests 0 Failures 0 Ignored 
OK
```

Note that `setUp()` and `tearDown()` isolate the individual test cases 
from each other. Each test case begins with the same prerequisites. 

Therefore, **test cases can be executed in any order and as often as required**.


## References
* Gerard Meszaros. **xUnit Test Patterns**. Addison-Wesley, 2007 
* [XUnit Basics](http://xunitpatterns.com/XUnitBasics.html)
* [Unity: Getting Started](https://github.com/ThrowTheSwitch/Unity/blob/master/docs/UnityGettingStartedGuide.md)
* [Unity: Assertions Reference](https://github.com/ThrowTheSwitch/Unity/blob/master/docs/UnityAssertionsReference.md)
 
*Egon Teiniker, 2020-2026, GPL v3.0* 