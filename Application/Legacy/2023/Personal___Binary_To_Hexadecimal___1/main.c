#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>

int binary_to_decimal(int binary)
{
	int decimal = 0;
	int power = 0;
	while (binary > 0)
	{
		int digit = binary % 10;
		decimal += digit * pow(2, power);
		power++;
		binary /= 10;
	}
	return decimal;
}

char* binary_to_hexadecimal(int binary)
{
	int size = 0;
	int temp = binary;
	while (temp > 0)
	{
		size++;
		temp /= 10;
	}
	size = (int) ceil((float) size / 4);
	char* hexadecimal = (char*) malloc(sizeof(char) * size);
	int index = 0;
	int b_mod = 1;
	temp = 0;
	while (binary > 0)
	{
		int digit = binary % 10;
		if (b_mod > 1000)
		{
			int decimal = binary_to_decimal(temp);
			if (-1 < decimal && decimal < 10)
			{
				hexadecimal[index++] = ('0' + decimal);
			}
			else if (9 < decimal && decimal < 16)
			{
				hexadecimal[index++] = ('A' + (decimal - 10));
			}
			b_mod = 1;
			temp = 0;
		}
		temp += digit % b_mod;
		b_mod *= 10;
		binary /= 10;
	}
	if (temp > 0)
	{
		int decimal = binary_to_decimal(temp);
		if (-1 < decimal && decimal < 10)
		{
			hexadecimal[index++] = ('0' + decimal);
		}
		else if (9 < decimal && decimal < 16)
		{
			hexadecimal[index++] = ('A' + (decimal - 10));
		}
	}
	return hexadecimal;
}

int main(void)
{
	int binary = 0;
	scanf("%d", &binary);
	printf("Binary to Decimal: %d\n", binary_to_decimal(binary));
	printf("Binary to Hexadecimal: %s\n", binary_to_hexadecimal(binary));
	binary_to_hexadecimal(binary);

	int exit_code = 0;
	scanf("%d", &exit_code);
	return 0;
}

