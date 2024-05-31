
int _recursive_diagonal_sum(int diagonal_sum, int row_index, int column_index, int matrix[4][4])
{
    if (column_index <= -1)
    {
        return diagonal_sum;
    }
    diagonal_sum += matrix[row_index][column_index];
    row_index += 1;
    column_index -= 1;
    return _recursive_diagonal_sum(diagonal_sum, row_index, column_index, matrix);
}

int recursive_diagonal_sum()
{
    int matrix[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};
    int matrix_row_length = sizeof(matrix) / sizeof(matrix[0]);
    int matrix_column_length = sizeof(matrix[0]) / sizeof(matrix[0][0]);
    int diagonal_sum = 0, column_index = matrix_column_length - 1;
    return _recursive_diagonal_sum(0, 0, column_index, matrix);
}
