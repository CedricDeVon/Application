
int _recursive_factorial(int number, int current) {
    if (current == 1) {
        return number;
    }
    
    number *= current;
    return _recursive_factorial(number, current - 1);
}

int recursive_factorial(int number) {
    return _recursive_factorial(number, number - 1);
}

