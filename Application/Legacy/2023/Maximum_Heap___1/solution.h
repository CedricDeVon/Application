#ifndef SOLUTION_H
#define SOLUTION_H

typedef struct maximum_heap
{
	long long int* items;
	unsigned int current_size;
	unsigned int maximum_size;

} *MaximumHeap;

MaximumHeap MaximumHeap_allocate(unsigned int maximum_size);
/*
time < 1 s

[NULL]
-1
0

[Object]
1
10
1,000
1,000,000
*/

MaximumHeap MaximumHeap_deallocate(MaximumHeap heap);
/*
time < 1 s

[NULL]
NULL
heap items is NULL
heap maximum size is 1
heap maximum size is 10
heap maximum size is 1,000
heap maximum size is 1,000,000
*/

bool MaximumHeap_is_empty(MaximumHeap heap);
/*
time < 1 s

[false]
NULL
heap current size is 1
heap current size is 10
heap current size is 1,000
heap current size is 1,000,000

[true]
heap current size is 0
*/

bool MaximumHeap_is_not_empty(MaximumHeap heap);
/*
time < 1 s

[false]
NULL
heap current size is 0

[true]
heap current size is 1
heap current size is 10
heap current size is 1,000
heap current size is 1,000,000
*/

bool MaximumHeap_is_full(MaximumHeap heap);
/*
time < 1 s

[false]
NULL
heap current size is (heap maximum size - 1)
	heap maximum size is 1
	heap maximum size is 10
	heap maximum size is 1,000
	heap maximum size is 1,000,000

[true]
heap current size is equal to heap maximum size
	heap maximum size is 1
	heap maximum size is 10
	heap maximum size is 1,000
	heap maximum size is 1,000,000
*/

bool MaximumHeap_is_not_full(MaximumHeap heap);
/*
time < 1 s

[false]
NULL
heap current size is equal to heap maximum size
	heap maximum size is 1
	heap maximum size is 10
	heap maximum size is 1,000
	heap maximum size is 1,000,000

[true]
heap current size is (heap maximum size - 1)
	heap maximum size is 1
	heap maximum size is 10
	heap maximum size is 1,000
	heap maximum size is 1,000,000
*/

void MaximumHeap_clear(MaximumHeap heap);
/*
time < 1 s

[abort]
NULL	

[success]
heap maximum size is 1
heap maximum size is 10
heap maximum size is 1,000
heap maximum size is 1,000,000
*/

MaximumHeap MaximumHeap_copy(MaximumHeap heap);
/*
time < 1 s

[abort]
NULL
heap current size is 0

[success]
heap current size is 1
heap current size is 10
heap current size is 1,000
heap current size is 1,000,000
*/

long long int* MaximumHeap_convert_from_heap_to_array(MaximumHeap heap);
/*
time < 1 s

[abort]
NULL
heap current size is 0

[success]
heap current size is 1
heap current size is 10
heap current size is 1,000
heap current size is 1,000,000
*/

MaximumHeap MaximumHeap_convert_from_array_to_heap(long long int* array, unsigned int size);
/*
time < 1 s

[abort]
array is NULL
size is -1
size is 0

[success]
size is 1
size is 10
size is 1,000
size is 1,000,000
*/

unsigned int __MaximumHeap_get_parent_index(unsigned int current_index);
unsigned int __MaximumHeap_get_left_child_index(unsigned int current_index);
unsigned int __MaximumHeap_get_right_child_index(unsigned int current_index);
void __MaximumHeap_insert(MaximumHeap heap, unsigned int current_index);
void __MaximumHeap_heapify(MaximumHeap heap, unsigned int current_index);
void MaximumHeap_insert(MaximumHeap heap, long long int value);

/*
time < 1 s

[abort]
heap is NULL
heap current size is equal to maximum size
	maximum size is 1
	maximum size is 10
	maximum size is 1,000
	maximum size is 1,000,000

[success]
from heap maximum size to 0
from 0 to heap maximum size
from -(heap maximum size) to 0
from 0 to -(heap maximum size)
from -(heap maximum size / 2) to (heap maximum size / 2)
	1
	10
	1,000
	1,000,000
*/

long long int MaximumHeap_remove_maximum(MaximumHeap heap);
/*
time < 1 s

[abort]
heap is NULL
heap is empty

[success]
heap current size
	1
	10
	1,000
	1,000,000
*/

long long int MaximumHeap_replace_maximum(MaximumHeap heap, long long int new_value);
/*
time < 1 s

[abort]
heap is NULL
heap is empty

[success]
new value is
	less
	greater
	equal
heap current size
	1
	10
	1,000
	1,000,000
*/

long long int MaximumHeap_get_maximum(MaximumHeap heap);
/*
time < 1 s

[abort]
heap is NULL
heap is empty

[success]
from heap maximum size to 0
from 0 to heap maximum size
from -(heap maximum size) to 0
from 0 to -(heap maximum size)
from -(heap maximum size / 2) to (heap maximum size / 2)
	1
	10
	1,000
	1,000,000
*/

void MaximumHeap_merge(MaximumHeap target_heap, MaximumHeap other_heap);
/*
time < 1 s

[abort]
target heap is null
other heap is null
other heap is empty

[success]
target heap current size is:
	0
	1
	10
	1,000
	1,000,000
other heap current size is:
	1
	10
	1,000
	1,000,000
*/

MaximumHeap MaximumHeap_combine(MaximumHeap heap_a, MaximumHeap heap_b);
/*
time < 1 s

[abort]
heap_a is null
heap_b is null
heap_a and b size is less than 1

[success]
heap_a current size is:
	0
	1
	10
	1,000
	1,000,000
heap_b current size is:
	1
	10
	1,000
	1,000,000
*/

MaximumHeap MaximumHeap_meld(MaximumHeap* pointer_heap_a, MaximumHeap* pointer_heap_b);
/*
time < 1 s

[abort]
heap_a is null
heap_b is null
heap_a value is null
heap_b value is null
heap_a and b size is less than 1

[success]
heap_a current size is:
	0
	1
	10
	1,000
	1,000,000
heap_b current size is:
	1
	10
	1,000
	1,000,000
*/

#endif
