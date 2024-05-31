
void findTheLargestCollatzSequenceSumAndNumber()
{
    int maxSum = 0;
    int maxNumber = 0;
    for (int i = 10; i <= 1000; i += 1)
    {
        int n = i;
        int sum = i;
        while (n > 1)
        {
            n = (n % 2 == 0) ? n / 2 : (3 * n) + 1;
            sum += n;
        }

        if (maxSum < sum)
        {
            maxSum = sum;
            maxNumber = i;
        }
    }

    std::cout << maxNumber << '\n';
    std::cout << maxSum << '\n';     
}
