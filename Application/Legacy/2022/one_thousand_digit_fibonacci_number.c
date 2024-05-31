
void one_thousand_digit_fibonacci_number()
{
    // In Progress
    unsigned long long int one = 0;
    unsigned long long int two = 1;
    unsigned long long int save = 1;
    for (int i = 1; i <= 100; i++)
    {
        printf("Term: %d, Value: %lli \n", i, two);
        two += one;
        one = save;
        save = two;
    }
}