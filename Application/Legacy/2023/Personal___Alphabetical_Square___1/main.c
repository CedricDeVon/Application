#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(void)
{
	int row_size = 0;
	int column_size = 0;
	scanf("%d %d", &row_size, &column_size);

	int c = 0;
	for (int i = 0; i < row_size; i++)
	{
		for (int j = 0; j < column_size; j++)
		{
			printf("%c", 'A' + c);
			c = ++c % 26;
		}
		printf("\n");
	}

	int exit_code = 0;
	scanf("%d", &exit_code);
	
	return 0;
}
