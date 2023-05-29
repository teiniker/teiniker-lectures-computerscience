#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>

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
   vector<int> v = {7, 5, 16, 8};
   size_t len = v.size();

   TEST_ASSERT_EQUAL(4, len);
}

void test_index_operator(void)
{
   vector<int> v = {7, 5, 16, 8};

   TEST_ASSERT_EQUAL(7, v[0]);
   TEST_ASSERT_EQUAL(5, v[1]);
   TEST_ASSERT_EQUAL(16, v[2]);
   TEST_ASSERT_EQUAL(8, v[3]);
}

void test_vector_push_back(void)
{
   vector<int> v = {7, 5, 16, 8};
   v.push_back(25);
   v.push_back(13);

   TEST_ASSERT_EQUAL(6, v.size());
   TEST_ASSERT_EQUAL(25, v[4]);
   TEST_ASSERT_EQUAL(13, v[5]);
}

void test_vector_for_each(void)
{
   vector<int> v = {7, 5, 16, 8};

   for(int n : v)
   {
      printf("%3d\n", n);
   }
}


int main(void)
{
	UNITY_BEGIN();
   RUN_TEST(test_vector_length);
   RUN_TEST(test_index_operator);
   RUN_TEST(test_vector_push_back);
   RUN_TEST(test_vector_for_each);
   //...

	return UNITY_END();
}
