#include <unity.h>

#include "complex_number.h"


void setUp(void)
{
}

void tearDown(void)
{
}


void test_constructor(void)
{
    ComplexNumber c(1.0, 2.0);                          // Create object in stack

    TEST_ASSERT_FLOAT_WITHIN(1E-03, 1.0, c.real());
    TEST_ASSERT_FLOAT_WITHIN(1E-03, 2.0, c.imag());
}

void test_constructor_with_new(void)
{
    ComplexNumber *c_ptr = new ComplexNumber(1.0, 2.0); // Create object in heap

    TEST_ASSERT_FLOAT_WITHIN(1E-03, 1.0, c_ptr->real());
    TEST_ASSERT_FLOAT_WITHIN(1E-03, 2.0, c_ptr->imag());

    delete c_ptr;
}

void test_add(void)
{
    ComplexNumber c1(1.0, 2.0);
    ComplexNumber c2(3.0, 4.0);
    
    c1.add(c2);

    TEST_ASSERT_FLOAT_WITHIN(1E-03, 1.0+3.0, c1.real());
    TEST_ASSERT_FLOAT_WITHIN(1E-03, 2.0+4.0, c1.imag());
}

void test_sub(void)
{
    ComplexNumber c1(1.0, 2.0);
    ComplexNumber c2(3.0, 4.0);
    
    c1.sub(c2);

    TEST_ASSERT_FLOAT_WITHIN(1E-03, 1.0-3.0, c1.real());
    TEST_ASSERT_FLOAT_WITHIN(1E-03, 2.0-4.0, c1.imag());
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_constructor);
    RUN_TEST(test_constructor_with_new);
    RUN_TEST(test_add);
    RUN_TEST(test_add);
	return UNITY_END();
}
