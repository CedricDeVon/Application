
void flatten_array()
{
    int matrix[4][2] = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
    int matrix_row_length = sizeof(matrix) / sizeof(matrix[0]);
    int matrix_column_length = sizeof(matrix[0]) / sizeof(matrix[0][0]);
    int array[] = {}, array_index = 0;
    for (int row_index = 0; row_index < matrix_row_length; row_index += 1)
    {
        for (int column_index = 0; column_index < matrix_column_length; column_index += 1)
        {
            array[array_index] = matrix[row_index][column_index];
            array_index += 1;
            printf("%d", array[array_index]);
        }
    }
}
