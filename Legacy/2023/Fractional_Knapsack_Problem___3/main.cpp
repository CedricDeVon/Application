#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

typedef struct Item
{
	double price;
	double weight;

} item;

bool compare(Item a, Item b)
{
	double aa = (double) a.price / (double) a.weight;
	double bb = (double) b.price / (double) b.weight;
	return aa > bb;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n = 0;
	double w = 0.0;
	std::cin >> n >> w;

	Item items[n];
	for (int i = 0; i < n; i++)
	{
		std::cin >> items[i].price;
		std::cin >> items[i].weight;
	}

	std::sort(items, items + n, compare);

	double output = 0.0;
	for (int i = 0; i < n; i++)
	{
		if (items[i].weight <= w)
		{
			output += (double) items[i].price;
			w -= (double) items[i].weight;
		}
		else
		{
			output += items[i].price * (w / items[i].weight);
		}
	}

	std::cout << output;

	int exit_code = 0;
	std::cin >> exit_code;

	return 0;
}
