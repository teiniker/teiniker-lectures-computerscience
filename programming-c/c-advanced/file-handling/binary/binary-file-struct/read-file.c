#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#define NUMBER_OF_VALUES 5

typedef struct 
{
    uint32_t value;
    uint8_t tolerance;
} resistor_t;

resistor_t data[NUMBER_OF_VALUES];

int main(void)
{
    char *file_name = "data.bin";

    FILE *fp = fopen(file_name, "rb");
    if (fp == NULL) 
    {
        fprintf(stderr, "Can't open %s file!\n", file_name);
        return EXIT_FAILURE;
    }
    
    // Read all records from file into the array
    size_t size = fread(data, sizeof(resistor_t), NUMBER_OF_VALUES, fp);
    printf("Read %d elements from file.\n", size);

    for(int i=0; i< NUMBER_OF_VALUES; i++)
    {
        printf("%4d Ohms, %d %%\n", data[i].value, data[i].tolerance);
    }
    puts("\n"); // puts(str) short for printf("%s", str);

    fclose(fp);

    return EXIT_SUCCESS;
}