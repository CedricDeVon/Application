#ifndef SOLUTION_H
#define SOLUTION_H

typedef struct matrix
{
	int row_size;
	int column_size;
	int** values;	

} *Matrix;

typedef struct coordinate
{
	int x;
	int y;

} *Coordinate;

Matrix Matrix_allocate(int row_size, int column_size);
Matrix Matrix_copy(Matrix matrix);
void Matrix_deallocate(Matrix matrix);
Coordinate Coordinate_allocate();
void Coordinate_deallocate(Coordinate coordinate);
int get_max(int values[4]);
int solution(Matrix matrix, Matrix visited, int x, int y);

#endif