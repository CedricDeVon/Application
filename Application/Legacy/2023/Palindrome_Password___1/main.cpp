#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

unsigned long long int digit_sum(std::string value)
{
	unsigned long long int sum = 0;
	for (unsigned long long int i = 0; i < value.size(); i++)
	{
		sum += value[i] - '0';
	}
	return sum;
}

int main(void)
{
	std::string input;
	std::cin >> input;

	unsigned long long int sum = digit_sum(input);
	std::cout << sum << "\n";
	std::cout << pow(sum, 2) << "\n";

	int exit_code = 0;
	std::cin >> exit_code;

	return 0;
}