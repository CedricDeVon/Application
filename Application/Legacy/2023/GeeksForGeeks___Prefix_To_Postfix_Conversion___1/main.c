#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <windows.h>
#include <ctype.h>
#include <limits.h>

typedef struct node
{
	char value;
	struct node* next_node;

} *Node;

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

typedef struct stack
{
	char size;
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

void Stack_push(Stack stack, char value)
{
	Node node = Node_allocate(value);
	node->next_node = stack->head_node;
	stack->head_node = node;
	stack->size++;
}

char Stack_pop(Stack stack)
{
	if (stack->head_node == NULL)
	{
		return -1;
	}

	char value = stack->head_node->value;
	if (stack->head_node->next_node == NULL)
	{
		Node_deallocate(stack->head_node);
		stack->head_node = NULL;
	}
	else
	{
		Node target_node = stack->head_node;
		stack->head_node = target_node->next_node;
		Node_deallocate(target_node);
	}
	stack->size--;

	return value;
}

char Stack_peak(Stack stack)
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
	while (node != NULL)
	{
		printf("%d", node->value);
		if (node->next_node != NULL)
		{
			printf(" -> ");
		}
		node = node->next_node;
	}
	printf("\n");
}

bool is_operator(char character)
{
	return character == '+' || character == '-' ||
		character == '*' || character == '/' || character == '%' ||
		character == '^';
}

bool is_operand(char character)
{
	return (('0' - 1) < character && character < ('9' + 1)) ||
		(('a' - 1) < character && character < ('z' + 1)) ||
		(('A' - 1) < character && character < ('Z' + 1))
}

int get_precedence_value(char operator)
{
	if (operator == '^')
	{
		return 3
	}
	else if (operator == '*' || operator == '/' || operator == '%')
	{
		return 2
	}
	else if (operator == '+' || operator == '-')
	{
		return 1
	}
	
	return 0;
}

int main(void)
{
	// *+A^B(C-D)%E
	char prefix_expression[1000];
	scanf("%s", prefix_expression);
	int size = strlen(prefix_expression);
	Stack operands = Stack_allocate();
	Stack operators = Stack_allocate();

	

	Stack_deallocate(operands);
	Stack_deallocate(operators);

	int exit_code = 0;
	scanf("%d", &exit_code);
	return 0;
}