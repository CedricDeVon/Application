#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

void handle_exit_code();
void swap(std::string& value, int i, int j);
void solve(std::string& value, int i);

int main(void)
{
	std::string input;
	std::cin >> input;
	
	solve(input, 0);

	handle_exit_code();
	return 0;
}

void handle_exit_code()
{
	int exit_code = 0;
	std::cin >> exit_code;
}

void swap(std::string& value, int i, int j)
{
	char t = value[i];
	value[i] = value[j];
	value[j] = t;
}

void solve(std::string& value, int i)
{
	if (i == value.size())
	{
		std::cout << value << "\n";
		return;
	}
	for (int t = i; t < value.size(); t++)
	{
		swap(value, i, t);
		solve(value, i + 1);
		swap(value, i, t);
	}
}
