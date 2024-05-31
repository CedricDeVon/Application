#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <windows.h>

#include "solution.h"

Node Node_allocate(int value)
{
	Node node = (Node) malloc(sizeof(struct node));
	node->value = value;
	node->next_node = NULL;

	return node;
}

void Node_deallocate(Node node)
{
	free(node);
	node = NULL;
}

Stack Stack_allocate()
{
	Stack stack = (Stack) malloc(sizeof(struct stack));
	stack->size = 0;
	stack->head_node = NULL;

	return stack;
}

void Stack_deallocate(Stack stack)
{
	Node current_node = stack->head_node;
	while (current_node != NULL)
	{
		Node target_node = current_node;
		current_node = current_node->next_node;
		Node_deallocate(target_node);
	}
	free(stack);
	stack = NULL;
}

bool Stack_is_empty(Stack stack)
{
	return stack->head_node == NULL;
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
	if (Stack_is_empty(stack))
	{
		return 0;
	}

	Node target_node = stack->head_node;
	int value = target_node->value;
	stack->head_node = target_node->next_node;
	Node_deallocate(target_node);
	stack->size--;

	return value;
}

int Stack_peak(Stack stack)
{
	return (stack->head_node != NULL) ? stack->head_node->value : 0;
}

int solution(char* expression)
{
	Stack stack = Stack_allocate();
	int size = strlen(expression);
	for (int index = 0; index < size; index++)
	{
		char c = expression[index];
		if (('0' - 1) < c && c < ('9' + 1))
		{
			Stack_push(stack, c - '0');
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^')
		{
			int y = Stack_pop(stack);
			int x = Stack_pop(stack);
			switch (c)
			{
				case '+':
					Stack_push(stack, x + y);
					break;

				case '-':
					Stack_push(stack, x - y);
					break;

				case '*':
					Stack_push(stack, x * y);
					break;

				case '/':
					Stack_push(stack, x / y);
					break;

				case '%':
					Stack_push(stack, x % y);
					break;

				case '^':
					Stack_push(stack, (int) pow(x, a));
					break;
			}
		}
	}

	return Stack_peak(stack);
}
