#pragma once

std::vector<int> recursiveBubbleSort(std::vector<int> numbers);
std::vector<int> recursiveBubbleSort(std::vector<int> numbers, int rowIndex, int columnIndex);

std::vector<int> recursiveBubbleSort(std::vector<int> numbers)
{
	return recursiveBubbleSort(numbers, 0, 1);
}

std::vector<int> recursiveBubbleSort(std::vector<int> numbers, int rowIndex, int columnIndex)
{
	int rowNumber = numbers[rowIndex];
	int columnNumber = numbers[columnIndex];
	if (numbers[rowIndex] > numbers[columnIndex])
	{
		numbers[rowIndex] = columnNumber;
		numbers[columnIndex] = rowNumber;
	}

	if (rowIndex >= numbers.size() - 2)
	{
		return numbers;
	}

	if (columnIndex >= numbers.size() - 1)
	{
		rowIndex += 1;
		columnIndex = rowIndex + 1;
	}
	else
	{
		columnIndex += 1;
	}

	return recursiveBubbleSort(numbers, rowIndex, columnIndex);
}

/*
f(n, 0, 1)

f(n, 0, 2)

*/