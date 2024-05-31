// #include <ctime>
// #include <cmath>
// #include <cctype>
// #include <cstdlib>
// #include <climits>
// #include <numeric>
// #include <iostream>
// #include <algorithm>
// #include <exception>

// #include <string>
// #include <sstream>
// #include <array>
// #include <vector>
// #include <list>
// #include <forward_list>
// #include <stack>
// #include <queue>
// #include <map>
// #include <unordered_map>
// #include <set>
// #include <unordered_set>

// g++ -Wall main.cpp -o main.exe

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

	return 0;
}

void solve()
{
	std::string input;
	std::cin >> input;
	
	if (input.length() < 2 ||
		input.length() == 2 &&
			input.at(0) == input.at(1))
	{
		std::cout << input;
		return;
	}

	std::string palindrome = "";
	for (int i = input.length() - 1; i > 1; i--)
	{
		char c_i = input.at(i); 
		int j = i + 2;
		for (; j > 0; j--)
		{
			char c_j = input.at(j);
			if (c_i == c_j &&
				i - j + 1 > palindrome.length())
			{
				break;
			}
		}

		bool is_valid = true;
		int c = i;
		int d = j;
		while (is_valid && c > d)
		{
			if (input.at(c) != input.at(d))
			{
				is_valid = false;
			}
			else
			{
				c--;
				d++;
			}
		}
		if (is_valid)
		{
			palindrome = input.substr(j, i);
		}
	}

	std::cout << palindrome;
}


