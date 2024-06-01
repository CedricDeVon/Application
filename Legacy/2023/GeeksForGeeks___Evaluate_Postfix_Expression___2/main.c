#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <windows.h>
#include <limits.h>

#include "solution.h"

int main(void)
{
	char input[1000];
	scanf("%s", input);

	printf("%d\n", solution(input, strlen(input)));

	int exit_code = 0;
	scanf("%d", &exit_code);
	return 0;
}