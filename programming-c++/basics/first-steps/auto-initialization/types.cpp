#include <cstdio>
#include <cstdlib>

int *fibonacci(size_t n);

int main(void)
{
    auto c = 'X';
    printf("Character '%c' = %d in ASCII code\n", c,c);

    auto number = 0x93;      
    printf("Decimal representation     = %d\n", number);
    printf("Hexadecimal representation = 0x%x\n", number);
    printf("Octal representation       = 0%o\n", number);

    auto pi = 3.141592653589793;
    printf("pi = %f\n", pi);

    auto result = fibonacci(5);
    for(auto i = 0; i < 5; i++)
    {
        printf("fibonacci[%d] = %d\n", i, result[i]);
    }
    free(result);

    return EXIT_SUCCESS;
}

int *fibonacci(size_t n)
{
    // Pre condition: n > 2
    int *sequence = (int *)malloc(n * sizeof(int));
    sequence[0] = 0;
    sequence[1] = 1;
    for(int i = 2; i < n; i++)
    {
        sequence[i] = sequence[i-2] + sequence[i-1];
    }
    return sequence; 
}
