
void sum_of_reverse_numbers()
{
    int r = 0, t = 0, s = 0;
    int arr[8] = {1878, 16302, 77500, 329, 79777, 10, 1649, 59955};
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i += 1)
    {
        t = 0;
        for (int num = arr[i]; num != 0; num /= 10)
        {
            r = num % 10;
            t = (t * 10) + r;
        }
        s += t;
    }
    printf("%d", s);
}
