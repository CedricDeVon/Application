#pragma once

unsigned int recursiveDigitSum(int number);
unsigned int recursiveDigitSum(int number, unsigned int sum);

unsigned int recursiveDigitSum(int number)
{
	return recursiveDigitSum(
			(number < 0) ? -(number) : number, 0
		);
}

unsigned int recursiveDigitSum(int number, unsigned int sum)
{
	return (number > 0) ?
		recursiveDigitSum(
			number / 10,
			(number % 10) + sum
		) : sum;
}
