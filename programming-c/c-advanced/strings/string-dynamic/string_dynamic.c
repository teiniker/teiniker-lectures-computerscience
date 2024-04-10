#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


int main(void)
{
    int str_len = 40;

    // Dynamic allocated string buffer
    char *d = (char *)calloc(str_len+1, sizeof(char));
    d[0] = 'A';
    d[1] = 'B';
    d[2] = 'C';
    d[3] = '\0';
    printf("\"%s\"\n", d);

    // Release string buffer
    free(d);

    return 0;
}
