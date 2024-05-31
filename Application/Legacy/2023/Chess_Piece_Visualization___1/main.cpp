#include <iostream>
#include <array>

/*
Knight
Bishop
Rook
Queen
King
*/

void print(int** matrix, int rank_size, int file_size)
{
	for (int i = 0; i < rank_size; i++)
	{
		for (int j = 0; j < file_size; j++)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << "\n";
	}	
}

int main(void)
{
	const int rank_size = 8;
	const int file_size = 8;
	int** matrix = new int*[rank_size];
	for (int i = 0; i < rank_size; i++)
	{
		matrix[i] = new int[file_size];
		for (int j = 0; j < file_size; j++)
		{
			matrix[i][j] = 0;
		}
	}

	std::string input = "";
	std::cin >> input;

	char key = input[0];
	int file_index = input[1] - 'a';
	int rank_index = '8' - input[2];
	matrix[rank_index][file_index] = 2;

	if (key == 'N')
	{
		
	}
	else if (key == 'B')
	{
		int i = rank_index - 1;
		int j = file_index - 1;
		while (i > -1 && j > -1)
		{
			matrix[i--][j--] = 1;
		}

		i = rank_index + 1;
		j = file_index + 1;
		while (i < rank_size && j < file_size)
		{
			matrix[i++][j++] = 1;
		}

		i = rank_index + 1;
		j = file_index - 1;
		while (i < rank_size && j > -1)
		{
			matrix[i++][j--] = 1;
		}

		i = rank_index - 1;
		j = file_index + 1;
		while (i > -1 && j < file_size)
		{
			matrix[i--][j++] = 1;
		}
	}
	else if (key == 'R')
	{
		for (int i = 0; i < rank_size; i++)
		{
			if (i != rank_index)
			{
				matrix[i][file_index] = 1;
			}
		}
		for (int i = 0; i < file_size; i++)
		{
			if (i != file_index)
			{
				matrix[rank_index][i] = 1;
			}
		}
	}
	else if (key == 'Q')
	{

	}
	else if (key == 'K')
	{

	}

	print(matrix, rank_size, file_size);

	int exit_code = 0;
	std::cin >> exit_code;
	return 0;
}