#include <stdio.h>

#define ROWS  3
#define COLUMNS 3

void matrix_print(int rows, int columns, int matrix[ROWS][COLUMNS]);
void matrix_transpose(int rows, int columns, int A[ROWS][COLUMNS], int C[ROWS][COLUMNS]);
void matrix_add(int rows, int columns, int A[ROWS][COLUMNS],int B[ROWS][COLUMNS], int C[ROWS][COLUMNS]);
void matrix_sub(int rows, int columns, int A[ROWS][COLUMNS],int B[ROWS][COLUMNS], int C[ROWS][COLUMNS]);


int main(void)
{
    int matrix_a[ROWS][COLUMNS] = 
    { {5,6,7}, 
      {8,9,10}, 
      {3,1,2} };
    int matrix_b[ROWS][COLUMNS] = { {1,2,3}, {4,5,6}, {7,8,9} };
    int matrix_c[ROWS][COLUMNS];

    printf("A =\n");
    matrix_print(ROWS, COLUMNS, matrix_a);
    printf("B =\n");
    matrix_print(ROWS, COLUMNS, matrix_b);

    matrix_transpose(ROWS, COLUMNS,matrix_a,matrix_c);
    printf("C = transpose(A) =\n");
    matrix_print(ROWS, COLUMNS, matrix_c);

    matrix_add(ROWS, COLUMNS,matrix_a, matrix_b, matrix_c);
    printf("C = A + B =\n");
    matrix_print(ROWS, COLUMNS, matrix_c);

    matrix_sub(ROWS, COLUMNS,matrix_a, matrix_b, matrix_c);
    printf("C = A - B =\n");
    matrix_print(ROWS, COLUMNS, matrix_c);

    return 0;
}

void matrix_print(int rows, int columns, int matrix[ROWS][COLUMNS])
{
    for(int i=0; i<rows; i++)
    {
        printf("[ ");
        for(int j=0; j<columns; j++)
        {
            printf("%3d ", matrix[i][j]);
        }
        printf("]\n");
    }
}


void matrix_transpose(int rows, int columns, int A[ROWS][COLUMNS], int C[ROWS][COLUMNS])
{
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<columns; j++)
        {
            C[i][j] = A[j][i];
        }
    }
}


void matrix_add(int rows, int columns, int A[ROWS][COLUMNS], 
    int B[ROWS][COLUMNS], int C[ROWS][COLUMNS])
{
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<columns; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}


void matrix_sub(int rows, int columns, int A[ROWS][COLUMNS], 
    int B[ROWS][COLUMNS], int C[ROWS][COLUMNS])
{
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<columns; j++)
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}
