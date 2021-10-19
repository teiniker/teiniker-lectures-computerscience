#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

int main(void)
{
    bool a = true;
    bool b = true;

    // Boolean expression for XOR
    bool result_xor = a && !b || !a && b;
    printf("%d XOR  %d = %d\n",a, b, result_xor);
    assert(!result_xor);
    
    return 0;
}

