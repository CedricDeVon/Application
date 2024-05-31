#include <iostream>

int main(void)
{
	int numbers[15] = {15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	for (int i = 0; i < 15; i++)
	{
		int minIndex = i;
		for (int j = i; j < 15; j++)
		{
			if (numbers[minIndex] > numbers[j])
			{
				minIndex = j;
			}
		}
		int temp = numbers[i];
		numbers[i] = numbers[minIndex];
		numbers[minIndex] = temp;
	}

	for (int i = 0; i < 15; i++)
	{
		std::cout << numbers[i] << " ";
	}
	std::cout << "\n";

	int exitCode = 0;
	std::cin >> exitCode;

	return 0;
}