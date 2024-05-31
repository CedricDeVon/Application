#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include <ctype.h>
#include <limits.h>

#include "solution.h"

Node Node_allocate(int value)
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

Queue Queue_allocate()
{
	Queue queue = (Queue) malloc(sizeof(struct queue));
	queue->size = 0;
	queue->head = NULL;
	queue->tail = NULL;

	return queue;
}

void Queue_deallocate(Queue queue)
{
	Node current_node = queue->head;
	while (current_node != NULL)
	{
		Node temporary_node = current_node;
		current_node = current_node->next;
		Node_deallocate(temporary_node);
	}
	queue->size = 0;
	queue->head = NULL;
	queue->tail = NULL;
	free(queue);
}

void Queue_enqueue(Queue queue, int value)
{
	Node new_node = Node_allocate(value);
	if (queue->head == NULL || 
		queue->tail == NULL)
	{
		queue->head = new_node;
		queue->tail = new_node;
	}
	else
	{
		queue->tail->next = new_node;
		queue->tail = new_node;	
	}
	queue->size++;
}

int Queue_dequeue(Queue queue)
{
	if (queue->head == NULL)
	{
		return -1;
	}

	int value = queue->head->value;
	if (queue->head == queue->tail)
	{
		Node_deallocate(queue->head);
		queue->head = NULL;
		queue->tail = NULL;
	}
	else
	{
		Node target_node = queue->head;
		queue->head = target_node->next;
		Node_deallocate(target_node);
	}
	queue->size--;

	return value;
}

int Queue_front(Queue queue)
{
	return (queue->head != NULL) ? queue->head->value : -1;
}

bool Queue_is_empty(Queue queue)
{
	return queue->head == NULL;
}

char* Queue_to_char_array(Queue queue)
{
	int i = 0;
	char* array = (char*) malloc(sizeof(char) * queue->size);
	Node node = queue->head;
	while (node != NULL)
	{
		array[i++] = node->value;
		node = node->next;
	}

	return array;
}

Stack Stack_allocate()
{
	Stack stack = (Stack) malloc(sizeof(struct stack));
	stack->size = 0;
	stack->head = NULL;

	return stack;
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
		return 0;
	}

	Node target_node = stack->head;
	int value = target_node->value;
	stack->head = target_node->next;
	Node_deallocate(target_node);
	stack->size--;

	return value;
}

int Stack_peak(Stack stack)
{
	return (stack->head != NULL) ? stack->head->value : 0;
}

bool Stack_is_empty(Stack stack)
{
	return stack->head == NULL;
}

bool is_operand(char character)
{
	return (('a' - 1) < character && character < ('z' + 1)) ||
		(('A' - 1) < character && character < ('Z' + 1));
}

char* solution(char* infix_expression, int size)
{
	Queue operands = Queue_allocate();
	Queue postfix_expression = Queue_allocate();
	for (int index = 0; index < size; index++)
	{
		char character = infix_expression[index];
		if (is_operand(character))
		{
			Queue_enqueue(operands, character);
		}
		else
		{
			char a = Queue_dequeue(operands);
			char b = Queue_dequeue(operands);
			if (a != -1)
			{
				Queue_enqueue(postfix_expression, a);
			}
			Queue_enqueue(postfix_expression, infix_expression[index]);
			if (b != -1)
			{
				Queue_enqueue(postfix_expression, b);
			}
		}
	}

	char* output = Queue_to_char_array(postfix_expression);

	Queue_deallocate(operands);

	return output;
}
