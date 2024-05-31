
void square_generator()
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
            else if (column == 1 || column == max)
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
