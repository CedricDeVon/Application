
void horizontal_straight_zigzag_generator()
{
    int length = 5;
    int quantity = 10;
    for (int row = 1; row <= length; row++)
    {
        for (int column = 1; column <= quantity * 2; column++)
        {
            if ((row == 1 && column % 2 == 0 && column % 4 != 0) || (row == length && column % 4 == 0))
            {
                printf("- ");
            }
            else if ((row == 1 && column % 2 == 0) || (row == length && column % 2 == 0))
            {
                printf("  ");
            }
            else if (column % 2 == 0)
            {
                printf("  ");
            }
            else
            {
                printf("| ");
            }
        }
        printf("\n");
    }
}
