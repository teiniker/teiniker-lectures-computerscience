#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define RETURN_OK 0
#define RETURN_ERROR -1

#define SIZE 10

int data_read(char *filename, double data[], size_t size);
void data_print(double data[], size_t size);
double data_min(double data[], size_t size);
double data_max(double data[], size_t size);

int main(void)
{
    char *filename = "measurement.txt";

    // Read data from text file
    double data[SIZE];
    data_read(filename, data, SIZE);
    data_print(data, SIZE);

    // Calculate min value
    double min = data_min(data, SIZE);
    printf("min = %lf\n", min);

    // Calculate max value
    double max = data_max(data, SIZE);
    printf("max = %lf\n", max);

    return 0;
}


int data_read(char *filename, double data[], size_t size)
{
    FILE *fptr = fopen(filename, "r");
    if (fptr == NULL) 
    {
        fprintf(stderr, "Can't open %s file!\n", filename);
        return RETURN_ERROR;
    }
    
    for(int i=0; i < 10; i++)
    {
        fscanf(fptr, "%lf", &data[i]);
    }
    fclose(fptr);
    return RETURN_OK;
}

void data_print(double data[], size_t size)
{
    for(int i=0; i<size; i++)
    {
        printf("data[%d] = %lf\n", i, data[i]);
    }
}

double data_min(double data[], size_t size)
{
    double min = data[0];
    for(int i=0; i<size; i++)
    {
        if(data[i] < min)
        {
            min = data[i];
        }
    }
    return min;
}

double data_max(double data[], size_t size)
{
    double max = data[0];
    for(int i=0; i<size; i++)
    {
        if(data[i] > max)
        {
            max = data[i];
        }
    }
    return max;
}
