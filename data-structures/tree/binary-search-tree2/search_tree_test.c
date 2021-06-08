#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unity.h>

#include "search_tree.h"

node_t *root_ptr = NULL;
/*
                100
              /    \
            20        500
          /  \      
        10     30        
*/



int comparator_1(const void * a, const void * b) 
{
    const int *integer_a = (const int *)a;
    const int *integer_b = (const int *)b;

    return (*integer_a - *integer_b);
}

int comparator_2(const void * a, const void * b) 
{
    const int *integer_a = (const int *)a;
    const int *integer_b = (const int *)b;

   return (*integer_b - *integer_a);
}

comparator_t cmp = NULL; 

void setUp(void)
{
    cmp = comparator_2;
    root_ptr = tree_insert(root_ptr, 100, cmp);
    root_ptr = tree_insert(root_ptr, 500, cmp);
    root_ptr = tree_insert(root_ptr, 20, cmp);
    root_ptr = tree_insert(root_ptr, 10, cmp);
    root_ptr = tree_insert(root_ptr, 30, cmp);
}

void tearDown(void)
{
    tree_delete(root_ptr);
    root_ptr = NULL;
}


void test_tree_search(void)
{
    node_t *n = tree_search(root_ptr, 30, cmp);

    printf("Result: %d\n", n->value);
    TEST_ASSERT_EQUAL(30, n->value);
}

void test_tree_print(void)
{
    printf("In-Order: ");
    tree_print(root_ptr);
    printf("\n");
}


int main(void)
{
	UNITY_BEGIN();
    RUN_TEST(test_tree_print);
    RUN_TEST(test_tree_search);
	return UNITY_END();
}
