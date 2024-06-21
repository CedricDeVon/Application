#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <windows.h>

unsigned long int solution(unsigned int n)
{
    if (n <= 1)
        return 1;
 
    unsigned long int res = 0;
    for (int i = 0; i < n; i++)
        res += solution(i) * solution(n - i - 1);
 
    return res;
}

int main(void)
{
	int n = 0;
	printf("Input: ");
	scanf("%d", &n);

	printf("Output: ");
	for (int i = 0; i < n; i++)
	{
		printf("%ld ", solution(i));
	}
	printf("\n");

	int exit_code = 0;
	scanf("%d", &exit_code);
	return 0;
}
