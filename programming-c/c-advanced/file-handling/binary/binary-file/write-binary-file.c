#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define NUMBER_OF_VALUES 12

double data[NUMBER_OF_VALUES] = 
{
    1.123,
    1.345,
    1.678,
    1.987,
    2.121,
    2.001,
    1.987,
    1.765,
    1.654,
    1.423,
    1.234,
    1.112  
};

int main(void)
{
    char *file_name = "data.bin";

    FILE *fp;
    fp = fopen(file_name, "wb");
    if (fp == NULL) 
    {
        fprintf(stderr, "Can't create file: %s !\n", file_name);
        return -1;
    }

    fwrite(data, sizeof(double), NUMBER_OF_VALUES, fp);

    fclose(fp);

    return 0;
}