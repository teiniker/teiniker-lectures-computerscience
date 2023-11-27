#include <stdio.h>
#include <stdbool.h> 

bool is_leap_year(int yyyy);
void print_leap_year(int start_year, int end_year);



int main(void)
{
    print_leap_year(1990, 2025);
    return 0;
}

bool is_leap_year(int yyyy)
{
    return (yyyy % 400 == 0) || (yyyy % 4 == 0) && (yyyy % 100 != 0);
}

void print_leap_year(int start_year, int end_year)
{
    for(int yyyy = start_year; yyyy <= end_year; yyyy++)
    {
        if(is_leap_year(yyyy))
        {
            printf("%4d\n", yyyy);
        }
    }
}
