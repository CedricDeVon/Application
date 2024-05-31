#include <iostream>
#include <array>
#include <vector>
#include <string>

/*
Knight /
Bishop
Rook /
Queen
King /

rows    - ranks
columns - files
top-bottom: 8 ... 1
left-right: a (0) ... h (7)
*/

int convert_file_to_index(char file)
{
	return file - 'a';
}

int convert_rank_to_index(char rank)
{
	return '8' - rank;
}

bool is_chess_piece_character_valid(char chess_piece_character)
{
	return chess_piece_character == 'N' || chess_piece_character == 'B' ||
		chess_piece_character == 'R' || chess_piece_character == 'Q' || chess_piece_character == 'K';
}

bool is_file_valid(char file)
{
	return ('a' - 1) < file && file < ('h' + 1);
}

bool is_rank_valid(char rank)
{
	return '0' < rank && rank < '9';
}

bool is_valid_move_syntax(std::string move)
{
	return move.length() == 3 &&
		is_chess_piece_character_valid(move.at(0)) &&
		is_file_valid(move.at(1)) &&
		is_rank_valid(move.at(2));
}

bool is_valid_knight_move(std::string old_move, std::string new_move)
{
	return (old_move != new_move && old_move.at(0) == 'N' && new_move.at(0) == 'N') && 
		(((abs(old_move.at(1) - new_move.at(1)) == 2) && (abs(old_move.at(2) - new_move.at(2)) == 1)) ||
		((abs(old_move.at(1) - new_move.at(1)) == 1) && (abs(old_move.at(2) - new_move.at(2)) == 2)));
}

bool is_valid_bishop_move(std::string old_move, std::string new_move)
{
	return (old_move != new_move && old_move.at(0) == 'B' && new_move.at(0) == 'B') && 
		(abs(old_move.at(1) - new_move.at(1)) == abs(old_move.at(2) - new_move.at(2)));
}

bool is_valid_rook_move(std::string old_move, std::string new_move)
{
	return (old_move != new_move && old_move.at(0) == 'R' && new_move.at(0) == 'R') && 
		(old_move.at(1) == new_move.at(1) || old_move.at(2) == new_move.at(2));
}

bool is_valid_queen_move(std::string old_move, std::string new_move)
{
	return (old_move != new_move && old_move.at(0) == 'Q' && new_move.at(0) == 'Q') &&
		((abs(old_move.at(1) - new_move.at(1)) == abs(old_move.at(2) - new_move.at(2))) ||
		(old_move.at(1) == new_move.at(1) || old_move.at(2) == new_move.at(2)));
}

bool is_valid_king_move(std::string old_move, std::string new_move)
{
	return (old_move != new_move && old_move.at(0) == 'K' && new_move.at(0) == 'K') &&
		(abs(old_move.at(1) - new_move.at(1)) < 2 && abs(old_move.at(2) - new_move.at(2)) < 2);
}

void exit_handler()
{
	int exit_code = 0;
	std::cin >> exit_code;
}

int main(void)
{
	int move_count = 0;
	std::cin >> move_count;
	if (move_count < 2)
	{
		std::cout << "INVALID" << '\n';
		exit_handler();
		return 0;
	}

	std::string old_move;
	std::cin >> old_move;
	if (!is_valid_move_syntax(old_move))
	{
		std::cout << "INVALID" << "\n";
		exit_handler();
		return 0;
	}
	for (int i = 1; i < move_count; i++)
	{
		std::string new_move;
		std::cin >> new_move;
		if (!is_valid_move_syntax(new_move))
			// !is_valid_queen_move(old_move, new_move))
			// !is_valid_rook_move(old_move, new_move) ||
			// !is_valid_king_move(old_move, new_move))
		{
			std::cout << "INVALID" << '\n';
			break;
		}
		old_move = new_move;
	}

	exit_handler();
	return 0;
}