// #include <stdio.h>
// #include <stdlib.h>

// using namespace std;

// int is_character_X(char value)
// {
//     return value == 'X';
// }

// int is_character_O(char value)
// {
//     return value == 'O';
// }

// int update_score(char value, int score)
// {
//     if (is_character_X(value))
//     {
//         score += 1;
//     }
//     else if (is_character_O(value))
//     {
//         score -= 1;
//     }

//     return score;
// }

// int is_equal_to_3(int value)
// {
//     return value == 3;
// }

// int is_equal_to_negative_3(int value)
// {
//     return value == -3;
// }

// int is_array_item_equal_to_3(int array[], int length)
// {
//     for (int index = 0; index < length; index += 1)
//     {
//         if (is_equal_to_3(array[index]))
//         {
//             return 1;
//         }
//     }

//     return 0;
// }

// int is_array_item_equal_to_negative_3(int array[], int length)
// {
//     for (int index = 0; index < length; index += 1)
//     {
//         if (is_equal_to_negative_3(array[index]))
//         {
//             return 1;
//         }
//     }

//     return 0;
// }
// void reset_array_items_to_0(int array[], int length)
// {
//     for (int index = 0; index < length; index += 1)
//     {
//         array[index] = 0;
//     }
// }

// int is_less_than_3(int value)
// {
//     return value < 3;
// }

// void print_X_wins_on_the_console()
// {
//     printf("X Wins!");
// }

// void print_O_wins_on_the_console()
// {
//     printf("O Wins!");
// }

// void handle_updating_scores(int scores[], char matrix[3][3], int row)
// {
//     for (int column = 0; is_less_than_3(column); column += 1)
//     {
//         scores[0] = update_score(matrix[row][column], scores[0]);
//         scores[1] = update_score(matrix[column][row], scores[1]);
//         scores[2] = update_score(matrix[column][2 - column], scores[2]);
//         scores[3] = update_score(matrix[column][column], scores[3]);
//     }
// }

// void reset_scores_array_items_to_0(int scores[4])
// {
//     reset_array_items_to_0(scores, 4);
// }

// int is_X_pattern_found(int scores[4])
// {
//     return is_array_item_equal_to_3(scores, 4);
// }

// int is_O_pattern_found(int scores[4])
// {
//     return is_array_item_equal_to_negative_3(scores, 4);
// }

// int handle_result(int scores[4])
// {
//     int result = -1;
//     if (is_X_pattern_found(scores))
//     {
//         result = 1;
//     }
//     else if (is_O_pattern_found(scores))
//     {
//         result = 0;
//     }
//     return result;
// }

// int is_equal_to_1(int value)
// {
//     return value == 1;
// }

// int is_equal_to_0(int value)
// {
//     return value == 0;
// }

// int is_equal_to_negative_1(int value)
// {
//     return value == -1;
// }

// int is_not_equal_to_negative_1(int value)
// {
//     return !is_equal_to_negative_1(value);
// }

// int is_either_X_or_O_pattern_found(int result)
// {
//     return is_not_equal_to_negative_1(result);
// }

// void print_neither_won_on_the_console()
// {
//     printf("Neither Won...");
// }

// void handle_result_based_console_statements(int result)
// {
//     if (is_equal_to_1(result))
//     {
//         print_X_wins_on_the_console();
//     }
//     else if (is_equal_to_0(result))
//     {
//         print_O_wins_on_the_console();
//     }
//     else if (is_equal_to_negative_1(result))
//     {
//         print_neither_won_on_the_console();
//     }
// }

// void analyze_tick_tack_toe_score(char matrix[3][3])
// {
//     int scores[4] = {0, 0, 0, 0};
//     int result = -1;
//     for (int row = 0; is_less_than_3(row); row += 1)
//     {
//         handle_updating_scores(scores, matrix, row);
//         result = handle_result(scores);
//         if (is_either_X_or_O_pattern_found(result))
//         {
//             handle_result_based_console_statements(result);
//             break;
//         }
//         else
//         {
//             reset_scores_array_items_to_0(scores);
//         }
//     }
// }

// int main(int argc, char *argv[])
// {
//     char matrix[3][3] = {{'X', 'O', '-'},
//                          {'-', '-', 'X'},
//                          {'O', '-', 'X'}};
//     analyze_tick_tack_toe_score(matrix);

//     return 0;
// }
