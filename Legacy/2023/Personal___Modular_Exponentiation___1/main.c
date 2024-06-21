#pragma GCC optimze("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>

int decimal_to_binary(int n)
{
	int a = 0;
	int m = 1;
	while (n > 0)
	{
		a += (n % 2) * m;
		n /= 2;
		m *= 10;
	}
	n = 0;
	m = 1;
	while (a > 0)
	{
		n += (a % 10) * m;
		a /= 10;
		m *= 10;
	}
	return n;
}

int calculate_modulo_exponentiation(int n, int e, int m)
{
	int x = 1;
	int p = n % m;
	e = decimal_to_binary(e);
	while (e > 0)
	{
		x = (e % 10 == 1) ? (x * p) % m : x;
		p = (p * p) % m;
		e /= 10;
	}
	return x;
}

int main(void)
{
	int n = 0;
	int e = 0;
	int m = 0;
	scanf("%d %d %d", &n, &e, &m);

	printf("%d", calculate_modulo_exponentiation(n, e, m));

	int exit_code = 0;
	scanf("%d", &exit_code);
	return 0;
}