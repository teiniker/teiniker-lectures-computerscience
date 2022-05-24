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


// TODO: Implement functions.
