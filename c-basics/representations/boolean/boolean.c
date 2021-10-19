#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    bool is_on  = true;     // #define true 1
    bool is_off = false;    // #define false 0    

    printf("is_on  = %d\nis_off = %d\n", is_on, is_off);

    bool a = true;
    bool b = false;

    printf("%d NOT = %d\n", a, !a);
    printf("%d AND %d = %d\n",a, b, a && b);
    printf("%d OR  %d = %d\n",a, b, a | b);

    return 0;
}

