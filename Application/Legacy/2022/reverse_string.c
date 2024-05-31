void reverse_string()
{
    char original_string[16] = "Hello World!";
    int original_string_length = sizeof(original_string) / sizeof(char);
    char reversed_string[16] = "";
    for (int index = 0; index < original_string_length; index += 1)
    {
        reversed_string[index] = original_string[original_string_length - index - 1];
        printf("%c", reversed_string[index]);
    }
}
