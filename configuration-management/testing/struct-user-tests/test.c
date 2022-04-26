#include <stdlib.h>
#include <assert.h>
#include <unity.h>

#include "user.h"

void setUp(void)
{
	// Setup
}

void tearDown(void)
{
	// tear down code
}


void test_user_create(void)
{
    // Setup
    user_t homer;

	// Exercise
    homer.id = 3;
    homer.username = "homer";
    homer.password = "Drink4DuffBeers!";

	// Verify
	TEST_ASSERT_EQUAL(3, homer.id);
    TEST_ASSERT_EQUAL_STRING("homer", homer.username);
    TEST_ASSERT_EQUAL_STRING("Drink4DuffBeers!", homer.password);
}

void test_user_init(void)
{
    // Setup & Exercise
    user_t bart = {5, "bart", "EatMyShorts!"};

	// Verify
	TEST_ASSERT_EQUAL(5, bart.id);
    TEST_ASSERT_EQUAL_STRING("bart", bart.username);
    TEST_ASSERT_EQUAL_STRING("EatMyShorts!", bart.password);
}

void test_user_create_heap(void)
{
    // Setup
    user_t *marge = malloc(sizeof(user_t));

	// Exercise
    marge->id = 7;  
    marge->username = "marge";    
    marge->password = "LoveMy3Kids!";

	// Verify
	TEST_ASSERT_EQUAL(7, marge->id);
    TEST_ASSERT_EQUAL_STRING("marge", marge->username);
    TEST_ASSERT_EQUAL_STRING("LoveMy3Kids!", marge->password);

    // Teardown
    free(marge);
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_user_create);
    RUN_TEST(test_user_init);
    RUN_TEST(test_user_create_heap);

	return UNITY_END();
}
