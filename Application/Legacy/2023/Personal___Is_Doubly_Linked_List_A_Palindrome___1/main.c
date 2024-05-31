#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
	int value;
	struct node* next_node;
	struct node* previous_node;

} Node;

typedef struct doubly_linked_list
{
	int size;
	Node* head_node;
	Node* tail_node;

} DoublyLinkedList;

Node* Node_allocate(int value)
{
	Node* node = (Node*) malloc(sizeof(Node));
	node->value = value;
	node->next_node = NULL;
	node->previous_node = NULL;

	return node;
}

DoublyLinkedList* DoublyLinkedList_allocate()
{
	DoublyLinkedList* doubly_linked_list = (DoublyLinkedList*) malloc(sizeof(DoublyLinkedList));
	doubly_linked_list->size = 0;
	doubly_linked_list->head_node = NULL;
	doubly_linked_list->tail_node = NULL;

	return doubly_linked_list;
}

void DoublyLinkedList_add_first(DoublyLinkedList* doubly_linked_list, int value)
{
	if (doubly_linked_list == NULL)
	{
		return;
	}

	Node* new_node = Node_allocate(value);
	if (doubly_linked_list->head_node == NULL ||
		doubly_linked_list->tail_node == NULL)
	{
		doubly_linked_list->head_node = new_node;
		doubly_linked_list->tail_node = new_node;
	}
	else
	{
		new_node->next_node = doubly_linked_list->head_node;
		doubly_linked_list->head_node->previous_node = new_node;
		doubly_linked_list->head_node = new_node;
	}
	doubly_linked_list->size++;
}

void DoublyLinkedList_add_last(DoublyLinkedList* doubly_linked_list, int value)
{
	if (doubly_linked_list == NULL)
	{
		return;
	}

	Node* new_node = Node_allocate(value);
	if (doubly_linked_list->head_node == NULL ||
		doubly_linked_list->tail_node == NULL)
	{
		doubly_linked_list->head_node = new_node;
		doubly_linked_list->tail_node = new_node;
	}
	else
	{
		doubly_linked_list->tail_node->next_node = new_node;
		new_node->previous_node = doubly_linked_list->tail_node;
		doubly_linked_list->tail_node = new_node;
	}
	doubly_linked_list->size++;
}

bool DoublyLinkedList_is_palindrome(DoublyLinkedList* doubly_linked_list)
{
	if (doubly_linked_list == NULL)
	{
		return true;
	}

	Node* node_a = doubly_linked_list->head_node;
	Node* node_b = doubly_linked_list->tail_node;
	while (node_a != node_b && node_a->previous_node != node_b)
	{
		if (node_a->value != node_b->value)
		{
			return false;
		}

		node_a = node_a->next_node;
		node_b = node_b->previous_node;
	}

	return true;
}

void DoublyLinkedList_display(DoublyLinkedList* doubly_linked_list)
{
	if (doubly_linked_list == NULL)
	{
		return;
	}

	printf("[");
	Node* node = doubly_linked_list->head_node;
	while (node != NULL)
	{
		printf("%d", node->value);
		if (node->next_node != NULL)
		{
			printf(" <-> ");
		}
		node = node->next_node;
	}
	printf("]\n");
}

void DoublyLinkedList_replace_x_with_y(DoublyLinkedList* doubly_linked_list, int x, int y)
{
	Node* current_node = doubly_linked_list->head_node;
	while (current_node != NULL)
	{
		if (current_node->value == x)
		{
			current_node->value = y;
		}

		current_node = current_node->next_node;
	}
}

bool DoublyLinkedList_is_squence_found(
	DoublyLinkedList* list, DoublyLinkedList* sequence)
{
	if (list->head_node == NULL || sequence->head_node == NULL)
	{
		return false;
	}

	Node* node_a = list->head_node;
	Node* node_b = sequence->head_node;
	while (node_a != NULL && node_b != NULL)
	{
		if (node_a->value == node_b->value)
		{
			node_b = node_b->next_node;
		}
		else
		{
			node_b = sequence->head_node;
			if (node_a->value == node_b->value)
			{
				node_b = node_b->next_node;
			}
		}
		// node_b = (node_a->value == node_b->value) ?
		// 	node_b->next_node : (node_a->value == sequence->head_node->value) ?
		// 		node_b->next_node : sequence->head_node;
		node_a = node_a->next_node;
	}

	return node_b == NULL;
}

int main(void)
{
	DoublyLinkedList* doubly_linked_list_a = DoublyLinkedList_allocate();
	DoublyLinkedList_add_last(doubly_linked_list_a, 5);
	DoublyLinkedList_add_last(doubly_linked_list_a, 6);
	DoublyLinkedList_add_last(doubly_linked_list_a, 1);
	DoublyLinkedList_add_last(doubly_linked_list_a, 2);
	DoublyLinkedList_add_last(doubly_linked_list_a, 1);
	DoublyLinkedList_add_last(doubly_linked_list_a, 2);
	DoublyLinkedList_add_last(doubly_linked_list_a, 1);
	DoublyLinkedList_add_last(doubly_linked_list_a, 2);
	DoublyLinkedList_add_last(doubly_linked_list_a, 1);
	DoublyLinkedList_add_last(doubly_linked_list_a, 2);
	DoublyLinkedList_add_last(doubly_linked_list_a, 3);
	DoublyLinkedList_display(doubly_linked_list_a);

	DoublyLinkedList* doubly_linked_list_b = DoublyLinkedList_allocate();
	DoublyLinkedList_add_last(doubly_linked_list_b, 1);
	DoublyLinkedList_add_last(doubly_linked_list_b, 2);
	DoublyLinkedList_add_last(doubly_linked_list_b, 3);
	DoublyLinkedList_display(doubly_linked_list_b);

	printf("Is Sequence Found? %d\n", DoublyLinkedList_is_squence_found(doubly_linked_list_a, doubly_linked_list_b));
	// printf("Is Palindrome: %d", DoublyLinkedList_is_palindrome(doubly_linked_list));

	int exit_code = 0;
	scanf("%d", &exit_code);
	return 0;
}