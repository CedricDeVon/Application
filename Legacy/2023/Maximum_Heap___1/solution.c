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

MaximumHeap MaximumHeap_allocate(unsigned int maximum_size)
{
	if (maximum_size < 1)
	{
		return NULL;
	}

	MaximumHeap heap = (MaximumHeap) malloc(sizeof(struct maximum_heap));
	heap->items = (long long int*) malloc(sizeof(long long int) * maximum_size);
	heap->current_size = 0;
	heap->maximum_size = maximum_size;

	return heap;
}

MaximumHeap MaximumHeap_deallocate(MaximumHeap heap)
{
	if (heap == NULL)
	{
		return NULL;
	}

	heap->items = NULL;
	heap->current_size = 0;
	heap->maximum_size = 0;
	free(heap);

	return heap;
}

void MaximumHeap_display(MaximumHeap heap)
{
	if (heap == NULL || heap->current_size == 0)
	{
		printf("[] \n");
		return;
	}

	printf("[");
	for (unsigned int index = 0; index < heap->current_size; index++)
	{
		printf("%lld", heap->items[index]);
		if (index < heap->current_size - 1)
		{
			printf(", ");
		}
	}
	printf("] \n");
}

bool MaximumHeap_is_empty(MaximumHeap heap)
{
	return (heap != NULL && heap->current_size < 1);
}

bool MaximumHeap_is_not_empty(MaximumHeap heap)
{
	return !MaximumHeap_is_empty(heap);
}

bool MaximumHeap_is_full(MaximumHeap heap)
{
	return (heap != NULL && heap->current_size > heap->maximum_size - 1);
}

bool MaximumHeap_is_not_full(MaximumHeap heap)
{
	return !MaximumHeap_is_full(heap);
}

void MaximumHeap_clear(MaximumHeap heap)
{
	if (heap == NULL)
	{
		return;
	}

	heap->current_size = 0;
}

MaximumHeap MaximumHeap_copy(MaximumHeap heap)
{
	if (MaximumHeap_is_empty(heap))
	{
		return NULL;
	}

	MaximumHeap copy = MaximumHeap_allocate(heap->current_size);
	for (unsigned int index = 0; index < heap->current_size; index++)
	{
		copy->items[index] = heap->items[index];
	}
	copy->current_size = heap->current_size;

	return copy;
}

long long int* MaximumHeap_convert_from_heap_to_array(MaximumHeap heap)
{
	if (MaximumHeap_is_empty(heap))
	{
		return NULL;
	}

	long long int* array = (long long int*) malloc(sizeof(long long int) * heap->current_size);
	for (unsigned int index = 0; index < heap->current_size; index++)
	{
		array[index] = heap->items[index];
	}

	return array;
}

MaximumHeap MaximumHeap_convert_from_array_to_heap(long long int* array, unsigned int size)
{
	if (array == NULL || size < 1)
	{
		return NULL;
	}

	MaximumHeap heap = MaximumHeap_allocate(size);
	for (unsigned int index = 0; index < size; index++)
	{
		heap->items[index] = array[index];
	}

	return heap;
}

unsigned int __MaximumHeap_get_parent_index(unsigned int current_index)
{
	return (current_index - 1) / 2;
}

unsigned int __MaximumHeap_get_left_child_index(unsigned int current_index)
{
	return current_index * 2 + 1;
}

unsigned int __MaximumHeap_get_right_child_index(unsigned int current_index)
{
	return current_index * 2 + 2;
}

void __MaximumHeap_insert(MaximumHeap heap, unsigned int current_index)
{
	unsigned int parent_index = __MaximumHeap_get_parent_index(current_index);
	if (heap->items[parent_index] < heap->items[current_index])
	{
		long long int temporary_value = heap->items[parent_index];
		heap->items[parent_index] = heap->items[current_index];
		heap->items[current_index] = temporary_value;
		__MaximumHeap_insert(heap, parent_index);
	}
}

void MaximumHeap_insert(MaximumHeap heap, long long int value)
{
	if (MaximumHeap_is_full(heap))
	{
		return;
	}

	heap->items[heap->current_size] = value;
	__MaximumHeap_insert(heap, heap->current_size);
	heap->current_size++;
}

void __MaximumHeap_heapify(MaximumHeap heap, unsigned int current_index)
{
	unsigned int left_child_index = __MaximumHeap_get_left_child_index(current_index);
	unsigned int right_child_index = __MaximumHeap_get_right_child_index(current_index);
	unsigned int target_index = current_index;

	if (left_child_index < 0 || left_child_index > heap->current_size - 1 ||
		right_child_index < 0 || right_child_index > heap->current_size - 1)
	{
		return;
	}

	if (heap->items[left_child_index] > heap->items[current_index])
	{
		target_index = left_child_index;
	}
	if (heap->items[right_child_index] > heap->items[target_index])
	{
		target_index = right_child_index;
	}

	if (heap->items[target_index] > heap->items[current_index])
	{
		long long int temporary_value = heap->items[target_index];
		heap->items[target_index] = heap->items[current_index];
		heap->items[current_index] = temporary_value;
		__MaximumHeap_heapify(heap, target_index);
	}
}

long long int MaximumHeap_remove_maximum(MaximumHeap heap)
{
	if (MaximumHeap_is_empty(heap))
	{
		return 0;
	}

	long long int value = heap->items[0];
	heap->items[0] = heap->items[heap->current_size - 1];
	heap->current_size--;
	__MaximumHeap_heapify(heap, 0);

	return value;
}

long long int MaximumHeap_replace_maximum(MaximumHeap heap, long long int new_value)
{
	if (MaximumHeap_is_empty(heap))
	{
		return 0;
	}

	long long int value = heap->items[0];
	heap->items[0] = new_value;
	__MaximumHeap_heapify(heap, 0);

	return value;
}

long long int MaximumHeap_get_maximum(MaximumHeap heap)
{
	return (MaximumHeap_is_not_empty(heap)) ? heap->items[0] : 0;
}

void MaximumHeap_merge(MaximumHeap target_heap, MaximumHeap other_heap)
{
	if (target_heap == NULL || MaximumHeap_is_empty(other_heap))
	{
		return;
	}

	for (unsigned int index = 0; index < other_heap->current_size; index++)
	{
		MaximumHeap_insert(target_heap, other_heap->items[index]);
	}
}

MaximumHeap MaximumHeap_combine(MaximumHeap heap_a, MaximumHeap heap_b)
{
	if (heap_a == NULL || MaximumHeap_is_empty(heap_b))
	{
		return NULL;
	}

	MaximumHeap heap_c = MaximumHeap_allocate(heap_a->current_size + heap_b->current_size);
	for (unsigned int index = 0; index < heap_a->current_size; index++)
	{
		MaximumHeap_insert(heap_c, heap_a->items[index]);
	}
	for (unsigned int index = 0; index < heap_b->current_size; index++)
	{
		MaximumHeap_insert(heap_c, heap_b->items[index]);
	}

	return heap_c;
}

MaximumHeap MaximumHeap_meld(MaximumHeap* pointer_heap_a, MaximumHeap* pointer_heap_b)
{
	if (pointer_heap_a == NULL || pointer_heap_b == NULL ||
		*pointer_heap_a == NULL || MaximumHeap_is_empty(*pointer_heap_b))
	{
		return NULL;
	}

	MaximumHeap heap_a = *pointer_heap_a;
	MaximumHeap heap_b = *pointer_heap_b;
	MaximumHeap heap_c = MaximumHeap_allocate(heap_a->current_size + heap_b->current_size);
	for (unsigned int index = 0; index < heap_a->current_size; index++)
	{
		MaximumHeap_insert(heap_c, heap_a->items[index]);
	}
	for (unsigned int index = 0; index < heap_b->current_size; index++)
	{
		MaximumHeap_insert(heap_c, heap_b->items[index]);
	}

	*pointer_heap_a = MaximumHeap_deallocate(heap_a);
	*pointer_heap_b = MaximumHeap_deallocate(heap_b);

	return heap_c;
}
