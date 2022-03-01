#include <stdio.h>

#define ROWS    5
#define COLUMNS 10

void print_matrix(int rows, int columns, int matrix[ROWS][COLUMNS]);
void fill_matrix(int rows, int columns, int matrix[ROWS][COLUMNS], int value);


int main(void)
{
    int matrix[ROWS][COLUMNS] = {
                                    {10,11,12,13,14,15,16,17,18,19},
                                    {20,21,22,23,24,25,26,27,28,29},
                                    {30,31,32,33,34,35,36,37,38,39},
                                    {40,41,42,43,44,45,46,47,48,49},
                                    {50,51,52,53,54,55,56,67,58,59}
                                };


    print_matrix(ROWS,COLUMNS,matrix);
    // 10 11 12 13 14 15 16 17 18 19 
    // 20 21 22 23 24 25 26 27 28 29 
    // 30 31 32 33 34 35 36 37 38 39 
    // 40 41 42 43 44 45 46 47 48 49 
    // 50 51 52 53 54 55 56 67 58 59     


    fill_matrix(ROWS,COLUMNS,matrix,7);
    print_matrix(ROWS,COLUMNS,matrix);
    // 7 7 7 7 7 7 7 7 7 7 
    // 7 7 7 7 7 7 7 7 7 7 
    // 7 7 7 7 7 7 7 7 7 7 
    // 7 7 7 7 7 7 7 7 7 7 
    // 7 7 7 7 7 7 7 7 7 7

    return 0;
}


void print_matrix(int rows, int columns, int matrix[ROWS][COLUMNS])
{
   for(int i=0; i<rows; i++)
   {
        for(int j=0; j<columns; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
   }
    printf("\n");
}

void fill_matrix(int rows, int columns, int matrix[ROWS][COLUMNS], int value)
{
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<columns; j++)
        {
            matrix[i][j] = value;
        }
    }
}
