#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <windows.h>

void display_matrix(char** matrix, int matrix_x_size, int matrix_y_size)
{
	printf("|");
	for (int row_index = 0; row_index < matrix_y_size; row_index++)
	{
		printf("---");
		if (row_index < matrix_y_size - 1)
		{
			printf("|");
		}
	}
	printf("|\n");
	for (int row_index = 0; row_index < matrix_x_size; row_index++)
	{
		printf("|");
		for (int column_index = 0; column_index < matrix_y_size; column_index++)
		{
			char current_character = matrix[row_index][column_index];
			if (current_character == 'A')
			{
				printf(" \x1b[32;40m%c\x1b[0m ", current_character);
			}
			else if (current_character == 'B')
			{
				printf(" \x1b[31;40m%c\x1b[0m ", current_character);
			}
			else if (current_character == '*' || current_character == 'X')
			{
				printf(" \x1b[33;40m%c\x1b[0m ", current_character);
			}
			else
			{
				printf(" %c ", current_character);
			}
			if (column_index < matrix_y_size - 1)
			{
				printf("|");
			}
		}
		printf("|\n|");
		for (int column_index = 0; column_index < matrix_y_size; column_index++)
		{
			printf("---");
			if (column_index < matrix_y_size - 1)
			{
				printf("|");
			}
		}
		printf("|\n");
	}
}

char** allocate_matrix(int matrix_x_size, int matrix_y_size)
{
	char** matrix = (char**) malloc(sizeof(char*) * matrix_x_size);
	for (int row_index = 0; row_index < matrix_x_size; row_index++)
	{
		matrix[row_index] = (char*) malloc(sizeof(char) * matrix_y_size);
		for (int column_index = 0; column_index < matrix_y_size; column_index++)
		{
			matrix[row_index][column_index] = ' ';
		}
	}
	return matrix;
}

void deallocate_matrix(char** matrix, int matrix_y_size)
{
	for (int row_index = 0; row_index < matrix_y_size; row_index++)
	{
		free(matrix[row_index]);
		matrix[row_index] = NULL;
	}
	free(matrix);
	matrix = NULL;
}

int main(void)
{
	int matrix_x_size = 0;
	int matrix_y_size = 0;
	scanf("%d %d", &matrix_x_size, &matrix_y_size);

	int player_x = 0;
	int player_y = 0;
	scanf("%d %d", &player_x, &player_y);
	int missle_x = player_x;
	int missle_y = player_y;

	int enemy_x = 0;
	int enemy_y = 0;
	scanf("%d %d", &enemy_x, &enemy_y);

	char** matrix = allocate_matrix(matrix_x_size, matrix_y_size);
	matrix[player_x][player_y] = 'A';
	matrix[enemy_x][enemy_y] = 'B';

	while (missle_x != enemy_x || missle_y != enemy_y)
	{
		display_matrix(matrix, matrix_x_size, matrix_y_size);
		Sleep(1000);
		system("cls");
		
		if (missle_x < enemy_x)
		{
			missle_x++;
		}
		else if (missle_x > enemy_x)
		{
			missle_x--;
		}

		if (missle_y < enemy_y)
		{
			missle_y++;
		}
		else if (missle_y > enemy_y)
		{
			missle_y--;
		}

		matrix[missle_x][missle_y] = '*';
	}
	matrix[enemy_x][enemy_y] = 'X';
	display_matrix(matrix, matrix_x_size, matrix_y_size);

	deallocate_matrix(matrix, matrix_y_size);

	int exit_code = 0;
	scanf("%d", &exit_code);
	return 0;
}