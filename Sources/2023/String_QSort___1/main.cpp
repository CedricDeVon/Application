#include <bits/stdc++.h>

#define MAX_INPUT_SIZE 3

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

void solve();
void print(std::array<int, MAX_INPUT_SIZE>);

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	// std::cin.tie(NULL);
	// std::cout.tie(NULL);

	srand(time(NULL));

	solve();

	int exit_code;
	std::cin >> exit_code;
	return 0;
}

void print(std::array<int, MAX_INPUT_SIZE> values)
{
	for (int value : values)
	{
		std::cout << value << " ";
	}
	std::cout << "\n";
}

void solve()
{
	std::array<int, MAX_INPUT_SIZE> inputs;
	for (int i = 0; i < MAX_INPUT_SIZE; i++)
	{
		inputs[i] = (rand() % (MAX_INPUT_SIZE + 1));
	}
	print(inputs);

	sort(inputs.begin(), inputs.end(), std::greater<int>());
	print(inputs);

	sort(inputs.begin(), inputs.end(), std::less<int>());
	print(inputs);
}
