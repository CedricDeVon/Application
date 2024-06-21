
void collatz_conjecture()
{
    int start = 31;
    int current = start;
    int end = 700;
    int total_cycles = 0;
    int largest_cycles = 0;
    int largest_conjecture = 0;
    while (current <= end)
    {
        int number = current;
        int current_count = 0;
        while (number != 1)
        {
            if (number % 2 == 0)
            {
                number = number / 2;
            }
            else
            {
                number = number * 3 + 1;
            }

            printf("%d,", number);

            current_count += 1;
            total_cycles += 1;
        }
        
        printf("\n");
        printf("The number of cycles for %d is %d \n", current, current_count);
        printf("-------------------- \n");

        if (current_count > largest_cycles)
        {
            largest_cycles = current_count;
            largest_conjecture = current;
        }
        
        current += 1;
    }

    printf("Start: %d \n", start);
    printf("End: %d \n", end);
    printf("Largest conjecture: %d \n", largest_conjecture);
    printf("Largest number of cycles: %d \n", largest_cycles);
    printf("Total cycles: %d \n", total_cycles);
}
