#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <windows.h>
#include <ctype.h>

#include "solution.h"

int* solution(int* values, int size)
{
	int* outputs = (int*) malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++)
	{
		int j = i;
		outputs[i] = 0;
		while (j > -1 && values[j] <= values[i])
		{
			outputs[i]++;
			j--;
		}
	}

	return outputs;
}
