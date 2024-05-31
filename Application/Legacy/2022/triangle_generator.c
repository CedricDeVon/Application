
void triangle_generator()
{
    int size = 20;
    int first_pointer = size / 2;
    int last_pointer = first_pointer + 1;
    for (int row = 1; row <= size / 2; row++)
    {
        for (int column = 1; column <= size; column++)
        {
            if (column == first_pointer)
            {
                printf("/");
            }
            else if (column == last_pointer)
            {
                printf("\\");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");

        if (first_pointer >= 1 && last_pointer < size)
        {
            first_pointer -= 1;
            last_pointer += 1;
        }
        else
        {
            for (int row = 1; row <= size; row++)
            {
                printf("=");
            }
        }
    }
}
