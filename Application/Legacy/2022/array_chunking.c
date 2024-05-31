void array_chunking()
{
    int matrix[4][2] = {};
    int matrix_row_length = sizeof(matrix) / sizeof(matrix[0]);
    int matrix_column_length = sizeof(matrix[0]) / sizeof(matrix[0][0]);
    int array[8] = {1, 2, 3, 4, 5, 6, 7, 8}, array_index = 0;
    for (int row_index = 0; row_index < matrix_row_length; row_index += 1)
    {
        for (int column_index = 0; column_index < matrix_column_length; column_index += 1)
        {
            matrix[row_index][column_index] = array[array_index];
            array_index += 1;
            printf("%d, ", matrix[row_index][column_index]);
        }
        printf("\n");
    }
}