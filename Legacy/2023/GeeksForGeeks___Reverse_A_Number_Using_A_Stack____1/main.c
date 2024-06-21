#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <windows.h>

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
	if (stack->head_node == NULL)
	{
		return -1;
	}

	int value = stack->head_node->value;
	if (stack->head_node->next_node == NULL)
	{
		Node_deallocate(stack->head_node);
		stack->head_node = NULL;
	}
	else
	{
		Node temporary_node = stack->head_node;
		stack->head_node = temporary_node->next_node;
		Node_deallocate(temporary_node);
	}
	stack->size--;

	return value;
}

int Stack_peak(Stack stack)
{
	return stack->head_node != NULL ? stack->head_node->value : -1;
}

bool Stack_is_empty(Stack stack)
{
	return stack->head_node == NULL;
}

void Stack_display(Stack stack)
{
	Node node = stack->head_node;
	while (node != NULL)
	{
		printf("%d", node->value);
		if (node->next_node != NULL)
		{
			printf(" -> ");
		}
		node = node->next_node;
	}
}

void Stack_reverse(Stack stack)
{
	int size = stack->size;
	int values[size];
	for (int i = 0; i < size; i++)
	{
		values[i] = Stack_pop(stack);
	}
	for (int i = 0; i < size; i++)
	{
		Stack_push(stack, values[i]);
	}
}

int Stack_to_integer(Stack stack)
{
	int mod = 1;
	int output = 0;
	Node node = stack->head_node;
	while (node != NULL)
	{
		output += (node->value * mod);
		mod *= 10;
		node = node->next_node;
	}

	return output;
}

int main(void)
{
	int input = 0;
	scanf("%d", &input);

	Stack stack = Stack_allocate();
	while (input > 0)
	{
		Stack_push(stack, input % 10);
		input /= 10;
	}

	printf("%d\n", Stack_to_integer(stack));

	int exit_code = 0;
	scanf("%d", &exit_code);
	return 0;
}