#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

typedef struct 
{
    uint32_t value;
    uint8_t tolerance;
} resistor_t;


resistor_t *resistor_new(const uint32_t value, const uint8_t tolerance);
void resistor_delete(resistor_t *r);

resistor_t *resistor_serial(const resistor_t *r1, const resistor_t *r2);
resistor_t *resistor_parallel(const resistor_t *r1, const resistor_t *r2);
int max(const uint8_t t1, const uint8_t t2);

int main(void)
{
    resistor_t *r1 = resistor_new(270,5); 
    resistor_t *r2 = resistor_new(120,2);
    resistor_t *r3 = resistor_new(120,1);

    resistor_t *r_par = resistor_parallel(r2, r3);
    assert(120/2 == r_par->value);
    assert(2 == r_par->tolerance);

    resistor_t *r_ser = resistor_serial(r1, r_par);
    assert(270 + 120/2 == r_ser->value);
    assert(5 == r_ser->tolerance);

    resistor_delete(r1);
    resistor_delete(r2);
    resistor_delete(r3);
    resistor_delete(r_par);
    resistor_delete(r_ser);

    return 0;
}

resistor_t *resistor_new(const uint32_t value, const uint8_t tolerance)
{
    resistor_t * r = malloc(sizeof(resistor_t));
    r->value = value;
    r->tolerance = tolerance;
    return r;
}

void resistor_delete(resistor_t *r)
{
    free(r);
}

resistor_t *resistor_serial(const resistor_t *r1, const resistor_t *r2)
{
    uint32_t r = r1->value + r2->value;
    uint8_t t = max(r1->tolerance, r2->tolerance);
    return resistor_new(r, t);
}

resistor_t *resistor_parallel(const resistor_t *r1, const resistor_t *r2)
{
    uint32_t r = r1->value * r2->value / (r1->value + r2->value);
    uint8_t t = max(r1->tolerance, r2->tolerance);
    return resistor_new(r, t);
}

int max(const uint8_t t1, const uint8_t t2)
{
    return (t1 > t2)? t1: t2;
}