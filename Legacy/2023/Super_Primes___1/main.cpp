#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

bool is_prime(int value)
{
	if (value < 2)
	{
		return false;
	}

	for (int i = 2; i < value; i++)
	{
		if (value % i == 0)
		{
			return false;
		}
	}

	return true;
}

void handle_program_termination()
{
	int exit_code;
	std::cin >> exit_code;
}

int main(void)
{
	int n = 0;
	std::cin >> n;

	int j = 1;
	for (int i = 2; i < n + 1; i++)
	{
		if (is_prime(j) && is_prime(i))
		{
			std::cout << i << " ";
		}
		if (is_prime(i))
		{
			j++;
		}
	}
	std::cout << "\n";

	handle_program_termination();
	return 0;
}