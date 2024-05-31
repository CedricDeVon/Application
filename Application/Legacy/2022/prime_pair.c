
void handle_argument_validations(int even_number);

void prime_pair(int even_number)
{
    handle_argument_validations(even_number);

    int primes[100];
    for (int i = 1; i <= even_number; i += 1)
    {
        int is_prime = 0;
        for (int n = 1; n < i; n += 1)
        {
            if (n % i != 0)
            {
                printf("%d,", i);
            }
        }
        printf("\n");
    }
}

void handle_argument_validations(int even_number)
{
    if (even_number % 2 != 0)
    {
        printf("Error: Please supply an even number!");
        exit(1);
    }
}