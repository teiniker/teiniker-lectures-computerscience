#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unity.h>

#include <glib.h>

void list_print(GList *list)
{
    for (GList *l = list; l != NULL; l = l->next) 
    {
        printf("%s\n", (char *)l->data);
    }
}

GList *list = NULL;

void setUp(void)
{
    list = g_list_append(list, "one");
    list = g_list_prepend(list, "two");
    list = g_list_append(list, "three");
}

void tearDown(void)
{
    g_list_free(list);
    list = NULL;
}


void test_size(void)
{
    size_t size = g_list_length(list);
    TEST_ASSERT_EQUAL(3, size);
}


void test_get(void) 
{
    list_print(list);

    TEST_ASSERT_EQUAL_STRING("two", g_list_nth_data(list, 0));
    TEST_ASSERT_EQUAL_STRING("one", g_list_nth_data(list, 1));
    TEST_ASSERT_EQUAL_STRING("three", g_list_nth_data(list, 2));
}

void test_find(void) 
{
    list_print(list);
    TEST_ASSERT_EQUAL(2, g_list_index(list, "three"));
}

void test_insert_first(void)
{
    list = g_list_insert(list, "five", 0);

    TEST_ASSERT_EQUAL_STRING("five", g_list_nth_data(list, 0));
    TEST_ASSERT_EQUAL("two", g_list_nth_data(list, 1));
    TEST_ASSERT_EQUAL("one", g_list_nth_data(list, 2));
    TEST_ASSERT_EQUAL("three", g_list_nth_data(list, 3));
}

void test_insert(void)
{
    list = g_list_insert(list, "seven", 2);

    TEST_ASSERT_EQUAL_STRING("two", g_list_nth_data(list, 0));
    TEST_ASSERT_EQUAL_STRING("one", g_list_nth_data(list, 1));
    TEST_ASSERT_EQUAL_STRING("seven", g_list_nth_data(list,2));
    TEST_ASSERT_EQUAL_STRING("three", g_list_nth_data(list, 3));
}

void test_remove(void)
{
    list = g_list_remove(list, "one");

    TEST_ASSERT_EQUAL_STRING("two", g_list_nth_data(list, 0));
    TEST_ASSERT_EQUAL_STRING("three", g_list_nth_data(list, 1));
}


int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_size);
	RUN_TEST(test_get);
    RUN_TEST(test_find);
	RUN_TEST(test_insert_first);
	RUN_TEST(test_insert);
	RUN_TEST(test_remove);

	return UNITY_END();
}
