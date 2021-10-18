#include <stdio.h>

// gobal variable declarations
int year = 2020;                // with initializer    
int day;

int main(void)
{
    printf("year=%d\n", year);
    day = 14;                   // assignment
    printf("day =%d\n", day);

    // local variable declarations
    int i = 7;                  // with initializer
    printf("i=%d\n", i);
    int j = 3;
    printf("j=%d\n", j);

	return 0;
}
