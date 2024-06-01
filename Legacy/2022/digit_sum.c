
void get_digit_sum()
{
    int sum = 0;
    int number = 101;
    while (number != 0)
    {
        sum += number % 10;
        number = number / 10;
    }
    printf("%d", sum);
}
