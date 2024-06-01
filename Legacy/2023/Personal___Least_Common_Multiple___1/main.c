#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>

/*
LCM(12,17) = (12 × 17) / GCF(12,17)
= (12 × 17) / 1
= 204 / 1
= 204
*/

int calculate_gcf(int a , int b)
{
	int c = 0;
	int d[a];
	for (int i = 1; i < a + 1; i++)
	{
		if (a % i == 0)
		{
			d[c] = i;
			c++;
		}
	}

	for (int i = c - 1; i > -1; i--)
	{
		int e = d[i];
		for (int j = 1; j < b + 1; j++)
		{
			if (e == j && b % j == 0)
			{
				return e;
			}
		}
	}

	return 1;
}

int calculate_lcm(int a, int b)
{
	return (a * b) / calculate_gcf(a, b);
}

int main(void)
{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);

	printf("LCM: %d", calculate_lcm(a, b));

	int exit_code = 0;
	scanf("%d", &exit_code);

	return 0;
}