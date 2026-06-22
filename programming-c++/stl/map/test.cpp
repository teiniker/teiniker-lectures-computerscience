#include <cstdio>
#include <string>
#include <map>

#include <unity.h>

using namespace std;

map<string, int> scores;

void setUp(void)
{
    scores["homer"] = 90;
    scores["marge"] = 85;
    scores["bart"] = 92;
}

void tearDown(void)
{
    scores.clear();
}

void test_size(void)
{
    TEST_ASSERT_EQUAL(3, scores.size());
    TEST_ASSERT_FALSE(scores.empty());
}

void test_access_operator(void)
{
    TEST_ASSERT_EQUAL(90, scores["homer"]);
    TEST_ASSERT_EQUAL(85, scores["marge"]);
    TEST_ASSERT_EQUAL(92, scores["bart"]);
}

void test_access_at(void)
{
    TEST_ASSERT_EQUAL(90, scores.at("homer"));
    TEST_ASSERT_EQUAL(85, scores.at("marge"));
    TEST_ASSERT_EQUAL(92, scores.at("bart"));
}

void test_update_value(void)
{
    scores["homer"] = 95;
    TEST_ASSERT_EQUAL(95, scores["homer"]);
    TEST_ASSERT_EQUAL(3, scores.size());   // no new entry added
}

void test_insert_new_key(void)
{
    scores["lisa"] = 88;
    TEST_ASSERT_EQUAL(4, scores.size());
    TEST_ASSERT_EQUAL(88, scores["lisa"]);
}

void test_empty(void)
{
    map<string, int> empty_map;
    TEST_ASSERT_TRUE(empty_map.empty());
    TEST_ASSERT_EQUAL(0, empty_map.size());
}

void test_find(void)
{
    map<string, int>::iterator it = scores.find("marge");
    TEST_ASSERT_TRUE(it != scores.end());
    TEST_ASSERT_EQUAL(85, it->second);
}

void test_find_not_found(void)
{
    map<string, int>::iterator it = scores.find("moe");
    TEST_ASSERT_TRUE(it == scores.end());
}

void test_erase(void)
{
    scores.erase("marge");
    TEST_ASSERT_EQUAL(2, scores.size());
    TEST_ASSERT_TRUE(scores.find("marge") == scores.end());
}

void test_sorted_keys(void)
{
    // std::map keeps keys in ascending sorted order
    map<string, int>::iterator it = scores.begin();
    TEST_ASSERT_TRUE("bart" == it->first); ++it;
    TEST_ASSERT_TRUE("homer" == it->first); ++it;
    TEST_ASSERT_TRUE("marge" == it->first);
}

void test_iteration(void)
{
    for (map<string, int>::iterator it = scores.begin(); it != scores.end(); ++it)
    {
        printf("%-10s %d\n", it->first.c_str(), it->second);
    }
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_size);
    RUN_TEST(test_access_operator);
    RUN_TEST(test_access_at);
    RUN_TEST(test_update_value);
    RUN_TEST(test_insert_new_key);
    RUN_TEST(test_empty);
    RUN_TEST(test_find);
    RUN_TEST(test_find_not_found);
    RUN_TEST(test_erase);
    RUN_TEST(test_sorted_keys);
    RUN_TEST(test_iteration);

    return UNITY_END();
}
