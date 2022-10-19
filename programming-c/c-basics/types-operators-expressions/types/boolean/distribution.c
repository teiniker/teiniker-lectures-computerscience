#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

int main(void)
{
    bool a = true;
    bool b = true;
    bool c = false;

    bool expr_1 = (a||b) && (a||c);
    bool expr_2 = a || (b&&c);

    printf("(a+b)*(a+c) = %d\n", expr_1);
    printf("a+(b*c) = %d\n", expr_2);

    assert(expr_1 == expr_2);

    return 0;
}
