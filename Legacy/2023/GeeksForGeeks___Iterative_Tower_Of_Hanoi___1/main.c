#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <windows.h>
#include <ctype.h>

typedef struct node
{
	int value;
	struct node* next_node;

} *Node;

Node Node_allocate(int value)
{
	Node node = (Node) malloc(sizeof(struct node));
	node->value = value;
	node->next_node = NULL;

	return node;
}

Node Node_deallocate(Node node)
{
	node->value = 0;
	node->next_node = NULL;
	free(node);
	node = NULL;

	return node;
}

typedef struct stack
{
	int size;
	Node head_node;

} *Stack;

Stack Stack_allocate()
{
	Stack stack = (Stack) malloc(sizeof(struct stack));
	stack->size = 0;
	stack->head_node = NULL;

	return stack;
}

Stack Stack_deallocate(Stack stack)
{
	Node current_node = stack->head_node;
	while (current_node != NULL)
	{
		Node target_node = current_node;
		current_node = current_node->next_node;
		Node_deallocate(target_node);
	}

	stack->size = 0;
	stack->head_node = NULL;
	free(stack);
	stack = NULL;

	return stack;
}

void Stack_push(Stack stack, int value)
{
	Node new_node = Node_allocate(value);
	new_node->next_node = stack->head_node;
	stack->head_node = new_node;
	stack->size++;
}

int Stack_pop(Stack stack)
{
	Node target_node = stack->head_node;
	int value = target_node->value;
	stack->head_node = target_node->next_node;
	Node_deallocate(target_node);
	stack->size--;

	return value;
}

int Stack_peak(Stack stack)
{
	return (stack->head_node != NULL) ? stack->head_node->value : -1;
}

bool Stack_is_empty(Stack stack)
{
	return stack->head_node == NULL;
}

void Stack_display(Stack stack)
{
	Node node = stack->head_node;
	printf("[");
	while (node != NULL)
	{
		printf("%d", node->value);
		if (node->next_node != NULL)
		{
			printf(", ");
		}
		node = node->next_node;
	}
	printf("]\n");
}

void Stacks_display(Stack* stacks, int n)
{
	for (int i = 0; i < n; i++)
	{
		Stack_display(stacks[i]);
	}
	printf("\n");
}

void solution()
{
	int n = 0;
	scanf("%d", &n);
	int max = pow(2, n) - 1;
	Stack* stacks = (Stack*) malloc(sizeof(Stack) * 3);
	for (int i = 0; i < 3; i++)
	{
		stacks[i] = Stack_allocate();
	}
	for (int i = n; i > 0; i--)
	{
		Stack_push(stacks[0], i);
	}

	Stacks_display(stacks, 3);
	for (int i = 1; i < max + 1; i++)
	{
		int x = 0;
		int y = 2;
		if (i % 3 == 0)
		{
			x = 1;
		}
		else if (i % 3 == 2)
		{
			y = 1;
		}

		if (!Stack_is_empty(stacks[x]) && Stack_is_empty(stacks[y]))
		{
			Stack_push(stacks[y], Stack_pop(stacks[x]));
		}
		else if (Stack_is_empty(stacks[x]) && !Stack_is_empty(stacks[y]))
		{
			Stack_push(stacks[x], Stack_pop(stacks[y]));
		}
		else if (Stack_peak(stacks[x]) < Stack_peak(stacks[y]))
		{
			Stack_push(stacks[y], Stack_pop(stacks[x]));
		}
		else if (Stack_peak(stacks[x]) > Stack_peak(stacks[y]))
		{
			Stack_push(stacks[x], Stack_pop(stacks[y]));
		}
	}
	Stacks_display(stacks, 3);
}

int main(void)
{
	solution();

	int exit_code = 0;
	scanf("%d", &exit_code);
	return 0;
}