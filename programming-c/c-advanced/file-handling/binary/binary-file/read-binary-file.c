#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define NUMBER_OF_VALUES 12

double data[NUMBER_OF_VALUES];

int main(void)
{
    char *file_name = "data.bin";

    FILE *fp = fopen(file_name, "rb");
    if (fp == NULL) 
    {
        fprintf(stderr, "Can't open %s file!\n", file_name);
        return -1;
    }
    
    for(int i=0; i< NUMBER_OF_VALUES; i++)
    {
        fread(&data[i], sizeof(double), 1, fp);
        printf("%2d  %lf\n", i, data[i]);
    }
    puts("\n");

    // Move the cursor back to the 5th element
    fseek(fp, sizeof(double) * 5, SEEK_SET);
    for(int i=0; i< NUMBER_OF_VALUES - 5; i++)
    {
        fread(&data[i], sizeof(double), 1, fp);
        printf("%2d  %lf\n", i, data[i]);
    }

    fclose(fp);

    return 0;
}