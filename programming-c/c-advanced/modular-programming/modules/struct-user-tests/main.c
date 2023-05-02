#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "user.h"

int main(void)
{
    // Create a User on the stack (local variable)
    user_t homer;
    homer.id = 3;
    homer.username = "homer";
    homer.password = "Drink4DuffBeers!";
    assert(homer.id == 3);
    assert(strcmp("homer", homer.username) == 0);
    assert(strcmp("Drink4DuffBeers!", homer.password) == 0);

    user_t bart = {5, "bart", "EatMyShorts!"};
    assert(bart.id == 5);
    assert(strcmp("bart", bart.username) == 0);
    assert(strcmp("EatMyShorts!", bart.password) == 0);


    // Create a User on the heap 
    user_t *marge = malloc(sizeof(user_t));
    marge->id = 7;              // (*marge).id = 7;
    marge->username = "marge";    
    marge->password = "LoveMy3Kids!";
    assert(marge->id == 7);     // assert((*marge).id == 7);    
    assert(strcmp("marge", marge->username) == 0);
    assert(strcmp("LoveMy3Kids!", marge->password) == 0);
    free(marge);

    return 0;
}
