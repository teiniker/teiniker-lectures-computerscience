#include <cstdio>
#include <cstdlib>

// Function Overloading
void print(int i);
void print(double d);
void print(const char *s);

int main(void)
{
    print(7);
    print(3.1415);
    print("Homer Simpson");

    return EXIT_SUCCESS;
}

// Function Overloading 
void print(int i)
{
    printf("int: %d\n", i);
}

void print(double d)
{
    printf("double: %5.2f\n", d);
}

void print(const char *s)
{
    printf("string: %s\n", s);
}

