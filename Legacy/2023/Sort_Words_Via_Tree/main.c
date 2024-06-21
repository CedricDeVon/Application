#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <windows.h>
#include <ctype.h>
#include <limits.h>

#include "solution.h"

int main(void)
{
	srand(time(NULL));

	StringTree tree = StringTree_allocate();
	const int word_size = 1;
	for (int i = 0; i < 1000000; i++)
	{
		char word[word_size];
		for (int j = 0; j < word_size; j++)
		{
			word[j] = (rand() % 26) + 'A';
		}
		StringTree_insert(tree, word, word_size);
	}

	StringTree_display(tree);
	// StringTree_visualize(tree);

	StringTree_deallocate(tree);


	int exit_code = 0;
	scanf("%d", &exit_code);

	return 0;
}