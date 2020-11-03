#include <stdio.h>
#include <stdbool.h> 

int main(void)
{
    // initial values
    //int yyyy = 1900;    // false
    int yyyy = 1999;    // false
    //int yyyy = 2000;    // true
    //int yyyy = 2020;    // true

    bool is_leap_year = false;

    // TODO

    printf("%4d : is_leap_year = %s\n", yyyy, is_leap_year ? "true" : "false");
    
    return 0;
}
