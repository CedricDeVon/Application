
using namespace convert;

namespace convert
{
    char *string_to_lower_case(char *original_string, int original_string_length)
    {
        char *lowercased_string = (char *)malloc(original_string_length * sizeof(original_string[0]));
        for (int index = 0; index < original_string_length; index += 1)
        {
            lowercased_string[index] = character_to_lower_case(original_string[index]);
        }
        return lowercased_string;
    }

}
