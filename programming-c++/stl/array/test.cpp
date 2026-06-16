#include <cstdio>
#include <string>
#include <array>
#include <algorithm>

#include <unity.h>

std::array<int, 5> array;

void setUp(void)
{
   array = {10, 20, 30, 40, 50};
}

void tearDown(void)
{
   // Nothing to do here
}

void test_size(void)
{
   TEST_ASSERT_EQUAL(5, array.size());
}

void test_accessing_values(void)
{   
   TEST_ASSERT_EQUAL(10, array[0]);
   TEST_ASSERT_EQUAL(20, array[1]);
   TEST_ASSERT_EQUAL(30, array[2]);
   TEST_ASSERT_EQUAL(40, array[3]);
   TEST_ASSERT_EQUAL(50, array[4]);
}

void test_accessing_values_at(void)
{
   TEST_ASSERT_EQUAL(10, array.at(0));
   TEST_ASSERT_EQUAL(20, array.at(1));
   TEST_ASSERT_EQUAL(30, array.at(2));
   TEST_ASSERT_EQUAL(40, array.at(3));
   TEST_ASSERT_EQUAL(50, array.at(4));
}

void test_change_value(void)
{
   array[2] = 100;
   TEST_ASSERT_EQUAL(100, array[2]);
}

void test_change_value_at(void)
{
   array.at(2) = 200;
   TEST_ASSERT_EQUAL(200, array.at(2));
}

void test_fill(void)
{
   std::array<int, 5> filled_array;
   filled_array.fill(99);
   TEST_ASSERT_EQUAL(99, filled_array[0]);
   TEST_ASSERT_EQUAL(99, filled_array[1]);
   TEST_ASSERT_EQUAL(99, filled_array[2]);
   TEST_ASSERT_EQUAL(99, filled_array[3]);
   TEST_ASSERT_EQUAL(99, filled_array[4]);
}

void test_iteration(void)
{
   for (int element : array) 
   {
      printf("%d ", element);
   }
   putchar('\n');
}

void test_first_element(void)
{
   TEST_ASSERT_EQUAL(10, array.front());
}

void test_last_element(void)
{
   TEST_ASSERT_EQUAL(50, array.back());
}

void test_empty(void)
{
   std::array<int, 0> empty_array;
   TEST_ASSERT_TRUE(empty_array.empty());
}

void test_equal(void)
{
   std::array<int, 5> expected = {10, 20, 30, 40, 50};
   TEST_ASSERT_TRUE(expected == array);
}

void test_not_equal(void)
{
   std::array<int, 5> expected = {10, 20, 30, 0, 50};
   TEST_ASSERT_TRUE(expected != array);
}


void test_find(void)
{
   std::array<int, 5>::iterator it = std::find(array.begin(), array.end(), 30);
   TEST_ASSERT_TRUE(it != array.end());
   TEST_ASSERT_EQUAL(30, *it);

   it = std::find(array.begin(), array.end(), 99);
   TEST_ASSERT_TRUE(it == array.end());
}

void test_binary_search(void)
{
   // array == {10, 20, 30, 40, 50} -- already sorted
   TEST_ASSERT_TRUE(std::binary_search(array.begin(), array.end(), 40));
   TEST_ASSERT_FALSE(std::binary_search(array.begin(), array.end(), 99));
}

void test_sort(void)
{
   std::array<int, 5> unsorted = {30, 10, 50, 20, 40};
   std::sort(unsorted.begin(), unsorted.end());
   TEST_ASSERT_EQUAL(10, unsorted[0]);
   TEST_ASSERT_EQUAL(20, unsorted[1]);
   TEST_ASSERT_EQUAL(30, unsorted[2]);
   TEST_ASSERT_EQUAL(40, unsorted[3]);
   TEST_ASSERT_EQUAL(50, unsorted[4]);
}


int main(void)
{
	UNITY_BEGIN();
   RUN_TEST(test_size);
   RUN_TEST(test_accessing_values);
   RUN_TEST(test_accessing_values_at);
   RUN_TEST(test_change_value);
   RUN_TEST(test_change_value_at);
   RUN_TEST(test_fill);
   RUN_TEST(test_first_element);
   RUN_TEST(test_last_element);
   RUN_TEST(test_empty);
   RUN_TEST(test_iteration);
   RUN_TEST(test_equal);
   RUN_TEST(test_not_equal);
   RUN_TEST(test_find);
   RUN_TEST(test_binary_search);
   RUN_TEST(test_sort);
   //...

	return UNITY_END();
}
