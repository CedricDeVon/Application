
int _recursive_matrix_addition(int sum, int row, int column, int row_length, int column_length, int matrix[2][2])
{
    if (row == row_length)
    {
        return sum;
    }
    else if (column == column_length)
    {
        row += 1;
        column = 0;
    }
    else
    {
        sum += matrix[row][column];
        column += 1;
    }
    return _recursive_matrix_addition(sum, row, column, row_length, column_length, matrix);
}

void recursive_matrix_addition()
{
    int matrix[2][2] = {
        {9, 2},
        {3, 4}};
    int matrix_row_length = sizeof(matrix) / sizeof(matrix[0]);
    int matrix_column_length = sizeof(matrix[0]) / sizeof(matrix[0][0]);
    int sum = _recursive_matrix_addition(0, 0, 0, matrix_row_length, matrix_column_length, matrix);
    printf("%d", sum);
}
