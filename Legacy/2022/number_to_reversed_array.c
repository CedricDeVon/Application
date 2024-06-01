
void number_to_reversed_array(int *numbers, int *pointer_number)
{
    int index = 0;
    int *pointer_index = &index;
    while (*pointer_number > 0)
    {
        *(numbers + *pointer_index) = *pointer_number % 10;
        *pointer_number /= 10;
        *pointer_index += 1;
    }
}
