#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "usertable.h"

int main(void)
{
    // Create users on the heap 

    user_t *table = table_new(3);

    table_set_user(table, 0, 3, "homer", "Drink4DuffBeers!");
    table_set_user(table, 1, 5, "bart", "EatMyShorts!");
    table_set_user(table, 2, 7, "marge", "LoveMy3Kids!");

    // test_get_user_0()
    user_t homer = table_get_user(table, 0);
    assert(homer.id == 3);
    assert(strcmp("homer", homer.username) == 0);
    assert(strcmp("Drink4DuffBeers!", homer.password) == 0);

    // test_get_user_1()
    user_t bart = table_get_user(table, 1);
    assert(bart.id == 5);
    assert(strcmp("bart", bart.username) == 0);
    assert(strcmp("EatMyShorts!", bart.password) == 0);

    // test_get_user_2()
    user_t *marge = table+2 ;
    assert(marge->id == 7);      
    assert(strcmp("marge", marge->username) == 0);
    assert(strcmp("LoveMy3Kids!", marge->password) == 0);

    // test_set_user()
    table_set_user(table, 1, 13, "burns", "LosDieHunde!");
    assert(13 == table[1].id);
    assert(strcmp("burns", table[1].username) == 0);
    assert(strcmp("LosDieHunde!", table[1].password) == 0);
  
    table_delete(table);

    return 0;
}
