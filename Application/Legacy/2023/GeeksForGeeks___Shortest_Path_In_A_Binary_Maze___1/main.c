#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <windows.h>

#include "solution.h"

int main(void)
{
	int row_size = 0;
	int column_size = 0;
	printf("Matrix Dimensions: \n");
	scanf("%d %d", &row_size, &column_size);

	Matrix matrix = Matrix_allocate(row_size, column_size);
	printf("Matrix: \n");
	for (int i = 0; i < row_size; i++)
	{
		for (int j = 0; j < column_size; j++)
		{
			scanf("%d", &matrix->values[i][j]);
		}
	}
	
	Coordinate origin = Coordinate_allocate();
	printf("Origin: \n");
	scanf("%d %d", &origin->x, &origin->y);

	Matrix visited = Matrix_copy(matrix);
	printf("Distance: %d\n", solution(matrix, visited, origin->x, origin->y));

	Matrix_deallocate(matrix);
	Matrix_deallocate(visited);
	Coordinate_deallocate(origin);
	int exit_code = 0;
	scanf("%d", &exit_code);

	return 0;
}
