#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stack.h"

Node* Node_allocate(int value)
{
	Node* node = (Node*) malloc(sizeof(Node));
	node->value = value;
	node->next_node = NULL;

	return node;
}

Node* Node_deallocate(Node* node)
{
	node->value = 0;
	node->next_node = NULL;
	free(node);
	node = NULL;

	return node;
}

Stack* Stack_allocate(int maximum_size)
{
	Stack* stack = (Stack*) malloc(sizeof(Stack));
	stack->maximum_size = maximum_size;
	stack->current_size = 0;
	stack->tail_node = NULL;

	return stack;
}

Stack* Stack_deallocate(Stack* stack)
{
	Node* current_node = stack->tail_node->next_node;
	while (current_node != stack->tail_node)
	{
		Node* target_node = current_node;
		current_node = current_node->next_node;
		Node_deallocate(target_node);
	}
	Node_deallocate(current_node);

	stack->current_size = 0;
	stack->maximum_size = 0;
	stack->tail_node = NULL;
	free(stack);
	stack = NULL;

	return stack;
}

void Stack_push(Stack* stack, int value)
{
	if (Stack_is_full(stack))
	{
		return;
	}

	Node* new_node = Node_allocate(value);
	if (stack->tail_node == NULL)
	{
		stack->tail_node = new_node;
		new_node->next_node = new_node;
	}
	else
	{
		Node* temporary_node = stack->tail_node->next_node;
		stack->tail_node->next_node = new_node;
		stack->tail_node = new_node;
		new_node->next_node = temporary_node;
	}
	stack->current_size++;
}

void Stack_pop(Stack* stack)
{
	if (Stack_is_empty(stack))
	{
		return;
	}

	if (stack->tail_node->next_node == stack->tail_node)
	{
		Node_deallocate(stack->tail_node);
		stack->tail_node = NULL;
	}
	else
	{
		Node* target_node = stack->tail_node->next_node;
		Node* temporary_node = target_node->next_node;
		stack->tail_node->next_node = temporary_node;
		Node_deallocate(target_node);
	}
	stack->current_size--;
}

int Stack_peak(Stack* stack)
{
	return (stack->tail_node != NULL) ? stack->tail_node->value : -1;
}

bool Stack_is_empty(Stack* stack)
{
	return stack->current_size == 0;
}

bool Stack_is_full(Stack* stack)
{
	return stack->current_size == stack->maximum_size;
}

void Stack_display(Stack* stack)
{
	if (stack->tail_node == NULL)
	{
		printf("[]\n");
		return;
	}

	printf("[");
	Node* node = stack->tail_node->next_node;
	while (node != stack->tail_node)
	{
		printf("%d", node->value);
		if (node != stack->tail_node)
		{
			printf(", ");
		}
		node = node->next_node;
	}
	printf("%d", node->value);
	printf("]\n");
}