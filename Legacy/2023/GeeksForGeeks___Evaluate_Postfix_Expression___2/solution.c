#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <windows.h>
#include <limits.h>

#include "solution.h"

Node Node_allocate(int value)
{
	Node node = (Node) malloc(sizeof(struct node));
	node->value = value;
	node->next = NULL;

	return node;
}
	
Stack Stack_allocate()
{
	Stack stack = (Stack) malloc(sizeof(struct stack));
	stack->size = 0;
	stack->head = NULL;

	return stack;
}
	
void Node_deallocate(Node node)
{
	node->value = 0;
	node->next = NULL;
	free(node);
}
	
void Stack_deallocate(Stack stack)
{
	Node current_node = stack->head;
	while (current_node != NULL)
	{
		Node temporary_node = current_node;
		current_node = current_node->next;
		Node_deallocate(temporary_node);
	}
	stack->size = 0;
	stack->head = NULL;
	free(stack);
}
	
void Stack_push(Stack stack, int value)
{
	Node new_node = Node_allocate(value);
	new_node->next = stack->head;
	stack->head = new_node;
	stack->size++;
}
	
int Stack_pop(Stack stack)
{
	if (stack->head == NULL)
	{
		return ' ';
	}

	Node temporary_node = stack->head;
	int value = temporary_node->value;
	stack->head = temporary_node->next;
	Node_deallocate(temporary_node);
	stack->size--;

	return value;
}
	
int Stack_peak(Stack stack)
{
	if (stack->head == NULL)
	{
		return ' ';
	}

	return (stack->head != NULL) ? stack->head->value : -1;
}
	
bool Stack_is_empty(Stack stack)
{
	return stack->head == NULL;
}

bool is_an_operand(int character)
{
	return ('0' - 1) < character && character < ('9' + 1);
}

int calculate_expression(int x, char operator, int y)
{
	if (operator == '+')
	{
		return x + y;
	}
	else if (operator == '-')
	{
		return x - y;
	}
	else if (operator == '*')
	{
		return x * y;
	}
	else if (operator == '/')
	{
		return x / y;
	}
	else if (operator == '%')
	{
		return x % y;
	}
	else if (operator == '^')
	{
		return pow(x, y);
	}

	return 0;
}

int solution(char* expression, int size)
{
	Stack operands = Stack_allocate();
	for (int i = 0; i < size; i++)
	{
		char character = expression[i];
		if (is_an_operand(character))
		{
			Stack_push(operands, character - '0');
		}
		else
		{
			char x = Stack_pop(operands);
			char y = Stack_pop(operands);
			Stack_push(operands, calculate_expression(x, character, y));
		}
	}

	int answer = Stack_pop(operands);
	Stack_deallocate(operands);

	return answer;
}	
