
void vertical_straight_zigzag_generator()
{
    int max_row = 10;
    int max_column = 10;
    int direction = 1;
    for (int row = 1; row <= max_row; row++)
    {
        for (int column = 1; column <= max_column; column++)
        {
            printf("- ");
        }
        printf("\n");

        for (int column = 1; column <= max_column; column++)
        {
            if (column == direction)
            {
                printf("| ");
            }
            else
            {
                printf("  ");
            }
        }
        if (direction == 1)
        {
            direction = max_column;
        }
        else if (direction == max_column)
        {
            direction = 1;
        }
        printf("\n");
    }
}
