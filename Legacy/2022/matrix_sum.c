#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int A[4][4] = {};
    int B[4][4] = {};
    int common_matrix_size = 4;

    for (int A_row = 0; A_row < common_matrix_size; A_row += 1)
    {
        for (int A_column = 0; A_column < common_matrix_size; A_column += 1)
        {
            scanf("%d", &A[A_row][A_column]);
        }
    }

    printf("Matrix A: \n");
    for (int A_row = 0; A_row < common_matrix_size; A_row += 1)
    {
        for (int A_column = 0; A_column < common_matrix_size; A_column += 1)
        {
            printf("%d,", A[A_row][A_column]);
        }
        printf("\n");
    }

    for (int B_row = 0; B_row < common_matrix_size; B_row += 1)
    {
        for (int B_column = 0; B_column < common_matrix_size; B_column += 1)
        {
            scanf("%d", &B[B_row][B_column]);
        }
    }

    printf("\nMatrix B: \n");
    for (int B_row = 0; B_row < common_matrix_size; B_row += 1)
    {
        for (int B_column = 0; B_column < common_matrix_size; B_column += 1)
        {
            printf("%d,", B[B_row][B_column]);
        }
        printf("\n");
    }

    printf("\nMatrix Sum: \n");
    for (int row = 0; row < common_matrix_size; row += 1)
    {
        for (int column = 0; column < common_matrix_size; column += 1)
        {
            int matrix_sum = A[row][column] + B[row][column];
            printf("%d,", matrix_sum);
        }
        printf("\n");
    }

    return 0;
}


