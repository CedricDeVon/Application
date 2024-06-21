
void diamond_generator()
{
    int max = 6;
    int left_pointer = max / 2;
    int right_pointer = left_pointer + 1;
    int is_going_down = 0;
    for (int row = 1; row <= max; row++)
    {
        for (int column = 1; column <= max && !is_going_down; column++)
        {
            if (column == left_pointer)
            {
                printf("/");
            }
            else if (column == right_pointer)
            {
                printf("\\");
            }
            else
            {
                printf(" ");
            }
        }

        for (int column = 1; column <= max && is_going_down; column++)
        {
            if (column == left_pointer)
            {
                printf("\\");
            }
            else if (column == right_pointer)
            {
                printf("/");
            }
            else
            {
                printf(" ");
            }
        }

        if (is_going_down)
        {
            left_pointer += 1;
            right_pointer -= 1;
        }
        else if (left_pointer == 1 && right_pointer == max)
        {
            is_going_down = 1;
        }

        if (left_pointer > 0 && !is_going_down)
        {
            left_pointer -= 1;
        }

        if (right_pointer < max && !is_going_down)
        {
            right_pointer += 1;
        }

        printf("\n");
    }
}
