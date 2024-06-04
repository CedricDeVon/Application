
void nested_loops_1()
{
    int n = 5;
    int i = 1;
    int j = 0;
    int k = 1;
    for (i = 1; i <= n; i++)
    {
        for (j = 0; j < i; j++)
        {
            printf("%d ", k);
            k++;
        }
        printf("\n");
    }
}