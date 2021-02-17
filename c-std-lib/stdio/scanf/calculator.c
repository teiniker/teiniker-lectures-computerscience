#include <stdio.h>

int main(void)
{
    int a;
    int b;
    char op;

    // read two integer numbers and a char from the console
    printf("calc> ");
    scanf("%d %d %c", &a, &b, &op);

    switch(op)
    {
        case '+':
            printf("%d + %d = %d\n", a, b, a + b);
            break;

        case '-':
            printf("%d - %d = %d\n", a, b, a - b);
            break;

        default:
            printf("Operation not supported!\n");
            break;    
    }

    return 0;
}
