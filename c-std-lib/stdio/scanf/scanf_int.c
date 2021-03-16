#include <stdio.h>

int main(void)
{
    int a;
    float b;

    printf("int a = ");
    scanf("%d", &a);

    printf("double b = ");
    scanf("%f", &b);
 
    printf("a = %d, b = %f\n", a, b);
 
    return 0;
}
