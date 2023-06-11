#include <cstdio>
#include <cstdlib>
#include <queue>

#include <unity.h>


std::queue<int> numbers;

void setUp(void)
{
   numbers.push(1);
   numbers.push(2);
   numbers.push(3);
}

void tearDown(void)
{
   while(!numbers.empty())
   {
      numbers.pop();
   }
}

void test_size(void)
{
   size_t size = numbers.size();
   TEST_ASSERT_EQUAL(3, size);
}

void test_front_pop_empty(void)
{
   TEST_ASSERT_EQUAL(1, numbers.front());
   numbers.pop();
   TEST_ASSERT_EQUAL(2, numbers.front());
   numbers.pop();
   TEST_ASSERT_EQUAL(3, numbers.front());
   numbers.pop();
   TEST_ASSERT_TRUE(numbers.empty());
}

void test_front_and_back(void)
{
   int front = numbers.front();
   TEST_ASSERT_EQUAL(1, front);

   int back = numbers.back();
   TEST_ASSERT_EQUAL(3, back);
}


int main(void)
{
	UNITY_BEGIN();
   RUN_TEST(test_size);
   RUN_TEST(test_front_pop_empty);
   RUN_TEST(test_front_and_back);
   //...

	return UNITY_END();
}
