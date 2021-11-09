#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

int main(void)
{
    bool a = true;
    bool b = true;

    // Logical operators
    printf("%d NOT = %d\n", a, !a);
    printf("%d AND %d = %d\n",a, b, a && b);
    printf("%d OR  %d = %d\n",a, b, a || b);

    // Boolean expression for XOR
    a = true;
    b = false;
    bool result_xor = a && !b || !a && b;
    printf("%d XOR  %d = %d\n",a, b, result_xor);

    // Relational expressions
    int value = 17;
    bool result_lt = value < 10;
    printf("%d < 10 => %d\n", value, result_lt);


    // Equality expressions
    value = 666;
    bool result_eq = (value == 666);
    printf("%d == 666 => %d\n", value, result_eq);

    return 0;
}

