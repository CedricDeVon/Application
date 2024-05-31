#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int main(void)
{
	int n = 0;
	int m = 0;
	scanf("%d %d", &n, &m);
	int s = n * m;
	int* nums = (int*) malloc(sizeof(int) * s);
	for (int i = 0; i < s; i++)
	{
		scanf("%d", &nums[i]);
	}

	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < s; j++)
		{
			if (nums[i] < nums[j])
			{
				int temp = nums[i];
				nums[i] = nums[j];
				nums[j] = temp;
			}
		}
	}

	float mean = nums[0];
	int cn = nums[0];
	int mf = 1;
	int cf = 1;
	for (int i = 1; i < s; i++)
	{
		int num = nums[i];
		if (cn != num && mf < cf)
		{
			mf = cf;
			cn = num;
			cf = 1;
		}
		else if (cn != num)
		{
			cn = num;
			cf = 1;
		}
		else if (cn == num)
		{
			cf += 1;
		}
		mean += nums[i];
	}
	if (mf < cf)
	{
		mf = cf;
	}
	printf("Mode: %lf\n", (s % 2 == 0) ?
		((float) (nums[(s / 2)] + nums[(s / 2) - 1]) / 2) : nums[(s / 2)]);
	printf("Median: ");
	cn = nums[0];
	cf = 1;
	for (int i = 1; i < s; i++)
	{
		int num = nums[i];
		if (cn != num && cf == mf)
		{
			printf("%d ", cn);
			cn = num;
			cf = 1;
		}
		else if (cn != num)
		{
			cn = num;
			cf = 1;
		}
		else if (cn == num)
		{
			cf += 1;
		}
	}
	if (cf == mf)
	{
		printf("%d", cn);
	}
	printf("\n");
	printf("Mean: %lf\n", (mean / (float) s));
	free(nums);
	nums = NULL;

	int exit_code = 0;
	scanf("%d", &exit_code);

	return 0;
}
