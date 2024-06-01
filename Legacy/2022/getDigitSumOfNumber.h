#pragma once

int getDigitSumOfNumber(int number)
{
	if (number < 0)
	{
		exit(1);
	}

	int sum = 0;
	while (number > 0)
	{
		sum += number % 10;
		number /= 10;
	}
	return sum;
}

