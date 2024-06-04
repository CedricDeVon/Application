#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <stdbool.h>
// #include <time.h>
// #include <math.h>
// #include <windows.h>
// #include <ctype.h>
// #include <limits.h>

int compare(const void* a, const void* b)
{
	return strcmp(*(const char**) a, *(const char**) b);
}

void reverse(char* values[], int size)
{
	for (int i = 0; i < size; i++)
	{
		strrev(values[i]);
	}
}

void print(char* values[], int size)
{
	/*
	Edge Cases:
	- if size is negative
	- if size is 0
	- if values is empty
	- if values has 1 item
	- if values has 10 items
	- if values has 100 items
	- if values has 1000 items
	*/

	for (int i = 0; i < size; i++)
	{
		printf("%s ", values[i]);
	}
	printf("\n");
}

int main(void)
{
	const int size = 9;
	char* values[9] = {
		"The",
		"Quick",
		"Brown",
		"Fox",
		"Jumps",
		"Over",
		"The",
		"Lazy",
		"Dog"
	};

	print(values, size);
	qsort(values, size, sizeof(const char*), compare);
	print(values, size);
	reverse(values, size);
	print(values, size);

	int exit_code = 0;
	scanf("%d", &exit_code);
	return 0;
}

