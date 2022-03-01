#include <stdio.h>
#include <math.h>
#include <assert.h>

const double ERROR = 1E-3;
const double EXPECTED = 14.764823;

int main(void)
{
    double a = 7.0;
    double b = 13.0;
    double c;

    // TODO: c=...

    printf("a=%f, b=%f, c=%f\n", a,b,c);
    assert(fabs(EXPECTED - c) <= ERROR);

    return 0;
}
