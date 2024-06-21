void well_ordered_digits()
{
    int numbers[15] = {};
    int numbers_length = sizeof(numbers) / sizeof(numbers[0]);
    int well_ordered_numbers_count = 0;
    for (int index = 0; index < numbers_length; index += 1)
    {
        int number = numbers[index];
        scanf("%d", &number);
        if (number <= 9)
        {
            printf("Please supply positive numbers with 2 or more digits!");
            exit(1);
        }
    }

    printf("Array content: ");
    for (int index = 0; index < numbers_length; index += 1)
    {
        printf("%d,", numbers[index]);
    }

    printf("\nWell-ordered number(s): ");
    for (int index = 0; index < numbers_length; index += 1)
    {
        int number = numbers[index];
        int is_ordered = 1;
        while (number > 0 && is_ordered)
        {
            int first_digit = number % 10;
            int second_digit = (number / 10) % 10;
            if (first_digit >= second_digit)
            {
                number /= 10;
            }
            else
            {
                is_ordered = 0;
            }
        }

        if (is_ordered)
        {
            well_ordered_numbers_count += 1;
            printf("%d,", numbers[index]);
        }
    }
    printf("\nWell-ordered number(s) count: %d", well_ordered_numbers_count);
}