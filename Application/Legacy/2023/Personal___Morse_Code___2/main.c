#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <windows.h>

char keys[50] = {
	'A', 'B', 'C', 'D', 'E',
	'F', 'G', 'H', 'I', 'J',
	'K', 'L', 'M', 'N', 'O',
	'P', 'Q', 'R', 'S', 'T',
	'U', 'V', 'W', 'X', 'Y',
	'Z', '0', '1', '2', '3',
	'4', '5', '6', '7', '8',
	'9', '.', ',', '?', '\'',
	'!', '/', ':', ';', '=',
	'+', '-', '_', '"', '@'
};

char* values[50] = {
	".-", "-...", "-.-.", "-..", ".",
	"..-.", "--.", "....", "..", ".---",
	"-.-", ".-..", "--", "-.", "---",
	".--.", "--.-", ".-.", "...", "-",
	"..-", "...-", ".--", "-..-", "-.--",
	"--..", "-----", ".----", "..---", "...--",
	"....-", ".....", "-....", "--...", "---..",
	"----.", ".-.-.-", "--..--", "..--..", ".----.",
	"-.-.--", "-..-.", "---...", "-.-.-.", "-...-",
	".-.-.", "-....-", "..--.-", ".-..-.", ".--.-."
};

void ascii_to_morse_code(char* string)
{
	int size = strlen(string);
	for (int index = 0; index < size; index++)
	{
		int index = 0;
		bool is_found = false;
		char character = (('a' - 1) < string[index] && string[index] < ('z' + 1)) ?
			string[index] - 32 : string[index];
		while (index < 50)
		{
			if (character == keys[index])
			{
				is_found = true;
				break;
			}
			index++;
		}
		if (is_found)
		{
			printf("%s", values[index]);
		}
		else
		{
			printf("%c", character);
		}
		printf("/");
	}
	printf("\n");
}

int main(void)
{
	char ascii[1000];
	scanf("%s", ascii);

	ascii_to_morse_code(ascii);

	int exit_code = 0;
	scanf("%d", &exit_code);
	
	return 0;
}
