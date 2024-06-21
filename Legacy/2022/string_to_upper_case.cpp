namespace convert
{
    char *string_to_upper_case(char *original_string, int original_string_length)
    {
        char *uppercased_string = (char *)malloc(original_string_length * sizeof(original_string[0]));
        for (int index = 0; index < original_string_length; index += 1)
        {
            uppercased_string[index] = character_to_upper_case(original_string[index]);
        }
        return uppercased_string;
    }

}
