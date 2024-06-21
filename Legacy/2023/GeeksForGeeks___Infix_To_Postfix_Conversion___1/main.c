#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <ctype.h>

typedef struct node
{
	char value;
	struct node* next_node;

} *Node;

typedef struct stack
{
	int size;
	Node head_node;

} *Stack;

Node Node_allocate(char value)
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

	return stack;
}

void Stack_push(Stack stack, char value)
{
	Node new_node = Node_allocate(value);
	new_node->next_node = stack->head_node;
	stack->head_node = new_node;
	stack->size++;
}

char Stack_pop(Stack stack)
{
	Node target_node = stack->head_node;
	char value = target_node->value;
	stack->head_node = target_node->next_node;
	Node_deallocate(target_node);
	stack->size--;

	return value;
}

char Stack_peak(Stack stack)
{
	return stack->head_node->value;
}

bool Stack_is_empty(Stack stack)
{
	return stack->head_node == NULL;
}

void Stack_reverse(Stack stack)
{
	int size = stack->size;
	char values[stack->size];
	for (int i = 0; i < size; i++)
	{
		values[i] = Stack_pop(stack);
	}
	for (int i = 0; i < size; i++)
	{
		Stack_push(stack, values[i]);
	}
}

void Stack_display(Stack stack)
{
	Node node = stack->head_node;
	while (node != NULL)
	{
		printf("%c", node->value);
		node = node->next_node;
	}
	printf("\n");
}

// "a+b*(c^d-e)^(f+g*h)-i";

int get_precedent(char c)
{
	if (c == '^')
	{
		return 3;
	}
	else if (c == '/' || c == '*' || c == '%')
	{
		return 2;
	}
	else if (c == '+' || c == '-')
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

int main(void)
{
	char infix_expression[1000];
	scanf("%s", infix_expression);

	Stack operators = Stack_allocate();
	Stack postfix = Stack_allocate();
	int size = strlen(infix_expression);
	for (int i = 0; i < size; i++)
	{
		char c = infix_expression[i];
		if ((('a' - 1) < c && c < ('z' + 1)) ||
			(('A' - 1) < c && c < ('Z' + 1)) ||
			(('0' - 1) < c && c < ('9' + 1)))
		{
			Stack_push(postfix, c);
		}
		else if (c == '(')
		{
			Stack_push(operators, c);
		}
		else if (c == ')')
		{
			while (Stack_peak(operators) != '(')
			{
				Stack_push(postfix, Stack_pop(operators));
			}
			Stack_pop(operators);
		}
		else
		{
			while (!Stack_is_empty(operators) &&
				get_precedent(c) <= get_precedent(Stack_peak(operators)))
			{
				Stack_push(postfix, Stack_pop(operators));
			}
			Stack_push(operators, c);
		}
	}
	while (!Stack_is_empty(operators))
	{
		Stack_push(postfix, Stack_pop(operators));
	}

	Stack_reverse(postfix);
	Stack_display(postfix);

	int exit_code = 0;
	scanf("%d", &exit_code);
	return 0;
}