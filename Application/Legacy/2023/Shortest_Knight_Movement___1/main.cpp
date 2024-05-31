#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

bool is_move_invalid(std::string move)
{
	return move.length() != 2 ||
		(('a' > move.at(0) || move.at(0) > 'h') || ('1' > move.at(1) || move.at(1) > '8'));
}

void handle_termination()
{
	int exit_code = 0;
	std::cin >> exit_code;	
}

int convert_from_file_to_index(char file)
{
	return file - 'a';
}

int convert_from_rank_to_index(char rank)
{
	return '8' - rank;
}

char convert_from_index_to_file(int index)
{
	return 'a' + index;
}

char convert_from_index_to_rank(int index)
{
	return '8' - index;
}

std::string generate_chess_move_via_index(int file_index, int rank_index)
{
	std::string move = "00";
	move[0] = convert_from_index_to_file(file_index);
	move[1] = convert_from_index_to_rank(rank_index);

	return move;
}

int** create_chess_board(std::string starting_position, std::string ending_position)
{
	int** chess_board = new int*[8];
	for (int i = 0; i < 8; i++)
	{
		chess_board[i] = new int[8];
		for (int j = 0; j < 8; j++)
		{
			chess_board[i][j] = 0;
		}
	}

	chess_board[convert_from_rank_to_index(ending_position.at(1))][convert_from_file_to_index(ending_position.at(0))] = 1;

	return chess_board;
}

int** copy_chess_board(int** other_chess_board)
{
	int** new_chess_board = new int*[8];
	for (int i = 0; i < 8; i++)
	{
		new_chess_board[i] = new int[8];
		for (int j = 0; j < 8; j++)
		{
			new_chess_board[i][j] = other_chess_board[i][j];
		}
	}

	return new_chess_board;
}

int** delete_chess_board(int** chess_board)
{
	for (int i = 0; i < 8; i++)
	{
		delete chess_board[i];
		chess_board[i] = NULL;
	}
	delete chess_board;
	chess_board = NULL;

	return chess_board;
}

void print_chess_board(int** chess_board)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			std::cout << chess_board[i][j] << " ";
		}
		std::cout << "\n";
	}	
}

bool is_valid_chess_coordinate(int rank_index, int file_index)
{
	return (-1 < rank_index && rank_index < 8) && (-1 < file_index && file_index < 8);
}

int decide(int** chess_board, int rank_index, int file_index)
{
	return (chess_board[rank_index][file_index] != 1) ? 0 : 1;
}

void solve(int** chess_board, std::vector<std::string> path, int rank_index, int file_index)
{
	if (!is_valid_chess_coordinate(rank_index, file_index) || chess_board[rank_index][file_index] == -1)
	{
		return;
	}

	path.push_back(generate_chess_move_via_index(file_index, rank_index));
	if (chess_board[rank_index][file_index] == 1)
	{
		for (std::string value : path)
		{
			std::cout << value << " ";
		}
		std::cout << "\n";
		return;
	}

	chess_board[rank_index][file_index] = -1;
	solve(chess_board, path, rank_index - 2, file_index - 1);
	solve(chess_board, path, rank_index - 2, file_index + 1);
	solve(chess_board, path, rank_index + 2, file_index - 1);
	solve(chess_board, path, rank_index + 2, file_index + 1);

	solve(chess_board, path, rank_index - 1, file_index - 2);
	solve(chess_board, path, rank_index + 1, file_index - 2);
	solve(chess_board, path, rank_index - 1, file_index + 2);
	solve(chess_board, path, rank_index + 1, file_index + 2);

	// chess_board[rank_index][file_index] = 0;
}

int main(void)
{
	std::string starting_position;
	std::cin >> starting_position;

	std::string ending_position;
	std::cin >> ending_position;

	if (starting_position == ending_position ||
		is_move_invalid(starting_position) ||
		is_move_invalid(ending_position))
	{
		std::cout << "INVALID" << "\n";
		handle_termination();
		return 0;
	}

	int** chess_board = create_chess_board(starting_position, ending_position);
	print_chess_board(chess_board);
	std::vector<std::string> path;
	// std::vector<std::vector<std::string>>* shortest_paths = new std::vector<std::vector<std::string>>();
	solve(chess_board, path, convert_from_rank_to_index(starting_position.at(1)), convert_from_file_to_index(starting_position.at(0)));


	handle_termination();
	return 0;
}

// Microsoft Visual Studio - Community