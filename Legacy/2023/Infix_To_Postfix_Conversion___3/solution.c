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

Node Node_allocate(char value)
{
	Node node = (Node) malloc(sizeof(struct node));
	node->value = value;
	node->next = NULL;

	return node;
}

void Node_deallocate(Node node)
{
	node->value = 0;
	node->next = NULL;
	free(node);
}

CircularSinglyLinkedList CircularSinglyLinkedList_allocate()
{
	CircularSinglyLinkedList linked_list = (CircularSinglyLinkedList) malloc(sizeof(struct circular_singly_linked_list));
	linked_list->size = 0;
	linked_list->head = NULL;
	linked_list->tail = NULL;

	return linked_list;
}

void CircularSinglyLinkedList_deallocate(CircularSinglyLinkedList linked_list)
{
	Node current_node = linked_list->head;
	while (current_node != linked_list->tail)
	{
		Node target_node = current_node;
		current_node = current_node->next;
		Node_deallocate(target_node);
	}
	if (linked_list->head != NULL || linked_list->tail != NULL)
	{
		Node_deallocate(current_node);	
	}
	linked_list->size = 0;
	linked_list->head = NULL;
	linked_list->tail = NULL;
	free(linked_list);
}

void CircularSinglyLinkedList_add_head(CircularSinglyLinkedList linked_list, char value)
{
	Node new_node = Node_allocate(value);
	if (linked_list->head == NULL || linked_list->tail == NULL)
	{
		linked_list->head = new_node;
		linked_list->tail = new_node;
	}
	else
	{
		new_node->next = linked_list->head;
		linked_list->head = new_node;
		linked_list->tail->next = linked_list->head;
	}
	linked_list->size++;
}

void CircularSinglyLinkedList_add_tail(CircularSinglyLinkedList linked_list, char value)
{
	Node new_node = Node_allocate(value);
	if (linked_list->head == NULL || linked_list->tail == NULL)
	{
		linked_list->head = new_node;
		linked_list->tail = new_node;
	}
	else
	{
		linked_list->tail->next = new_node;
		linked_list->tail = new_node;
		linked_list->tail->next = linked_list->head;
	}
	linked_list->size++;
}

char CircularSinglyLinkedList_remove_head(CircularSinglyLinkedList linked_list)
{
	if (linked_list->head == NULL || linked_list->tail == NULL)
	{
		return ' ';
	}

	char value = linked_list->head->value;
	if (linked_list->head == linked_list->tail)
	{
		Node_deallocate(linked_list->head);
		linked_list->head = NULL;
		linked_list->tail = NULL;
	}
	else
	{
		Node target_node = linked_list->head;
		linked_list->head = target_node->next;
		linked_list->tail->next = linked_list->head;
		Node_deallocate(target_node);
	}
	linked_list->size--;

	return value;
}

char CircularSinglyLinkedList_remove_tail(CircularSinglyLinkedList linked_list)
{
	if (linked_list->head == NULL || linked_list->tail == NULL)
	{
		return ' ';
	}

	char value = linked_list->tail->value;
	if (linked_list->head == linked_list->tail)
	{
		Node_deallocate(linked_list->tail);
		linked_list->head = NULL;
		linked_list->tail = NULL;
	}
	else
	{
		Node current_node = linked_list->head;
		while (current_node->next != linked_list->tail)
		{
			current_node = current_node->next;
		}
		linked_list->tail = current_node;
		linked_list->tail->next = linked_list->head;
	}
	linked_list->size--;

	return value;
}

char CircularSinglyLinkedList_peak_head(CircularSinglyLinkedList linked_list)
{
	return (linked_list->head != NULL) ? linked_list->head->value : ' ';
}

char CircularSinglyLinkedList_peak_tail(CircularSinglyLinkedList linked_list)
{
	return (linked_list->tail != NULL) ? linked_list->tail->value : ' ';
}

bool CircularSinglyLinkedList_is_empty(CircularSinglyLinkedList linked_list)
{
	return linked_list->head == NULL || linked_list->tail == NULL;
}

char* CircularSinglyLinkedList_to_array(CircularSinglyLinkedList linked_list)
{
	char* array = (char*) malloc(sizeof(char) * linked_list->size);
	int i = 0;
	Node current_node = linked_list->head;
	while (current_node != linked_list->tail)
	{
		printf("%c\n", current_node->value);
		array[i++] = current_node->value;
		current_node = current_node->next;
	}
	array[i] = current_node->value;
	
	return array;
}

void CircularSinglyLinkedList_display(CircularSinglyLinkedList linked_list)
{
	if (linked_list->head == NULL || linked_list->tail == NULL)
	{
		return;
	}

	Node current_node = linked_list->head;
	while (current_node != linked_list->tail)
	{
		printf("%c", current_node->value);
		current_node = current_node->next;
	}
	printf("%c\n", current_node->value);
}

bool is_opening_bracket(char value)
{
	return (value == '(') || (value == '[');
}

bool is_closing_bracket(char value)
{
	return (value == ')') || (value == ']');
}

bool is_bracket(char value)
{
	return is_opening_bracket(value) || is_closing_bracket(value);
}

bool is_operator(char value)
{
	return (value == '+') ||
		(value == '-') ||
		(value == '*') ||
		(value == '/') ||
		(value == '%') ||
		(value == '^');
}

bool is_operand(char value)
{
	return (('0' - 1) < value && value < ('9' + 1)) ||
		(('a' - 1) < value && value < ('z' + 1)) ||
		(('A' - 1) < value && value < ('Z' + 1));
}

int calculate_operator_precedence(char value)
{
	switch (value)
	{
		case '+' : return 1;
		case '-' : return 1;
		case '*' : return 2;
		case '/' : return 2;
		case '%' : return 2;
		case '^' : return 3;
	}

	return 0;
}

CircularSinglyLinkedList solution(char* infix_expression, int size)
{
	CircularSinglyLinkedList operators = CircularSinglyLinkedList_allocate();
	CircularSinglyLinkedList operands = CircularSinglyLinkedList_allocate();
	for (int index = 0; index < size; index++)
	{
		char character = infix_expression[index];
		if (character == '-' && is_operand(infix_expression[index + 1]))
		{
			CircularSinglyLinkedList_add_tail(operands, '-');
			CircularSinglyLinkedList_add_tail(operands, infix_expression[++index]);
		}
		else if (is_opening_bracket(character))
		{
			CircularSinglyLinkedList_add_tail(operators, character);
		}
		else if (is_closing_bracket(character))
		{
			while (!is_opening_bracket(CircularSinglyLinkedList_peak_head(operators)))
			{
				CircularSinglyLinkedList_add_tail(operands, ' ');
				CircularSinglyLinkedList_add_tail(operands, CircularSinglyLinkedList_remove_head(operators));
			}
			CircularSinglyLinkedList_remove_head(operators);
		}
		else if (is_operand(character))
		{
			CircularSinglyLinkedList_add_tail(operands, character);
		}
		else if (is_operator(character))
		{
			while (!CircularSinglyLinkedList_is_empty(operators) &&
				calculate_operator_precedence(CircularSinglyLinkedList_peak_head(operators)) >=
				calculate_operator_precedence(character))
			{
				CircularSinglyLinkedList_add_tail(operands, CircularSinglyLinkedList_remove_head(operators));
				CircularSinglyLinkedList_add_tail(operands, ' ');
			}
			CircularSinglyLinkedList_add_head(operators, character);
		}
		else if (character == ' ' && CircularSinglyLinkedList_peak_tail(operands) != ' ')
		{
			CircularSinglyLinkedList_add_tail(operands, ' ');
		}
	}
	while (!CircularSinglyLinkedList_is_empty(operators))
	{
		CircularSinglyLinkedList_add_tail(operands, ' ');
		CircularSinglyLinkedList_add_tail(operands, CircularSinglyLinkedList_remove_head(operators));
	}
	CircularSinglyLinkedList_deallocate(operators);

	return operands;
}
