#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>

void grassfire(int** matrix, int row_size, int column_size, int x, int y, int n)
{
	if (x < 0 || x > (row_size - 1) || y < 0 || y > (column_size - 1) || matrix[x][y] != 0)
	{
		return;
	}

	matrix[x][y] = n;
	grassfire(matrix, row_size, column_size, x - 1, y, n + 2);
	grassfire(matrix, row_size, column_size, x + 1, y, n + 2);
	grassfire(matrix, row_size, column_size, x, y - 1, n + 2);
	grassfire(matrix, row_size, column_size, x, y + 1, n + 2);
}

int main(void)
{
	int row_size = 0;
	int column_size = 0;
	scanf("%d %d", &row_size, &column_size);

	int target_x = 0;
	int target_y = 0;
	scanf("%d %d", &target_x, &target_y);

	int** matrix = (int**) malloc(sizeof(int) * row_size);
	for (int i = 0; i < row_size; i++)
	{
		matrix[i] = (int*) malloc(sizeof(int) * column_size);
	}

	for (int i = 0; i < row_size; i++)
	{
		for (int j = 0; j < column_size; j++)
		{
			matrix[i][j] = 0;
		}
	}

	grassfire(matrix, row_size, column_size, target_x, target_y, 1);

	for (int i = 0; i < row_size; i++)
	{
		for (int j = 0; j < column_size; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	int exit_code = 0;
	scanf("%d", &exit_code);
	return 0;
}
