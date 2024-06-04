#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



int main(void)
{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);

	int c = (a < b) ? a : b;
	while (true)
	{
		if (c % a == 0 && c % b == 0)
		{
			printf("%d\n", c);
			break;
		}
		c++;
	}

	c = (a < b) ? a : b;
	while (c > 1)
	{
		if (a % c == 0 && b % c == 0)
		{
			break;
		}
		c--;
	}
	printf("%d\n", c);

	int exit_code = 0;
	scanf("%d", &exit_code);

	return 0;
}