#include <stdio.h>

#define N 10

void print_array(int n, int v[]);
void fill_array(int n, int v[], int value);
int size_of_array(int v[]);


int main(void)
{
    int vector[N] = {10,20,30,40,50,60,70,80,90,100};

    // 10 20 30 40 50 60 70 80 90 100 
    for(int i=0; i<N; i++)
    {
        printf("%d ", vector[i]);
    }
    printf("\n");

    // 100 90 80 70 60 50 40 30 20 10
    for(int i=N-1; i>=0; i--)
    {
        printf("%d ", vector[i]);
    }
    printf("\n");

    // Sum of vector[] = 550
    int sum = 0;
    for(int i=0; i<N; i++)
    {
        sum += vector[i];
    }
    printf("Sum of vector[] = %d\n", sum);

    // 10 20 33 40 50 66 70 80 90 100
    vector[2] = 33;
    vector[5] = 66;
    print_array(N, vector);

    // 7 7 7 7 7 7 7 7 7 7 
    // Call by reference !!
    fill_array(N, vector, 7);
    print_array(N, vector);     

    // 7 7 7 7 7 
    print_array(5, vector);  

    // Size of vector = 40 (10*4 bytes)
    // Size of vector in function = 8 (size of address)
    printf("Size of vector = %d\n", sizeof(vector));
    printf("Size of vector in function = %d\n", size_of_array(vector));
    
    return 0;
}


void print_array(int n, int v[])
{
   for(int i=0; i<n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void fill_array(int n, int v[], int value)
{
    for(int i=0; i<n; i++)
    {
        v[i] = value;
    }
}

int size_of_array(int v[])
{
    return sizeof(v);
}