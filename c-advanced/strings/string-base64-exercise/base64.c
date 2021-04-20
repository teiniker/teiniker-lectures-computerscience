#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

 char *base64_code = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

char *base64(size_t size, unsigned char *bytes)
{
    if(size % 3 != 0)
    {
        printf("ERROR: The size of bytes must be a multiple of 3!");
        return "";
    }

    // TODO: Implementation
}

int main(void)
{
    unsigned char in1[3] = {0x1A, 0xCF, 0xD2};
    char *out1 = base64(3, in1);
    printf("output: %s\n", out1);
    assert(strcmp("Gs/S", out1) == 0);
    free(out1);

    unsigned char in2[6] = {0x1A, 0xCF, 0xD2, 0x32, 0xEE, 0x11};
    char *out2 = base64(6, in2);
    printf("output: %s\n", out2);
    assert(strcmp("Gs/SMu4R", out2) == 0);
    free(out2);

    unsigned char in3[9] = {0x1A, 0xCF, 0xD2, 0x32, 0xEE, 0x11, 0x46, 0xCC, 0x33};
    char *out3 = base64(9, in3);
    printf("output: %s\n", out3);
    assert(strcmp("Gs/SMu4RRswz", out3) == 0);
    free(out3);

    return 0;
}