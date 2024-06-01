
void reverse_array(int array[], int size);

void reverse_array(int array[], int size)
{
    int temporary = 0;
    int middle_index = 0;
    if (size % 2 == 0)
    {
        middle_index = size / 2 - 1;
    }
    else
    {
        middle_index = size / 2;
    }

    for (int index = 0; index <= middle_index; index += 1)
    {
        temporary = array[size - index - 1];
        array[size - index - 1] = array[index];
        array[index] = temporary;
    }
}
