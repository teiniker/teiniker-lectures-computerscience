#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unity.h>

#include "binary_tree.h"

node_t *tree = NULL;
/*
               book1
              /    \
           book2   book3
          /  \    
       book4 book5        
*/

book_t book1 = {"978-0393979503", "K. N. King", "C Programming: A Modern Approach"};
book_t book2 = {"978-0131103627","Brian W. Kernighan, Dennis Ritchie","The C Programming Language"};
book_t book3 = {"978-1718501041","Robert C. Seacord","Effective C: An Introduction to Professional C Programming"};
book_t book4 = {"978-1593278885","Josh Lospinoso","C++ Crash Course: A Fast-Paced Introduction"};
book_t book5 = {"978-0275967819", "Stroustrup Bjarne","Programming: Principles and Practice Using C++"};

void setUp(void)
{
    tree = node_new(&book1);
    tree_insert_left(tree, &book2);
    tree_insert_right(tree, &book3);

    tree_insert_left(tree->left_ptr, &book4);
    tree_insert_right(tree->left_ptr, &book5);
}

void tearDown(void)
{
    node_delete(tree->left_ptr->left_ptr);
    node_delete(tree->left_ptr->right_ptr);
    node_delete(tree->left_ptr);

    node_delete(tree->right_ptr);
    node_delete(tree);
    tree = NULL;
}


void test_traversal_preorder(void)
{
    printf("Pre-Order:\n");
    tree_traversal_preorder(tree);
    printf("\n");
}

void test_traversal_inorder(void)
{
    printf("In-Order:\n");
    tree_traversal_inorder(tree);
    printf("\n");
}

void test_traversal_postorder(void)
{
    printf("Post-Order:\n");
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
