#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(void)
{
	unsigned long long int n = 0;
	unsigned long long int m = 0;
	unsigned long long int a = 0;
	scanf("%d %d %d", &n, &m, &a);

	printf("%d", (unsigned long long int) ceil((float) n / a) * (unsigned long long int) ceil((float) m / a));

	// int exit_code = 0;
	// scanf("%d", &exit_code);

	return 0;
}
