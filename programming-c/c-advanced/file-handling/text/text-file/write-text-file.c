#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


double data[12] = 
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
    char *file_name = "measurement.txt";

    FILE *fp;
    fp = fopen(file_name, "w");
    if (fp == NULL) 
    {
        fprintf(stderr, "Can't create file: %s !\n", file_name);
        return -1;
    }

    for(int i=0; i < 12; i++)
    {
        fprintf(fp, "%5.3lf\n", data[i]);
    }   
 
    fclose(fp);

    return 0;
}