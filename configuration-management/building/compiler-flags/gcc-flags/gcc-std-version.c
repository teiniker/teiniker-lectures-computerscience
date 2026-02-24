/*
The __STDC_VERSION__ macro indicates the C standard version 
the compiler is using by default or under specific flags.

Interpreting the Output:
    199409L – C94 (an amendment to C90)
    199901L – C99
    201112L – C11
    201710L – C17
    202x – Upcoming C2x

$ gcc -std=c17 -o program program.c
*/

#include <stdio.h>

int main() 
{
    printf("C Standard version: %ld\n", __STDC_VERSION__);
    return 0;
}
