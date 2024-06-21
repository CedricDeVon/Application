
void reverse_integer_array()
{
    int original_array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int original_array_length = sizeof(original_array) / sizeof(int);
    int reversed_array[10] = {};
    for (int index = 0; index < original_array_length; index += 1)
    {
        reversed_array[index] = original_array[original_array_length - index - 1];
        printf("%d, ", reversed_array[index]);
    }
}
