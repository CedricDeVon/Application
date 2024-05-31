#ifndef SOLUTION_H
#define SOLUTION_H

typedef struct item
{
	float weight;
	float price;
	float ratio;

} *Item;

Item Item_allocate();
void Item_deallocate(Item item);
void Items_sort(Item* items, int size);

#endif