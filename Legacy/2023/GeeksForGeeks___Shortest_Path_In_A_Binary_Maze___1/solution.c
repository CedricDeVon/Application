#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <windows.h>

#include "solution.h"

Matrix Matrix_allocate(int row_size, int column_size)
{
	Matrix matrix = (Matrix) malloc(sizeof(struct matrix));
	matrix->row_size = row_size;
	matrix->column_size = column_size;
	matrix->values = (int**) malloc(sizeof(int*) * row_size);
	for (int i = 0; i < column_size; i++)
	{
		matrix->values[i] = (int*) malloc(sizeof(int) * column_size);
	}

	return matrix;
}

Matrix Matrix_copy(Matrix matrix)
{
	Matrix copy = Matrix_allocate(matrix->row_size, matrix->column_size);
	for (int i = 0; i < matrix->row_size; i++)
	{
		for (int j = 0; j < matrix->column_size; j++)
		{
			copy->values[i][j] = matrix->values[i][j];
		}
	}

	return copy;
}

void Matrix_deallocate(Matrix matrix)
{
	for (int i = 0; i < matrix->row_size; i++)
	{
		free(matrix->values[i]);
		matrix->values[i] = NULL;
	}
	free(matrix->values);
	matrix->values = NULL;
	free(matrix);
	matrix = NULL;
}

Coordinate Coordinate_allocate()
{
	Coordinate coordinate = (Coordinate) malloc(sizeof(struct coordinate));
	coordinate->x = 0;
	coordinate->y = 0;

	return coordinate;
}

void Coordinate_deallocate(Coordinate coordinate)
{
	free(coordinate);
	coordinate = NULL;
}

int get_max(int values[4])
{
	int max = 0;
	for (int i = 0; i < 4; i++)
	{
		int value = values[i];
		if (max < value)
		{
			max = value;
		}
	}
	return max;
}

int solution(Matrix matrix, Matrix visited, int x, int y)
{
	if (x < 0 || y < 0 || x > matrix->row_size - 1 || y > matrix->column_size - 1 ||
		matrix->values[x][y] == 0 || visited->values[x][y] == 0)
	{
		return 0;
	}

	visited->values[x][y] = 0;
	int a = solution(matrix, visited, x - 1, y);
	int b = solution(matrix, visited, x + 1, y);
	int c = solution(matrix, visited, x, y - 1);
	int d = solution(matrix, visited, x, y + 1);
	
	int values[4] = {a, b, c, d};

	return get_max(values);
}