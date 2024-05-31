#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <windows.h>

int binary_to_decimal(int binary)
{
	int decimal = 0;
	int power = 0;
	while (binary > 0)
	{
		decimal += (binary % 10) * pow(2, power);
		binary /= 10;
		power++;
	}
	return decimal;
}

int octal_to_decimal(int octal)
{
	int decimal = 0;
	int power = 0;
	while (octal > 0)
	{
		decimal += (octal % 10) * pow(8, power);
		octal /= 10;
		power++;
	}
	return decimal;
}

int hexadecimal_to_decimal(char hexadecimal[])
{
	int decimal = 0;
	int power = 0;
	for (int index = strlen(hexadecimal) - 1; index > -1; index--)
	{
		int digit = (('A' - 1) < hexadecimal[index] && hexadecimal[index] < ('F' + 1)) ?
			(hexadecimal[index] - 'A' + 10) : (hexadecimal[index] - '0');
		decimal += digit * pow(16, power);
		power++;
	}
	return decimal;
}

int main(void)
{
	int binary = 0;
	scanf("%d", &binary);
	int decimal = binary_to_decimal(binary);
	printf("Binary to Decimal: %d\n", decimal);

	int octal = 0;
	scanf("%d", &octal);
	decimal = octal_to_decimal(octal);
	printf("Octal to Decimal: %d\n", decimal);

	char hexadecimal[1000];
	scanf("%s", hexadecimal);
	decimal = hexadecimal_to_decimal(hexadecimal);
	printf("Hexadecimal to Decimal: %d\n", decimal);

	int exit_code = 0;
	scanf("%d", &exit_code);
	return 0;
}
