#include <stdio.h>
#include <string.h>

int main(void)
{
    char *s1 = "Hello Graz!";
    char s2[40+1];

    strncpy(s2, "Hello World!", 12+1);    

    printf("s1 = \"%s\"\n", s1);
    printf("s2 = \"%s\"\n", s2);

    return 0;
}
