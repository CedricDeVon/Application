
void solution_of_pointer_quiz_part_one()
{
    int c = 0;
    int n = 10;
    int m = n / 3;
    short int *p = (short int *)calloc(n, sizeof(short int));
    for (int i = 0; i < n; i += 1)
    {
        c += m + i;
        *p = c;
        printf("%p:", p);
        printf("%d,", *p);
        p += 1;
    }
}
