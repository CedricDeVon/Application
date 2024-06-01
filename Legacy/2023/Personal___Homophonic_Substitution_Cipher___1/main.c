#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <windows.h>

typedef struct code
{
	char key;
	char* values;

} *Code;

Code Code_allocate(char key, char* values)
{
	Code code = (Code) malloc(sizeof(Code));
	code->key = key;
	code->values = values;

	return code;
}

Code Code_deallocate(Code code)
{
	free(code);
	code = NULL;

	return code;
}

Code* Table_allocate()
{
	Code* table = (Code*) malloc(sizeof(Code) * 26);
	table[0] = Code_allocate('A', "D9");
	table[1] = Code_allocate('B', "X");
	table[2] = Code_allocate('C', "S");
	table[3] = Code_allocate('D', "F");
	table[4] = Code_allocate('E', "Z721");
	table[5] = Code_allocate('F', "E");
	table[6] = Code_allocate('G', "H");
	table[7] = Code_allocate('H', "C");
	table[8] = Code_allocate('I', "V3");
	table[9] = Code_allocate('J', "I");
	table[10] = Code_allocate('K', "T");
	table[11] = Code_allocate('L', "P");
	table[12] = Code_allocate('M', "G");
	table[13] = Code_allocate('N', "A5");
	table[14] = Code_allocate('O', "Q0");
	table[15] = Code_allocate('P', "L");
	table[16] = Code_allocate('Q', "K");
	table[17] = Code_allocate('R', "J");
	table[18] = Code_allocate('S', "R4");
	table[19] = Code_allocate('T', "U6");
	table[20] = Code_allocate('U', "O");
	table[21] = Code_allocate('V', "W");
	table[22] = Code_allocate('W', "M");
	table[23] = Code_allocate('X', "Y");
	table[24] = Code_allocate('Y', "B");
	table[25] = Code_allocate('Z', "N");

	return table;
}

Code* Table_deallocate(Code* table)
{
	for (int i = 0; i < 26; i++)
	{
		table[i] = Code_deallocate(table[i]);
	}
	free(table);
	table = NULL;

	return table;
}

void encrypt(char* text, Code* table)
{
	int size = strlen(text);
	for (int i = 0; i < size; i++)
	{
		char c = text[i];
		text[i] = (('A' - 1) < c && c < ('Z' + 1)) ?
			table[c - 'A']->values[rand() % strlen(table[c - 'A']->values)] : c;		
	}
}

void decrypt(char* text, Code* table)
{
	int size = strlen(text);
	for (int i = 0; i < size; i++)
	{
		char c = text[i];
		bool is_valid = false;
		for (int j = 0; j < 26 && !is_valid; j++)
		{
			int size = strlen(table[j]->values);
			for (int k = 0; k < size && !is_valid; k++)
			{
				if (table[j]->values[k] == c)
				{
					text[i] = table[j]->key;
					is_valid = true;
				}
			}
		}
	}
}

int main(void)
{
	Code* table = Table_allocate();
	char text[1000];
	scanf("%s", text);
	
	printf("%s \n", text);
	encrypt(text, table);
	printf("%s \n", text);
	decrypt(text, table);
	printf("%s \n", text);

	Table_deallocate(table);

	int exit_code = 0;
	scanf("%d", &exit_code);
	return 0;
}
