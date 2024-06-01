#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef struct morse_code
{
	char key;
	char* value;

} MorseCode;

typedef struct morse_code_table
{
	MorseCode** codes;
	unsigned long long int size;

} MorseCodeTable;

MorseCode* MorseCode_allocate(char key, char value[])
{
	MorseCode* morse_code = (MorseCode*) malloc(sizeof(MorseCode));
	morse_code->key = key;
	morse_code->value = value;

	return morse_code;
}

MorseCode* MorseCode_deallocate(MorseCode* morse_code)
{
	if (morse_code == NULL)
	{
		return NULL;
	}

	free(morse_code);
	morse_code = NULL;

	return morse_code;
}

MorseCodeTable* MorseCodeTable_allocate()
{
	// MorseCodeTable* morse_code_table = (MorseCodeTable*) malloc(sizeof(MorseCodeTable));
	// morse_code_table->size = 36;
	// morse_code_table->codes = (MorseCode**) malloc(sizeof(MorseCode*) * morse_code_table->size);
	// char keys[] = {
	// 	'A', 'B', 'C', 'D', 'E',
	// 	'F', 'G', 'H', 'I', 'J',
	// 	'K', 'L', 'M', 'N', 'O',
	// 	'P', 'Q', 'R', 'S', 'T',
	// 	'U', 'V', 'W', 'X', 'Y',
	// 	'Z', '0', '1', '2', '3',
	// 	'4', '5', '6', '7', '8',
	// 	'9'
	// };
	// char* codes[] = {
	// 	"._", "_...", "_._.", "_..", ".",
	// 	".._.", "__.", "....", "..", ".___",
	// 	"_._", "._..", "....", "..", ".___",

	// };
	// for (unsigned long long int i = 0; i < morse_code_table->size; i++)
	// {
	// 	morse_code_table->codes[i] = MorseCode_allocate(keys[i], codes[i]);
	// }

	// return morse_code_table;
}

void MorseCodeTable_display(MorseCodeTable* morse_code_table)
{
	for (unsigned long long int index = 0; index < morse_code_table->size; index++)
	{
		MorseCode* morse_code = morse_code_table->codes[index];
		printf("%c : %s\n", morse_code->key, morse_code->value);
	}
}

MorseCodeTable* MorseCodeTable_deallocate(MorseCodeTable* morse_code_table)
{
	if (morse_code_table == NULL)
	{
		return NULL;
	}

	for (unsigned long long int index = 0; index < morse_code_table->size; index++)
	{
		free(morse_code_table->codes[index]);
		morse_code_table->codes[index] = NULL;
	}
	free(morse_code_table->codes);
	morse_code_table->codes = NULL;
	free(morse_code_table);
	morse_code_table = NULL;

	return morse_code_table;
}

int main(void)
{
	MorseCodeTable* morse_code_table = MorseCodeTable_allocate();
	MorseCodeTable_display(morse_code_table);

	
	int exit_code = 0;
	scanf("%d", &exit_code);
	return 0;
}

