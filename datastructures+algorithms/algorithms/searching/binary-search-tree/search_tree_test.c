#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unity.h>

#include "search_tree.h"

node_t *root_ptr = NULL;
/*
                100
              /    \
            20     500
           /  \      
         10    30        
*/

void setUp(void)
{
    root_ptr = tree_insert(root_ptr, 100);
    root_ptr = tree_insert(root_ptr, 500);
    root_ptr = tree_insert(root_ptr, 20);
    root_ptr = tree_insert(root_ptr, 10);
    root_ptr = tree_insert(root_ptr, 30);
}

void tearDown(void)
{
    tree_delete(root_ptr);
    root_ptr = NULL;
}


void test_tree_search(void)
{
    node_t *n = tree_search(root_ptr, 30);

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
