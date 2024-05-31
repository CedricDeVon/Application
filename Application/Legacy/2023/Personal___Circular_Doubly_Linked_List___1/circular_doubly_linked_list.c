#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <windows.h>

typedef struct circular_doubly_linked_list_node
{
	float value;
	struct circular_doubly_linked_list_node* next_node;
	struct circular_doubly_linked_list_node* previous_node;

} CircularDoublyLinkedListNode;

typedef struct circular_doubly_linked_list
{
	unsigned long long int size;
	CircularDoublyLinkedListNode* head_node;
	CircularDoublyLinkedListNode* tail_node;

} CircularDoublyLinkedList;

CircularDoublyLinkedListNode* CircularDoublyLinkedListNode_allocate(float value)
{
	CircularDoublyLinkedListNode* node =
		(CircularDoublyLinkedListNode*) malloc(sizeof(CircularDoublyLinkedListNode));
	node->value = value;
	node->next_node = NULL;
	node->previous_node = NULL;

	return node;
}

CircularDoublyLinkedList* CircularDoublyLinkedList_allocate()
{
	CircularDoublyLinkedList* linked_list =
		(CircularDoublyLinkedList*) malloc(sizeof(CircularDoublyLinkedList));
	linked_list->size = 0;
	linked_list->head_node = NULL;
	linked_list->tail_node = NULL;

	return linked_list;
}

CircularDoublyLinkedListNode* CircularDoublyLinkedListNode_deallocate(
	CircularDoublyLinkedListNode* node)
{
	if (node == NULL)
	{
		return NULL;
	}

	node->value = 0;
	node->next_node = NULL;
	node->previous_node = NULL;
	free(node);
	node = NULL;

	return node;
}

CircularDoublyLinkedList* CircularDoublyLinkedList_deallocate(
	CircularDoublyLinkedList* linked_list)
{
	if (linked_list == NULL)
	{
		return NULL;
	}

	CircularDoublyLinkedListNode* node = linked_list->head_node;
	for (unsigned long long int index = 0; index < linked_list->size; index++)
	{
		CircularDoublyLinkedListNode* temporary_node = node;
		node = node->next_node;
		CircularDoublyLinkedListNode_deallocate(temporary_node);
	}
	linked_list->size = 0;
	linked_list->head_node = NULL;
	linked_list->tail_node = NULL;
	free(linked_list);
	linked_list = NULL;

	return linked_list;
}

void CircularDoublyLinkedList_clear(CircularDoublyLinkedList* linked_list)
{
	if (linked_list == NULL || linked_list->head_node == NULL && linked_list->tail_node == NULL)
	{
		return;
	}

	CircularDoublyLinkedListNode* node = linked_list->head_node;
	while (node != linked_list->tail_node)
	{
		CircularDoublyLinkedListNode* temporary_node = node;
		node = node->next_node;
		CircularDoublyLinkedListNode_deallocate(temporary_node);
	}
	CircularDoublyLinkedListNode_deallocate(node);
	linked_list->size = 0;
	linked_list->head_node = NULL;
	linked_list->tail_node = NULL;
}

void CircularDoublyLinkedList_display(CircularDoublyLinkedList* linked_list)
{
	if (linked_list == NULL || linked_list->head_node == NULL && linked_list->tail_node == NULL)
	{
		printf("[]\n");
		return;
	}

	printf("[");
	CircularDoublyLinkedListNode* node = linked_list->head_node;
	for (unsigned long long int index = 0; index < linked_list->size; index++)
	{
		printf("%.2llf", node->value);
		if (index < linked_list->size - 1)
		{
			printf(", ");
		}
		node = node->next_node;
	}
	printf("]\n");
}

void CircularDoublyLinkedList_repeat_display(
	CircularDoublyLinkedList* linked_list, unsigned long long int maximum_iteration)
{
	if (linked_list == NULL || linked_list->head_node == NULL && linked_list->tail_node == NULL)
	{
		printf("[]\n");
		return;
	}

	unsigned long long int current_iteration = 0;
	CircularDoublyLinkedListNode* node = linked_list->head_node;
	printf("[");
	while (current_iteration < maximum_iteration)
	{
		if (node == linked_list->tail_node)
		{
			current_iteration++;
		}

		printf("%.2llf", node->value);
		if (current_iteration < maximum_iteration)
		{
			printf(", ");
		}
		node = node->next_node;
	}
	printf("]\n", node->value);
}

void CircularDoublyLinkedList_insert_at_head(CircularDoublyLinkedList* linked_list, float value)
{
	if (linked_list == NULL)
	{
		return;
	}

	CircularDoublyLinkedListNode* node = CircularDoublyLinkedListNode_allocate(value);
	if (linked_list->head_node == NULL && linked_list->tail_node == NULL)
	{
		linked_list->head_node = node;
		linked_list->tail_node = node;
		node->next_node = node;
		node->previous_node = node;
	}
	else
	{
		node->next_node = linked_list->head_node;
		linked_list->head_node->previous_node = node;
		linked_list->head_node = node;
		linked_list->tail_node->next_node = node;
		node->previous_node = linked_list->tail_node;
	}
	linked_list->size++;
}

void CircularDoublyLinkedList_insert_at_tail(CircularDoublyLinkedList* linked_list, float value)
{
	if (linked_list == NULL)
	{
		return;
	}

	CircularDoublyLinkedListNode* node = CircularDoublyLinkedListNode_allocate(value);
	if (linked_list->head_node == NULL && linked_list->tail_node == NULL)
	{
		linked_list->head_node = node;
		linked_list->tail_node = node;
		node->next_node = node;
		node->previous_node = node;
	}
	else
	{
		node->previous_node = linked_list->tail_node;
		linked_list->tail_node->next_node = node;
		linked_list->tail_node = node;
		linked_list->head_node->previous_node = node;
		node->next_node = linked_list->head_node;
	}
	linked_list->size++;
}

void CircularDoublyLinkedList_delete_at_head(CircularDoublyLinkedList* linked_list)
{
	if (linked_list == NULL || linked_list->head_node == NULL && linked_list->tail_node == NULL)
	{
		return;
	}

	if (linked_list->head_node == linked_list->tail_node)
	{
		CircularDoublyLinkedListNode_deallocate(linked_list->head_node);
		linked_list->head_node = NULL;
		linked_list->tail_node = NULL;
	}
	else
	{
		CircularDoublyLinkedListNode* temporary_node = linked_list->head_node;
		linked_list->head_node = linked_list->head_node->next_node;
		linked_list->tail_node->next_node = linked_list->head_node;
		linked_list->head_node->previous_node = linked_list->tail_node;
		CircularDoublyLinkedListNode_deallocate(temporary_node);
	}
	linked_list->size--;
}

void CircularDoublyLinkedList_delete_at_tail(CircularDoublyLinkedList* linked_list)
{
	if (linked_list == NULL || linked_list->head_node == NULL && linked_list->tail_node == NULL)
	{
		return;
	}

	if (linked_list->head_node == linked_list->tail_node)
	{
		CircularDoublyLinkedListNode_deallocate(linked_list->head_node);
		linked_list->head_node = NULL;
		linked_list->tail_node = NULL;
	}
	else
	{
		CircularDoublyLinkedListNode* temporary_node = linked_list->tail_node;
		linked_list->tail_node = linked_list->tail_node->previous_node;
		linked_list->head_node->previous_node = linked_list->tail_node;
		linked_list->tail_node->next_node = linked_list->head_node;
		CircularDoublyLinkedListNode_deallocate(temporary_node);
	}
	linked_list->size--;
}

void CircularDoublyLinkedList_reverse(CircularDoublyLinkedList* linked_list)
{
	if (linked_list == NULL || linked_list->head_node == linked_list->tail_node ||
		linked_list->head_node == NULL && linked_list->tail_node == NULL)
	{
		return;
	}

	CircularDoublyLinkedListNode* node_a = linked_list->head_node;
	CircularDoublyLinkedListNode* node_b = node_a->next_node;
	CircularDoublyLinkedListNode* node_c = node_b->next_node;
	while (node_b != linked_list->tail_node)
	{
		node_a->previous_node = node_b;
		node_b->next_node = node_a;

		node_a = node_b;
		node_b = node_c;
		node_c = node_c->next_node;
	}
	node_a->previous_node = node_b;
	node_b->next_node = node_a;
	linked_list->head_node->next_node = linked_list->tail_node;
	linked_list->tail_node->previous_node = linked_list->head_node;
	CircularDoublyLinkedListNode* temporary_node = linked_list->head_node;
	linked_list->head_node = linked_list->tail_node;
	linked_list->tail_node = temporary_node;
}

unsigned long long int CircularDoublyLinkedList_count_number_of_nodes(
	CircularDoublyLinkedList* linked_list)
{
	if (linked_list == NULL || linked_list->head_node == NULL && linked_list->tail_node == NULL)
	{
		return 0;
	}

	unsigned long long int node_count = 0;
	CircularDoublyLinkedListNode* current_node = linked_list->head_node;
	while (current_node != linked_list->tail_node)
	{
		current_node = current_node->next_node;
		node_count++;
	}

	return ++node_count;
}

long long int CircularDoublyLinkedList_index_of_node_value(
	CircularDoublyLinkedList* linked_list, float target_value)
{
	if (linked_list == NULL || linked_list->head_node == NULL && linked_list->tail_node == NULL)
	{
		return -1;
	}

	long long int current_index = 0;
	CircularDoublyLinkedListNode* current_node = linked_list->head_node;
	while (current_node != linked_list->tail_node)
	{
		if (current_node->value == target_value)
		{
			return current_index;
		}

		current_node = current_node->next_node;
		current_index++;
	}

	return (current_node->value == target_value) ? current_index : -1;
}

bool CircularDoublyLinkedList_is_node_value_found(
	CircularDoublyLinkedList* linked_list, float target_value)
{
	if (linked_list == NULL || linked_list->head_node == NULL && linked_list->tail_node == NULL)
	{
		return false;
	}

	CircularDoublyLinkedListNode* current_node = linked_list->head_node;
	while (current_node != linked_list->tail_node)
	{
		if (current_node->value == target_value)
		{
			return true;
		}

		current_node = current_node->next_node;
	}

	return (current_node->value == target_value);
}

bool CircularDoublyLinkedList_is_empty(CircularDoublyLinkedList* linked_list)
{
	return (linked_list == NULL &&
		linked_list->head_node == NULL && linked_list->tail_node == NULL);
}

unsigned long long int CircularDoublyLinkedList_node_value_count(
	CircularDoublyLinkedList* linked_list, float target_value)
{
	if (linked_list == NULL || linked_list->head_node == NULL && linked_list->tail_node == NULL)
	{
		return 0;
	}

	unsigned long long int node_count = 0;
	CircularDoublyLinkedListNode* current_node = linked_list->head_node;
	while (current_node != linked_list->tail_node)
	{
		if (current_node->value == target_value)
		{
			node_count++;
		}
		current_node = current_node->next_node;
	}

	return (current_node->value == target_value) ? ++node_count : node_count;
}

void CircularDoublyLinkedList_bubble_sort(CircularDoublyLinkedList* linked_list)
{
	if (linked_list == NULL || linked_list->head_node == NULL && linked_list->tail_node == NULL ||
		linked_list->head_node == linked_list->tail_node)
	{
		return;
	}

	CircularDoublyLinkedListNode* node_a = linked_list->head_node;
	for (unsigned long long int index_a = 0; index_a < linked_list->size; index_a++)
	{
		CircularDoublyLinkedListNode* node_b = linked_list->head_node;
		for (unsigned long long int index_b = 0; index_b < linked_list->size; index_b++)
		{
			if (node_a->value < node_b->value)
			{
				float temp = node_a->value;
				node_a->value = node_b->value;
				node_b->value = temp;
			}
			node_b = node_b->next_node;
		}
		node_a = node_a->next_node;
	}
}

bool CircularDoublyLinkedList_is_circular(CircularDoublyLinkedList* linked_list)
{
	if (linked_list == NULL || linked_list->head_node == NULL && linked_list->tail_node == NULL)
	{
		return false;
	}

	CircularDoublyLinkedListNode* node_a = linked_list->head_node;
	CircularDoublyLinkedListNode* node_b = node_a->next_node;
	while (node_a != node_b)
	{
		if (node_a->next_node == NULL ||
			node_b->next_node == NULL || node_b->next_node->next_node == NULL)
		{
			return false;
		}

		node_a = node_a->next_node;
		node_b = node_b->next_node->next_node;
	}

	return true;
}

float CircularDoublyLinkedList_get_node_value_at_index(
	CircularDoublyLinkedList* linked_list, unsigned long long int target_index)
{
	if (linked_list == NULL || linked_list->head_node == NULL && linked_list->tail_node == NULL)
	{
		return -1;
	}

	unsigned long long int current_index = 0;
	CircularDoublyLinkedListNode* node = linked_list->head_node;
	while (node != linked_list->tail_node && current_index < target_index)
	{
		node = node->next_node;
		current_index++;
	}

	return (current_index == target_index) ? node->value : -1;
}

void CircularDoublyLinkedList_swap_node_values(
	CircularDoublyLinkedList* linked_list, float target_value_a, float target_value_b)
{
	if (linked_list == NULL || linked_list->head_node == NULL && linked_list->tail_node == NULL ||
		linked_list->head_node == linked_list->tail_node ||
		target_value_a == target_value_b)
	{
		return;
	}

	CircularDoublyLinkedListNode* node_a = NULL;
	CircularDoublyLinkedListNode* node_b = NULL;
	CircularDoublyLinkedListNode* current_node = linked_list->head_node;
	while (current_node != linked_list->tail_node)
	{
		if (node_a == NULL && current_node->value == target_value_a)
		{
			node_a = current_node;
		}
		else if (node_b == NULL && current_node->value == target_value_b)
		{
			node_b = current_node;
		}
		current_node = current_node->next_node;
	}
	if (node_a == NULL && current_node->value == target_value_a)
	{
		node_a = current_node;
	}
	else if (node_b == NULL && current_node->value == target_value_b)
	{
		node_b = current_node;
	}
	if (node_a == NULL || node_b == NULL)
	{
		return;
	}

	float temporary_value = node_a->value;
	node_a->value = node_b->value;
	node_b->value = temporary_value;
}

float CircularDoublyLinkedList_kth_node_from_tail(
	CircularDoublyLinkedList* linked_list, unsigned long long int kth)
{
	if (linked_list == NULL || linked_list->head_node == NULL && linked_list->tail_node == NULL ||
		linked_list->head_node == linked_list->tail_node)
	{
		return -1;
	}

	CircularDoublyLinkedListNode* node_a = linked_list->head_node;
	CircularDoublyLinkedListNode* node_b = linked_list->head_node;
	for (unsigned long long int current_iteration = 1;
		current_iteration < kth; current_iteration++)
	{
		node_b = node_b->next_node;
	}
	while (node_b != linked_list->tail_node)
	{
		node_a = node_a->next_node;
		node_b = node_b->next_node;
	}

	return node_a->value;
}

bool CircularDoublyLinkedList_is_a_set(CircularDoublyLinkedList* linked_list)
{
	if (linked_list == NULL || linked_list->head_node == NULL && linked_list->tail_node == NULL ||
		linked_list->head_node == linked_list->tail_node)
	{
		return true;
	}

	CircularDoublyLinkedListNode* node_a = linked_list->head_node;
	for (unsigned long long int index_a = 0; index_a < linked_list->size; index_a++)
	{
		CircularDoublyLinkedListNode* node_b = linked_list->head_node;
		for (unsigned long long int index_b = 0; index_b < linked_list->size; index_b++)
		{
			if (index_a != index_b && node_a->value == node_b->value)
			{
				return false;
			}
			node_b = node_b->next_node;
		}
		node_a = node_a->next_node;
	}

	return true;
}

CircularDoublyLinkedList* CircularDoublyLinkedList_union(
	CircularDoublyLinkedList* linked_list_a, CircularDoublyLinkedList* linked_list_b)
{
	if (linked_list_a == NULL || linked_list_b == NULL ||
		linked_list_a->head_node == NULL && linked_list_a->tail_node == NULL ||
		linked_list_b->head_node == NULL && linked_list_b->tail_node == NULL)
	{
		return NULL;
	}

	CircularDoublyLinkedList* linked_list = CircularDoublyLinkedList_allocate();
	CircularDoublyLinkedListNode* node_a = linked_list_a->head_node;
	for (unsigned long long int index_a = 0; index_a < linked_list_a->size; index_a++)
	{
		CircularDoublyLinkedList_insert_at_tail(linked_list, node_a->value);
		node_a = node_a->next_node;
	}

	node_a = linked_list_b->head_node;
	for (unsigned long long int index_a = 0; index_a < linked_list_b->size; index_a++)
	{
		bool is_found = false;
		CircularDoublyLinkedListNode* node_b = linked_list_a->head_node;
		for (unsigned long long int index_b = 0; index_b < linked_list_a->size; index_b++)
		{
			if (node_a->value == node_b->value)
			{
				is_found = true;
				break;
			}
			node_b = node_b->next_node;
		}
		if (!is_found)
		{
			CircularDoublyLinkedList_insert_at_tail(linked_list, node_a->value);
		}
		node_a = node_a->next_node;
	}

	return linked_list;
}

CircularDoublyLinkedList* CircularDoublyLinkedList_intersection(
	CircularDoublyLinkedList* linked_list_a, CircularDoublyLinkedList* linked_list_b)
{
	if (linked_list_a == NULL || linked_list_b == NULL ||
		linked_list_a->head_node == NULL && linked_list_a->tail_node == NULL ||
		linked_list_b->head_node == NULL && linked_list_b->tail_node == NULL)
	{
		return NULL;
	}

	CircularDoublyLinkedList* linked_list = CircularDoublyLinkedList_allocate();
	CircularDoublyLinkedListNode* node_a = linked_list_a->head_node;
	for (unsigned long long int index_a = 0; index_a < linked_list_a->size; index_a++)
	{
		bool is_found = false;
		CircularDoublyLinkedListNode* node_b = linked_list_b->head_node;
		for (unsigned long long int index_b = 0; index_b < linked_list_b->size; index_b++)
		{
			if (!is_found && node_a->value == node_b->value)
			{
				CircularDoublyLinkedList_insert_at_tail(linked_list, node_a->value);
				is_found = true;
			}

			node_b = node_b->next_node;
		}
		node_a = node_a->next_node;
	}

	return linked_list;
}

CircularDoublyLinkedList* CircularDoublyLinkedList_difference(
	CircularDoublyLinkedList* linked_list_a, CircularDoublyLinkedList* linked_list_b)
{
	if (linked_list_a == NULL || linked_list_b == NULL ||
		linked_list_a->head_node == NULL && linked_list_a->tail_node == NULL ||
		linked_list_b->head_node == NULL && linked_list_b->tail_node == NULL)
	{
		return NULL;
	}

	CircularDoublyLinkedList* linked_list = CircularDoublyLinkedList_allocate();
	CircularDoublyLinkedListNode* node_a = linked_list_a->head_node;
	for (unsigned long long int index_a = 0; index_a < linked_list_a->size; index_a++)
	{
		bool is_found = false;
		CircularDoublyLinkedListNode* node_b = linked_list_b->head_node;
		for (unsigned long long int index_b = 0; index_b < linked_list_b->size; index_b++)
		{
			if (node_a->value == node_b->value)
			{
				is_found = true;
			}

			node_b = node_b->next_node;
		}
		if (!is_found)
		{
			CircularDoublyLinkedList_insert_at_tail(linked_list, node_a->value);
		}
		node_a = node_a->next_node;
	}

	return linked_list;
}

CircularDoublyLinkedList* CircularDoublyLinkedList_symmetric_difference(
	CircularDoublyLinkedList* linked_list_a, CircularDoublyLinkedList* linked_list_b)
{
	if (linked_list_a == NULL || linked_list_b == NULL ||
		linked_list_a->head_node == NULL && linked_list_a->tail_node == NULL ||
		linked_list_b->head_node == NULL && linked_list_b->tail_node == NULL)
	{
		return NULL;
	}

	CircularDoublyLinkedList* linked_list = CircularDoublyLinkedList_allocate();
	CircularDoublyLinkedListNode* node_a = linked_list_a->head_node;
	for (unsigned long long int index_a = 0;
		index_a < linked_list_a->size; index_a++)
	{
		bool is_found = false;
		CircularDoublyLinkedListNode* node_b = linked_list_b->head_node;
		for (unsigned long long int index_b = 0;
			index_b < linked_list_b->size; index_b++)
		{
			if (node_a->value == node_b->value)
			{
				is_found = true;
			}
			node_b = node_b->next_node;
		}
		if (!is_found)
		{
			CircularDoublyLinkedList_insert_at_tail(linked_list, node_a->value);
		}
		node_a = node_a->next_node;
	}

	node_a = linked_list_b->head_node;
	for (unsigned long long int index_a = 0;
		index_a < linked_list_b->size; index_a++)
	{
		bool is_found = false;
		CircularDoublyLinkedListNode* node_b = linked_list_a->head_node;
		for (unsigned long long int index_b = 0;
			index_b < linked_list_a->size; index_b++)
		{
			if (node_a->value == node_b->value)
			{
				is_found = true;
			}
			node_b = node_b->next_node;
		}
		if (!is_found)
		{
			CircularDoublyLinkedList_insert_at_tail(linked_list, node_a->value);
		}
		node_a = node_a->next_node;
	}

	return linked_list;
}

void CircularDoublyLinkedList_insert_at_middle(
	CircularDoublyLinkedList* linked_list, float value, unsigned long long int target_index)
{
	if (linked_list == NULL || target_index < 0)
	{
		return;
	}

	if (target_index > linked_list->size - 1)
	{
		return;
	}
	else if (target_index == 0)
	{
		CircularDoublyLinkedList_insert_at_head(linked_list, value);
		return;
	}
	else if (target_index == linked_list->size - 1)
	{
		CircularDoublyLinkedList_insert_at_tail(linked_list, value);
		return;
	}

	target_index--;
	unsigned long long int current_index = 0;
	CircularDoublyLinkedListNode* new_node = CircularDoublyLinkedListNode_allocate(value);
	CircularDoublyLinkedListNode* current_node = linked_list->head_node;
	while (current_index < target_index)
	{
		current_node = current_node->next_node;
		current_index++;
	}
	CircularDoublyLinkedListNode* node_b = current_node->next_node;
	current_node->next_node = new_node;
	new_node->next_node = node_b;
	node_b->previous_node = new_node;
	new_node->previous_node = current_node;
	linked_list->size++;
}

void CircularDoublyLinkedList_delete_at_middle(
	CircularDoublyLinkedList* linked_list, unsigned long long int target_index)
{
	if (linked_list == NULL || target_index < 0 || target_index >= linked_list->size)
	{
		return;
	}

	if (target_index == 0)
	{
		CircularDoublyLinkedList_delete_at_head(linked_list);
		return;
	}
	else if (target_index == linked_list->size - 1)
	{
		CircularDoublyLinkedList_delete_at_tail(linked_list);
		return;
	}

	target_index--;
	unsigned long long int current_index = 0;
	CircularDoublyLinkedListNode* current_node = linked_list->head_node;
	while (current_index < target_index)
	{
		current_node = current_node->next_node;
		current_index++;
	}
	CircularDoublyLinkedListNode* target_node = current_node->next_node;
	CircularDoublyLinkedListNode* node_b = target_node->next_node;
	current_node->next_node = node_b;
	node_b->previous_node = current_node;
	CircularDoublyLinkedListNode_deallocate(target_node);
	linked_list->size--;
}

CircularDoublyLinkedList* CircularDoublyLinkedList_zip(
	CircularDoublyLinkedList* linked_list_a, CircularDoublyLinkedList* linked_list_b)
{
	if (linked_list_a == NULL || linked_list_b == NULL ||
		linked_list_a->head_node == NULL && linked_list_a->tail_node == NULL ||
		linked_list_b->head_node == NULL && linked_list_b->tail_node == NULL)
	{
		return NULL;
	}

	unsigned long long int node_count_a = 0;
	unsigned long long int node_count_b = 0;
	unsigned long long int total_size = linked_list_a->size + linked_list_b->size;
	CircularDoublyLinkedListNode* node_a = linked_list_a->head_node;
	CircularDoublyLinkedListNode* node_b = linked_list_b->head_node;
	CircularDoublyLinkedList* linked_list_c = CircularDoublyLinkedList_allocate();
	for (unsigned long long int index = 0; index < total_size; index++)
	{
		if (index % 2 == 0 && node_count_a < linked_list_a->size)
		{
			CircularDoublyLinkedList_insert_at_tail(linked_list_c, node_a->value);
			node_a = node_a->next_node;
			node_count_a++;
		}
		else if (index % 2 != 0 && node_count_b < linked_list_b->size)
		{
			CircularDoublyLinkedList_insert_at_tail(linked_list_c, node_b->value);
			node_b = node_b->next_node;	
			node_count_b++;
		}
		else if (node_count_a >= linked_list_a->size)
		{
			CircularDoublyLinkedList_insert_at_tail(linked_list_c, node_b->value);
			node_b = node_b->next_node;	
			node_count_b++;	
		}
		else if (node_count_b >= linked_list_b->size)
		{
			CircularDoublyLinkedList_insert_at_tail(linked_list_c, node_a->value);
			node_a = node_a->next_node;	
			node_count_a++;	
		}
	}

	return linked_list_c;
}

CircularDoublyLinkedList** CircularDoublyLinkedList_split(
	CircularDoublyLinkedList* linked_list, unsigned long long int sub_size)
{
	unsigned long long int linked_lists_size = ceil((float) linked_list->size / sub_size);
	CircularDoublyLinkedList** linked_lists = (CircularDoublyLinkedList**)
		malloc(sizeof(CircularDoublyLinkedList*) * linked_lists_size);
	for (unsigned long long int index = 0; index < linked_lists_size; index++)
	{
		linked_lists[index] = CircularDoublyLinkedList_allocate();
	}
	unsigned long long int count = 0;
	unsigned long long int index = 0;
	CircularDoublyLinkedListNode* node = linked_list->head_node;
	while (node != linked_list->tail_node)
	{
		if (count >= sub_size)
		{
			index++;
			count = 0;
		}
		CircularDoublyLinkedList_insert_at_tail(linked_lists[index], node->value);
		node = node->next_node;
		count++;
	}
	CircularDoublyLinkedList_insert_at_tail(
		(count >= sub_size) ? linked_lists[++index] : linked_lists[index], node->value);

	return linked_lists;
}

CircularDoublyLinkedList* CircularDoublyLinkedList_combine(
	CircularDoublyLinkedList** linked_lists, unsigned long long int size)
{
	CircularDoublyLinkedList* linked_list_a = CircularDoublyLinkedList_allocate();
	for (unsigned long long int index_a = 0; index_a < size; index_a++)
	{
		CircularDoublyLinkedList* linked_list_b = linked_lists[index_a];
		CircularDoublyLinkedListNode* node = linked_list_b->head_node;
		for (unsigned long long int index_b = 0; index_b < linked_list_b->size; index_b++)
		{
			CircularDoublyLinkedList_insert_at_tail(linked_list_a, node->value);
			node = node->next_node;
		}
	}

	return linked_list_a;
}

float* CircularDoublyLinkedList_to_array(CircularDoublyLinkedList* linked_list)
{
	if (linked_list == NULL || linked_list->head_node == NULL && linked_list->tail_node == NULL)
	{
		return NULL;
	}

	float* array = (float*) malloc(sizeof(float) * linked_list->size);
	CircularDoublyLinkedListNode* node = linked_list->head_node;
	for (unsigned long long int index = 0; index < linked_list->size; index++)
	{
		array[index] = node->value;
		node = node->next_node;
	}

	return array;
}

CircularDoublyLinkedList* CircularDoublyLinkedList_to_linked_list(
	float* array, unsigned long long int size)
{
	if (array == NULL || size == 0)
	{
		return NULL;
	}

	CircularDoublyLinkedList* linked_list = CircularDoublyLinkedList_allocate();
	for (unsigned long long int index = 0; index < size; index++)
	{
		CircularDoublyLinkedList_insert_at_tail(linked_list, array[index]);
	}

	return linked_list;
}

void CircularDoublyLinkedList_remove_duplications(CircularDoublyLinkedList* linked_list)
{
	if (linked_list == NULL || linked_list->head_node == NULL && linked_list->tail_node == NULL)
	{
		return;
	}

	CircularDoublyLinkedListNode* node_a = linked_list->head_node;
	for (unsigned long long int index_a = 0; index_a < linked_list->size; index_a++)
	{
		CircularDoublyLinkedListNode* node_b = linked_list->head_node;
		for (unsigned long long int index_b = 0; index_b < linked_list->size; index_b++)
		{
			if (index_a != index_b && index_b == 0 && node_b->value == node_a->value)
			{
				CircularDoublyLinkedList_delete_at_head(linked_list);
			}
			else if (index_a != index_b && index_b == (linked_list->size - 1) &&
				node_b->value == node_a->value)
			{
				CircularDoublyLinkedList_delete_at_tail(linked_list);
			}
			else if (index_b != index_a && node_b->value == node_a->value)
			{
				CircularDoublyLinkedList_delete_at_middle(linked_list, index_b);
			}
			node_b = node_b->next_node;
		}
		node_a = node_a->next_node;
	}
}

int main(void)
{
	int exit_code = 1;
	scanf("%d", &exit_code);
	return 0;
}
