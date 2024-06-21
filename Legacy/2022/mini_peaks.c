
void mini_peaks()
{
    // Mini Peaks
    // Write a function that returns all the elements in an array that are strictly greater than their adjacent left and right neighbors.

    // Examples
    // miniPeaks([4, 5, 2, 1, 4, 9, 7, 2]) ➞ [5, 9]
    // 5 has neighbours 4 and 2, both are less than 5.

    // miniPeaks([1, 2, 1, 1, 3, 2, 5, 4, 4]) ➞ [2, 3, 5]

    // miniPeaks([1, 2, 3, 4, 5, 6]) ➞ []
    // Notes
    // Do not count boundary numbers, since they only have one left/right neighbor.
    // If no such numbers exist, return an empty array.

    int numbers[] = {4, 5, 2, 7, 9, 1};
    int numbers_length = sizeof(numbers) / sizeof(numbers[0]);
    for (int index = 2; index < numbers_length; index++)
    {
        int last_number = numbers[index - 2];
        int middle_number = numbers[index - 1];
        int first_number = numbers[index];
        if (last_number < middle_number && middle_number > first_number)
        {
            printf("%d \n", middle_number);
        }
    }
}

