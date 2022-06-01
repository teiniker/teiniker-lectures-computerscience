#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


int main(void)
{
    char *file_name = "data.txt";

    FILE *fp = fopen(file_name, "r");
    if (fp == NULL) 
    {
        fprintf(stderr, "Can't open %s file!\n", file_name);
        return EXIT_FAILURE;
    }
    
    int i=0;
    char line[81];
    while(fgets(line, 80, fp) != NULL)
    {
        printf("%3d \t %s", i, line);
        i++;
    }
    fclose(fp);

    return EXIT_SUCCESS;
}