
int highly_divisible_triangular_number(int divisor_count_limit, int limit)
{
    int sum = 0;
    int is_not_found = 1;
    for (int number = 1; number <= limit && is_not_found; number++)
    {
        int divisor_count = 0;
        for (int divisor = 1; divisor <= sum; divisor++)
        {
            if (sum % divisor == 0)
            {
                divisor_count += 1;
            }
        }

        if (divisor_count > divisor_count_limit)
        {
            is_not_found = 0;
        }
        else
        {
            sum += number;
        }
    }

    return sum;
}
