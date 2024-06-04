#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#include "pascals_triangle.h"

int main(void)
{
	int n = 0;
	scanf("%d", &n);

	display_pascals_triangle(n);

	int exit_code = 0;
	scanf("%d", &exit_code);
	return 0;
}

