#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>

void encrypt_via_affine_cypher(char txt[], int q, int b)
{
	int size = strlen(txt);
	for (int i = 0; i < size; i++)
	{
		txt[i] = ('a' <= txt[i] && txt[i] <= 'z') ?
			(((((txt[i] - 'a') * q) + b) % 26) + 'a') :
				('A' <= txt[i] && txt[i] <= 'Z') ?
			(((((txt[i] - 'A') * q) + b) % 26) + 'A') : txt[i];
	}
}

int calculate_modulo_inverse(int a, int b)
{
	int c = 0;
	while ((a * c) % b != 1)
	{
		c++;
	}
	return c;
}

void decrypt_via_affine_cypher(char txt[], int q, int b)
{
	int size = strlen(txt);
	q = calculate_modulo_inverse(q, 26);
	char first = 'a';
	char last = 'z';
	for (int i = 0; i < size; i++)
	{
		if ('a' <= txt[i] && txt[i] <= 'z')
		{
			first = 'a';
			last = 'z';
		}
		else if ('A' <= txt[i] && txt[i] <= 'Z')
		{
			first = 'A';
			last = 'Z';
		}
		else
		{
			continue;
		}

		int a = (q * (txt[i] - first - b));
		txt[i] = (a < 0) ? (last + a + 1) : (a % 26) + first;
	}
}

int main(void)
{
	char txt[1000];
	scanf("%s", txt);
	int q = 0;
	int b = 0;
	scanf("%d %d", &q, &b);

	printf("Plain Text: %s\n", txt);
	encrypt_via_affine_cypher(txt, q, b);
	printf("Encrypt: %s\n", txt);
	decrypt_via_affine_cypher(txt, q, b);
	printf("Decrypt: %s\n", txt);

	int exit_code = 0;
	scanf("%d", &exit_code);

	// abcdefghijklmnopqrstuvwxyz1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ

	return 0;
}