#include <stdio.h>
#include <stdbool.h> 

int main(void)
{
    int value = 150;

    // Range [min, max]
    int min = 0;
    int max = 100;

    if(value < min)
    {
        value = min;
    }
    else if(value > max)
    {
        value = max;
    }
    else
    {
        // value in range
    }

    printf("%d <= %d <= %d\n", min, value, max);

    // Alternative Implementation
    int value = 150;
    
    value = (value > max) ? max: value;
    value = (value < min) ? min: value;

    printf("%d <= %d <= %d\n", min, value, max);

    return 0;
}
