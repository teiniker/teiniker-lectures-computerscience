#include <cstdio>
#include <string>
#include <unordered_map>

#include <unity.h>

std::unordered_map<std::string, int> ageMap;

void setUp(void)
{
   ageMap["Homer"] = 38;
   ageMap["Marge"] = 36;
   ageMap["Bart"] = 10;
   ageMap["Lisa"] = 8;
   ageMap["Maggie"] = 1;
}

void tearDown(void)
{
   ageMap.clear();
}

void test_size(void)
{
   TEST_ASSERT_EQUAL(5, ageMap.size());
}

void test_accessing_values(void)
{   
   TEST_ASSERT_EQUAL(10, ageMap["Bart"]);
   TEST_ASSERT_EQUAL(8, ageMap["Lisa"]);
   TEST_ASSERT_EQUAL(1, ageMap["Maggie"]);
   TEST_ASSERT_EQUAL(38, ageMap["Homer"]);
   TEST_ASSERT_EQUAL(36, ageMap["Marge"]);
}


void test_iteration(void)
{
   // Note that the order of iteration is not guaranteed in unordered_map
   for (const auto& pair : ageMap) 
   {
      printf("%s : %d\n", pair.first.c_str(), pair.second);
   }
}

void test_bucket_count(void)
{
   // Check the number of buckets
   size_t bucketCount = ageMap.bucket_count();
   TEST_ASSERT_EQUAL(bucketCount, ageMap.bucket_count());

   for(size_t i = 0; i < bucketCount; ++i)
   {
      printf("Bucket %zu has %zu elements\n", i, ageMap.bucket_size(i));
   }
}

void test_hash_function(void)
{
   // The default hash function for a type like std::string is always the same
   // It's defined by the standard std::hash<T> specialization for that type.
   std::hash<std::string> hash_fn;
   size_t hash_val = hash_fn("Bart");
   size_t bucket_count = ageMap.bucket_count();
   size_t bucket_index = hash_val % bucket_count;
   printf("Hash of 'Bart': %zu\n", bucket_index);

   TEST_ASSERT_EQUAL(bucket_index, ageMap.bucket("Bart"));
}

void test_hash_function1(void)
{
   std::hash<std::string> hash_fn = ageMap.hash_function();
   size_t hash_val = hash_fn("Bart");
   size_t bucket_count = ageMap.bucket_count();
   size_t bucket_index = hash_val % bucket_count;
   printf("Hash of 'Bart': %zu\n", bucket_index);

   TEST_ASSERT_EQUAL(bucket_index, ageMap.bucket("Bart"));
}

int main(void)
{
	UNITY_BEGIN();
   RUN_TEST(test_size);
   RUN_TEST(test_accessing_values);
   RUN_TEST(test_iteration);
   RUN_TEST(test_bucket_count);
   RUN_TEST(test_hash_function);
   RUN_TEST(test_hash_function1);
   //...

	return UNITY_END();
}
