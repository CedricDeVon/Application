#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <windows.h>

typedef struct node
{
	int value;
	struct node* next_node;

} Node;

Node* Node_allocate(int value)
{
	Node* node = (Node*) malloc(sizeof(Node));
	node->value = value;
	node->next_node = NULL;

	return node;
}

Node* Node_deallocate(Node* node)
{
	if (node == NULL)
	{
		return NULL;
	}

	node->value = 0;
	node->next_node = NULL;
	free(node);
	node = NULL;

	return node;
}

typedef struct stack
{
	int size;
	Node* head_node;
	Node* tail_node;

} Stack;

Stack* Stack_allocate()
{
	Stack* stack = (Stack*) malloc(sizeof(Stack));
	stack->size = 0;
	stack->head_node = NULL;
	stack->tail_node = NULL;

	return stack;
}

Stack* Stack_deallocate(Stack* stack)
{
	if (stack == NULL)
	{
		return NULL;
	}

	Node* node = stack->head_node;
	while (node != NULL)
	{
		Node* target = node;
		node = node->next_node;
		Node_deallocate(target);
	}
	stack->size = 0;
	stack->head_node = NULL;
	free(stack);
	stack = NULL;

	return stack;
}

void Stack_display(Stack* stack)
{
	if (stack == NULL || stack->head_node == NULL)
	{
		printf("[]\n");
		return;
	}

	printf("[");
	Node* node = stack->head_node;
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

void Stack_push_sorted(Stack* stack, int value)
{
	if (stack == NULL)
	{
		return;
	}

	Node* new_node = Node_allocate(value);
	if (stack->head_node == NULL || stack->tail_node == NULL)
	{
		stack->head_node = new_node;
		stack->tail_node = new_node;
	}
	else if (value <= stack->head_node->value)
	{
		new_node->next_node = stack->head_node;
		stack->head_node = new_node;
	}
	else if (stack->tail_node->value <= value)
	{
		stack->tail_node->next_node = new_node;
		stack->tail_node = new_node;
	}
	else
	{
		Node* current_node = stack->head_node;
		while (current_node != NULL &&
			!(current_node->value <= value &&
				value <= current_node->next_node->value))
		{
			current_node = current_node->next_node;
		}
		Node* temporary_node = current_node->next_node;
		current_node->next_node = new_node;
		new_node->next_node = temporary_node;
	}
	stack->size++;
}

int main(void)
{
	// Insert all before sorting
	// Sort every insertion

	int input_size = 0;
	Stack* stack = Stack_allocate();
	scanf("%d", &input_size);
	// for (int index = 0; index < input_size; index++)
	// {
	// 	int input = 0;
	// 	scanf("%d", &input);
	// 	Stack_push_sorted(stack, input);
	// }
	// Stack_display(stack);

	while (true)
	{
		int input = 0;
		scanf("%d", &input);
		if (input == -1)
		{
			break;
		}

		Stack_push_sorted(stack, input);
	}
	Stack_display(stack);

	stack = Stack_deallocate(stack);
	int exit_code = 0;
	scanf("%d", &exit_code);
	return 0;
}

/*
Test Cases: 

Inputs:
	7
	1 4 3 3 8 5 10
Outputs:
	[1, 3, 3, 4, 5, 8, 10]

Inputs:
	3
	3 3 3
Outputs:
	[3, 3, 3]

Inputs:
	0
Outputs: 
	[]
*/
