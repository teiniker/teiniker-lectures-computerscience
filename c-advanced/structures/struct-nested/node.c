#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node
{
    int value;  
    struct node *next_ptr;  
} node_t;

node_t *node_new(const int value)
{
    node_t *ptr = malloc(sizeof(node_t));
    ptr->value = value;
    ptr->next_ptr = NULL;
    return ptr;
}


int main(void)
{
    // -->[3]-->[7]-->[9]-->[NULL]
    node_t *first_ptr = node_new(3);
    first_ptr->next_ptr = node_new(7);
    first_ptr->next_ptr->next_ptr = node_new(9);

    node_t *ptr = first_ptr;
    while(ptr != NULL)
    {
        printf("%d\n", ptr->value);
        ptr = ptr->next_ptr;
    }

    free(first_ptr->next_ptr->next_ptr);
    free(first_ptr->next_ptr);
    free(first_ptr);
    return 0;
}
