
int _is_true(int value);
int _is_ratio_not_equal(int *numbers, int index);
int _is_validation_unfinished(int first_value, int second_value, int third_value);
int _is_less_than(int first_number, int second_number);
int _is_less_than_3(int value);
float _is_not_equal(float first_value, float second_value);
double _divide_floats(float first_number, float second_number);
void _terminate_program();
void _print_true_on_the_console();
void _print_false_on_the_console();
void _print_message_on_the_console(char message[]);
void _handle_console_print_statements(int value);
void _handle_parameter_edge_cases(int length);

void is_geometric_sequence(int *numbers, int length)
{
    _handle_parameter_edge_cases(length);

    int is_ratio_consistent = 1;
    for (int index = 2; _is_validation_unfinished(index, length, is_ratio_consistent); index += 1)
    {
        if (_is_ratio_not_equal(numbers, index))
        {
            is_ratio_consistent = 0;
        }
    }

    _handle_console_print_statements(is_ratio_consistent);
}

void _handle_parameter_edge_cases(int length)
{
    if (_is_less_than_3(length))
    {
        _terminate_program();
    }
}

int _is_ratio_not_equal(int *numbers, int index)
{
    float base_ratio = _divide_floats(numbers[1], numbers[0]);
    float current_ratio = _divide_floats(numbers[index], numbers[index - 1]);
    return _is_not_equal(base_ratio, current_ratio);
}

void _handle_console_print_statements(int value)
{
    if (_is_true(value))
    {
        _print_true_on_the_console();
    }
    else
    {
        _print_false_on_the_console();
    }
}

int _is_validation_unfinished(int first_value, int second_value, int third_value)
{
    return _is_less_than(first_value, second_value) && _is_true(third_value);
}

int _is_less_than(int first_number, int second_number)
{
    return first_number < second_number;
}

int _is_true(int value)
{
    return value == 1;
}

double _divide_floats(float first_number, float second_number)
{
    return (double)first_number / second_number;
}

float _is_not_equal(float first_value, float second_value)
{
    return first_value != second_value;
}


int _is_less_than_3(int value)
{
    return _is_less_than(value, 3);
}

void _terminate_program()
{
    exit(1);
}

void _print_true_on_the_console()
{
    _print_message_on_the_console("True");
}

void _print_false_on_the_console()
{
    _print_message_on_the_console("False");
}

void _print_message_on_the_console(char message[])
{
    printf("%s", message);
}
