
void multiples_of_3_and_5(int limit)
{
    int sum = 0;
    for (int index = 1; index < limit; index++)
    {
        if (index % 3 == 0 || index % 5 == 0)
        {
            sum += index;
        }
    }

    return sum;
}
