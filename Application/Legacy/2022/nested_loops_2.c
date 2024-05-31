
void nested_loops_2()
{

    int numbers[5][5] = {};
    for (int row = 0; row < 5; row++)
    {
        for (int column = 0; column < 5; column++)
        {
            if (column <= row)
            {
                numbers[row][column] = (row + 1) * (column + 1);
            }
            else
            {
                numbers[row][column] = 0;
            }
        }
    }

    for (int row = 0; row < 5; row++)
    {
        for (int column = 0; column < 5; column++)
        {
            printf("%d, ", numbers[row][column]);
        }
        printf("\n");
    }
}
