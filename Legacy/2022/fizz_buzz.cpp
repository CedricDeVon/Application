
void fizz_buzz(int *start, int *end)
{
    if (*start <= 0 || *end <= 0 || *start >= *end)
    {
        printf("Error: 'start' must be lesser than 'end' and both must be greater than 0");
        exit(-1);
    }

    int *h_start = (int*) malloc(sizeof(int));
    int *h_end = (int*) malloc(sizeof(int)); 
    *h_start = *start;
    *h_end = *end;

    while (*h_start <= *h_end)
    {
        if (*h_start % 3 == 0 && *h_start % 5 == 0)
        {
            cout << "FizzBuzz" << endl;
        }
        else if (*h_start % 3 == 0)
        {
            cout << "Fizz" << endl;
        }
        else if (*h_start % 5 == 0)
        {
            cout << "Buzz" << endl;
        }
        else
        {
            cout << *h_start << endl;
        }

        *h_start += 1;
    }

    free(h_start);
    free(h_end);
}

