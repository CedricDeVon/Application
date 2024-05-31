#include <stdio.h>
#include <math.h>
#include <windows.h>

void clearScreen()
{
    printf("\033[H\033[J");
}

int main(void)
{
    clearScreen();

    int radius = 3;
    int diameter = radius * 2 + 1;

    for (int y = 0; y < diameter; y++)
    {
        for (int x = 0; x < diameter; x++)
        {
            printf("%s ",
                (pow(x - radius, 2) + pow(y - radius, 2) < pow(radius, 2) + 1) ? "*" : " ");
        }
        printf("\n");
    }

    int exit_code = 0;
    scanf("%d", &exit_code);
    return 0;
}
