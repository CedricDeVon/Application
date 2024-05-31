#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include <ctype.h>

#include "solution.h"

int main(void)
{
	int item_count = 0;
	float total_price = 0;
	scanf("%d %f", &item_count, &total_price);
	Item* items = (Item*) malloc(sizeof(Item) * item_count);
	for (int index = 0; index < item_count; index++)
	{
		items[index] = Item_allocate();
		scanf("%f %f", &items[index]->weight, &items[index]->price);
		items[index]->ratio = items[index]->weight / items[index]->price;
	}

	Items_sort(items, item_count);

	int temporary_price = 0;
	for (int index = 0; index < item_count; index++)
	{
		Item item = items[index];
		temporary_price += item->price;
		if (temporary_price >= total_price)
		{
			float ratio = (item->price - (temporary_price - total_price)) / item->price;
			item->weight = item->weight * ratio;
			item->price = item->price * ratio;
			printf("%.2f : %.2f\n", item->weight, item->price);
			break;
		}
		else
		{
			printf("%.2f : %.2f\n", item->weight, item->price);
		}
	}

	int exit_code = 0;
	scanf("%d", &exit_code);
	return 0;
}