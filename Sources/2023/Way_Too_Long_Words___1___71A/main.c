#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <math.h>

int main(void)
{
	int n = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		char word[100];
		scanf("%s", word);
		int word_length = strlen(word);
		if (word_length > 10)
		{
			printf("%c%d%c", word[0], word_length - 2, word[word_length - 1]);
		}
		else
		{
			printf("%s", word);
		}
		printf("\n");
	}

	// int exit_code;
	// scanf("%d", &exit_code);

	return 0;
}

