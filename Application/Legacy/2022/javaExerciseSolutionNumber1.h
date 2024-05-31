#pragma once

using namespace std;

void print5ColumnsOfPrimeNumbersFrom1To100()
{
	int count = 0;
	for (int i = 2; i <= 100; i += 1)
	{
		bool isPrime = true;
		for (int j = 2; j < i; j += 1)
		{
			if (i % j == 0)
			{
				isPrime = false;
			}
		}
		if (isPrime)
		{
			cout << i << " ";
			count += 1;
		}

		if (count >= 5)
		{
			cout << "\n";
			count = 0;
		}
	}
}
