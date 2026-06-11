#include <unity.h>

#include "resistor.h"


void setUp(void)
{
}

void tearDown(void)
{
}


void test_constructor(void)
{
    Resistor r(470, 2);        // Stack                 

    TEST_ASSERT_EQUAL(470, r.value());
    TEST_ASSERT_EQUAL(2, r.tolerance());
}

void test_constructor_with_new(void)
{
    Resistor *r = new Resistor(470, 2); // Heap 

    TEST_ASSERT_EQUAL(470, r->value());
    TEST_ASSERT_EQUAL(2, r->tolerance());

    delete r;
}

void test_serial(void)
{
    Resistor r1(270, 5);
    Resistor r2(120, 2);
    
    r1.serial(r2);

    TEST_ASSERT_EQUAL(270+120, r1.value());
    TEST_ASSERT_EQUAL(5, r1.tolerance());
}

void test_parallel(void)
{
    Resistor r1(270, 5);
    Resistor r2(120, 2);
    
    r1.parallel(r2);
    TEST_ASSERT_EQUAL(270*120/(270+120), r1.value());
    TEST_ASSERT_EQUAL(5, r1.tolerance());
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_constructor);
    RUN_TEST(test_constructor_with_new);
    RUN_TEST(test_serial);
    RUN_TEST(test_parallel);
	return UNITY_END();
}
