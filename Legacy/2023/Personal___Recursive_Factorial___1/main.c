#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <windows.h>
#include <limits.h>

int recursive_fibonacci(int n)
{
	/*
	Possible Edge Cases:
	n is less than 0
	n is 0
	n is 1
	n is 2
	n is 5
	n is 10
	n is 1000
	n is equal to INT_MAX
	*/

	if (n < 2)
	{
		return n;
	}

	return recursive_fibonacci(n - 1) + recursive_fibonacci(n - 2);
}

int main(void)
{
	int n = INT_MAX;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		printf("%d ", recursive_fibonacci(i));
	}
	printf("\n");

	int exit_code = 0;
	scanf("%d", &exit_code);
	return 0;
}

