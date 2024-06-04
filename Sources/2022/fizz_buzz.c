
void handle_argument_edge_cases(int limit);
int is_less_than(int first_number, int second_number);
int is_divisible_to_3_and_5(int number);
void print_fizz_buzz();
int is_divisible_to_3(int number);
void print_fizz();
int is_divisible_to_5(int number);
void print_buzz();
void print_integer(int integer);
void print_line_break();
int is_less_than_or_equal_to_0(int number);
void terminate_program_due_to_invalid_type_exception();

void fizz_buzz(int limit)
{
    handle_argument_edge_cases(limit);

    for (int iteration = 0; is_less_than(iteration, limit); iteration += 1)
    {
        if (is_divisible_to_3_and_5(iteration))
        {
            print_fizz_buzz();
        }
        else if (is_divisible_to_3(iteration))
        {
            print_fizz();
        }
        else if (is_divisible_to_5(iteration))
        {
            print_buzz();
        }
        else
        {
            print_integer(iteration);
        }
        print_line_break();
    }
}

void handle_argument_edge_cases(int limit)
{
    if (is_less_than_or_equal_to_0(limit))
    {
        terminate_program_due_to_invalid_type_exception();
    }
}

int is_less_than(int first_number, int second_number)
{
    return first_number < second_number;
}

int is_divisible_to_3_and_5(int number)
{
    return is_divisible_to_3(number) && is_divisible_to_5(number);
}

void print_fizz_buzz()
{
    printf("FizzBuzz");
}

int is_divisible_to_3(int number)
{
    return number % 3 == 0;
}

void print_fizz()
{
    printf("Fizz");
}

int is_divisible_to_5(int number)
{
    return number % 5 == 0;
}

void print_buzz()
{
    printf("Buzz");
}

void print_integer(int integer)
{
    printf("%d", integer);
}

void print_line_break()
{
    printf("\n");
}

int is_less_than_or_equal_to_0(int number)
{
    return number <= 0;
}

void terminate_program_due_to_invalid_type_exception()
{
    exit(1);
}
