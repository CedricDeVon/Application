#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include <ctype.h>
#include <limits.h>

#include "solution.h"

int calculate_integer_digit_size(int n)
{
	int size = 0;
	while (n > 0)
	{
		size++;
		n /= 10;
	}

	return size;
}

char* integer_to_string(int n, int size)
{
	char* string = (char*) malloc(sizeof(char) * size);
	for (int i = size - 1; i > -1; i--)
	{
		string[i] = (n % 10) + '0';
		n /= 10;
	}

	return string;
}

void display_string(char* string, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%c", string[i]);
	}
	printf("\n");
}

void sort_via_ascending_order(char* string, int start, int size)
{
	for (int i = start; i < size; i++)
	{
		for (int j = start; j < size; j++)
		{
			char a = string[i];
			char b = string[j];
			if (a < b)
			{
				string[i] = b;
				string[j] = a;
			}
		}
	}
}

int compare(const void* a, const void* b)
{
	return *(const char**) a < *(const char**) b;
}

char* solution(int n, int size)
{
	int i = size - 2;
	char* string = integer_to_string(n, size);
	while (i > -1 && string[i] > string[i + 1])
	{
		i--;
	}
	if (i == -1)
	{
		return string;
	}

	int k = i + 1;
	for (int j = i + 1; j < size; j++)
	{
		if (string[j] < string[k])
		{
			k = j;
		}
	}
	k = (k >= size) ? k - 1 : k;

	char temp = string[i];
	string[i] = string[k];
	string[k] = temp;

	sort_via_ascending_order(string, i + 1, size);

	return string;
}

int main(void)
{
	int n = 0;
	scanf("%d", &n);
	int size = calculate_integer_digit_size(n);
	char* string = solution(n, size);
	display_string(string, size);

	int exit_code = 0;
	scanf("%d", &exit_code);
	return 0;
}