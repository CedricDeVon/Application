
int summation_of_primes(int limit)
{
    int sum = 0;
    for (int number = 2; number <= limit; number++)
    {
        int is_prime_found = 1;
        for (int factor = 2; factor < number && is_prime_found; factor++)
        {
            if (number % factor == 0)
            {
                is_prime_found = 0;
            }
        }

        if (is_prime_found)
        {
            sum += number;
        }
    }

    return sum;
}
