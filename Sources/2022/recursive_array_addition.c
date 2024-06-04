

int _recursive_array_addition(int sum, int index, int length, int *numbers)
{
    if (index == length)
    {
        return sum;
    }

    sum += numbers[index];
    index += 1;
    return _recursive_array_addition(sum, index, length, numbers);
}

void recursive_array_addition()
{
    int numbers[3] = {1, 2, 3};
    int numbers_length = sizeof(numbers) / sizeof(numbers[0]);
    int sum = _recursive_array_addition(0, 0, numbers_length, numbers);
    printf("%d", sum);
}



