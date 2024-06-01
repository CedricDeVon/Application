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

bool is_a_digit(char character)
{
	return ('0' - 1) < character && character < ('9' + 1);
}

bool is_an_operator(char character)
{
	return character == '+' || character == '-' ||
		character == '*' || character == '/' || character == '%' ||
		character == '^';
}

int evaluate_expression(int value_1, char operator, int value_2)
{
	switch (operator)
	{
		case '+' : return value_1 + value_2;
		case '-' : return value_1 - value_2;
		case '*' : return value_1 * value_2;
		case '/' : return value_1 / value_2;
		case '%' : return value_1 % value_2;
		case '^' : return pow(value_1, value_2);
	}

	return 0;
}

int calculate_precedence(char operator)
{
	if (operator == '+' || operator == '-')
	{
		return 1;
	}
	else if (operator == '*' || operator == '/' || operator == '%')
	{
		return 2;
	}
	else if (operator == '^')
	{
		return 3;
	}

	return 0;
}

int solution(char* infix_expression, int size)
{
	Stack operands = Stack_allocate();
	Stack operators = Stack_allocate();
	for (int index = 0; index < size; index++)
	{
		if (infix_expression[index] == ' ')
		{
			continue;
		}
		else if (infix_expression[index] == '(')
		{
			Stack_push(operators, '(');
		}
		else if (is_a_digit(infix_expression[index]))
		{
			int value = 0;
			while (index < size && is_a_digit(infix_expression[index]))
			{
				value = (value * 10) + (infix_expression[index] - '0');
				index++;
			}	
			Stack_push(operands, value);
			index--;
		}
		else if (infix_expression[index] == ')')
		{
			while (!Stack_is_empty(operators) && Stack_peak(operators) != '(')
			{
				int value_2 = Stack_pop(operands);
				int value_1 = Stack_pop(operands);
				char operator = Stack_pop(operators);

				Stack_push(operands, evaluate_expression(value_1, operator, value_2));
			}

			if (!Stack_is_empty(operators))
			{
				Stack_pop(operators);
			}
		}
		else
		{
			while (!Stack_is_empty(operators) &&
				calculate_precedence(Stack_peak(operators)) >=
				calculate_precedence(infix_expression[index]))
			{
				int value_2 = Stack_pop(operands);
				int value_1 = Stack_pop(operands);
				char operator = Stack_pop(operators);

				Stack_push(operands, evaluate_expression(value_1, operator, value_2));
			}

			Stack_push(operators, infix_expression[index]);
		}
	}

	while (!Stack_is_empty(operators))
	{
		int value_2 = Stack_pop(operands);
		int value_1 = Stack_pop(operands);
		char operator = Stack_pop(operators);

		Stack_push(operands, evaluate_expression(value_1, operator, value_2));
	}

	int value = Stack_peak(operands);
	Stack_deallocate(operands);
	Stack_deallocate(operators);

	return value;
}
