#include <unity.h>
#include <string.h>
#include <stdlib.h>

#include "book.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_constructor(void)
{
    book_t book = {"978-0131103627", "Brian W. Kernighan and Dennis Ritchie", "The C Programming Language"};

    TEST_ASSERT_EQUAL_STRING("978-0131103627", book.isbn);
    TEST_ASSERT_EQUAL_STRING("Brian W. Kernighan and Dennis Ritchie", book.author);
    TEST_ASSERT_EQUAL_STRING("The C Programming Language", book.title);
}


void test_constructor_with_new(void)
{
    book_t *book = book_new("978-0131103627", "Brian W. Kernighan and Dennis Ritchie", "The C Programming Language");

    TEST_ASSERT_EQUAL_STRING("978-0131103627", book->isbn);
    TEST_ASSERT_EQUAL_STRING("Brian W. Kernighan and Dennis Ritchie", book->author);
    TEST_ASSERT_EQUAL_STRING("The C Programming Language", book->title);

    book_delete(book);
}


void test_json(void)
{
    book_t book = {"978-0131103627", "Brian W. Kernighan and Dennis Ritchie", "The C Programming Language"};
    char *json = toJson(&book);
    printf("json: %s\n", json);

    char *expected = "{\"isbn\":\"978-0131103627\",\"author\":\"Brian W. Kernighan and Dennis Ritchie\",\"title\":\"The C Programming Language\"}";
    TEST_ASSERT_EQUAL_STRING(expected,json);
    free(json);
}


int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_constructor);
    RUN_TEST(test_constructor_with_new);
    RUN_TEST(test_json);
	return UNITY_END();
}
