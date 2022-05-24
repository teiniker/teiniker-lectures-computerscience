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
    
    int i;
    double value;
    while(fscanf(fptr, "%d %lf", &i, &value) != EOF)
    {
        printf("%3d \t %5.3f\n", i, value);
    }
    fclose(fptr);

    return 0;
}