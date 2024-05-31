
int consecutive_prime_sum(int limit)
{
    int sums[1000] = {};
    int terms = 0;
    int last_prime = 0;
    for (int number = 2; number < limit; number++)
    {
        int is_prime = 1;
        for (int divisor = 2; divisor < number && is_prime; divisor++)
        {
            if (number % divisor == 0)
            {
                is_prime = 0;
            }
        }

        if (is_prime)
        {
            sums[terms] = number;
            terms += 1;
        }
    }

    int sum = 0;
    int answer = 0;
    int max_reached = 1;
    for (int index = 0; index < terms && max_reached; index++)
    {
        int is_prime = 1;
        for (int divisor = 2; divisor < sum && is_prime; divisor++)
        {
            if (sum % divisor == 0)
            {
                is_prime = 0;
            }
        }

        if (is_prime && sum < limit)
        {
            answer = sum;
        }
        else if (sum >= limit)
        {
            max_reached = 0;
        }

        sum += sums[index];
    }

    return answer;
}
