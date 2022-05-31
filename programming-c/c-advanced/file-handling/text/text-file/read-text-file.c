#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


int main(void)
{
    char *file_name = "data.txt";

    FILE *fptr;
    fptr = fopen(file_name, "r");
    if (fptr == NULL) 
    {
        fprintf(stderr, "Can't open %s file!\n", file_name);
        return -1;
    }
    
    int i=0;
    char line[81];

    while(fgets(line, 80, fptr) != NULL)
    {
        printf("%3d \t %s", i, line);
        i++;
    }
    fclose(fptr);

    return 0;
}