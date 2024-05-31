#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <windows.h>
#include <ctype.h>

int main(void)
{
	int n = 0;
	scanf("%d", &n);
	int y = 0;
	int** matrix = (int**) malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++)
	{
		bool is_found = true;
		matrix[i] = (int*) malloc(sizeof(int) * n);
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &matrix[i][j]);
			if (matrix[i][j] != 0)
			{
				is_found = false;
			}
		}

		if (is_found)
		{
			y = i;
		}
	}

	bool is_found = true;
	for (int i = 0; i < n; i++)
	{
		if (i != y && matrix[i][y] != 1)
		{
			is_found = false;
			break;
		}
	}

	printf("%d\n", (is_found) ? (y + 1) : -1);

	int exit_code = 0;
	scanf("%d", &exit_code);

	return 0;
}
