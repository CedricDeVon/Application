#pragma once

int binarySearch(int numbers[], int size, int targetNumber)
{
    return binarySearch(numbers, size, targetNumber, 0, size / 2, size);
}

int binarySearch(int numbers[], int size, int targetNumber, int startingIndex, int middleIndex, int endingIndex)
{
    int currentNumber = numbers[middleIndex];
    if ((middleIndex <= 0 && targetNumber != currentNumber) ||
        (middleIndex >= size - 1 && targetNumber != currentNumber))
    {
        return -1;
    }
    else if (targetNumber > currentNumber)
    {
        return binarySearch(numbers, size, targetNumber, middleIndex, (endingIndex + middleIndex) / 2, endingIndex);
    }
    else if (targetNumber < currentNumber)
    {
        return binarySearch(numbers, size, targetNumber, startingIndex, (middleIndex + startingIndex) / 2, middleIndex);    
    }
    else
    {
        return middleIndex;     
    }
}

