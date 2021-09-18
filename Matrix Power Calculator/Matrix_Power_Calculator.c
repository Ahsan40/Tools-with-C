#include <stdio.h>

/*
Test-1:
Input
4
4
0 6 0 4
2 4 0 0
4 5 3 3
6 6 2 5

Output
 144  192   32   80
  32  112    0   32 
 160  308   60  160
 200  400   64  220 


Test-2:
Input
4
4
0 1 1 0
1 0 0 1
1 0 0 1
0 1 1 0

Output
8 0 0 8
0 8 8 0
0 8 8 0
8 0 0 8
*/

void matrix_power(int size, int matrix[][size], int result[][size], int power);
void scan_matrix(int size, int matrix[][size]);
void print_matrix(int size, int matrix[][size]);
void init_matrix(int size, int matrix[][size], int value);

int main()
{
    int size, power;
    printf("Enter a Matrix Size (n x n): ");
    scanf("%d", &size);

    int matrix[size][size], result[size][size];
    init_matrix(size, result, 0);

    printf("Enter the Power of Matrix: ");
    scanf("%d", &power);

    printf("Enter the Matrix: \n");
    scan_matrix(size, matrix);

    printf("\nThe Matrix is: \n");
    print_matrix(size, matrix);

    printf("\nThe Matrix Power is: \n");
    matrix_power(size, matrix, result, power);
    print_matrix(size, result);
    return 0;
}

// function to calculate the power of matrix
void matrix_power(int size, int matrix[][size], int result[][size], int power)
{
    for (int count = 1; count <= power; count++)
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                for (int k = 0; k < size; k++)
                    result[i][j] += matrix[i][k] * matrix[k][j];
}

void init_matrix(int size, int matrix[][size], int value)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            matrix[i][j] = value;
}

void scan_matrix(int size, int matrix[][size])
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            scanf("%d", &matrix[i][j]);
}

void print_matrix(int size, int matrix[][size])
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            printf("%5d ", matrix[i][j]);
        printf("\n");
    }
}
