
void is_sequence_arithmetic_or_geometric_or_neither()
{
    int sequence[7] = {1, 2, 4, 8, 16};
    int sequence_length = sizeof(sequence) / sizeof(int);
    int first_difference = sequence[1] - sequence[0];
    int is_not_a_sequence = 0;
    int is_arithmetic_sequence = 1;
    for (int index = 2; index < sequence_length; index += 1)
    {
        int current_difference = sequence[index] - sequence[index - 1];
        if (current_difference != first_difference && current_difference != first_difference * index)
        {
            is_not_a_sequence = 1;
            break;
        }
        else if (current_difference == first_difference)
        {
            is_arithmetic_sequence = 1;
        }
        else if (current_difference == first_difference * index)
        {
            is_arithmetic_sequence = 0;
        }
    }
    if (is_not_a_sequence == 1)
    {
        printf("Not a Seqence");
    }
    else if (is_arithmetic_sequence == 1)
    {
        printf("Arithmetic Sequence");
    }
    else if (is_arithmetic_sequence == 0)
    {
        printf("Geometric Sequence");
    }
}