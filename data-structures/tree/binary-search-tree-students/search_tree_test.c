#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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



int comparator(const void *a, const void *b) 
{
    const student_t *student_a = a;
    const student_t *student_b = b;

    //printf("compare: %d %d = %d\n", student_a->id, student_b->id, student_a->id - student_b->id);
    return student_a->id - student_b->id;
}

comparator_t cmp = NULL; 

void setUp(void)
{
    cmp = comparator;
    root_ptr = tree_insert(root_ptr, student_new(100, "Homer", "Simpson"), cmp);
    root_ptr = tree_insert(root_ptr, student_new(500, "Marge", "Simpson"), cmp);
    root_ptr = tree_insert(root_ptr, student_new(20, "Bart", "Simpson"), cmp);
    root_ptr = tree_insert(root_ptr, student_new(10, "Lisa", "Simpson"), cmp);
    root_ptr = tree_insert(root_ptr, student_new(30, "Maggie", "Simpson"), cmp);
}

void tearDown(void)
{
    tree_delete(root_ptr);
    root_ptr = NULL;
}


void test_tree_search(void)
{
    student_t *student = student_new(20, "", "");
    node_t *n = tree_search(root_ptr, student, cmp);
    free(student);

    printf("Result: %d %s %s\n", n->value->id, n->value->first_name, n->value->last_name);
    TEST_ASSERT_EQUAL(20, n->value->id);
    TEST_ASSERT_EQUAL_STRING("Bart", n->value->first_name);
    TEST_ASSERT_EQUAL_STRING("Simpson", n->value->last_name);
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
