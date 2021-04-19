#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define STR_LEN 40

int main(void)
{
    char s[STR_LEN + 1];
    int i;
    double d;
    char c;

    // Write formated data into a string
    i = 7;
    d = 3.1415;
    c = 'A';
    sprintf(s, "%d %3.2lf %c", i, d, c);
    puts(s);
    assert(strcmp("7 3.14 A", s) == 0);

    // Read data from a string
    strcpy(s, "11 1.41 B");
    sscanf(s, "%d %lf %c", &i, &d, &c);
    assert(i == 11);
    assert(abs(1.41 - d) < 0.001);
    assert(c == 'B');

    return 0;
}

