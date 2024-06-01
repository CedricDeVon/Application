
using namespace std;

void triangle_generator(int *size)
{
    if (*size <= 1)
    {
        printf("Error: Please supply an integer greater than 1");
        exit(-1);
    }

    int(*matrix)[*size] = (int(*)[*size])calloc(*size, sizeof(int));
    int *heap_row = (int *)malloc(sizeof(int));
    int *heap_column = (int *)malloc(sizeof(int));
    int *heap_character_id = (int *)malloc(sizeof(int));
    for (*heap_row = 0; *heap_row < *size; *heap_row += 1)
    {
        for (*heap_column = 0; *heap_column < *size; *heap_column += 1)
        {
            heap_character_id = *(matrix + *heap_row) + *heap_column;
            if (*heap_row == *heap_column - 1)
            {
                *heap_character_id = 1;
            }
            else if (*heap_row == *size - 1)
            {
                *heap_character_id = 2;
            }
            else if (*heap_column == 0)
            {
                *heap_character_id = 3;
            }
            else
            {
                *heap_character_id = 0;
            }
            switch (*heap_character_id)
            {
            case 1:
                cout << '\\';
                break;
            case 2:
                cout << '-';
                break;
            case 3:
                cout << '|';
                break;
            default:
                cout << ' ';
            }
        }
        cout << endl;
    }

    free(matrix);
    free(heap_row);
    free(heap_column);
    free(heap_character_id);
}