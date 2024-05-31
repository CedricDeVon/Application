
int iterative_factorial(int number) {
    int sum = 1;
    while (is_greater_than(number, 1)) {
        sum *= number;
        number--;
    }
    return sum;
}
