#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <windows.h>

#include "pascals_triangle.h"

int get_factorial(int n)
{
	int a = 1;
	for (; n > 1; n--)
	{
		a *= n;
	}
	return a;
}

int get_combinations(int n, int r)
{
	return get_factorial(n) / (get_factorial(r) * get_factorial(n - r));
}

void display_pascals_triangle(int row_count)
{
	for (int i = 0; i < row_count; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			printf("%d ", get_combinations(i, j));
		}
		printf("\n");
	}
}
