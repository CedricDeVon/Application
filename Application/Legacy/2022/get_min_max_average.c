#include <stdio.h>

int getMax(int numbers[], int size);
int getMin(int numbres[], int size);
float getMinMaxAverage(int numbers[], int size);

int main(int argc, char *argv[])
{
    int numbers[10] = {4, 2, 45, 33, 32, 78, 64, 11, 32, 1};
    int numbers_length = sizeof(numbers) / sizeof(numbers[0]);
    int min = getMin(numbers, numbers_length);
    int max = getMax(numbers, numbers_length);
    float min_max_average = getMinMaxAverage(numbers, numbers_length);

    printf("Min: %d \n", min);
    printf("Max: %d \n", max);
    printf("Min-Max Average: %.2f \n", min_max_average);

    return 0;
}

int getMin(int numbers[], int size)
{
    int min = numbers[0];
    for (int index = 1; index < size; index += 1)
    {
        int number = numbers[index];
        if (number < min)
        {
            min = number;
        }
    }
    return min;
}

int getMax(int numbers[], int size)
{
    int max = numbers[0];
    for (int index = 1; index < size; index += 1)
    {
        int number = numbers[index];
        if (number > max)
        {
            max = number;
        }
    }
    return max;
}

float getMinMaxAverage(int numbers[], int size)
{
    int min = getMin(numbers, size);
    int max = getMax(numbers, size);
    return (float) (min + max) / 2;
}
