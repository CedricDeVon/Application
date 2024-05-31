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
		decimal += (digit * pow(2, power));
		power++;
		binary /= 10;
	}
	return decimal;
}

int binary_to_octal(int binary)
{
	int octal = 0;
	int a_modifier = 1;
	int b_modifier = 1;
	int temp = 0;
	while (binary > 0)
	{
		int digit = binary % 10;
		if (b_modifier > 100)
		{
			octal += (binary_to_decimal(temp) * a_modifier);
			a_modifier *= 10;
			b_modifier = 1;
			temp = 0;
		}
		temp += (digit * b_modifier);
		b_modifier *= 10;
		binary /= 10;
	}
	if (temp > 0)
	{
		octal += (binary_to_decimal(temp) * a_modifier);
	}

	return octal;
}

int main(void)
{
	int binary = 0;
	scanf("%d", &binary);

	printf("Binary to Decimal: %d\n", binary_to_decimal(binary));

	printf("Binary to Octal: %d\n", binary_to_octal(binary));

	int exit_code = 0;
	scanf("%s", &exit_code);
}
