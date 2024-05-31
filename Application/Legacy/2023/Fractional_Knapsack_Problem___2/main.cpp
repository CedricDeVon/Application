#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

typedef struct item
{
	double price;
	double weight;

	item(double price, double weight)
	{
		this->price = price;
		this->weight = weight;
	}

} Item;

bool compare(Item first, Item second)
{
	double a = (double) first.price / (double) first.weight;
	double b = (double) second.price / (double) second.weight;
	return a > b;
}

int main(void)
{
	// std::ios_base::sync_with_stdio(false);
	// std::cin.tie(NULL);
	// std::cout.tie(NULL);

	int n, w;
	std::cin >> n >> w;
	std::vector<Item> items;
	for (int i = 0; i < n; i++)
	{
		double a, b;
		std::cin >> a >> b;
		items.push_back({a, b});
	}

	std::sort(items.begin(), items.end(), compare);

	double value = 0.0;
	for (int i = 0; i < n; i++)
	{
		if (items[i].weight <= w)
		{
			value += items[i].price;
			w -= items[i].weight;
		}
		else
		{
			value += items[i].price * ((double) w / (double) items[i].weight);
			break;
		}
	}

	std::cout << value << '\n';

	int exit_code = 0;
	std::cin >> exit_code;

	return 0;
}