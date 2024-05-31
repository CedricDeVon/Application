
void isCuriousNumber(int number)
{
    int sum = 0;
    int digits = number;
    while (digits > 0)
    {
        int product = 1;
        int digit = digits % 10;
        while (digit >= 1)
        {
            product *= digit;
            digit -= 1;
        }

        sum += product;
        digits /= 10;
    }

    if (sum == number)
    {
        std::cout << "True";
    }
    else
    {
        std::cout << "False";
    }
}