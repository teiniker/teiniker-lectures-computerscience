#include <cstdio>
#include <string>
#include <set>

#include <unity.h>

using namespace std;

set<string> names;

void setUp(void)
{
    names.insert("homer");
    names.insert("marge");
    names.insert("bart");
}

void tearDown(void)
{
    names.clear();
}

void test_size(void)
{
    TEST_ASSERT_EQUAL(3, names.size());
    TEST_ASSERT_FALSE(names.empty());
}

void test_empty(void)
{
    set<string> empty_set;
    TEST_ASSERT_TRUE(empty_set.empty());
    TEST_ASSERT_EQUAL(0, empty_set.size());
}

void test_insert(void)
{
    names.insert("lisa");
    TEST_ASSERT_EQUAL(4, names.size());
    TEST_ASSERT_EQUAL(1, names.count("lisa"));
}

void test_insert_duplicate(void)
{
    names.insert("homer");          // already present, ignored
    TEST_ASSERT_EQUAL(3, names.size());
}

void test_count(void)
{
    TEST_ASSERT_EQUAL(1, names.count("bart"));
    TEST_ASSERT_EQUAL(0, names.count("moe"));
}

void test_find(void)
{
    set<string>::iterator it = names.find("marge");
    TEST_ASSERT_TRUE(it != names.end());
    TEST_ASSERT_EQUAL_STRING("marge", it->c_str());
}

void test_find_not_found(void)
{
    set<string>::iterator it = names.find("moe");
    TEST_ASSERT_TRUE(it == names.end());
}

void test_erase(void)
{
    names.erase("marge");
    TEST_ASSERT_EQUAL(2, names.size());
    TEST_ASSERT_TRUE(names.find("marge") == names.end());
}

void test_sorted_order(void)
{
    // std::set keeps elements in ascending sorted order
    set<string>::iterator it = names.begin();
    TEST_ASSERT_EQUAL_STRING("bart",  it->c_str()); ++it;
    TEST_ASSERT_EQUAL_STRING("homer", it->c_str()); ++it;
    TEST_ASSERT_EQUAL_STRING("marge", it->c_str());
}

void test_iteration(void)
{
    for (set<string>::iterator it = names.begin(); it != names.end(); ++it)
    {
        printf("%s\n", it->c_str());
    }
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_size);
    RUN_TEST(test_empty);
    RUN_TEST(test_insert);
    RUN_TEST(test_insert_duplicate);
    RUN_TEST(test_count);
    RUN_TEST(test_find);
    RUN_TEST(test_find_not_found);
    RUN_TEST(test_erase);
    RUN_TEST(test_sorted_order);
    RUN_TEST(test_iteration);

    return UNITY_END();
}
