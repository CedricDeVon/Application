#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int main(void)
{
	int n = 0;
	scanf("%d", &n);
	int s = 2 * (n - 1) + 1;
	int f = n - 1;
	int e = n - 1;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < s; j++)
		{
			if (j >= f && j <= e)
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
		f -= 1;
		e += 1;
	}
	for (int i = 0; i < s; i++)
	{
		printf("*");
	}
	printf("\n");
	f = 1;
	e = s - 2;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < s; j++)
		{
			if (j >= f && j <= e)
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
		f += 1;
		e -= 1;
	}

	int exit_code = 0;
	scanf("%d", &exit_code);

	return 0;
}

