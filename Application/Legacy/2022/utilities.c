int is_less_than_or_equal(int value_1, int value_2) {
    return value_1 <= value_2;
}

int is_greater_than(int value_1, int value_2) {
    return value_1 > value_2;
}

int is_equal(int value_1, int value_2) {
    return value_1 == value_2;
}

int is_divisible(int value_1, int value_2) {
    return value_1 % value_2 == 0;
}

int is_not_divisible(int value_1, int value_2) {
    return !is_divisible(value_1, value_2);
}

int is_divisible_by_3(int value) {
    return value % 3 == 0;
}

int is_divisible_by_5(int value) {
    return value % 5 == 0;
}

int is_divisible_by_3_and_5(int value) {
    return is_divisible_by_3(value) && is_divisible_by_5(value);
}

void print_integer(int value) {
    printf("%i", value);
}

void print_float(float value) {
    printf("%f", value);
}

void print_new_line() {
    printf("\n");
}

