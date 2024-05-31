
using namespace std;

class Validator
{

public:
    static void check_email(string value)
    {
        int index = 0;
        char current_character = value[index];
        bool is_number_sign_character_found = false;
        bool is_dot_character_found = false;
        while (current_character != constants.STRING_BREAK)
        {
            if (current_character == constants.NUMBER_SIGN)
            {
                is_number_sign_character_found = true;
            }
            else if (current_character == constants.DOT)
            {
                is_dot_character_found = true;
            }

            index += 1;
            current_character = value[index];
        }

        if (!is_number_sign_character_found ||
            !is_dot_character_found)
        {
            Error_Handler::throw_error("Invalid email!");
        }
    }

    static void check_string_emptiness(string value)
    {
        int index = 0;
        char current_character = value[index];
        bool is_non_empty_character_found = false;
        while (current_character != constants.STRING_BREAK)
        {
            if (current_character != constants.SPACE)
            {
                is_non_empty_character_found = true;
                break;
            }

            index += 1;
            current_character = value[index];
        }

        if (!is_non_empty_character_found)
        {
            Error_Handler::throw_error("String must not be empty!");
        }
    }

    static void check_number_range(
        int value,
        int maximum_value,
        int minimum_value)
    {
        if (value < minimum_value ||
            value > maximum_value ||
            minimum_value > maximum_value ||
            maximum_value < minimum_value)
        {
            Error_Handler::throw_error("Invalid parameters!");
        }
    }

    static void check_string_length(
        string value,
        int maximum_length,
        int minimum_length = 1)
    {
        if (minimum_length < 1 ||
            maximum_length < 2 ||
            minimum_length > maximum_length ||
            maximum_length < minimum_length)
        {
            Error_Handler::throw_error("Invalid parameters!");
        }

        int current_length = 0;
        char current_character = value[current_length];
        while (current_character != constants.STRING_BREAK)
        {
            current_length += 1;
            current_character = value[current_length];
        }

        if (current_length < minimum_length ||
            current_length > maximum_length)
        {
            Error_Handler::throw_error("Minimum or maximum length has been reached!");
        }
    }
};
