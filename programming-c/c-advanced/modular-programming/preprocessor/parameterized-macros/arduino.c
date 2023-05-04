#include <assert.h>

#define DELTA 1E-6

// Macro definitions found in Arduino.h
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define round(x) ((x)>=0?(long)((x)+0.5):(long)((x)-0.5))
#define sq(x) ((x)*(x))

int main(void)
{
    // Macro parameters have no particular type. 
    // As a result, a macro can accept arguments 
    // of any type, provided that the resulting 
    // program - after preprocessing - is valid.

    // using integer values 
    assert(7 == max(3,7));
    assert(3 == min(3,7));

    // using float values
    assert(abs(max(3.3,7.7) - 7.7) <= DELTA);
    assert(abs(min(3.3,7.7) - 3.3) <= DELTA);

    // round float to integer
    assert(3 == round(3.3));
    assert(8 == round(7.7));

    // Square root for integer and float 
    assert(3*3 == sq(3));
    assert(abs(sq(3.3) - 3.3*3.3) <= DELTA); 

    return 0;
}