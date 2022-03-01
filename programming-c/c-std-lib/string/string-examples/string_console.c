#include <stdio.h>
#include <string.h>
#include <assert.h>

#define STR_LEN 40

int main(void)
{
    char s[STR_LEN+1];

    // Read a string (including spaces) from the console
    printf("Enter line> ");
    fgets(s, STR_LEN+1, stdin);

    // Write a string (including '\n') to the console
    puts(s);

    return 0;
}

