#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unity.h>

#include "sum.h"


void setUp(void)
{
    // Nothing to do
}

void tearDown(void)
{
    // Nothing to do
}


void test_n_zero(void)
{
    TEST_ASSERT_EQUAL(0, sum_of_integers(0));
}

void test_n_one(void)
{
    TEST_ASSERT_EQUAL(1, sum_of_integers(1));
}

void test_n(void)
{
    TEST_ASSERT_EQUAL(1+2+3+4+5, sum_of_integers(5));
}


int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_n_zero);
    RUN_TEST(test_n_one);
	RUN_TEST(test_n);
	return UNITY_END();
}
