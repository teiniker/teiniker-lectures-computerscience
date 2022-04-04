#include <stdlib.h>
#include <stdio.h>
#include <unity.h>

#include "string_operations.h"

void setUp(void)
{
	// Setup
}

void tearDown(void)
{
	// tear down code
}


void test_string_length(void)
{
	// Exercise
	size_t len = string_length("1001 0011 1111 0000");
	
	// Verify
	TEST_ASSERT_EQUAL(19, len);
}

void test_string_equal(void)
{
    // Exercise & Verify
	TEST_ASSERT_TRUE(string_equal("1100", "1100"));   // s1 == a2
    TEST_ASSERT_FALSE(string_equal("100", "1100"));   // s1 is too short
    TEST_ASSERT_FALSE(string_equal("0100", "1100"));  // s1 != s2
}

void test_string_copy(void)
{
	// Setup
    char *s = "1001 0011 1111 0000";    
    
	// Exercise
	char *p = string_copy(s);
    
	// Verify
    TEST_ASSERT_EQUAL_STRING("1001 0011 1111 0000", p);  

	// Teardown
    free(p);
}

void test_string_concatination(void)
{
	// Setup
    char *s1 = "1001 0011 ";
    char *s2 = "1111 0000";

	// Exercise
    char *q = string_concatenation(s1, s2);

	// Verify
	TEST_ASSERT_EQUAL_STRING("1001 0011 1111 0000", q);  
    
	// Teardown
	free(q);
}


int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_string_length);
	RUN_TEST(test_string_equal);
	RUN_TEST(test_string_copy);
	RUN_TEST(test_string_concatination);
	return UNITY_END();
}
