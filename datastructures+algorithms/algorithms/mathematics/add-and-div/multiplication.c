#include <stdio.h>
#include <assert.h>
#include <stdint.h>

uint64_t multiply(uint32_t a, uint32_t b) 
{
    uint64_t result = 0;          // Initialize result
    uint64_t multiplicand = a;    // Promote to 64 bits to prevent overflow during shifting
    uint32_t multiplier = b;      // Use a copy of the multiplier

    while (multiplier > 0) 
    {
        // If the least significant bit is set, add the current multiplicand to the result
        if (multiplier & 1) 
        {
            result += multiplicand;
        }

        // Shift the multiplicand left by 1 (equivalent to multiplying by 2)
        multiplicand <<= 1;

        // Shift the multiplier right by 1 to process the next bit
        multiplier >>= 1;
    }
    return result;
}

int main(void)
{
    // Test 1
    {
        int32_t a = 7;
        int32_t b = 13;

        int32_t result = multiply(a, b);
        assert(7*13 == result);
    }

    // Test 2
    {
        int32_t a = 0;
        int32_t b = 13;

        int32_t result = multiply(a, b);
        assert(0 == result);
    }

    // Test 3
    {
        int32_t a = 7;
        int32_t b = 0;

        int32_t result = multiply(a, b);
        assert(0 == result);
    }

    // Test 4
    {
        int32_t a = UINT32_MAX;
        int32_t b = UINT32_MAX;

        int32_t result = multiply(a, b);
        assert(UINT32_MAX * UINT32_MAX == result);
    }

    return 0;
}
