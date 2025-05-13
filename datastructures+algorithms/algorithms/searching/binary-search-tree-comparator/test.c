#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unity.h>

#include "search_tree.h"

node_t *tree = NULL;
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
    cmp = comparator_1;
    tree = tree_insert(tree, 100, cmp);
    tree = tree_insert(tree, 500, cmp);
    tree = tree_insert(tree, 20, cmp);
    tree = tree_insert(tree, 10, cmp);
    tree = tree_insert(tree, 30, cmp);
}

void tearDown(void)
{
    tree_delete(tree);
    tree = NULL;
}


void test_tree_search(void)
{
    node_t *n = tree_search(tree, 30, cmp);

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
