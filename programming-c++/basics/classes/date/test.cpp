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
    Date birthday(23, 6, 1912); // Alan Turing's date of birth                        

    TEST_ASSERT_EQUAL(23, birthday.getDay());
    TEST_ASSERT_EQUAL(6, birthday.getMonth());
    TEST_ASSERT_EQUAL(1912, birthday.getYear());
}

void test_constructor_with_new(void)
{
    Date *birthday = new Date(23, 6, 1912); 

    TEST_ASSERT_EQUAL(23, birthday->getDay());
    TEST_ASSERT_EQUAL(6, birthday->getMonth());
    TEST_ASSERT_EQUAL(1912, birthday->getYear());

    delete birthday;
}

void test_is_leap_year(void)
{
    Date birthday(23, 6, 1912);
    
    TEST_ASSERT_TRUE(birthday.isLeapYear());
}

void test_setters(void)
{
    Date birthday(23, 6, 1912);
    
    // Using setter methods to modify the Date object
    birthday.setDay(24);
    birthday.setMonth(7);
    birthday.setYear(1913);

    TEST_ASSERT_EQUAL(24, birthday.getDay());
    TEST_ASSERT_EQUAL(7, birthday.getMonth());
    TEST_ASSERT_EQUAL(1913, birthday.getYear());
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
