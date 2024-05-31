
void even_odd_transform(int *numbers,
                        int *pointer_size,
                        int *pointer_maximum_iteration)
{
    int index = 0;
    int *pointer_index = &index;
    for (; *pointer_index < *pointer_size;
         *pointer_index += 1)
    {
        int current_iteration = 0;
        int *pointer_current_iteration = &current_iteration;
        for (; *pointer_current_iteration < *pointer_maximum_iteration;
             *pointer_current_iteration += 1)
        {
            int number = *(numbers + *pointer_index);
            int *pointer_number = &number;
            if (*pointer_number % 2 == 0)
            {
                *(numbers + *pointer_index) = number - 2;
            }
            else
            {
                *(numbers + *pointer_index) = number + 2;
            }
        }
    }
}
