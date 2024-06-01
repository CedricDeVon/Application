#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <windows.h>

typedef struct node
{
	char value;
	struct node *next_node;

} *Node;

typedef struct stack
{
	Node head_node;

} *Stack;

Node Node_allocate(char value)
{
	Node node = (Node) malloc(sizeof(Node));
	node->value = value;
	node->next_node = NULL;

	return node;
}

Stack Stack_allocate()
{
	Stack stack = (Stack) malloc(sizeof(Stack));
	stack->head_node = NULL;

	return stack;
}

Node Node_deallocate(Node node)
{
	if (node == NULL)
	{
		return NULL;
	}

	node->value = ' ';
	node->next_node = NULL;
	free(node);
	node = NULL;

	return node;
}

Stack Stack_deallocate(Stack stack)
{
	if (stack == NULL)
	{
		return NULL;
	}

	Node node = stack->head_node;
	while (node != NULL)
	{
		Node temporary_node = node;
		node = node->next_node;
		Node_deallocate(temporary_node);
	}
	stack->head_node = NULL;
	free(stack);
	stack = NULL;

	return stack;
}

void Stack_push(Stack stack, char value)
{
	if (stack == NULL)
	{
		return;
	}

	Node node = Node_allocate(value);
	if (stack->head_node == NULL)
	{
		stack->head_node = node;
	}
	else
	{
		node->next_node = stack->head_node;
		stack->head_node = node;
	}
}

char Stack_pop(Stack stack)
{
	if (stack == NULL || stack->head_node == NULL)
	{
		return ' ';
	}

	char output = ' ';
	if (stack->head_node->next_node == NULL)
	{
		output = stack->head_node->value;
		Node_deallocate(stack->head_node);
		stack->head_node = NULL;
	}
	else
	{
		Node temporary_node = stack->head_node;
		output = temporary_node->value;
		stack->head_node = stack->head_node->next_node;
		Node_deallocate(temporary_node);
	}

	return output;
}

char Stack_peak(Stack stack)
{
	return (stack == NULL || stack->head_node == NULL) ? ' ' : stack->head_node->value;
}

bool Stack_is_empty(Stack stack)
{
	return (stack == NULL || stack->head_node == NULL);
}

void Stack_display(Stack stack)
{
	if (stack == NULL)
	{
		return;
	}

	Node node = stack->head_node;
	printf("[");
	while (node != NULL)
	{
		printf("%c", node->value);
		if (node->next_node != NULL)
		{
			printf(", ");
		}
		node = node->next_node;
	}
	printf("]\n");
}

bool is_an_opening_brace(char character)
{
	return character == '[' || character == '{' || character == '(' || character == '<';
}

bool is_an_ending_brace(char character)
{
	return character == ']' || character == '}' || character == ')' || character == '>';
}

bool is_equal(char a, char b)
{
	return b == '[' && a == ']' || b == '{' && a == '}' || b == '(' && a == ')' || b == '<' && a == '>';
}

bool is_not_equal(char a, char b)
{
	return b == '[' && a != ']' || b == '{' && a != '}' ||
			b == '(' && a != ')' || b == '<' && a != '>' ||
			b == ' ';
}

bool is_balanced_braces(char input[])
{
	Stack stack = Stack_allocate();
	int size = strlen(input);
	bool is_balanced = true;
	for (int index = 0; index < size; index++)
	{
		char a = input[index];
		char b = Stack_peak(stack);
		if (is_an_opening_brace(a))
		{
			Stack_push(stack, a);
		}
		else if (is_an_ending_brace(a) && is_equal(a, b))
		{
			Stack_pop(stack);
		}
		else if (is_an_ending_brace(a) && is_not_equal(a, b))
		{
			is_balanced = false;
			break;
		}
	}
	if (!Stack_is_empty(stack))
	{
		is_balanced = false;
	}
	Stack_deallocate(stack);
	
	return is_balanced;
}

int main(void)
{
	char input[1000];
	scanf("%s", &input);

	bool is_balanced = is_balanced_braces(input);
	printf("%s\n", (is_balanced) ? "Balanced" : "Not Balanced");

	int exit_code = 0;
	scanf("%d", &exit_code);
	return 0;
}
