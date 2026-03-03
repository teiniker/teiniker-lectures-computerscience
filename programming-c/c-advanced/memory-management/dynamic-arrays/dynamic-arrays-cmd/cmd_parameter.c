#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// cmd_parameter 1 2 3 4 5 6 7 
int main(int argc, char *argv[])
{
    printf("argc = %d\n", argc);
    for(int i=0; i<argc; i++)
    {
        printf("argv[%2d] = %s => %02d\n", i, argv[i], atoi(argv[i]));
    }

    return 0;
}