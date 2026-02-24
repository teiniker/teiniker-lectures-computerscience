#include <unity.h>

#include <stdio.h>
#include <math.h>

const double EPS = 1e-6;
const double PI = 3.14159265358979323846;

void setUp(void)
{
}

void tearDown(void)
{
}


void test_sqrt(void)
{
	TEST_ASSERT_DOUBLE_WITHIN(EPS, 2.0, sqrt(4.0));
	TEST_ASSERT_DOUBLE_WITHIN(EPS, 0.0, sqrt(0.0));
	TEST_ASSERT_DOUBLE_WITHIN(EPS, 2.0, sqrt(2.0) * sqrt(2.0));
}

void test_sin(void)
{
	TEST_ASSERT_DOUBLE_WITHIN(EPS, 0.0, sin(0.0));
	TEST_ASSERT_DOUBLE_WITHIN(EPS, 1.0, sin(PI / 2.0));
	TEST_ASSERT_DOUBLE_WITHIN(EPS, 0.0, sin(PI));
}

void test_cos(void)
{
	TEST_ASSERT_DOUBLE_WITHIN(EPS, 1.0, cos(0.0));
	TEST_ASSERT_DOUBLE_WITHIN(EPS, 0.0, cos(PI / 2.0));
	TEST_ASSERT_DOUBLE_WITHIN(EPS, -1.0, cos(PI));
}

void test_tan(void)
{
	TEST_ASSERT_DOUBLE_WITHIN(EPS, 0.0, tan(0.0));
	TEST_ASSERT_DOUBLE_WITHIN(EPS, 1.0, tan(PI / 4.0));
}

void test_pow(void)
{
	TEST_ASSERT_DOUBLE_WITHIN(EPS, 8.0, pow(2.0, 3.0));
	TEST_ASSERT_DOUBLE_WITHIN(EPS, 3.0, pow(9.0, 0.5));
	TEST_ASSERT_DOUBLE_WITHIN(EPS, 1.0, pow(5.0, 0.0));
}

void test_exp(void)
{
	TEST_ASSERT_DOUBLE_WITHIN(EPS, 1.0, exp(0.0));
	TEST_ASSERT_DOUBLE_WITHIN(EPS, 1.0, log(exp(1.0)));
}

void test_log(void)
{
	TEST_ASSERT_DOUBLE_WITHIN(EPS, 0.0, log(1.0));
	TEST_ASSERT_DOUBLE_WITHIN(EPS, 10.0, exp(log(10.0)));
}

int main(void)
{
	UNITY_BEGIN();

	RUN_TEST(test_sqrt);
	RUN_TEST(test_sin);
	RUN_TEST(test_cos);
	RUN_TEST(test_tan);
	RUN_TEST(test_pow);
	RUN_TEST(test_exp);
	RUN_TEST(test_log);

	return UNITY_END();
}
