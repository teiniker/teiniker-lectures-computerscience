#include <stdio.h>

int main(void)
{
    char c = '#';

    printf("Filename = \"C:\\tmp\\table.txt\"\n");

    printf("\t+--------+--------+\n");
    printf("\t| char   | %-6c |\n", c);
    printf("\t+--------+--------+\n");

    printf("Status: 25%%\n");

    return 0;
}
