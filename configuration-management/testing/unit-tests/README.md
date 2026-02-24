# Using the Unity Test Framework

## Structure of a Test File

Test files are C files. 
Most often you will create a single test file for each C module that you want to test. 
The test file should include `unity.h` and the header for your C module to be tested.

A test file will include a `setUp()` and `tearDown()` function: 
* The `setUp()` function can contain anything you would like to run before each test. 
* The `tearDown()` function can contain anything you would like to run after each test. 

Both functions accept no arguments and return nothing. 
We may leave either or both of these blank if we have no need for them.

The linker complains if it can't find `Setup()` and `tearDown()`, therefore, **we have to 
add empty functions at least**.
 
The majority of the file will be a series of **test functions**. 
Test functions take no arguments and return nothing. 
Test functions follow the convention of starting with the word `test_`. 
We don't have to name them this way, but it makes it clear what functions are tests 
for other developers. 

At the bottom of your test file, we will write a `main()` function. 
This function will call `UNITY_BEGIN()`, then `RUN_TEST()` for each test, 
and finally `UNITY_END()`.

This is what will actually trigger each of those test functions to run, 
so **it is important that each function gets its own `RUN_TEST()` call**.

Example: Unity test file
```C
#include <unity.h>              // Include Unitiy framework

void setUp(void)                // Setup code (or empty)
{
    printf("Setup\n");
}

void tearDown(void)             // Teardown code (or empty)
{
    printf("Teardown\n");
}

void test_A(void)               // Test case
{
    printf("Test_A\n");
}

void test_B(void)               // Test case
{
    printf("Test_B\n");
}

int main(void)                  // Configure and start the test runner
{
    UNITY_BEGIN();
    RUN_TEST(test_A);
    RUN_TEST(test_B);
    return UNITY_END();
}
```

## Test Runner

The **Test Runner** is embedded in the final executable and executes 
`setUp()` before, and `tearDown()` after each test function.

_Example_: Execution order enforced by the test runner

```bash
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


## Result Verification

In result verification, we inspect the state of the system under test after it has been exercised 
and compare it to the expected state (**State Verification**).

How it works:
* We exercise the SUT by invoking the functions of interest.
* We interact with the SUT to retrieve its post-exercise state and compare it with the expected 
    end state by calling **assert functions**.

Unity provides a lot of assert functions we can use:

* **Numerical Assertions: Boolean** 
    * `TEST_ASSERT_TRUE(condition)`\
        Evaluates whatever code is in condition and fails if it evaluates to false.
    
    * `TEST_ASSERT_FALSE(condition)`\
        Evaluates whatever code is in condition and fails if it evaluates to true.
        
    * `TEST_ASSERT(condition)`\
        Another way of calling `TEST_ASSERT_TRUE`.

* **Numerical Assertions: Integers**
    * Compare two integers for equality and display errors as **signed integers**. 
    ```    
        TEST_ASSERT_EQUAL_INT(expected, actual)
        TEST_ASSERT_EQUAL_INT8(expected, actual)
        TEST_ASSERT_EQUAL_INT16(expected, actual)
        TEST_ASSERT_EQUAL_INT32(expected, actual)
        TEST_ASSERT_EQUAL_INT64(expected, actual)
    ```
    
    * Compare two integers for equality and display errors as **unsigned integers**.
    ```
        TEST_ASSERT_EQUAL_UINT(expected, actual)
        TEST_ASSERT_EQUAL_UINT8(expected, actual)
        TEST_ASSERT_EQUAL_UINT16(expected, actual)
        TEST_ASSERT_EQUAL_UINT32(expected, actual)
        TEST_ASSERT_EQUAL_UINT64(expected, actual)
    ```
  
    * `TEST_ASSERT_EQUAL(expected, actual)`\
        Another way of calling `TEST_ASSERT_EQUAL_INT`.

* **Numerical Assertions: Bitwise**   
    * `TEST_ASSERT_BITS(mask, expected, actual)`\
        Use an integer mask to specify which bits should be compared between two other integers. 
        High bits in the mask are compared, low bits ignored.
    
    * `TEST_ASSERT_BITS_HIGH(mask, actual)`\
        Use an integer mask to specify which bits should be inspected to determine if they are all set high. 
        High bits in the mask are compared, low bits ignored.
  
    * `TEST_ASSERT_BITS_LOW(mask, actual)`\
        Use an integer mask to specify which bits should be inspected to determine if they are all set low. 
        High bits in the mask are compared, low bits ignored.
    
    * `TEST_ASSERT_BIT_HIGH(bit, actual)`\
        Test a single bit and verify that it is high. The bit is specified 0-31 for a 32-bit integer.    
     
    * `TEST_ASSERT_BIT_LOW(bit, actual)`\
        Test a single bit and verify that it is low. The bit is specified 0-31 for a 32-bit integer.
  
* **Numerial Assertions: Floating Point** 
    * `TEST_ASSERT_FLOAT_WITHIN(delta, expected, actual)`\
        Asserts that the actual value is within plus or minus delta of the expected value.
        
    * Asserts that two floating point values are "equal" within a small % delta of the expected value.
    ```    
        TEST_ASSERT_EQUAL_FLOAT(expected, actual)    
        TEST_ASSERT_EQUAL_DOUBLE(expected, actual)
     ```

* **String Assertions**
    * `TEST_ASSERT_EQUAL_STRING(expected, actual)`\
        Compare two null-terminate strings. Fail if any character is different or if the lengths are different.
          
    *  `TEST_ASSERT_EQUAL_STRING_LEN(expected, actual, len)`\
        Compare two strings. Fail if any character is different, stop comparing after len characters.     
          
* **Pointer Assertions**\
    Most pointer operations can be performed by simply using the integer comparisons. 
    However, a couple of special cases are added for clarity.
    
    * `TEST_ASSERT_NULL(pointer)`\
        Fails if the pointer is not equal to NULL.
        
    * `TEST_ASSERT_NOT_NULL(pointer)`\
        Fails if the pointer is equal to NULL.
            
* **Memory Assertions**
    * `TEST_ASSERT_EQUAL_MEMORY(expected, actual, len)`\
        Compare two blocks of memory. 
        
* **Array Assertions**\
    We can append `_ARRAY` to any of these macros to make an array comparison of that type. 
    If we need to care a bit more about the actual size of the value being checked. 
    We can also specify an additional argument which is the number of elements to compare.
    ```
        TEST_ASSERT_EQUAL_HEX8_ARRAY(expected, actual, elements)
    ```
* **Assertion Message**\
    We can append `_MESSAGE` to any of the macros to make them take an additional argument. 
    This argument is a string that will be printed at the end of the failure strings. 
    This is useful for specifying more information about the problem.
    
  
## Build and Run a Test File

A test is produced by **compiling and linking Unity, the test source, and 
the C modules under test**.  
The resulting binary **is the test executable for that module** and can 
be run directly.

In practice, this means each module gets its own small test program, 
which keeps dependencies minimal and makes failures easier to isolate. 

We can rebuild and rerun these executables frequently during development 
to validate changes quickly.

_Example_: Use **make** to build and run the test file
```bash
$ make
mkdir -p build
gcc -std=c17 -g -Wall -c ../unity/unity.c -o build/unity.o
gcc -std=c17 -g -Wall -I ../unity -c test.c -o build/test.o
gcc -std=c17 -g -Wall build/unity.o build/test.o -o build/test
```

To run the tests, simply execute the built test binary. 
This launches the Unity test runner and prints a summary of 
passed and failed cases.

```bash
$ build/test
``` 

## References
* [Unity: Getting Started](https://github.com/ThrowTheSwitch/Unity/blob/master/docs/UnityGettingStartedGuide.md)
* [Unity: Assertions Reference](https://github.com/ThrowTheSwitch/Unity/blob/master/docs/UnityAssertionsReference.md)
 
*Egon Teiniker, 2020-2026, GPL v3.0* 