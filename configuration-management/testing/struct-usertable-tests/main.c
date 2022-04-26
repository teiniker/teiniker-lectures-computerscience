#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "usertable.h"

int main(void)
{
    // Create users on the heap 

    user_t *table = table_new(3);

    table_set_user(table, 0, 3, "homer", "Drink4DuffBeers!");
    table_set_user(table, 1, 5, "bart", "EatMyShorts!");
    table_set_user(table, 2, 7, "marge", "LoveMy3Kids!");

    // Read users from the heap
    user_t homer = table_get_user(table, 0);
    assert(homer.id == 3);
    assert(strcmp("homer", homer.username) == 0);
    assert(strcmp("Drink4DuffBeers!", homer.password) == 0);

    // Note that table_get_user() returns a copy of the structure!
    homer.password = "1234567";
    assert(strcmp("1234567", homer.password) == 0);   
    assert(strcmp("Drink4DuffBeers!", table[0].password) == 0);


    user_t bart = table_get_user(table, 1);
    assert(bart.id == 5);
    assert(strcmp("bart", bart.username) == 0);
    assert(strcmp("EatMyShorts!", bart.password) == 0);

    user_t *marge = table+2 ;
    assert(marge->id == 7);      
    assert(strcmp("marge", marge->username) == 0);
    assert(strcmp("LoveMy3Kids!", marge->password) == 0);
  
    table_delete(table);

    return 0;
}

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
    (table+index)->username = username;
    (table+index)->password = password;
}
