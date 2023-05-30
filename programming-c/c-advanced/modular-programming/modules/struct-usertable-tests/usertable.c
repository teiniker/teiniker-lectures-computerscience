#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "usertable.h"

user_t *table_new(size_t number_of_elements)
{
    return malloc(number_of_elements * sizeof(user_t));
}

void table_delete(user_t * table)
{
    free(table);
}

user_t table_get_user(user_t *table, int index)
{
    return table[index];
}

void table_set_user(user_t *table, int index, int id, char* username, char* password)
{
    table[index].id = id;
    table[index].username = username;
    table[index].password = password;
}
