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

    // TODO

    return EXIT_SUCCESS;
}