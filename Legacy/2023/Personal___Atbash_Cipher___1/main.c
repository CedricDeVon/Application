#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include <windows.h>

void encrypt_via_atbash_cipher(char* text)
{
	int size = strlen(text);
	for (int i = 0; i < size; i++)
	{
		text[i] = (('a' - 1) < text[i] && text[i] < ('z' + 1)) ? 'z' - (text[i] - 'a') :
				(('A' - 1) < text[i] && text[i] < ('Z' + 1)) ? 'Z' - (text[i] - 'A') : text[i];
	}
}

int main(void)
{
	char text[1000];
	scanf("%s", text);

	printf("%s\n", text);
	encrypt_via_atbash_cipher(text);
	printf("%s\n", text);

	int exit_code = 0;
	scanf("%d", &exit_code);
	return 0;
}
