#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <windows.h>

#include "solution.h"

int main(void)
{
	char expression[1000];
	printf("Input: ");
	scanf("%s", expression);
	printf("Output: %d\n", solution(expression));

	int exit_code = 0;
	scanf("%d", &exit_code);

	return 0;
}