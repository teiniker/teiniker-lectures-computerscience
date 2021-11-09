#include <stdio.h>
#include <stdbool.h>    // since c99

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

    int a = 7;
    int b = 13;

    bool a_is_greater = a > b;  
    if(a_is_greater)
    {
        printf("a is greater than b!\n");
    }
    else
    {
        printf("a is less or equal to b!\n");
    }
    

	return 0;
}
