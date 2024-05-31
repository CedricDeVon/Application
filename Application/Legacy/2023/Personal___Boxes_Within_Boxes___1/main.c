#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

int main(void)
{
	int n = 0;
	scanf("%d", &n);

	int s = 0;
	int e = n - 1;
	int a = n / 2;
	bool fill = true;
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (fill && j >= s && j <= e)
			{
				printf("* ");
			}
			else if (j % 2 == 0 && (j <= s || j >= e))
			{
				printf("* ");
			}
			else
			{
				printf("  ");
			}
		}
		printf("\n");
		if (fill)
		{
			fill = false;
		}
		else
		{
			fill = true;
			s += 2;
			e -= 2;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
		{
			printf("* ");
		}
		else
		{
			printf("  ");
		}
	}
	printf("\n");
	s -= 2;
	e += 2;
	fill = false;
	for (int i = a; i > -1; i--)
	{
		for (int j = 0; j < n; j++)
		{
			if (fill && j >= s && j <= e)
			{
				printf("* ");
			}
			else if (j % 2 == 0 && (j <= s || j >= e))
			{
				printf("* ");
			}
			else
			{
				printf("  ");
			}
		}
		printf("\n");
		if (fill)
		{
			fill = false;
			s -= 2;
			e += 2;
		}
		else
		{
			fill = true;
		}
	}

	int exit_code;
	scanf("%d", &exit_code);
	

	return 0;
}


/*

1
x

2
x x
x x

3
x x x
x   x
x x x

4
x x x x
x     x
x     x
x x x x

5
x x x x x
x       x
x   x   x
x       x
x x x x x

6
x x x x x x
x         x
x   x x   x
x   x x   x
x         x
x x x x x x

7
x x x x x x x
x           x
x   x x x   x
x   x   x   x
x   x x x   x
x           x
x x x x x x x

9
x x x x x x x x x
x               x
x   x x x x x   x
x   x       x   x
x   x   x   x   x
x   x       x   x
x   x x x x x   x
x               x
x x x x x x x x x

*/