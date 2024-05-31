#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

void solve();

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	solve();

	int exit_code = 0;
	std::cin >> exit_code;
	return 0;
}

void solve()
{
	int size = 0;
	std::cin >> size;
	int inputs[size];
	for (int i = 0; i < size; i++)
	{
		std::cin >> inputs[i];
	}
	int target = 0;
	std::cin >> target;

	int i = size / 2;
	while (i > -1 && i < size)
	{
		int value = inputs[i];
		if (value == target)
		{
			return i;
		}
		else if (value < target)
		{
			
		}
		else if (value > target)
		{
			
		}
	}
}
