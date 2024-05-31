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

int main(void)
{
	Heap heap_a = Heap_allocate(10);
	Heap_insert(heap_a, 10);
	Heap_insert(heap_a, 9);
	Heap_insert(heap_a, 8);
	Heap_display(heap_a);

	Heap heap_b = Heap_allocate(20);
	Heap_insert(heap_b, 7);
	Heap_insert(heap_b, 6);
	Heap_insert(heap_b, 5);
	Heap_display(heap_b);

	Heap heap_c = Heap_merge(heap_a, heap_b);
	Heap_display(heap_c);

	Heap* heap_a_p = &heap_a;
	Heap* heap_b_p = &heap_b;
	Heap heap_d = Heap_meld(heap_a_p, heap_b_p);
	Heap_display(heap_d);
	Heap_display(heap_a);
	Heap_display(heap_b);

	int exit_code = 0;
	scanf("%d", &exit_code);

	return 0;
}