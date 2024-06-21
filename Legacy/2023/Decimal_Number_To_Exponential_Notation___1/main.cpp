#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

void terminate_program()
{
	int exit_code;
	std::cin >> exit_code;
}

int main(void)
{
	std::string input;
	std::cin >> input;

	if (input.length() < 1)
	{
		terminate_program();
		return 0;
	}

	int tens_count = 0;
	bool is_non_zero_digit_found = false;
	for (int index = (input[0] == '-') ? 2 : 1;
		index < input.length() && input[index] != '.'; index++)
	{
		if (input[index] != '0')
		{
			is_non_zero_digit_found = true;
		}
		tens_count++;
	}

	std::cout << input[0];
	if (input[0] == '-')
	{
		std::cout << input[1];
	}
	if (is_non_zero_digit_found)
	{
		std::cout << '.';
	}
	for (int index = (input[0] == '-') ? 2 : 1;
		index < input.length() && is_non_zero_digit_found; index++)
	{
		if (input[index] != '.')
		{
			std::cout << input[index];
		}
	}
	std::cout << "^" << tens_count << "\n";

	terminate_program();
	return 0;
}