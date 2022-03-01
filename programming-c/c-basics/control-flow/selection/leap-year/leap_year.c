#include <stdio.h>
#include <stdbool.h> 

int main(void)
{
    // initial values
    //int yyyy = 1900;    // false
    //int yyyy = 1999;    // false
    //int yyyy = 2000;    // true
    int yyyy = 2020;    // true

    bool is_leap_year = false;
    
    if((yyyy % 4 == 0) && (yyyy % 100 != 0) || (yyyy % 400 == 0))
    {
        is_leap_year = true;
    }
    else
    {
        is_leap_year = false;     
    }

    printf("%4d : is_leap_year = %s\n", yyyy, is_leap_year ? "true" : "false");

    // Alternative implementation
    if(yyyy % 400 == 0)
    {
        is_leap_year = true;
    }
    else
    { 
        if(yyyy % 100 == 0)
        {
            is_leap_year = false;
        } 
        else
        { 
            if(yyyy % 4 == 0)
            {
                is_leap_year = true;
            }
            else 
            {
                is_leap_year = false;
            }
        }
    }
    printf("%4d : is_leap_year = %s\n", yyyy, is_leap_year ? "true" : "false");

    return 0;
}
