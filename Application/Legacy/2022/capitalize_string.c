void capitalizeString()
{
    char string[16] = "hello world!";
    int string_length = sizeof(string) / sizeof(char);
    for (int index = 0; index < string_length; index += 1)
    {
        int ascii_code = (int)string[index];
        if (ascii_code >= 97 && ascii_code <= 122)
        {
            ascii_code -= 32;
        }

        string[index] = (char)ascii_code;
        printf("%c", string[index]);
    }
}