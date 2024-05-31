
void twin_square_generator()
{
    int max = 10;
    for (int row = 1; row <= max; row++)
    {
        for (int column = 1; column <= max; column++)
        {
            if (row == 1 || row == max)
            {
                printf("-");
            }
            else if ((row == 2 && column > 1 && column < max) || (row == max - 1 && column > 1 && column < max))
            {
                printf("-");
            }
            else if (column == 1 || column == max || column == 2 || column == max - 1)
            {
                printf("|");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}


