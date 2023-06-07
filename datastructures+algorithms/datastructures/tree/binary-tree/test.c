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
    tree = node_new(13);
    tree_insert_left(tree, 7);
    tree_insert_right(tree, 23);

    tree_insert_left(tree->left_ptr, 3);
    tree_insert_right(tree->left_ptr, 11);

    tree_insert_left(tree->right_ptr, 17);
    tree_insert_right(tree->right_ptr, 29);

}

void tearDown(void)
{
    free(tree->left_ptr->left_ptr);
    free(tree->left_ptr->right_ptr);
    free(tree->left_ptr);

    free(tree->right_ptr->left_ptr);
    free(tree->right_ptr->right_ptr);
    free(tree->right_ptr);

    free(tree);
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
