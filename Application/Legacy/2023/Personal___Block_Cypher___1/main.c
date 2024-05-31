#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(void)
{
	int text_size = 0;
	scanf("%d", &text_size);
	char text[text_size];
	scanf("%s", text);
	int permutation_size = 0;
	scanf("%d", &permutation_size);
	int permutations[permutation_size];
	for (int i = 0; i < permutation_size; i++)
	{
		scanf("%d, ", &permutations[i]);
		permutations[i] -= 1;
	}

	int cypher_text_size = permutation_size * ceil((float) text_size / permutation_size);
	char cypher_text[cypher_text_size];
	for (int i = 0; i < text_size; i++)
	{
		if (text[i] == '%')
		{
			cypher_text[i] = ' ';
		}
		else
		{
			cypher_text[i] = text[i];
		}
	}
	for (int i = text_size; i < cypher_text_size; i++)
	{
		cypher_text[i] = ' ';
	}

	for (int i = 0; i < cypher_text_size; i += permutation_size)
	{
		char block[permutation_size];
		for (int j = 0; j < permutation_size; j++)
		{
			block[j] = cypher_text[i + permutations[j]];
		}
		for (int j = 0; j < permutation_size; j++)
		{
			cypher_text[i + j] = block[j];
		}
	}

	printf("Encrypted: ");
	for (int i = 0; i < cypher_text_size; i++)
	{
		printf("%c", cypher_text[i]);
	}
	printf("\n");

	for (int i = 0; i < cypher_text_size; i += permutation_size)
	{
		char block[permutation_size];
		for (int j = 0; j < permutation_size; j++)
		{
			block[permutations[j]] = cypher_text[i + j];
		}
		for (int j = 0; j < permutation_size; j++)
		{
			cypher_text[i + j] = block[j];
		}
	}

	printf("Decrypted: ");
	for (int i = 0; i < cypher_text_size; i++)
	{
		printf("%c", cypher_text[i]);
	}
	printf("\n");



	int exit_code;
	scanf("%d", &exit_code);

	// Personal BlockCypher 1

	return 0;
}
