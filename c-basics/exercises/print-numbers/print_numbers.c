#include <stdio.h>

int main(void)
{
    char c = '#';
    int i = 1;
    int j = 999999;
    float f = 0.1;
    double pi = 3.1415;

    printf("Filename = \"C:\\tmp\\table.txt\"\n");

    printf("\t+--------+--------+\n");
    printf("\t| char   | %-6c |\n", c);
    printf("\t| int    | %06d |\n", i);
    printf("\t| int    | %6d |\n", j);
    printf("\t| float  | %6.4f |\n", f);
    printf("\t| double | %6.4f |\n", pi);
    printf("\t+--------+--------+\n");

    printf("Status: 25%%\n");

    return 0;
}
