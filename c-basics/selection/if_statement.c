#include <stdio.h>

const int MIN = 0;
const int MAX = 10;

int main(void)
{
    int value = 7;      // User input 
    
    if(value >= MIN && value <= MAX)
    {
        printf("Value is in the range [MIN,MAX]\n");
    }
    else
    {
        printf("Value is invalid!\n");
    }
    
	return 0;
}
