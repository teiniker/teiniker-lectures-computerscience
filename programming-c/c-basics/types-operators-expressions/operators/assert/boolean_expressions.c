#include <stdio.h>
//#define NDEBUG
#include <assert.h>

int main(void)
{
    int value = 126;
    printf("value = %d\n", value);
    
    // Use assert to automatically verify a Boolean expression
    assert(value < 125);
    
    return 0;
}

