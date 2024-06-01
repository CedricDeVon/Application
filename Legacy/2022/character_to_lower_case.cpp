
/*
#include <iostream>
#include <cstdio>
#include <cerrno>
#include <cstring>

FILE *fp;
fp = fopen("filedoesnotexist.txt", "rb");

if (fp == NULL)
{
    printf("Value of errno: %d\n", errno);
    printf("Error opening the file: %s\n",
            strerror(errno));
    perror("Error printed by perror");

    exit(EXIT_FAILURE);
    printf("I will not be printed\n");
}

else
{
    fclose(fp);
    exit(EXIT_SUCCESS);
    printf("I will not be printed\n");
}
*/

namespace convert
{
    char character_to_lower_case(char character)
    {
        int a_character = (int)character;
        if (a_character < 65 || a_character > 90)
        {
            return character;
        }

        return (char)(a_character + 32);
    }
}
