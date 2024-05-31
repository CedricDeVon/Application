#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include <ctype.h>
#include <limits.h>

#include "solution.h"

Heap Heap_allocate(int maximum_size)
{
	Heap heap = (Heap) malloc(sizeof(struct heap));
	heap->items = (int*) malloc(sizeof(int) * maximum_size);
	heap->current_size = 0;
	heap->maximum_size = maximum_size;

	return heap;
}

void Heap_deallocate(Heap heap)
{
	free(heap->items);
	heap->current_size = 0;
	heap->maximum_size = 0;
	free(heap);
}

void Heap_display(Heap heap)
{
	if (heap == NULL)
	{
		printf("[]\n");
		return;
	}

	printf("[");
	for (int i = 0; i < heap->current_size; i++)
	{
		printf("%d", heap->items[i]);
		if (i < heap->current_size - 1)
		{
			printf(", ");
		}
	}
	printf("]\n");
}

int Heap_get_current_size(Heap heap)
{
	return (heap != NULL) ? heap->current_size : -1;
}

bool Heap_is_empty(Heap heap)
{
	return (heap != NULL && heap->current_size <= 0);
}

bool Heap_is_full(Heap heap)
{
	return (heap != NULL && heap->current_size >= heap->maximum_size);
}

Heap Heap_array_to_heap(int* items, int size)
{
	Heap heap = Heap_allocate(size);
	for (int i = 0; i < size; i++)
	{
		Heap_insert(heap, items[i]);
	}

	return heap;
}

int* Heap_heap_to_array(Heap heap)
{
	int* items = (int*) malloc(sizeof(int) * heap->current_size);
	for (int i = 0; i < heap->current_size; i++)
	{
		items[i] = heap->items[i];
	}

	return items;
}

Heap Heap_clone(Heap heap)
{
	Heap copy = Heap_allocate(heap->maximum_size);
	for (int i = 0; i < heap->current_size; i++)
	{
		copy->items[i] = heap->items[i];
	}

	return copy;
}

int Heap_find_min(Heap heap)
{
	return (heap != NULL && heap->current_size > 0) ? heap->items[0] : 0;
}

void __Heap_insert(Heap heap, int current_index)
{
	int parent_index = (current_index - 1) / 2;
	if (heap->items[parent_index] > heap->items[current_index])
	{
		int temporary_value = heap->items[parent_index];
		heap->items[parent_index] = heap->items[current_index];
		heap->items[current_index] = temporary_value;
		__Heap_insert(heap, parent_index);
	}
}

void Heap_insert(Heap heap, int value)
{
	if (Heap_is_full(heap))
	{
		return;
	}

	heap->items[heap->current_size] = value;
	__Heap_insert(heap, heap->current_size);
	heap->current_size++;
}

void __Heap_heapify(Heap heap, int current_index)
{
	int left_child_index = 2 * current_index + 1;
	int right_child_index = 2 * current_index + 2;
	int minimum_index = current_index;

	if ((left_child_index < 0 || left_child_index > heap->current_size - 1) ||
		(right_child_index < 0 || right_child_index > heap->current_size - 1))
	{
		return;
	}
	
	if (heap->items[left_child_index] < heap->items[current_index])
	{
		minimum_index = left_child_index;
	}
	if (heap->items[right_child_index] < heap->items[minimum_index])
	{
		minimum_index = right_child_index;
	}

	if (minimum_index != current_index)
	{
		int temporary_value = heap->items[current_index];
		heap->items[current_index] = heap->items[minimum_index];
		heap->items[minimum_index] = temporary_value;
		__Heap_heapify(heap, minimum_index);
	}
}

int Heap_delete_min(Heap heap)
{
	if (Heap_is_empty(heap))
	{
		return 0;
	}

	int minimum_value = heap->items[0];
	heap->items[0] = heap->items[heap->current_size - 1];
	heap->current_size--;
	__Heap_heapify(heap, 0);

	return minimum_value;
}

void Heap_replace_min(Heap heap, int value)
{
	if (Heap_is_full(heap))
	{
		return;
	}

	heap->items[0] = value;
	__Heap_heapify(heap, 0);
}

Heap Heap_merge(Heap heap_a, Heap heap_b)
{
	Heap merged_heap = Heap_allocate(heap_a->current_size + heap_b->current_size);
	for (int i = 0; i < heap_a->current_size; i++)
	{
		Heap_insert(merged_heap, heap_a->items[i]);
	}
	for (int i = 0; i < heap_b->current_size; i++)
	{
		Heap_insert(merged_heap, heap_b->items[i]);
	}

	return merged_heap;
}

Heap Heap_meld(Heap* heap_a, Heap* heap_b)
{
	Heap melded_heap = Heap_merge(*heap_a, *heap_b);
	Heap_deallocate(*heap_a);
	Heap_deallocate(*heap_b);
	*heap_a = NULL;
	*heap_b = NULL;

	return melded_heap;
}

