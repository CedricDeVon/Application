
void _recursive_fizz_buzz(int current, int limit)
{
    if (current > limit)
    {
        return;
    }
    else if (current % 3 == 0 && current % 5 == 0)
    {
        printf("FizzBuzz");
    }
    else if (current % 3 == 0)
    {
        printf("Fizz");
    }
    else if (current % 5 == 0)
    {
        printf("Buzz");
    }
    else
    {
        printf("%d", current);
    }
    printf("\n");
    current += 1;
    _recursive_fizz_buzz(current, limit);
}

void recursive_fizz_buzz()
{
    _recursive_fizz_buzz(1, 100);
}
