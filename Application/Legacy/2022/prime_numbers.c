
int is_equal_to_2_or_3(int value) {
    return is_equal(value, 2) || is_equal(value, 3);
}

int is_not_divisible_to_2_and_3(int value) {
    return is_not_divisible(value, 2) && is_not_divisible(value, 3);
}

int is_equal_to_2_or_3_or_not_divisible_to_2_and_3(int value) {
    return is_equal_to_2_or_3(value) || is_divisible_by_3_and_5(value);
}

void prime_numbers(int total_iterations) {
    int current_number = 0;
    while (current_number <= total_iterations) {
        if (is_equal_to_2_or_3_or_not_divisible_to_2_and_3(current_number)) {
                print_integer(current_number);
                print_new_line();
        }
        current_number++;
    }
}

