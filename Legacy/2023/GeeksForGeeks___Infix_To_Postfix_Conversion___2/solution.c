#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include <ctype.h>
#include <limits.h>

#include "solution.h"

CharacterNode CharacterNode_allocate(char value)
{
	CharacterNode node = (CharacterNode) malloc(sizeof(struct character_node));
	node->value = value;
	node->next = NULL;
	node->previous = NULL;

	return node;
}

void CharacterNode_deallocate(CharacterNode node)
{
	node->value = ' ';
	node->next = NULL;
	node->previous = NULL;
	free(node);
}

String String_allocate()
{
	String string = (String) malloc(sizeof(struct string));
	string->size = 0;
	string->head = NULL;
	string->tail = NULL;

	return string;
}

void String_deallocate(String string)
{
	CharacterNode node = string->head;
	while (node != NULL)
	{
		CharacterNode target_node = node;
		node = node->next;
		CharacterNode_deallocate(target_node);
	}
	string->size = 0;
	string->head = NULL;
	string->tail = NULL;
	free(string);
}

void String_push_front(String string, char value)
{
	CharacterNode new_node = CharacterNode_allocate(value);
	if (string->head == NULL || string->tail == NULL)
	{
		string->head = new_node;
		string->tail = new_node;
	}
	else
	{
		new_node->next = string->head;
		string->head->previous = new_node;
		string->head = new_node;
	}
	string->size++;
}

void String_push_back(String string, char value)
{
	CharacterNode new_node = CharacterNode_allocate(value);
	if (string->head == NULL || string->tail == NULL)
	{
		string->head = new_node;
		string->tail = new_node;
	}
	else
	{
		string->tail->next = new_node;
		new_node->previous = string->tail;
		string->tail = new_node;
	}
	string->size++;
}

char String_pop_front(String string)
{
	if (string->head == NULL || string->tail == NULL)
	{
		return ' ';
	}

	char value = string->head->value;
	if (string->head == string->tail)
	{
		CharacterNode_deallocate(string->head);
		string->head = NULL;
		string->tail = NULL;
	}
	else
	{
		CharacterNode target_node = string->head;
		string->head = target_node->next;
		string->head->previous = NULL;
		CharacterNode_deallocate(target_node);
	}
	string->size--;

	return value;
}

char String_pop_back(String string)
{
	if (string->head == NULL || string->tail == NULL)
	{
		return ' ';
	}

	char value = string->tail->value;
	if (string->head == string->tail)
	{
		CharacterNode_deallocate(string->head);
		string->head = NULL;
		string->tail = NULL;
	}
	else
	{
		CharacterNode target_node = string->tail;
		string->tail = target_node->previous;
		string->tail->next = NULL;
		CharacterNode_deallocate(target_node);
	}
	string->size--;

	return value;
}

bool String_is_empty(String string)
{
	return (string->head == NULL || string->tail == NULL);
}

void String_display(String string)
{
	CharacterNode node = string->head;
	while (node != NULL)
	{
		printf("%c", node->value);
		node = node->next;
	}
}

char* String_to_array(String string)
{
	CharacterNode current_node = string->head;
	char* values = (char*) malloc(sizeof(char) * string->size);
	for (int i = 0; i < string->size; i++)
	{
		values[i] = current_node->value;
		current_node = current_node->next;
	}

	return values;
}






StringNode StringNode_allocate(String string)
{
	StringNode node = (StringNode) malloc(sizeof(struct string_node));
	node->value = string;
	node->next = NULL;

	return node;
}

void StringNode_deallocate(StringNode node)
{
	node->value = NULL;
	node->next = NULL;
	free(node);
}

Stack Stack_allocate()
{
	Stack stack = (Stack) malloc(sizeof(struct stack));
	stack->size = 0;
	stack->sentence_size = 0;
	stack->head = NULL;
	stack->tail = NULL;

	return stack;
}

void Stack_deallocate(Stack stack)
{
	StringNode current_node = stack->head;
	while (current_node != NULL)
	{
		StringNode target_node = current_node;
		current_node = current_node->next;
		StringNode_deallocate(target_node);
	}
	stack->size = 0;
	stack->sentence_size = 0;
	stack->head = NULL;
	free(stack);
}

void Stack_push_at_head(Stack stack, String string)
{
	StringNode new_node = StringNode_allocate(string);
	if (stack->head == NULL || stack->tail == NULL)
	{
		stack->head = new_node;
		stack->tail = new_node;	
	}
	else
	{
		new_node->next = stack->head;
		stack->head = new_node;
	}
	stack->size++;
}

void Stack_push_at_tail(Stack stack, String string)
{
	StringNode new_node = StringNode_allocate(string);
	if (stack->head == NULL || stack->tail == NULL)
	{
		stack->head = new_node;
		stack->tail = new_node;
	}
	else
	{
		stack->tail->next = new_node;
		stack->tail = new_node;	
	}
	stack->size++;
}

String Stack_pop(Stack stack)
{
	if (stack->head == NULL)
	{
		return NULL;
	}

	String value = stack->head->value;
	if (stack->head == stack->tail)
	{
		StringNode_deallocate(stack->head);
		stack->head = NULL;
		stack->tail = NULL;
	}
	else
	{
		StringNode target_node = stack->head;
		stack->head = target_node->next;
		StringNode_deallocate(target_node);
	}
	stack->size--;
	
	return value;
}

String Stack_peak_head(Stack stack)
{
	return (stack->head != NULL) ? stack->head->value : NULL;
}

String Stack_peak_tail(Stack stack)
{
	return (stack->tail != NULL) ? stack->tail->value : NULL;
}

bool Stack_is_empty(Stack stack)
{
	return stack->head == NULL;
}

void Stack_display(Stack stack)
{
	StringNode node = stack->head;
	while (node != NULL)
	{
		String_display(node->value);
		printf("\n");

		node = node->next;
	}
	printf("\n");
}

String Stack_combine(Stack stack)
{
	String combined = String_allocate();
	StringNode node_a = stack->head;
	while (node_a != NULL)
	{
		String string = node_a->value;
		CharacterNode node_b = string->head;
		while (node_b != NULL)
		{
			String_push_back(combined, node_b->value);
			node_b = node_b->next;
		}
		node_a = node_a->next;
		if (node_a != NULL)
		{
			String_push_back(combined, ' ');
		}
	}

	return combined;
}

bool is_operand(char character)
{
	return (('0' - 1) < character && character < ('9' + 1)) ||
		(('a' - 1) < character && character < ('z' + 1)) ||
		(('A' - 1) < character && character < ('Z' + 1));
}

bool is_operator(char character)
{
	return (character == '+') ||
		(character == '-') ||
		(character == '*') ||
		(character == '/') ||
		(character == '%') ||
		(character == '^');
}

bool is_opening_bracket(char character)
{
	return (character == '(' || character == '[');
}

bool is_closing_bracket(char character)
{
	return (character == ')' || character == ']');
}

int calculate_precedent(char character)
{
	if (character == '+' || character == '-')
	{
		return 1;
	}
	else if (character == '*' || character == '/' || character == '%')
	{
		return 2;
	}
	else if (character == '^')
	{
		return 3;
	}

	return 0;
}
/*
Requirements:
- each operator and operand must be separated with spaces
- operators: -, +, *, /, %, ^
- positive and negative integers
- brackets: (), []


Simplify:
- StringNode
- String
- CircularSinglyLinkedListNode
- CircularSinglyLinkedList
*/

String solution(char* infix_expression, int size)
{
	Stack operators = Stack_allocate();
	Stack postfix = Stack_allocate();
	Stack_push_at_tail(postfix, String_allocate());

	for (int i = 0; i < size; i++)
	{
		char character = infix_expression[i];
		if (character == ' ' && !String_is_empty(Stack_peak_tail(postfix)))
		{
			Stack_push_at_tail(postfix, String_allocate());
		}
		else if (is_opening_bracket(character))
		{
			String operator = String_allocate();
			String_push_back(operator, character);
			Stack_push_at_head(operators, operator);
		}
		else if (is_closing_bracket(character))
		{
			while (!is_opening_bracket(Stack_peak_head(operators)->head->value))
			{
				Stack_push_at_tail(postfix, Stack_pop(operators));
			}
			Stack_pop(operators);
		}
		else if (character == '-' && is_operand(infix_expression[i + 1]))
		{
			String_push_back(Stack_peak_tail(postfix), '-');
			String_push_back(Stack_peak_tail(postfix), infix_expression[++i]);
		}
		else if (is_operand(character))
		{
			String_push_back(Stack_peak_tail(postfix), infix_expression[i]);
		}
		else if (is_operator(character))
		{
			while (!Stack_is_empty(operators) &&
				calculate_precedent(character) <= calculate_precedent(Stack_peak_head(operators)->head->value))
			{
				String_push_back(Stack_peak_tail(postfix), Stack_pop(operators)->head->value);
				Stack_push_at_tail(postfix, String_allocate());
			}
			String operator = String_allocate();
			String_push_back(operator, character);
			Stack_push_at_head(operators, operator);
		}
	}
	while (!Stack_is_empty(operators))
	{
		Stack_push_at_tail(postfix, Stack_pop(operators));
	}

	Stack_display(postfix);

	return Stack_combine(postfix);
}