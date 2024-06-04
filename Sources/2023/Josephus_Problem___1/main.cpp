#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

int main(void)
{
	unsigned long long int n;
	std::cin >> n;

	unsigned long long int k;
	std::cin >> k;

	std::queue<unsigned long long int> a;
	for (unsigned long long int i = 1; i < n + 1; i++)
	{
		a.push(i);
	}

	unsigned long long int s = a.size() - 1;
	for (unsigned long long int i = 0; i < s; i++)
	{
		for (unsigned long long int j = 1; j < k; j++)
		{
			unsigned long long int v = a.front();
			a.pop();
			a.push(v);
		}
		a.pop();
	}
	std::cout << a.front() << " " << "\n";

	int exit_code;
	std::cin >> exit_code;
	return 0;
}