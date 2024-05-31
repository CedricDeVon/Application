
void sort_integer_array(int *pointer_integer_array, int size)
{
    for (int i = 0; i < size; i += 1)
    {
        int *integer_array_item_i_address = pointer_integer_array + i;
        for (int j = i + 1; j < size; j += 1)
        {
            int *integer_array_item_j_address = pointer_integer_array + j;
            if (*(integer_array_item_i_address) > *(integer_array_item_j_address))
            {
                *(integer_array_item_i_address) = *(integer_array_item_i_address) + *(integer_array_item_j_address);
                *(integer_array_item_j_address) = *(integer_array_item_i_address) - *(integer_array_item_j_address);
                *(integer_array_item_i_address) = *(integer_array_item_i_address) - *(integer_array_item_j_address);
            }
        }
    }
}