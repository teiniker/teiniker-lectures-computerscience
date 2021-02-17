#include <unity.h>

#include <stdio.h>
#include <string.h>

char buffer[81];

void setUp(void)
{
	// Setup
	memset(buffer, 0x00, sizeof buffer);
}

void tearDown(void)
{
	// tear down code
}

void test_NoFormatString(void)
{
	// Exercise
	int len = sprintf(buffer,"Hello");
	
	// Verify
	TEST_ASSERT_EQUAL_STRING("Hello", buffer);
	TEST_ASSERT_EQUAL(5, len);
	TEST_ASSERT_EQUAL('\0', buffer[5]);
}

void test_StringParameter(void)
{
	// Setup
	char *str = "Graz"; 
	
	// Exercise
	int len = sprintf(buffer, "Hello %s!", str);
	
	// Verify
	TEST_ASSERT_EQUAL_STRING("Hello Graz!", buffer);
	TEST_ASSERT_EQUAL(11, len);
}

void test_IntegerParameter(void)
{
	// Setup
	int a = 3;
	int b = 7;
	
	// Exercise
	int len = sprintf(buffer, "%d + %d = %d", a, b, a+b);
	
	// Verify
	TEST_ASSERT_EQUAL_STRING("3 + 7 = 10", buffer);
	TEST_ASSERT_EQUAL(10, len);
}

void test_HexParameter(void)
{
	// Setup
	int a = 0xffd2;
	
	// Exercise
	int len = sprintf(buffer, "Hex: %08x", a);
	
	// Verify
	TEST_ASSERT_EQUAL_STRING("Hex: 0000ffd2", buffer);
	TEST_ASSERT_EQUAL(13, len);
}


void test_DoubleParameter(void)
{
	// Setup
	double d = 3.1415;
	
	// Exercise
	int len = sprintf(buffer, "PI = %3.2f", d);
	
	// Verify
	TEST_ASSERT_EQUAL_STRING("PI = 3.14", buffer);
	TEST_ASSERT_EQUAL(9, len);
}


int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_NoFormatString);
	RUN_TEST(test_StringParameter);
	RUN_TEST(test_IntegerParameter);
	RUN_TEST(test_HexParameter);
	RUN_TEST(test_DoubleParameter);
	return UNITY_END();
}
