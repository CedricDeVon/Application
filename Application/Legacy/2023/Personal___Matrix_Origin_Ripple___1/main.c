#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <windows.h>

int main(void)
{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);

	int x = 0;
	int y = 0;
	scanf("%d %d", &x, &y);

	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			int c = abs(i - x);
			int d = abs(j - y);
			if (c == 0 && d == 0)
			{
				printf("0 ");
			}
			else
			{
				printf("%d ", (c > d) ? c : d);
			}
		}
		printf("\n");
	}
	printf("\n");

	int exit_code = 0;
	scanf("%d", &exit_code);
	return 0;
}

