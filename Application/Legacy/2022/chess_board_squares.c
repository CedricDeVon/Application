
void chess_board_squares()
{
    //     Chess Board Squares
    // Create a function that takes a chess board square's coordinate and return its color.
    // Examples:
    // chessBoard("a1") ➞ "black"
    // chessBoard("e5") ➞ "black"
    // chessBoard("d1") ➞ "white"

    char file_character;
    int rank, file;
    printf("Enter chess board coordinate: [file] [rank] \n");
    scanf("%c%i", &file_character, &rank);

    file_character = tolower(file_character);
    switch (file_character)
    {
    case 'a':
        file = 1;
        break;
    case 'b':
        file = 2;
        break;
    case 'c':
        file = 3;
        break;
    case 'd':
        file = 4;
        break;
    case 'e':
        file = 5;
        break;
    case 'f':
        file = 6;
        break;
    case 'g':
        file = 7;
        break;
    case 'h':
        file = 8;
        break;
    }

    if ((rank == 1 || rank % 2 != 0 && file % 2 != 0) || (file % 2 == 0 && file % 2 == 0))
    {
        printf("%c%i: Black \n", file_character, rank);
    }
    else if ((rank == 1 || rank % 2 != 0 && file % 2 == 0) || (file % 2 == 0 && file % 2 != 0))
    {
        printf("%c%i: White \n", file_character, rank);
    }
}