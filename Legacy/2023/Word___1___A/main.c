#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int main(void)
{
	char text[100];
	scanf("%s", text);
	int text_size = strlen(text);

	int uppercase_count = 0;
	int lowercase_count = 0;
	for (int i = 0; i < text_size; i++)
	{
		char character = text[i];
		if ('a' <= character && character <= 'z')
		{
			lowercase_count += 1;
		}
		else if ('A' <= character && character <= 'Z')
		{
			uppercase_count += 1;
		}
	}

	int a = (uppercase_count > lowercase_count) ? 0 : -32;
	int b = (uppercase_count > lowercase_count) ? -32 : 32;
	
	for (int i = 0; i < text_size; i++)
	{
		char character = text[i];
		if (('a' + a) <= character && character <= ('z' + a))
		{
			text[i] += b;
		}
	}

	printf("%s", text);

	// int exit_code = 0;
	// scanf("%d", &exit_code);

	return 0;
}
