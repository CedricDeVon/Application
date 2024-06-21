
void perfect_number(int number)
{
    if (number < 1 || number > pow(10, 8))
    {
        return;
    }

    int sum = 0;
    for (int divisor = number - 1; divisor >= 1; divisor--)
    {
        if (number % divisor == 0)
        {
            sum += divisor;
        }
    }

    if (sum == number)
    {
        printf("true");
    }
    else
    {
        printf("false");
    }
}