#include <unity.h>

#include "date.h"


void setUp(void)
{
}

void tearDown(void)
{
}

void test_constructor(void)
{
    date_t birthday = {23, 6, 1912}; // Alan Turing's date of birth                        

    TEST_ASSERT_EQUAL(23, birthday.day);
    TEST_ASSERT_EQUAL(6, birthday.month);
    TEST_ASSERT_EQUAL(1912, birthday.year);
}

void test_constructor_with_new(void)
{
    date_t *birthday = date_new(23, 6, 1912); 

    TEST_ASSERT_EQUAL(23, birthday->day);
    TEST_ASSERT_EQUAL(6, birthday->month);
    TEST_ASSERT_EQUAL(1912, birthday->year);

    date_delete(birthday);
}

void test_is_leap_year(void)
{
    date_t birthday = {23, 6, 1912};
    
    TEST_ASSERT_TRUE(isLeapYear(&birthday));
}

void test_setters(void)
{
    date_t birthday = {23, 6, 1912};
    
    // Using setter methods to modify the Date object
    birthday.day = 24;
    birthday.month = 7;
    birthday.year = 1913;

    TEST_ASSERT_EQUAL(24, birthday.day);
    TEST_ASSERT_EQUAL(7, birthday.month);
    TEST_ASSERT_EQUAL(1913, birthday.year);
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_constructor);
    RUN_TEST(test_constructor_with_new);
    RUN_TEST(test_is_leap_year);
    RUN_TEST(test_setters);
	return UNITY_END();
}
