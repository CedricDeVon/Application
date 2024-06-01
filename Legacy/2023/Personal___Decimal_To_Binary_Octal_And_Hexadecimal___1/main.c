#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int decimal_to_binary(int n)
{
	int b = 0;
	int m = 1;
	while (n > 0)
	{
		b += (n % 2 * m);
		n /= 2;
		m *= 10;
	}	
	n = 0;
	m = 1;
	while (b > 0)
	{
		n += (b % 2 * m);
		b /= 10;
		m *= 10;
	}
	return n;
}

int decimal_to_octal(int n)
{
	int b = 0;
	int m = 1;
	while (n > 0)
	{
		b += (n % 8 * m);
		n /= 8;
		m *= 10;
	}
	return b;
}

char* decimal_to_hexadecimal(int n)
{


}

int main(void)
{
	int d = 0;
	scanf("%d", &d);
	int b = decimal_to_binary(d);
	printf("Decimal to Binary: %d = %d\n", d, b);

	scanf("%d", &d);
	int o = decimal_to_octal(d);
	printf("Decimal to Octal: %d = %d\n", d, o);

	int exit_code = 0;
	scanf("%d", &exit_code);

	return 0;
}
