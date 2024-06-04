#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int calculate_modular_inverse(int n, int m)
{
	int a = 1;
	while ((n * a) % m > 1)
	{
		a++;
	}
	return ((n * a) % m == 1) ? a : 0;
}

int main(void)
{
	int n = 0;
	int m = 0;
	scanf("%d %d", &n, &m);

	int a = calculate_modular_inverse(n, m);
	printf("Modulo Inverse: %d %d : %d \n", n, m, a);

	int exit_code = 0;
	scanf("%d", &exit_code);

	return 0;
}

