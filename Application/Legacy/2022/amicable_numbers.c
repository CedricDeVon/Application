
void amicable_numbers(int last_number)
{
    int sum = 0;
    for (int current_number = 1; current_number <= last_number; current_number++)
    {
        int first_total = 0;
        for (int factor = 1; factor < current_number; factor++)
        {
            if (current_number % factor == 0)
            {
                first_total += factor;
            }
        }

        int second_total = 0;
        for (int k = 1; k < first_total; k++)
        {
            if (first_total % k == 0)
            {
                second_total += k;
            }
        }
        
        if (current_number == second_total)
        {
            sum += current_number;
        }
    }

    printf("%d", sum);
}
