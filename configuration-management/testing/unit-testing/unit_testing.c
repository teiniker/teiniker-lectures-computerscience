#include <stdio.h>
#include <string.h>
#include <unity.h>

void setUp(void)
{
	printf("Setup\n");
}

void tearDown(void)
{
	printf("Teardown\n");
}

void test_A(void)
{
	printf("Test_A\n");
}

void test_B(void)
{
	printf("Test_B\n");
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_A);
	RUN_TEST(test_B);
	return UNITY_END();
}
