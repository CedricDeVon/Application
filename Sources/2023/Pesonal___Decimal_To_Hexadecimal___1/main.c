#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <windows.h>

void decimal_to_hexadecimal(int input)
{
	int temp = input;
	int size = 0;
	while (temp > 0)
	{
		temp /= 16;
		size++;
	}

	temp = input;
	size = (size == 0) ? 1 : size;
	char output[size];
	for (int index = size - 1; index > -1; index--)
	{
		int value = temp % 16;
		output[index] = (0 <= value && value <= 9) ? ('0' + value) : 'A' + (value - 10);
		temp /= 16;
	}
	printf("%d\n", strlen(output));
	for (int index = 0; index < size; index++)
	{
		printf("%c", output[index]);
	}
	printf("\n");
}

int main(void)
{
	int input = 0;
	scanf("%d", &input);
	
	decimal_to_hexadecimal(input);

	int exit_code = 0;
	scanf("%d", &exit_code);
}
