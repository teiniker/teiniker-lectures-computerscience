#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unity.h>

#include <glib.h>


 GString *str = NULL;

void setUp(void)
{
    str = g_string_new("Hello");
}

void tearDown(void)
{
    g_string_free(str, TRUE); // TRUE means it also frees character data
    str = NULL;
}


void test_length(void)
{
    TEST_ASSERT_EQUAL(5, str->len);
}


void test_append(void)
{
    g_string_append(str, " Homer!");
    TEST_ASSERT_EQUAL_STRING("Hello Homer!", str->str);
}


void test_append_printf(void)
{
    g_string_append_printf(str, " %d!", 2024);
    TEST_ASSERT_EQUAL_STRING("Hello 2024!", str->str);
}


void test_printf(void)
{
    g_string_printf(str, "%03d 0x%02x", 27, 27);
    TEST_ASSERT_EQUAL_STRING("027 0x1b", str->str);
}

void test_insert(void)
{
    g_string_insert(str, 2, "___");
    TEST_ASSERT_EQUAL_STRING("He___llo", str->str);
}


void test_erase(void)
{
    g_string_erase(str, 2, 2);  // pos, len  
    TEST_ASSERT_EQUAL_STRING("Heo", str->str);
}


int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_length);
    RUN_TEST(test_append);
    RUN_TEST(test_append_printf);
    RUN_TEST(test_insert);
    RUN_TEST(test_erase);
    RUN_TEST(test_printf);

	return UNITY_END();
}
