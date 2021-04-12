#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define STR_LEN 40

void dump_memory(char *s, size_t bytes);

int main(void)
{
    // String variable (array)
    char s[STR_LEN+1]  = "This is a string variable";

    assert(s[0] == 'T');
    assert(s[1] == 'h');
    assert(s[2] == 'i');
    //...
    assert(s[24] == 'e');
    assert(s[25] == '\0');
    assert(s[25] == 0x00);
    printf("\"%s\"\n", s);

    // Changing a string variable
    s[2] = 'X';
    printf("\"%s\"\n", s);

    // Array size vs. string length
    dump_memory(s, STR_LEN+1);

    // Dynamic allocated string
    char *d = malloc(STR_LEN+1);
    d[0] = 'A';
    d[1] = 'B';
    d[2] = 'C';
    d[3] = '\0';
    printf("\"%s\"\n", d);
    dump_memory(d, STR_LEN+1);
    free(d);

    return 0;
}

void dump_memory(char *s, size_t bytes)
{
    printf("dump: ");
    for(size_t i=0; i<bytes; i++)
    {
        printf("%02x ", s[i]);
    }
    printf("\n");
}