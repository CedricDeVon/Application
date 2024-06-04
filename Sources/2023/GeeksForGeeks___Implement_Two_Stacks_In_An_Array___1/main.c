#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <windows.h>
#include <ctype.h>

typedef struct array_stack
{
	int count_a;
	int count_b;
	int size_a;
	int size_b;
	int index_a;
	int index_b;
	int* values;

} *ArrayStack;

ArrayStack ArrayStack_allocate(int size_a, int size_b)
{
	int size = size_a + size_b;
	ArrayStack array_stack = (ArrayStack) malloc(sizeof(struct array_stack));
	array_stack->count_a = 0;
	array_stack->count_b = 0;
	array_stack->size_a = size_a;
	array_stack->size_b = size_b;
	array_stack->index_a = 0;
	array_stack->index_b = size -1;
	array_stack->values = (int*) malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++)
	{
		array_stack->values[i] = 0;
	}

	return array_stack;
}

ArrayStack ArrayStack_deallocate(ArrayStack array_stack)
{
	free(array_stack->values);
	array_stack->values = NULL;
	free(array_stack);
	array_stack = NULL;

	return array_stack;
}

void ArrayStack_push_1(ArrayStack array_stack, int value)
{
	if (array_stack->count_a == array_stack->size_a)
	{
		return;
	}

	array_stack->values[array_stack->index_a++] = value;
	if (array_stack->index_a == array_stack->size_a)
	{
		array_stack->index_a--;
	}
	array_stack->count_a++;
}

void ArrayStack_push_2(ArrayStack array_stack, int value)
{
	if (array_stack->count_b == array_stack->size_b)
	{
		return;
	}

	array_stack->values[array_stack->index_b--] = value;
	if (array_stack->index_b == array_stack->size_a - 1)
	{
		array_stack->index_b++;
	}
	array_stack->count_b++;
}

void ArrayStack_pop_1(ArrayStack array_stack)
{
	if (array_stack->count_a == 0)
	{
		return;
	}

	array_stack->values[array_stack->index_a--] = 0;
	if (array_stack->index_a < 0)
	{
		array_stack->index_a = 0;
	}
	array_stack->count_a--;
}

void ArrayStack_pop_2(ArrayStack array_stack)
{
	if (array_stack->count_b == 0)
	{
		return;
	}

	array_stack->values[array_stack->index_b++] = 0;
	int size = array_stack->size_a + array_stack->size_b;
	if (array_stack->index_b == size)
	{
		array_stack->index_b--;
	}
	array_stack->count_b--;
}

bool ArrayStack_is_empty_1(ArrayStack array_stack)
{
	return array_stack->count_a == 0 && array_stack->index_a == 0;
}

bool ArrayStack_is_empty_2(ArrayStack array_stack)
{
	return array_stack->count_b == 0 &&
		array_stack->index_b == (array_stack->size_a + array_stack->size_b) - 1;
}

void ArrayStack_display(ArrayStack array_stack)
{
	int size = array_stack->size_a + array_stack->size_b;
	printf("[");
	for (int i = 0; i < size; i++)
	{
		printf("%d", array_stack->values[i]);
		if (i < size - 1)
		{
			printf(", ");
		}
	}
	printf("]\n");
}

int main(void)
{
	ArrayStack array_stack = ArrayStack_allocate(3, 2);
	ArrayStack_push_2(array_stack, 6);
	ArrayStack_push_2(array_stack, 7);
	ArrayStack_push_2(array_stack, 8);
	ArrayStack_push_2(array_stack, 9);

	ArrayStack_display(array_stack);

	ArrayStack_push_1(array_stack, 1);
	ArrayStack_push_1(array_stack, 2);
	ArrayStack_push_1(array_stack, 3);
	ArrayStack_push_1(array_stack, 4);
	ArrayStack_push_1(array_stack, 5);

	ArrayStack_display(array_stack);

	ArrayStack_pop_1(array_stack);
	ArrayStack_pop_2(array_stack);

	ArrayStack_display(array_stack);

	ArrayStack_pop_1(array_stack);
	ArrayStack_pop_2(array_stack);
	ArrayStack_display(array_stack);

	ArrayStack_pop_1(array_stack);

	ArrayStack_display(array_stack);

	ArrayStack_pop_1(array_stack);
	ArrayStack_pop_2(array_stack);

	ArrayStack_display(array_stack);

	ArrayStack_push_2(array_stack, 6);
	ArrayStack_push_2(array_stack, 7);
	ArrayStack_push_2(array_stack, 8);
	ArrayStack_push_2(array_stack, 9);

	ArrayStack_display(array_stack);

	ArrayStack_push_1(array_stack, 1);
	ArrayStack_push_1(array_stack, 2);
	ArrayStack_push_1(array_stack, 3);
	ArrayStack_push_1(array_stack, 4);
	ArrayStack_push_1(array_stack, 5);

	ArrayStack_display(array_stack);

	ArrayStack_pop_1(array_stack);
	ArrayStack_pop_1(array_stack);
	ArrayStack_pop_1(array_stack);

	printf("%d %d\n", ArrayStack_is_empty_1(array_stack), ArrayStack_is_empty_2(array_stack));

	ArrayStack_display(array_stack);

	ArrayStack_pop_2(array_stack);
	ArrayStack_pop_2(array_stack);
	ArrayStack_pop_2(array_stack);

	printf("%d %d\n", ArrayStack_is_empty_1(array_stack), ArrayStack_is_empty_2(array_stack));

	ArrayStack_display(array_stack);

	int exit_code = 0;
	scanf("%d", &exit_code);
	return 0;
}