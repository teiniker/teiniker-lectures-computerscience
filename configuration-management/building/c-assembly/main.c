#include <stdio.h>

// Function implemented in assembly 
int add(int a, int b);

int main(void)
{
	int a = 7;
	int b = 5;

	int result = add(a,b);
	printf("%d + %d = %d\n", a,b, result);

	return 0;
}
