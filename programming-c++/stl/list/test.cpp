#include <cstdio>
#include <cstdlib>
#include <list>
#include <algorithm>

#include <unity.h>

using namespace std;

void setUp(void)
{
}

void tearDown(void)
{
}

void test_list_length(void)
{
   list<int> numbers = {7, 5, 16, 8};
   size_t len = numbers.size();

   TEST_ASSERT_EQUAL(4, len);
}

void test_equals(void)
{
   list<int> numbers = {7, 5, 16, 8};

   list<int> expected = {7, 5, 16, 8};
   TEST_ASSERT_TRUE(expected == numbers);
}

void test_list_push_back(void)
{
   list<int> numbers = {7, 5, 16, 8};
   numbers.push_back(25);
   numbers.push_back(13);

   list<int> expected = {7, 5, 16, 8, 25, 13};
   TEST_ASSERT_EQUAL(6, numbers.size());
   TEST_ASSERT_TRUE(expected == numbers);
}

void test_list_push_front(void)
{
   list<int> numbers = {7, 5, 16, 8};
   numbers.push_front(25);
   numbers.push_front(13);

   list<int> expected = {13, 25, 7, 5, 16, 8};
   TEST_ASSERT_EQUAL(6, numbers.size());
   TEST_ASSERT_TRUE(expected == numbers);
}

void test_for_each(void)
{
   list<int> numbers = {7, 5, 16, 8};

   for(int n : numbers)
   {
      printf("%3d\n", n);
   }
}

void test_list_sort(void)
{
   list<int> numbers = {7, 5, 16, 8};

   // std::list does not support random access, which means we 
   // can't use std::sort to sort a std::list. 
   numbers.sort();

   list<int> expected = {5, 7, 8, 16};
   TEST_ASSERT_TRUE(expected == numbers);
}

// Comparator function to sort in descending order
bool compareDesc(int a, int b) 
{
    return a > b;
}

void test_list_sort_descending(void)
{
   list<int> numbers = {7, 5, 16, 8};

   numbers.sort(compareDesc);

   list<int> expected = {16, 8, 7, 5};
   TEST_ASSERT_TRUE(expected == numbers);
}


void test_list_find(void)
{
   list<int> numbers = {7, 5, 16, 8};

   list<int>::iterator it = find(numbers.begin(), numbers.end(), 16);
   TEST_ASSERT_TRUE(it != numbers.end());
   TEST_ASSERT_EQUAL(16, *it);

   it = find(numbers.begin(), numbers.end(), 99);
   TEST_ASSERT_TRUE(it == numbers.end());
}

// Note: std::list has no random-access iterators, so binary_search()
// cannot jump to the midpoint and falls back to O(n) linear stepping.
// It returns a correct result but without the O(log n) benefit.
void test_list_binary_search(void)
{
   list<int> numbers = {5, 7, 8, 16};   // must be sorted

   TEST_ASSERT_TRUE(binary_search(numbers.begin(), numbers.end(), 8));
   TEST_ASSERT_FALSE(binary_search(numbers.begin(), numbers.end(), 99));
}

int main(void)
{
	UNITY_BEGIN();
   RUN_TEST(test_list_length);
   RUN_TEST(test_equals);
   RUN_TEST(test_list_push_back);
   RUN_TEST(test_list_push_front);
   RUN_TEST(test_for_each);
   RUN_TEST(test_list_sort);
   RUN_TEST(test_list_sort_descending);
   RUN_TEST(test_list_find);
   RUN_TEST(test_list_binary_search);
   //...

	return UNITY_END();
}
