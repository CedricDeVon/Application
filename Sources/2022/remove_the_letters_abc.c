
void remove_the_letters_abc()
{
    char character, string[100] = "This might be a bit hard";   
    printf("Original: %s \n", string);
    for (int index = 0; index < strlen(string); index++)
    {
        character = toupper(string[index]);
        if (character == 'A' || character == 'B' || character == 'C')
        {
            string[index] = ' ';
        }
    }
    printf("Modified: %s \n", string);
}
