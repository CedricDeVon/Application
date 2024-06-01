
void product_of_digit_sums()
{
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};
    int matrix_row_length = sizeof(matrix) / sizeof(matrix[0]);
    int matrix_column_length = sizeof(matrix[0]) / sizeof(matrix[0][0]);
    int products_of_digits[3] = {1, 1, 1};
    for (int row = 0; row < matrix_row_length; row++)
    {
        for (int column = 0; column < matrix_column_length; column++)
        {
            int digit_sum = 0;
            int number = matrix[row][column];
            while (number > 0)
            {
                digit_sum += number % 10;
                number = number / 10;
            }
            products_of_digits[row] *= digit_sum;
        }
        printf("%d ", products_of_digits[row]);
    }
}
