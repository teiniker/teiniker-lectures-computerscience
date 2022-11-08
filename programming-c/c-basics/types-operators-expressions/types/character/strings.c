#include <stdio.h>
#include <stdint.h>
#include <string.h>

void dump_memory(const void *s, size_t bytes); // just use it :-)

int main(void)
{
    char *s1 = "Hello Graz\U0001F642!"; // ""
    printf("s1 = \"%s\"\n", s1);
    dump_memory(s1, strlen(s1)+1);
    // memory [0x55cb409ea004]: 48 65 6c 6c 6f 20 47 72 61 7a f0 9f 99 82 21 00
    // U+1F642 => UTF-8: f0 9f 99 82

    char s2[40+1];
    strncpy(s2, "Hello World!", 12+1);    

    printf("s2 = \"%s\"\n", s2);
    dump_memory(s2, 40+1);

    return 0;
}

void dump_memory(const void *s, size_t bytes)
{
    printf("memory [%p]: ", s);
    char *ptr = (char *)s;
    for(size_t i=0; i<bytes; i++)
    {
        printf("%02x ", (uint8_t)ptr[i]);
    }
    printf("\n");
}