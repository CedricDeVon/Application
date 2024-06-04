#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

void handle_program_termination()
{
	int exit_code;
	std::cin >> exit_code;
}

unsigned long long int f_a(unsigned long long int n)
{
	return n * (n + 1) / 2;
}

unsigned long long int f_b(unsigned long long int n)
{
	return n * ((n + 1) / 2) + 1;
}

unsigned long long int f_c(unsigned long long int n)
{
	return n * (n + 1);
}

int main(void)
{
	unsigned long long int n;
	std::cin >> n;

	if (n < 0)
	{
		std::cout << "ERROR" << "\n";
		handle_program_termination();
		return 0;
	}

	unsigned long long int a = 1;
	unsigned long long int b = f_c(n) - n + 1;
	for (unsigned long long int i = n; i > 0; i--)
	{
		for (unsigned long long int j = 0; j < (n - i); j++)
		{
			std::cout << "  ";
		}

		for (unsigned long long int j = 0; j < i; j++)
		{
			std::cout << a++ << "*";
		}
		
		for (unsigned long long int j = 0; j < i; j++)
		{
			std::cout << b + j;
			if (j < i - 1)
			{
				std::cout << "*";
			}
		}
		std::cout << "\n";
		
		b -= i - 1;
	}

	handle_program_termination();
	return 0;
}