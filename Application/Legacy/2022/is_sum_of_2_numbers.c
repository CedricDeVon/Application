
void is_sum_of_2_numbers(int final_iteration)
{
    for (int left_addend = 1; left_addend <= final_iteration / 2; left_addend += 1)
    {
        int right_addend;
        for (right_addend = final_iteration - 1; right_addend >= 1; right_addend -= 1)
        {
            if (left_addend + right_addend == final_iteration)
            {
                printf("%d = %d + %d     ", final_iteration, left_addend, right_addend);
                break;
            }
        }

        int is_left_addend_a_prime = 1;
        if (left_addend == 1)
        {
            is_left_addend_a_prime = 0;
        }
        for (int left_addend_factor = 2; left_addend_factor < left_addend &&
                                         is_left_addend_a_prime;
             left_addend_factor += 1)
        {
            if (left_addend % left_addend_factor == 0)
            {
                is_left_addend_a_prime = 0;
            }
        }
        int is_right_addend_a_prime = 1;
        if (right_addend == 1)
        {
            is_right_addend_a_prime = 0;
        }
        for (int right_addend_factor = 2; right_addend_factor < right_addend &&
                                          is_right_addend_a_prime;
             right_addend_factor += 1)
        {
            if (right_addend % right_addend_factor == 0)
            {
                is_right_addend_a_prime = 0;
            }
        }

        if (is_left_addend_a_prime && is_right_addend_a_prime)
        {
            printf("Both are prime numbers");
        }
        else if (!is_left_addend_a_prime && !is_right_addend_a_prime)
        {
            printf("Both are not prime numbers");
        }
        else if (is_left_addend_a_prime)
        {
            printf("%d is a prime number, but %d is not", left_addend, right_addend);
        }
        else if (is_right_addend_a_prime)
        {
            printf("%d is a prime number, but %d is not", right_addend, left_addend);
        }
        printf("\n");
    }
}
