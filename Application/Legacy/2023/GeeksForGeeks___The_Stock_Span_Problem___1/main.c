#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <windows.h>
#include <ctype.h>

#include "solution.h"

int main(void)
{
	int size = 0;
	scanf("%d", &size);

	int inputs[size];
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &inputs[i]);
	}

	int* outputs = solution(inputs, size);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", outputs[i]);
	}
	printf("\n");

	int exit_code = 0;
	scanf("%d", &exit_code);

	return 0;
}

/*
Inputs:
10 4 5 90 120 80

Outputs:
1 1 2 4 5 1 
*/