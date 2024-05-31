#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

int main(void)
{
	int n;
	std::cin >> n;

	std::cout << " ";
	int b = n - 2;
	int f = b - 1;
	for (int i = 1; i < f; i++)
	{
		std::cout << "*";
	}
	std::cout << "\n";

	int c = (n - 3) / 2;
	for (int i = 0; i < c; i++)
	{
		std::cout << "*" << "\n";
	}

	std::cout << "* ";
	int e = b - 2;
	for (int i = 0; i < e; i++)
	{
		std::cout << "*";
	}
	std::cout << "\n";

	for (int i = 0; i < c; i++)
	{
		std::cout << "*";
		for (int j = 0; j < e; j++)
		{
			std::cout << " ";
		}
		std::cout << "*" << "\n";
	}

	std::cout << " ";
	for (int i = 1; i < f; i++)
	{
		std::cout << "*";
	}
	std::cout << "\n";

	int exit_code;
	std::cin >> exit_code;
	return 0;
}
