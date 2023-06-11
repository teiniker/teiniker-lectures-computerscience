#include <cstdio>
#include <cstdlib>
#include <stack>
#include <algorithm>

#include <unity.h>

using namespace std;

stack<int> numbers;

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

void test_stack_size(void)
{
   size_t size = numbers.size();
   TEST_ASSERT_EQUAL(3, size);
}

// Note that pop() does not return the top value
void test_stack_pop(void)
{
   TEST_ASSERT_EQUAL(3, numbers.top());
   numbers.pop();
   TEST_ASSERT_EQUAL(2, numbers.top());
   numbers.pop();
   TEST_ASSERT_EQUAL(1, numbers.top());
   numbers.pop();
   TEST_ASSERT_TRUE(numbers.empty());
}

void test_stack_top(void)
{
   int top = numbers.top();
   TEST_ASSERT_EQUAL(3, top);
   size_t size = numbers.size();
   TEST_ASSERT_EQUAL(3, size);
}


int main(void)
{
	UNITY_BEGIN();
   RUN_TEST(test_stack_size);
   RUN_TEST(test_stack_pop);
   RUN_TEST(test_stack_top);
   //...

	return UNITY_END();
}
