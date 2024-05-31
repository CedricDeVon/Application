
int pentagon_numbers(int limit)
{
    int sum = 0;
    for (int number = 1; number <= limit; number++)
    {
        sum += number * (3 * number - 1) / 2;
    }

    return sum;
}
