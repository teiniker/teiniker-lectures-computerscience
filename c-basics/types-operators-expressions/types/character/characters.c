#include <stdio.h>


int main(void)
{
    char a = 'A';
    char b = 0x42;
    char c = 'A' + 2;

    printf("a = '%c' %d 0x%x\n", a, a, a);
    printf("b = '%c' %d 0x%x\n", b, b, b);
    printf("c = '%c' %d 0x%x\n", c, c, c);

    printf("Special characters:\t \" \\ %%\n");


    return 0;
}
