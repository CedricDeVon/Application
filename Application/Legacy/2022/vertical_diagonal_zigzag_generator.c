
void vertical_diagonal_zigzag_generator()
{
    int quantity = 3;
    int length = 5;
    int pointer = 1;
    int direction = 1;
    for (int row = 1; row <= quantity * length; row++)   
    {
        for (int column = 1; column <= length; column++)
        {
            if (column == pointer && direction)
            {
                printf("\\");
            }
            else if (column == pointer && !direction)
            {
                printf("/");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");

        if (direction && pointer == length)
        {
            direction = 0;
            pointer += 1;
        }
        else if (!direction && pointer == 1)
        {
            direction = 1;
            pointer -= 1;
        }
        if (direction)
        {
            pointer += 1;
        }
        else
        {
            pointer -= 1;
        }
    }
}
