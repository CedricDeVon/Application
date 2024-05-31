/*
   -- Matrix Subtraction
   Two matrices must have an equal number of rows and columns to be subtracted.In which case, the subtracted of two matrices A and B will be a matrix which has the same number of rows and columns as A and B.

   The result of the subtraction of A and B, denoted A - B is computed by subtracting corresponding elements of A and B.

   Create a function that takes 2 x 2D array (matrix A, matrixB) as an argument and returns a 2D array (matrix C). C = A-B.

   Examples
   sub([
   [1, 2, 3],
   [4, 5, 6],
   [7, 8, 9]
   ], [
   [1, 2, 3],
   [4, 5, 6],
   [7, 8, 9]
   ]) ➞ [
   [0, 0, 0],
   [0, 0, 0],
   [0, 0, 0]
   ]
   Notes
   Treat strings of numbers as integers.
*/

void matrix_subtraction(int matrix_a[3][3], int matrix_b[3][3])
{
    int subtracted_matrix[3][3] = {};

    for (int row = 0; row < 3; row++)
    {
        for (int column = 0; column < 3; column++)
        {
            int matrix_a_number = matrix_a[row][column];
            int matrix_b_number = matrix_b[row][column];
            subtracted_matrix[row][column] = matrix_a_number - matrix_b_number;
        }
    }

    for (int row = 0; row < 3; row++)
    {
        for (int column = 0; column < 3; column++)
        {
            printf("%d, ", subtracted_matrix[row][column]);
        }
        printf("\n");
    }
}