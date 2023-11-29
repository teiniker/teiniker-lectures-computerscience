#include <stdio.h>
#include <stdbool.h> 


bool is_leap_year(int yyyy);
void print_leap_years(int start_year, int end_year);

int main(void)
{
    print_leap_years(1990, 2025);

    return 0;
}

// TODO: Imlement functions here