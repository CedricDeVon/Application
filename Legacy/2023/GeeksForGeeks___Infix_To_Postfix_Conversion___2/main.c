#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include <ctype.h>
#include <limits.h>

#include "solution.h"

int main(void)
{
	char infix_expression[1000];
	scanf("%[^\n]%*c", infix_expression);
	printf("%s\n", infix_expression);
	String_display(solution(infix_expression, strlen(infix_expression)));
	// printf("%s\n", 

	int exit_code = 0;
	scanf("%d", &exit_code);

	return 0;
}