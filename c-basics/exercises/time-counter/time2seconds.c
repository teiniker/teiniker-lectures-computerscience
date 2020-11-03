#include <stdio.h>
#include <stdbool.h> 

int main(void)
{
    // initial values
    int sec = 17;
    int min = 49;
    int hours = 15;

    int seconds = hours*3600 + min*60 + sec;
    printf("Seconds = %5d\n", seconds);

    int hh = seconds / 3600;
    int mm = (seconds - hh*3600)/60;
    int ss = seconds - hh*3600 - mm*60;
    printf("%2d:%02d:%02d\n", hh, mm, ss);

    return 0;
}
