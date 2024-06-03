#include <unity.h>

#include "book.h"

using namespace std;

void setUp(void)
{
}

void tearDown(void)
{
}

void test_constructor(void)
{
    Book book("978-0131103627", "Brian W. Kernighan and Dennis Ritchie", "The C Programming Language");                         

    TEST_ASSERT_EQUAL_STRING("978-0131103627", book.getIsbn().c_str());
    TEST_ASSERT_TRUE("Brian W. Kernighan and Dennis Ritchie" == book.getAuthor());
    TEST_ASSERT_TRUE("The C Programming Language" == book.getTitle());
}


void test_constructor_with_new(void)
{
    Book *book = new Book("978-0131103627", "Brian W. Kernighan and Dennis Ritchie", "The C Programming Language");                         

    TEST_ASSERT_TRUE("978-0131103627" == book->getIsbn());
    TEST_ASSERT_TRUE("Brian W. Kernighan and Dennis Ritchie" == book->getAuthor());
    TEST_ASSERT_TRUE("The C Programming Language" == book->getTitle());

    delete book;
}


void test_json(void)
{
    Book book("978-0131103627", "Brian W. Kernighan and Dennis Ritchie", "The C Programming Language");                         
    string json = book.toJson();
    printf("json: %s\n", json.c_str());

    string expected = "{\"isbn\":\"978-0131103627\",\"author\":\"Brian W. Kernighan and Dennis Ritchie\",\"title\":\"The C Programming Language\"}";
    TEST_ASSERT_TRUE(expected == json);
}


int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_constructor);
    RUN_TEST(test_constructor_with_new);
    RUN_TEST(test_json);
	return UNITY_END();
}
