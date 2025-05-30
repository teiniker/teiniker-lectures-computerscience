#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unity.h>

#include "binary_tree.h"

node_t *tree = NULL;
/*
                13
              /    \
            7        23
          /  \      /   \
        3     11   17    29     
*/

void setUp(void)
{
    tree = tree_insert(tree, 13);
    tree = tree_insert(tree, 7);
    tree = tree_insert(tree, 23);
    tree = tree_insert(tree, 3);
    tree = tree_insert(tree, 11);
    tree = tree_insert(tree, 17);
    tree = tree_insert(tree, 29);
}

void tearDown(void)
{
    tree_delete(tree);
    tree = NULL;
}


void test_traversal_preorder(void)
{
    printf("Pre-Order: ");
    tree_traversal_preorder(tree);
    printf("\n");
}

void test_traversal_inorder(void)
{
    printf("In-Order: ");
    tree_traversal_inorder(tree);
    printf("\n");
}

void test_traversal_postorder(void)
{
    printf("Post-Order: ");
    tree_traversal_postorder(tree);
    printf("\n");
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_traversal_preorder);
    RUN_TEST(test_traversal_inorder);
    RUN_TEST(test_traversal_postorder);
	return UNITY_END();
}
