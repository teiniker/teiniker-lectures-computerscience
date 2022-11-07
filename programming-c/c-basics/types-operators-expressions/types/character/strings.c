#include <stdio.h>
#include <string.h>

void dump_memory(const char *s, size_t bytes); // just use it :-)

int main(void)
{
    char *s1 = "Hello Graz!";
    char s2[40+1];

    strncpy(s2, "Hello World!", 12+1);    

    printf("s1 = \"%s\"\n", s1);
    dump_memory(s1, 11+1);

    printf("s2 = \"%s\"\n", s2);
    dump_memory(s1, 40+1);

    return 0;
}

void dump_memory(const char *s, size_t bytes)
{
    printf("memory [%p]: ", s);
    for(size_t i=0; i<bytes; i++)
    {
        printf("%02x ", s[i]);
    }
    printf("\n");
}