
class Vs_Schema
{
public:
    static void encrypt(char *string)
    {
        Vs_Schema::execute(string, Vs_Schema::ENCRYPTION_BASE);
    }

    static void decrypt(char *string)
    {
        Vs_Schema::execute(string, Vs_Schema::DECRYPTION_BASE);
    }

private:
    static const int ENCRYPTION_BASE = -3;
    static const int DECRYPTION_BASE = 3;
    static const int RANGE = 3;

    static void execute(char string[1024], int base)
    {
        int index = 0;
        int current_range = 0;
        int current_base = base;
        while (string[index] != '\0')
        {
            if (current_range <= RANGE)
            {
                current_range += 1;
                current_base += base;
            }

            current_range = 0;
            current_base = base;
            string[index] = (char)((int)string[index] + current_base);
            index += 1;
        }
    }
};
