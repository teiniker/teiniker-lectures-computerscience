#include <unity.h>

#include "vector.h"

const double DELTA = 1E-3;

vector_t a = {1.0, 2.0, 3.0};
vector_t b = {4.0, 5.0, 6.0};

void setUp(void)
{
	// Setup
}

void tearDown(void)
{
	// Tear down code
}


void test_equal(void)
{
    // Exercise + Verify
    TEST_ASSERT_TRUE(vector_equal(a, a, DELTA));
    TEST_ASSERT_FALSE(vector_equal(a, b, DELTA));
}

void test_add(void)
{
    // Exercise
    vector_t c = vector_add(a, b);
    vector_print(c);

    // Verify
    TEST_ASSERT_FLOAT_WITHIN(DELTA, 5.0, c.x);
    TEST_ASSERT_FLOAT_WITHIN(DELTA, 7.0, c.y);
    TEST_ASSERT_FLOAT_WITHIN(DELTA, 9.0, c.z);   
}

void test_sub(void)
{
    // Exercise
    vector_t c = vector_sub(a, b);
    vector_print(c);
    
    // Verify
    TEST_ASSERT_FLOAT_WITHIN(DELTA, -3.0, c.x);
    TEST_ASSERT_FLOAT_WITHIN(DELTA, -3.0, c.y);
    TEST_ASSERT_FLOAT_WITHIN(DELTA, -3.0, c.z);    
}

void test_scalar_mult(void)
{
    // Exercise
    vector_t c = vector_scalar_mult(2.0, a);
    vector_print(c);

    // Verify
    TEST_ASSERT_FLOAT_WITHIN(DELTA, 2.0, c.x);
    TEST_ASSERT_FLOAT_WITHIN(DELTA, 4.0, c.y);
    TEST_ASSERT_FLOAT_WITHIN(DELTA, 6.0, c.z);    
}

void test_dot_product(void)
{
    // Exercise
    double product = vector_dot_product(a, b);

    // Verify
    TEST_ASSERT_FLOAT_WITHIN(DELTA, 32, product);
}

void test_cross_product(void)
{
    // Exercise
    vector_t c = vecor_cross_product(a, b);
    vector_print(c);
 
    // Verify
    TEST_ASSERT_FLOAT_WITHIN(DELTA, -3.0, c.x);
    TEST_ASSERT_FLOAT_WITHIN(DELTA, 6.0, c.y);
    TEST_ASSERT_FLOAT_WITHIN(DELTA, -3.0, c.z);
}

int main(void)
{
	UNITY_BEGIN();

	RUN_TEST(test_equal);
	RUN_TEST(test_add);
	RUN_TEST(test_sub);
	RUN_TEST(test_scalar_mult);
    RUN_TEST(test_dot_product);
    RUN_TEST(test_cross_product);

	return UNITY_END();
}

