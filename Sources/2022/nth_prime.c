
void nth_prime(int distance, int limit)
{
    int is_nth_prime_not_found = 1;
    int place = 0;
    int prime = 0;
    for (int number = 2; number < limit && is_nth_prime_not_found; number++)
    {
        int is_prime = 1;
        for (int factor = 2; factor < number && is_prime; factor++)
        {
            if (number % factor == 0)
            {
                is_prime = 0;
            }
        }

        if (is_prime && place == distance)
        {
            printf("\nThe %dth prime number is: %d", distance, prime);

            is_nth_prime_not_found = 0;
        }
        else if (is_prime)
        {
            place += 1;
            prime = number;

            printf("%d, ", prime);
        }
    }
}
