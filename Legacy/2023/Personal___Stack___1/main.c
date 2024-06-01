#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stack.h"

int main(void)
{
	// [1, 2, 3, 4, 5]
	
	Stack* stack = Stack_allocate(10);
	Stack_push(stack, 1);
	Stack_push(stack, 2);
	Stack_push(stack, 3);
	Stack_display(stack);
	
	Stack_pop(stack);
	Stack_pop(stack);
	Stack_pop(stack);
	Stack_display(stack);

	Stack_push(stack, 1);
	Stack_push(stack, 2);
	Stack_push(stack, 3);
	Stack_push(stack, 4);
	Stack_display(stack);

	Stack_push(stack, 5);
	Stack_push(stack, 6);
	Stack_push(stack, 7);
	Stack_push(stack, 8);
	Stack_push(stack, 9);
	Stack_display(stack);

	Stack_deallocate(stack);

	int exit_code = 0;
	scanf("%d", &exit_code);
	return 0;
}
