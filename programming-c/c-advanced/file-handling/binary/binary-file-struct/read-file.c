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
    
    for(int i=0; i< NUMBER_OF_VALUES; i++)
    {
        fread(&data[i], sizeof(resistor_t), 1, fp);
        printf("%4d Ohms, %d %%\n", data[i].value, data[i].tolerance);
    }
    puts("\n");

    fclose(fp);

    return EXIT_SUCCESS;
}