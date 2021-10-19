#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

int main(void)
{
    bool a = true;
    bool b = false;

    // Logical operators
    printf("%d NOT = %d\n", a, !a);
    printf("%d AND %d = %d\n",a, b, a && b);
    printf("%d OR  %d = %d\n",a, b, a | b);

    // Boolean expression for XOR
    
    a = true;
    b = false;
    bool result_xor = a && !b || !a && b;
    printf("%d XOR  %d = %d\n",a, b, result_xor);

    // assert statements
    a = true;
    b = false;
    assert(!(a||b) == !a && !b);


    return 0;
}

