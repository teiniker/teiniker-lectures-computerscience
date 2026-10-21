#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct
{
    int numerator;
    int denominator;
} rational_t;


int gcd(int a, int b);
rational_t rational_init(int numerator, int denominator);
void rational_print(rational_t r);
rational_t rational_add(rational_t a, rational_t b);
rational_t rational_sub(rational_t a, rational_t b);
rational_t rational_mul(rational_t a, rational_t b);
rational_t rational_div(rational_t a, rational_t b);


int main(void)
{
    {
        printf("Test 1: init\n");
        rational_t r1 = rational_init(2, 4);
        rational_print(r1);
        assert(1 == r1.numerator);
        assert(2 == r1.denominator);
    }

    {
        printf("Test 2: init with negative denominator\n");
        rational_t r1 = rational_init(3, -6);
        rational_print(r1);
        assert(-1 == r1.numerator);
        assert(2 == r1.denominator);
    }

    {
        printf("Test 3: r3 = r1 + r2\n");
        rational_t r1 = rational_init(1, 2);
        rational_t r2 = rational_init(1, 3);
        rational_t r3 = rational_add(r1, r2);
        rational_print(r3);
        assert(5 == r3.numerator);
        assert(6 == r3.denominator);
    }

    {
        printf("Test 4: r3 = r1 - r2\n");
        rational_t r1 = rational_init(1, 3);
        rational_t r2 = rational_init(1, 2);
        rational_t r3 = rational_sub(r1, r2);
        rational_print(r3);
        assert(-1 == r3.numerator);
        assert(6 == r3.denominator);
    }

    {
        printf("Test 5: r3 = r1 * r2\n");
        rational_t r1 = rational_init(2, 3);
        rational_t r2 = rational_init(3, 4);
        rational_t r3 = rational_mul(r1, r2);
        rational_print(r3);
        assert(1 == r3.numerator);
        assert(2 == r3.denominator);
    }

    {
        printf("Test 6: r3 = r1 / r2\n");
        rational_t r1 = rational_init(1, 2);
        rational_t r2 = rational_init(3, 4);
        rational_t r3 = rational_div(r1, r2);
        rational_print(r3);
        assert(2 == r3.numerator);
        assert(3 == r3.denominator);
    }

    return 0;
}

int gcd(int a, int b)
{
    a = abs(a);
    b = abs(b);

    while (b != 0)
    {
        int tmp = b;

        b = a % b;
        a = tmp;
    }

    return a;
}

rational_t rational_init(int numerator, int denominator)
{
    assert(denominator != 0);

    if (denominator < 0)
    {
        numerator = -numerator;
        denominator = -denominator;
    }

    int divisor = gcd(numerator, denominator);

    rational_t r = {numerator / divisor, denominator / divisor};
    return r;
}

void rational_print(rational_t r)
{
    printf("%d/%d\n", r.numerator, r.denominator);
}

rational_t rational_add(rational_t a, rational_t b)
{
    return rational_init(a.numerator * b.denominator
                         + b.numerator * a.denominator,
                         a.denominator * b.denominator);
}

rational_t rational_sub(rational_t a, rational_t b)
{
    return rational_init(a.numerator * b.denominator
                         - b.numerator * a.denominator,
                         a.denominator * b.denominator);
}

rational_t rational_mul(rational_t a, rational_t b)
{
    return rational_init(a.numerator * b.numerator,
                         a.denominator * b.denominator);
}

rational_t rational_div(rational_t a, rational_t b)
{
    return rational_init(a.numerator * b.denominator,
                         a.denominator * b.numerator);
}
