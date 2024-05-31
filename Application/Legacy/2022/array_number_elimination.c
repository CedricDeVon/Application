
void array_number_elimination()
{
    int numbers[6] = {1, 2, 3, -1, 4, 5};
    int targets[2] = {1, -1};
    int numbers_length = sizeof(numbers) / sizeof(numbers[0]);
    int targets_length = sizeof(targets) / sizeof(targets[0]);
    for (int numbers_index = 0; numbers_index < numbers_length; numbers_index += 1)
    {
        int number = numbers[numbers_index];
        for (int targets_index = 0; targets_index < targets_length; targets_index += 1)
        {
            int is_not_found = 1;
            int target_number = targets[targets_index];
            if (number == target_number && is_not_found)
            {
                numbers[numbers_index] = 0;
                is_not_found = 1;
            }
        }
        printf("%d ", numbers[numbers_index]);
    }
}
