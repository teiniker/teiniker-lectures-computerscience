#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>

bool divide(uint32_t dividend, uint32_t divisor, uint32_t* quotient, uint32_t* remainder) 
{
    if (divisor == 0) 
        return false; // Division by zero is undefined

    uint32_t q = 0;         // Initialize quotient
    uint32_t r = 0;         // Initialize remainder
    int i;

    for (i = 31; i >= 0; i--) 
    {
        // Shift remainder left by 1 bit to make room for the next bit
        r <<= 1;

        // Bring down the next bit from the dividend
        r |= (dividend >> i) & 1;

        // If the remainder is greater than or equal to the divisor, subtract the divisor
        if (r >= divisor) 
        {
            r -= divisor;
            q |= (1U << i); // Set the corresponding bit in the quotient
        }
    }

    // Store the results
    *quotient = q;
    *remainder = r;

    return true;
}

int main(void)
{
    // Test 1
    {
        int32_t a = 15;
        int32_t b = 3;
        int32_t q, r;

        bool result = divide(a, b, &q, &r);
        assert(result);
        assert(a/b == q);
        assert(a%b == r);
    }

    // Test 2
    {
        int32_t a = 17;
        int32_t b = 5;
        int32_t q, r;

        bool result = divide(a, b, &q, &r);
        assert(result);
        assert(a/b == q);
        assert(a%b == r);
    }


    // Test 3
    {
        int32_t a = 17;
        int32_t b = 0;
        int32_t q, r;

        bool result = divide(a, b, &q, &r);
        assert(!result);
    }
  
    return 0;
}
