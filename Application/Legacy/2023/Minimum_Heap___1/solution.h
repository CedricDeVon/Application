#ifndef SOLUTION_H_INCLUDED
#define SOLUTION_H_INCLUDED

typedef struct heap
{
	int* items;
	int current_size;
	int maximum_size;

} *Heap;

Heap Heap_allocate(int maximum_size);
void Heap_deallocate(Heap heap);
void Heap_display(Heap heap);
int Heap_get_size(Heap heap);
bool Heap_is_empty(Heap heap);
Heap Heap_array_to_heap(int* items, int size);
int* Heap_heap_to_array(Heap heap);
Heap Heap_copy(Heap heap);
int Heap_find_min(Heap heap);
void __Heap_insert(Heap heap, int current_index);
void Heap_insert(Heap heap, int value);
void __Heap_heapify(Heap heap, int current_index);
int Heap_delete_min(Heap heap);
void Heap_replace_min(Heap heap, int value);
Heap Heap_merge(Heap heap_a, Heap heap_b);
Heap Heap_meld(Heap* heap_a, Heap* heap_b);

#endif
