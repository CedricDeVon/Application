
int countEven(int array[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i += 1)
    {
        int number = array[i];
        if (number % 2 == 0)
        {
            sum += number;
        }
    }
    return sum;
}
