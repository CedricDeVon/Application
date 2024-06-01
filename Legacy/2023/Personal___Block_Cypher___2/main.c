#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef struct string
{
	unsigned char* values;
	unsigned long long int size;

} String;

typedef struct permutations
{
	unsigned long long int* values;
	unsigned long long int size;

} Permutations;

String* allocate_empty_string(unsigned long long int size)
{
	if (size <= 0)
	{
		return NULL;
	}

	String* string = (String*) malloc(sizeof(String));
	string->values = (unsigned char*) malloc(sizeof(unsigned char) * size);
	for (unsigned long long int index = 0; index < size; index++)
	{
		string->values[index] = ' ';
	}
	string->size = size;

	return string;
}

String* allocate_copy_string(unsigned char* values)
{
	if (values == NULL)
	{
		return NULL;
	}

	String* string = (String*) malloc(sizeof(String));
	string->values = values;
	string->size = strlen(values);

	return string;
}

Permutations* allocate_permutations(unsigned long long int size)
{
	if (size <= 0)
	{
		return NULL;
	}

	Permutations* permutations = (Permutations*) malloc(sizeof(Permutations));
	permutations->values = (unsigned long long int*) malloc(sizeof(unsigned long long int) * size);
	permutations->size = size;
	return permutations;
}

void display_string(String* string)
{
	printf("\"");
	for (unsigned long long int index = 0; index < string->size; index++)
	{
		printf("%c", string->values[index]);
	}
	printf("\"\n");
}

void display_permutations(Permutations* permutations)
{
	printf("{ ");
	for (unsigned long long int index = 0; index < permutations->size; index++)
	{
		printf("%lld", permutations->values[index]);
		if (index < permutations->size - 1)
		{
			printf(", ");
		}
	}
	printf(" }\n");
}

String* deallocate_string(String* string)
{
	if (string == NULL)
	{
		return NULL;
	}

	free(string->values);
	string->values = NULL;
	free(string);
	string = NULL;

	return string;
}

Permutations* deallocate_permutations(Permutations* permutations)
{
	if (permutations == NULL)
	{
		return NULL;
	}

	free(permutations->values);
	permutations->values = NULL;
	free(permutations);
	permutations = NULL;

	return permutations;
}

unsigned long long int calculate_block_size(String* string, Permutations* permutations)
{
	if (string == NULL || permutations == NULL || string->size <= 0 || permutations->size <= 0)
	{
		return 0;
	}

	return permutations->size * ceil((float) string->size / permutations->size);
}

String* encrypt_via_block_transposition(String* plain_string, Permutations* permutations, unsigned char wildcard_character)
{
	if (plain_string == NULL || permutations == NULL || !wildcard_character || plain_string->size <= 0 || permutations->size <= 0)
	{
		return NULL;
	}

	unsigned long long int index_sum = 0;
	unsigned long long int current_permutation_index = 0;
	String* encrypted_string = allocate_empty_string(calculate_block_size(plain_string, permutations));
	for (unsigned long long int index = 0; index < plain_string->size; index++)
	{
		unsigned long long int current_permutation = permutations->values[current_permutation_index++] - 1;
		unsigned char current_character = plain_string->values[index];
		encrypted_string->values[index_sum + current_permutation] = current_character;
		if (current_permutation_index == permutations->size)
		{
			current_permutation_index = 0;
			index_sum += permutations->size;
		}
	}
	for (unsigned long long int index = 0; index < encrypted_string->size; index++)
	{
		if (encrypted_string->values[index] == ' ')
		{
			encrypted_string->values[index] = wildcard_character;
		}
	}

	return encrypted_string;
}

String* decrypt_via_block_transposition(
	String* encrypted_string, Permutations* permutations, unsigned char wildcard_character)
{
	if (encrypted_string == NULL || permutations == NULL || !wildcard_character || encrypted_string->size <= 0 || permutations->size <= 0)
	{
		return NULL;
	}

	unsigned long long int modifier = 0;
	unsigned long long int current_permutation_index = 0;
	String* decrypted_string = allocate_empty_string(calculate_block_size(encrypted_string, permutations));
	for (unsigned long long int index = 0; index < encrypted_string->size; index++)
	{
		unsigned long long int current_permutation = permutations->values[current_permutation_index++] - 1;
		unsigned char current_character = encrypted_string->values[modifier + current_permutation];
		decrypted_string->values[index] = (current_character == wildcard_character) ? ' ' : current_character;
		if (current_permutation_index == permutations->size)
		{
			current_permutation_index = 0;
			modifier += permutations->size;
		}
	}
	return decrypted_string;
}

int main(void)
{
	unsigned char string_input[1000];
	scanf("%s", string_input);
	String* string = allocate_copy_string(string_input);

	unsigned long long int permutation_size = 0;
	scanf("%lld", &permutation_size);
	Permutations* permutations = allocate_permutations(permutation_size);
	for (int index = 0; index < permutation_size; index++)
	{
		scanf("%lld, ", &permutations->values[index]);
	}

	printf("String: ");
	display_string(string);
	printf("Permutations: ");
	display_permutations(permutations);

	printf("Encrypted: ");
	String* encrypted_string = encrypt_via_block_transposition(string, permutations, '%');
	display_string(encrypted_string);

	printf("Decrypted: ");
	String* decrypted_string = decrypt_via_block_transposition(encrypted_string, permutations, '%');
	display_string(decrypted_string);

	deallocate_string(string);
	deallocate_permutations(permutations);
	deallocate_string(encrypted_string);
	deallocate_string(decrypted_string);

	int exit_code;
	scanf("%d", &exit_code);

	return 0;
}
