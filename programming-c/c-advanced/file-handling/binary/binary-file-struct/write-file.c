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

resistor_t data[NUMBER_OF_VALUES] = 
{
    {270, 5},
    {120, 2},
    {470, 2},
    {1000, 1},
    {680, 5}
};

int main(void)
{
    char *file_name = "data.bin";

    FILE *fp = fopen(file_name, "wb");
    if (fp == NULL) 
    {
        fprintf(stderr, "Can't create file: %s !\n", file_name);
        return EXIT_FAILURE;
    }

    fwrite(data, sizeof(resistor_t), NUMBER_OF_VALUES, fp);

    fclose(fp);

    return EXIT_SUCCESS;
}