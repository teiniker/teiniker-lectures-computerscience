#include <stdio.h>

// The following escape sequences are defined in standard C:
//  \uhhhh      Unicode code point below 10000 hexadecimal (added in C99)
//  \Uhhhhhhhh  Unicode code point where h is a hexadecimal digit

int main(void)
{
    printf("Unicode:\n");
    printf(" U+03C0  = \u03C0 \n");
    printf(" U+2153  = \u2153 \n");
    printf(" U+1F642 = \U0001F642 \n");
    return 0;
}
