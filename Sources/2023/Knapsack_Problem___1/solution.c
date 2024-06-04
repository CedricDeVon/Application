#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include <ctype.h>

#include "solution.h"

Item Item_allocate()
{
	Item item = (Item) malloc(sizeof(struct item));
	item->weight = 0;
	item->price = 0;
	item->ratio = 0;

	return item;
}

void Item_deallocate(Item item)
{
	free(item);
}

void Items_sort(Item* items, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			Item a = items[i];
			Item b = items[j];
			if (a->ratio > b->ratio)
			{
				items[i] = b;
				items[j] = a;
			}
		}
	}
}
