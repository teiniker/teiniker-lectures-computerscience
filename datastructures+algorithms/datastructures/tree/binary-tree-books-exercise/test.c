#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unity.h>

#include "binary_tree.h"

node_t *root_ptr = NULL;
/*
                13
              /    \
            7        23
          /  \      /   \
        3     11   17    29     
*/


void setUp(void)
{
    root_ptr = node_new(13);
    tree_insert_left(root_ptr, 7);
    tree_insert_right(root_ptr, 23);

    tree_insert_left(root_ptr->left_ptr, 3);
    tree_insert_right(root_ptr->left_ptr, 11);

    tree_insert_left(root_ptr->right_ptr, 17);
    tree_insert_right(root_ptr->right_ptr, 29);

}

void tearDown(void)
{
    node_delete(root_ptr->left_ptr->left_ptr);
    node_delete(root_ptr->left_ptr->right_ptr);
    node_delete(root_ptr->left_ptr);

    node_delete(root_ptr->right_ptr->left_ptr);
    node_delete(root_ptr->right_ptr->right_ptr);
    node_delete(root_ptr->right_ptr);

    node_delete(root_ptr);
    root_ptr = NULL;
}


void test_traversal_preorder(void)
{
    printf("Pre-Order: ");
    tree_traversal_preorder(root_ptr);
    printf("\n");
}

void test_traversal_inorder(void)
{
    printf("In-Order: ");
    tree_traversal_inorder(root_ptr);
    printf("\n");
}

void test_traversal_postorder(void)
{
    printf("Post-Order: ");
    tree_traversal_postorder(root_ptr);
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
