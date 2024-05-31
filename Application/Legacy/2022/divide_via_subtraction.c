
int divide_via_subtraction(int numerator, int denominator);

int divide_via_subtraction(int numerator, int denominator)
{
    if (numerator < 0 || denominator < 0 || numerator < denominator)
    {
        printf("Error: Invalid arguments");
        exit(-1);
    }

    if (numerator == 0 || denominator == 0)
    {
        return 0;
    }

    int quotient = 0;
    while (numerator >= 0)
    {
        quotient += 1;
        numerator -= denominator;
    }
    return quotient;
}
