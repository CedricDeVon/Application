
int pascals_triangle_generator(int maximum_depth);

int pascals_triangle_generator(int maximum_depth)
{
    if (maximum_depth < 0)
    {
        printf("Error: maximum_depth argument must be more than 0!");
        exit(-1);
    }

    for (int current_depth = 0; current_depth <= maximum_depth; current_depth += 1)
    {
        int previous_coefficient = 1;
        int term_rank = 0;
        printf("%d ", 1);
        for (int current_term = current_depth; current_term > 0; current_term -= 1)
        {
            int current_coefficient = (previous_coefficient * current_term) / (term_rank + 1);
            printf("%d ", current_coefficient);
            previous_coefficient = current_coefficient;
            term_rank += 1;
        }
        printf("\n");
    }
}