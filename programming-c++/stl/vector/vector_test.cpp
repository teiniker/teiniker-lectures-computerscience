#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

#include <unity.h>

using namespace std;

void setUp(void)
{
}

void tearDown(void)
{
}

void test_vector_length(void)
{
   vector<int> numbers = {7, 5, 16, 8};
   size_t len = numbers.size();

   TEST_ASSERT_EQUAL(4, len);
}

void test_index_operator(void)
{
   vector<int> numbers = {7, 5, 16, 8};

   TEST_ASSERT_EQUAL(7, numbers[0]);
   TEST_ASSERT_EQUAL(5, numbers[1]);
   TEST_ASSERT_EQUAL(16, numbers[2]);
   TEST_ASSERT_EQUAL(8, numbers[3]);
}

void test_equals(void)
{
   vector<int> numbers = {7, 5, 16, 8};

   vector<int> expected = {7, 5, 16, 8};
   TEST_ASSERT_TRUE(expected == numbers);
}

void test_vector_push_back(void)
{
   vector<int> numbers = {7, 5, 16, 8};
   numbers.push_back(25);
   numbers.push_back(13);

   TEST_ASSERT_EQUAL(6, numbers.size());
   TEST_ASSERT_EQUAL(25, numbers[4]);
   TEST_ASSERT_EQUAL(13, numbers[5]);
}

void test_vector_for_each(void)
{
   vector<int> numbers = {7, 5, 16, 8};

   for(int n : numbers)
   {
      printf("%3d\n", n);
   }
}

void test_vector_sort(void)
{
   vector<int> numbers = {7, 5, 16, 8};

   sort(numbers.begin(), numbers.end());

   vector<int> expected = {5, 7, 8, 16};
   TEST_ASSERT_TRUE(expected == numbers);
}


int main(void)
{
	UNITY_BEGIN();
   RUN_TEST(test_vector_length);
   RUN_TEST(test_index_operator);
   RUN_TEST(test_equals);
   RUN_TEST(test_vector_push_back);
   RUN_TEST(test_vector_for_each);
   RUN_TEST(test_vector_sort);
   //...

	return UNITY_END();
}
