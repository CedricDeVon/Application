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
	// Sample Input: (3 + -2) % -5 ^ 3 / (46 - -12) * [5 + (-4 - 8)] ^ 7 % 10
	char infix_expression[1000];
	scanf("%[^\n]%*c", infix_expression);

	CircularSinglyLinkedList_display(solution(infix_expression, strlen(infix_expression)));

	int exit_code = 0;
	scanf("%d", &exit_code);

	return 0;
}