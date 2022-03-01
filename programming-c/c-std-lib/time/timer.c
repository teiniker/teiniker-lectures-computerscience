#include <stdio.h>
#include <time.h>

// The C library function clock_t clock(void) returns the number of 
// clock ticks elapsed since the program was launched. 
// To get the number of seconds used by the CPU, you will need to 
// divide by CLOCKS_PER_SEC.
// https://www.tutorialspoint.com/c_standard_library/c_function_clock.htm

int main(void)
{
    clock_t start;
    clock_t stop;

    start = clock();

    // just to create some delay
    for(int i=0; i< 100000; i++)
    {
        printf("%d ", i);
    }

    stop = clock();

    clock_t interval = (stop - start)*1000.0 / CLOCKS_PER_SEC; // in ms
        
    printf("\n\n");
    printf("\t start   : %d clocks\n", start);
    printf("\t stop    : %d clocks\n", stop);
    printf("\t interval: %d [ms]\n", interval);
    return 0;
}

