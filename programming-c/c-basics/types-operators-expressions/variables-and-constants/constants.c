#include <stdio.h>


// Macro definition is a pre-processor directive
// #define PIN_NUMBER 3 

// const qualifier indicates that the value will not be changed
const int PIN_NUMBER = 3;                // integer constant (decimal)
const int BYTE_VALUE = 0xd2;             // integer constant (hex)
const int BINARY_VALUE = 0b11110000;     // supported by gcc but not C standard

const float PI = 3.1415f;                // floating point constant 

const char *MESSAGE = "Hello!";          // string literal

int main(void)
{
    printf("Pin   : %d\n", PIN_NUMBER);
    printf("Byte  : %x\n", BYTE_VALUE);
    printf("Binary: %x\n", BINARY_VALUE);

    printf("PI=%f\n", PI);

    printf("Message: %s\n", MESSAGE);

	return 0;
}
