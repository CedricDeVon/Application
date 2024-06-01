
void are_both_matrices_equal(int matrix_a[3][3], int matrix_b[3][3])
{
    int is_equal = 1;
    for (int row = 0; row < 3 && is_equal; row++)
    {
        for (int column = 0; column < 3; column++)
        {
            int matrix_a_number = matrix_a[row][column];
            int matrix_b_number = matrix_b[row][column];
            if (matrix_a_number != matrix_b_number)
            {
                is_equal = 0;
            }
        }
    }

    if (is_equal)
    {
        printf("Both matrices are equal!");
    }
    else
    {
        printf("Both matrices are not equal!");
    }
}
