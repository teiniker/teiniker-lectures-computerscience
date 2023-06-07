#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unity.h>

#include "search_tree.h"

node_t *tree = NULL;
/*
                100
              /    \
            20     500
           /  \      
         10    30        
*/

void setUp(void)
{
    tree = tree_insert(tree, 100);
    tree = tree_insert(tree, 500);
    tree = tree_insert(tree, 20);
    tree = tree_insert(tree, 10);
    tree = tree_insert(tree, 30);
}

void tearDown(void)
{
    tree_delete(tree);
    tree = NULL;
}


void test_tree_search(void)
{
    node_t *n = tree_search(tree, 30);

    printf("Result: %d\n", n->value);
    TEST_ASSERT_EQUAL(30, n->value);
}

void test_tree_print(void)
{
    printf("In-Order: ");
    tree_print(tree);
    printf("\n");
}


int main(void)
{
	UNITY_BEGIN();
    RUN_TEST(test_tree_print);
    RUN_TEST(test_tree_search);
	return UNITY_END();
}
