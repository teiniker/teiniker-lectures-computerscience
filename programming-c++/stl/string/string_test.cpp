#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>

#include <unity.h>

using namespace std;

void setUp(void)
{
}

void tearDown(void)
{
}

/**
 * size() returns the number of elements in the string.
 **/
void test_string_size(void)
{
   string str = "Hello World";
   size_t len = str.size();

   TEST_ASSERT_EQUAL(11, len);
}


/**
 * Operator[] returns a reference to the character at specified location pos 
 * if pos < size(), or a reference to CharT() if pos == size(). 
 * No bounds checking is performed.
 * 
 * at() returns a reference to the character at specified location pos. 
 * Bounds checking is performed, exception of type std::out_of_range will 
 * be thrown on invalid access.
 **/ 
void test_string_at(void)
{
   string str = "Hello World";
   char c1 = str[4];
   char c2 = str.at(4);
   TEST_ASSERT_EQUAL(c1, c2);

   str.at(4) = 'O';
   TEST_ASSERT_EQUAL('O', str[4]);
}


/**
 * c_str() returns a pointer to a null-terminated character array with data 
 * equivalent to those stored in the string.
 * Note that c_str() and data() perform the same function.
 **/
void test_c_str(void)
{
   string str = "Hello World";
   const char* s = str.c_str();

   TEST_ASSERT_EQUAL(0, strcmp("Hello World", s));
   TEST_ASSERT_EQUAL(11, strlen(s));
   TEST_ASSERT_EQUAL('\0', s[11]);
}

/**
 * Comparison Operators (==, !=, <, >, <=, >=):
 * We can use the comparison operators directly with std::string objects. 
 * These operators compare the lexicographical order of the strings.
 **/
void test_string_comparison_operators(void)
{
   string str1 = "Hello";
   string str2 = "World";

   TEST_ASSERT_FALSE(str1 == str2);
   TEST_ASSERT_TRUE(str1 != str2);
   TEST_ASSERT_TRUE(str1 < str2);
   TEST_ASSERT_FALSE(str1 > str2);
}


void test_string_concatination(void)
{
   string str1 = "Hello ";
   string str2 = "World";

   string str = str1 + str2;

   TEST_ASSERT_FALSE("" == str2);
   TEST_ASSERT_TRUE(str1 != str2);
   TEST_ASSERT_TRUE(str1 < str2);
   TEST_ASSERT_FALSE(str1 > str2);
}


int main(void)
{
	UNITY_BEGIN();
   RUN_TEST(test_string_size);
   RUN_TEST(test_string_at);
   RUN_TEST(test_c_str);
   RUN_TEST(test_string_comparison_operators);
   //...

	return UNITY_END();
}
