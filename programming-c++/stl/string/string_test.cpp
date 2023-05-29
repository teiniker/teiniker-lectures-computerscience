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

void test_string_length(void)
{
   string str = "Hello World";
   size_t len = str.length();

   TEST_ASSERT_EQUAL(11, len);
}

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


int main(void)
{
	UNITY_BEGIN();
   RUN_TEST(test_string_length);
   RUN_TEST(test_c_str);
   RUN_TEST(test_string_comparison_operators);
   //...

	return UNITY_END();
}
