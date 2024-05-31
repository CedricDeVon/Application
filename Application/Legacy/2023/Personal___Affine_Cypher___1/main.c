#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <math.h>

void encrypt_via_affine_cypher(char* plain_text, int q, int b)
{
	int plain_text_size = strlen(plain_text);
	for (int i = 0; i < plain_text_size; i++)
	{
		plain_text[i] = ('a' <= plain_text[i] && plain_text[i] <= 'z') ?
			(((((plain_text[i] - 'a') * q) + b) % 26) + 'a') : 
			('A' <= plain_text[i] && plain_text[i] <= 'Z') ?
				(((((plain_text[i] - 'A') * q) + b) % 26) + 'A') :
				plain_text[i];
	}
}

int calculate_modulo_invserse(int a, int m)
{
	int b = 0;
	while ((a * b) % m != 1)
	{
		b += 1;
	}
	return b;
}

void decrypt_via_affine_cypher(char* encrypted_text, int q, int b)
{
	int encrypted_text_size = strlen(encrypted_text);
	q = calculate_modulo_invserse(q, 26);
	for (int i = 0; i < encrypted_text_size; i++)
	{
		// encrypted_text[i] = ('a' <= encrypted_text[i] && encrypted_text[i] <= 'z') ?
		// 	(((mi * ((encrypted_text[i] - 'a') - b)) % 26) + 'a') :
		// 	('A' <= encrypted_text[i] && encrypted_text[i] <= 'Z') ?
		// 		(((mi * ((encrypted_text[i] - 'A') - b)) % 26) + 'A') :
		// 		encrypted_text[i];
	}
}

int main(void)
{
	char plain_text[1000];
	scanf("%s", plain_text);
	printf("Plain Text: %s\n", plain_text);

	int q = 0;
	int b = 0;
	scanf("%d %d", &q, &b);

	encrypt_via_affine_cypher(plain_text, q, b);
	printf("Encrypted: %s\n", plain_text);

	decrypt_via_affine_cypher(plain_text, q, b);
	printf("Decrypted: %s\n", plain_text);

	// `1234567890-=[]\;',./~!@#$%^&*()_+{}|:"<>?abcdefghijklmnopqrstuvwxyz`1234567890-=[]\;',./~!@#$%^&*()_+{}|:"<>?abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ`1234567890-=[]\;',./~!@#$%^&*()_+{}|:"<>?

	int exit_code = 0;
	scanf("%d", &exit_code);

	return 0;
}
