
char *remove_trailing_and_leading_zeros(char *original_string,
                                        int original_string_length)
{
    char *updated_string = (char *)malloc(original_string_length *
                                          sizeof(original_string[0]));
    int update_string_index = 0;
    int is_non_zero_digit_found = 0;
    int is_finished = 0;
    int is_dot_found = 0;

    for (int original_string_index = 0;
         original_string_index < original_string_length &&
         !is_finished;
         original_string_index += 1)
    {
        if (original_string[original_string_index] != '0')
        {
            is_non_zero_digit_found = 1;
        }

        if (original_string[original_string_index] == '.')
        {
            is_dot_found = 1;
        }

        if (is_dot_found)
        {
            if (original_string[original_string_index + 1] != '0' || original_string[original_string_index + 2] != '0')
            {
                updated_string[update_string_index] = '.';
                updated_string[update_string_index + 1] =
                    original_string[original_string_index + 1];
                updated_string[update_string_index + 2] =
                    original_string[original_string_index + 2];
                updated_string[update_string_index + 3] = '\0';
            }
            else
            {
                updated_string[update_string_index] = '\0';
            }
            is_finished = 1;
            break;
        }

        if (is_non_zero_digit_found)
        {
            updated_string[update_string_index] =
                original_string[original_string_index];
            update_string_index += 1;
        }
    }

    return updated_string;
}