
namespace convert
{
    char character_to_upper_case(char character)
    {
        int a_character = (int)character;
        if (a_character < 97 || a_character > 122)
        {
            return character;
        }

        return (char)(a_character - 32);
    }

}
