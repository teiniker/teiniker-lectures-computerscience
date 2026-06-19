#include <cstdio>
#include <cstdlib>
#include <deque>
#include <algorithm>

#include <unity.h>

using namespace std;

void setUp(void)
{
}

void tearDown(void)
{
}

void test_deque_size(void)
{
    deque<int> numbers = {7, 5, 16, 8};

    TEST_ASSERT_EQUAL(4, numbers.size());
    TEST_ASSERT_FALSE(numbers.empty());
}

void test_deque_index_operator(void)
{
    deque<int> numbers = {7, 5, 16, 8};

    TEST_ASSERT_EQUAL(7,  numbers[0]);
    TEST_ASSERT_EQUAL(5,  numbers[1]);
    TEST_ASSERT_EQUAL(16, numbers[2]);
    TEST_ASSERT_EQUAL(8,  numbers[3]);
}

void test_deque_front_back(void)
{
    deque<int> numbers = {7, 5, 16, 8};

    TEST_ASSERT_EQUAL(7, numbers.front());
    TEST_ASSERT_EQUAL(8, numbers.back());
}

void test_deque_push_back(void)
{
    deque<int> numbers = {7, 5, 16, 8};
    numbers.push_back(25);

    TEST_ASSERT_EQUAL(5,  numbers.size());
    TEST_ASSERT_EQUAL(25, numbers.back());
}

void test_deque_push_front(void)
{
    deque<int> numbers = {7, 5, 16, 8};
    numbers.push_front(99);

    TEST_ASSERT_EQUAL(5,  numbers.size());
    TEST_ASSERT_EQUAL(99, numbers.front());
    TEST_ASSERT_EQUAL(7,  numbers[1]);
}

void test_deque_pop_back(void)
{
    deque<int> numbers = {7, 5, 16, 8};
    numbers.pop_back();

    TEST_ASSERT_EQUAL(3, numbers.size());
    TEST_ASSERT_EQUAL(16, numbers.back());
}

void test_deque_pop_front(void)
{
    deque<int> numbers = {7, 5, 16, 8};
    numbers.pop_front();

    TEST_ASSERT_EQUAL(3, numbers.size());
    TEST_ASSERT_EQUAL(5, numbers.front());
}

void test_deque_equals(void)
{
    deque<int> numbers  = {7, 5, 16, 8};
    deque<int> expected = {7, 5, 16, 8};

    TEST_ASSERT_TRUE(expected == numbers);
}

void test_deque_for_each(void)
{
    deque<int> numbers = {7, 5, 16, 8};

    for (int n : numbers)
    {
        printf("%3d\n", n);
    }
}

void test_deque_sort(void)
{
    deque<int> numbers = {7, 5, 16, 8};

    sort(numbers.begin(), numbers.end());

    deque<int> expected = {5, 7, 8, 16};
    TEST_ASSERT_TRUE(expected == numbers);
}

void test_deque_find(void)
{
    deque<int> numbers = {7, 5, 16, 8};

    deque<int>::iterator it = find(numbers.begin(), numbers.end(), 16);
    TEST_ASSERT_TRUE(it != numbers.end());
    TEST_ASSERT_EQUAL(16, *it);

    it = find(numbers.begin(), numbers.end(), 99);
    TEST_ASSERT_TRUE(it == numbers.end());
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_deque_size);
    RUN_TEST(test_deque_index_operator);
    RUN_TEST(test_deque_front_back);
    RUN_TEST(test_deque_push_back);
    RUN_TEST(test_deque_push_front);
    RUN_TEST(test_deque_pop_back);
    RUN_TEST(test_deque_pop_front);
    RUN_TEST(test_deque_equals);
    RUN_TEST(test_deque_for_each);
    RUN_TEST(test_deque_sort);
    RUN_TEST(test_deque_find);

    return UNITY_END();
}
