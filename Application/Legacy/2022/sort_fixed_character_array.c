
void sort_fixed_character_array()
{
    char unsorted_array[] = {'A', 'T', 'T', 'G', 'G', 'C', 'A', 'C', 'G'};
    char *sorted_array = (char *)calloc(9, sizeof(char));
    int character_counters[4] = {0, 0, 0, 0};
    for (int index = 0; index < 9; index += 1)
    {
        char current_character = unsorted_array[index];
        if (current_character == 'A')
        {
            character_counters[0] += 1;
        }
        else if (current_character == 'G')
        {
            character_counters[1] += 1;
        }
        else if (current_character == 'C')
        {
            character_counters[2] += 1;
        }
        else if (current_character == 'T')
        {
            character_counters[3] += 1;
        }
    }
    int index = 0;
    for (int current_character_index = 0; current_character_index < 4;
         current_character_index += 1)
    {
        int character_count = character_counters[current_character_index];
        for (int current_count = 0; current_count < character_count; current_count += 1)
        {
            char *sorted_array_item_address = sorted_array + index;
            if (current_character_index == 0)
            {
                *(sorted_array_item_address) = 'A';
            }
            else if (current_character_index == 1)
            {
                *(sorted_array_item_address) = 'G';
            }
            else if (current_character_index == 2)
            {
                *(sorted_array_item_address) = 'C';
            }
            else if (current_character_index == 3)
            {
                *(sorted_array_item_address) = 'T';
            }
            index += 1;
        }
    }

    printf("Unsorted Array Items: ");
    for (int current_index = 0; current_index < 9; current_index += 1)
    {
        printf("%c", unsorted_array[current_index]);
        if (current_index < 8)
        {
            printf(", ");
        }
    }
    printf("\n");
    printf("Sorted Array Items: ");
    for (int current_index = 0; current_index < 9; current_index += 1)
    {
        printf("%c", *(sorted_array + current_index));
        if (current_index < 8)
        {
            printf(", ");
        }
    }
    free(sorted_array);
}
