#include <stdlib.h>
#include <unity.h>

#include "usertable.h"

user_t *table = NULL;

void setUp(void)
{
	table = table_new(3);
    table_set_user(table, 0, 3, "homer", "Drink4DuffBeers!");
    table_set_user(table, 1, 5, "bart", "EatMyShorts!");
    table_set_user(table, 2, 7, "marge", "LoveMy3Kids!");
}

void tearDown(void)
{
    table_delete(table);
}

void test_get_user_0(void)
{
	// Exercise
    user_t homer = table_get_user(table, 0);

	// Verify
	TEST_ASSERT_EQUAL(3, homer.id);
    TEST_ASSERT_EQUAL_STRING("homer", homer.username);
    TEST_ASSERT_EQUAL_STRING("Drink4DuffBeers!", homer.password);
}

void test_get_user_1(void)
{
	// Exercise
    user_t bart = table_get_user(table, 1);

	// Verify
	TEST_ASSERT_EQUAL(5, bart.id);
    TEST_ASSERT_EQUAL_STRING("bart", bart.username);
    TEST_ASSERT_EQUAL_STRING("EatMyShorts!", bart.password);
}

void test_get_user_2(void)
{
	// Exercise
    user_t *marge = table+2 ;

	// Verify
	TEST_ASSERT_EQUAL(7, marge->id);
    TEST_ASSERT_EQUAL_STRING("marge", marge->username);
    TEST_ASSERT_EQUAL_STRING("LoveMy3Kids!", marge->password);
}

void test_set_user(void)
{
	// Exercise
    table_set_user(table, 1, 13, "burns", "LosDieHunde!");

	// Verify
	TEST_ASSERT_EQUAL(13, table[1].id);
    TEST_ASSERT_EQUAL_STRING("burns", table[1].username);
    TEST_ASSERT_EQUAL_STRING("LosDieHunde!", table[1].password);
}


int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_get_user_0);
    RUN_TEST(test_get_user_1);
    RUN_TEST(test_get_user_2);
    RUN_TEST(test_set_user);

	return UNITY_END();
}
