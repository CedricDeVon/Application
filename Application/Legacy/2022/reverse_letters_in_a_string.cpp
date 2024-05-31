
char *reverse_letters_in_a_string(char *original_string, int original_string_length)
{
    if (original_string_length <= 0)
    {
        printf("Error: Please supply a string length greater than 0");
        exit(-1);
    }

    char *reverse_string = (char *)malloc(original_string_length);
    for (int index = original_string_length - 2; index >= 0; index -= 1)
    {
        reverse_string[original_string_length - (index + 2)] = original_string[index];
    }
    reverse_string[original_string_length - 1] = '\0';

    return reverse_string;
}
