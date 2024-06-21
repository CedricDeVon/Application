#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <windows.h>
#include <ctype.h>
#include <limits.h>

#include "solution.h"

DoublyLinkedListNode DoublyLinkedListNode_allocate(char value)
{
	DoublyLinkedListNode node = (DoublyLinkedListNode) malloc(sizeof(struct doubly_linked_list_node));
	node->value = value;
	node->next = NULL;
	node->prev = NULL;

	return node;
}

void DoublyLinkedListNode_deallocate(DoublyLinkedListNode node)
{
	node->value = 0;
	node->next = NULL;
	node->prev = NULL;
	free(node);
}

DoublyLinkedList DoublyLinkedList_allocate()
{
	DoublyLinkedList linked_list = (DoublyLinkedList) malloc(sizeof(struct doubly_linked_list));
	linked_list->size = 0;
	linked_list->head = NULL;


	return linked_list;
}

void DoublyLinkedList_deallocate(DoublyLinkedList linked_list)
{
	DoublyLinkedListNode current_node = linked_list->head;
	while (current_node != NULL)
	{
		DoublyLinkedListNode target_node = current_node;
		current_node = current_node->next;
		DoublyLinkedListNode_deallocate(target_node);
	}
	linked_list->size = 0;
	linked_list->head = NULL;
	linked_list->tail = NULL;
	free(linked_list);
}

bool DoublyLinkedList_is_empty(DoublyLinkedList linked_list)
{
	return linked_list->head == NULL;
}

void DoublyLinkedList_display(DoublyLinkedList linked_list)
{
	DoublyLinkedListNode current_node = linked_list->head;
	while (current_node != NULL)
	{
		printf("%c", current_node->value);
		current_node = current_node->next;
	}
	printf("\n");
}

void DoublyLinkedList_append_head(DoublyLinkedList linked_list, char value)
{
	DoublyLinkedListNode new_node = DoublyLinkedListNode_allocate(value);
	if (DoublyLinkedList_is_empty(linked_list))
	{
		linked_list->head = new_node;
		linked_list->tail = new_node;
	}
	else
	{
		new_node->next = linked_list->head;
		linked_list->head->prev = new_node;
		linked_list->head = new_node;
	}
	linked_list->size++;
}

void DoublyLinkedList_append_tail(DoublyLinkedList linked_list, char value)
{
	DoublyLinkedListNode new_node = DoublyLinkedListNode_allocate(value);
	if (DoublyLinkedList_is_empty(linked_list))
	{
		linked_list->head = new_node;
		linked_list->tail = new_node;
	}
	else
	{
		linked_list->tail->next = new_node;
		new_node->prev = linked_list->tail;
		linked_list->tail = new_node;
	}
	linked_list->size++;	
}

char DoublyLinkedList_delete_head(DoublyLinkedList linked_list)
{
	if (DoublyLinkedList_is_empty(linked_list))
	{
		return 0;
	}

	char value = linked_list->head->value;
	if (linked_list->head == linked_list->tail)
	{
		DoublyLinkedListNode_deallocate(linked_list->head);
		linked_list->head = NULL;
		linked_list->tail = NULL;
	}
	else
	{
		DoublyLinkedListNode target_node = linked_list->head;
		linked_list->head = target_node->next;
		linked_list->head->prev = NULL;
		DoublyLinkedListNode_deallocate(target_node);
	}
	linked_list->size--;

	return value;
}

char DoublyLinkedList_delete_tail(DoublyLinkedList linked_list)
{
	if (DoublyLinkedList_is_empty(linked_list))
	{
		return 0;
	}

	char value = linked_list->head->value;
	if (linked_list->head == linked_list->tail)
	{
		DoublyLinkedListNode_deallocate(linked_list->tail);
		linked_list->head = NULL;
		linked_list->tail = NULL;
	}
	else
	{
		DoublyLinkedListNode target_node = linked_list->tail;
		linked_list->tail = target_node->prev;
		linked_list->tail->next = NULL;
		DoublyLinkedListNode_deallocate(target_node);
	}
	linked_list->size--;

	return value;
}

char DoublyLinkedList_peak_head(DoublyLinkedList linked_list)
{
	return (linked_list->head != NULL) ? linked_list->head->value : 0;
}

char DoublyLinkedList_peak_tail(DoublyLinkedList linked_list)
{
	return (linked_list->tail != NULL) ? linked_list->tail->value : 0;
}

StringTreeNode StringTreeNode_allocate(char value)
{
	StringTreeNode node = (StringTreeNode) malloc(sizeof(struct string_tree_node));
	node->value = value;
	node->count = 0;
	node->children = (struct string_tree_node**) malloc(sizeof(struct string_tree_node) * 95);
	for (int i = 0; i < 95; i++)
	{
		node->children[i] = NULL;
	}

	return node; 
}

void StringTreeNode_deallocate(StringTreeNode node)
{
	node->value = 0;
	for (int i = 0; i < 95; i++)
	{
		node->children[i] = NULL;
	}
	free(node->children);
	node->children = NULL;
	free(node);
}

StringTree StringTree_allocate()
{
	StringTree tree = (StringTree) malloc(sizeof(struct string_tree));
	tree->children = (StringTreeNode*) malloc(sizeof(StringTreeNode) * 95);
	for (int i = 0; i < 95; i++)
	{
		tree->children[i] = NULL;
	}

	return tree;
}

void __StringTree_deallocate(StringTreeNode node)
{
	for (int i = 0; i < 95; i++)
	{
		if (node->children[i] != NULL)
		{
			__StringTree_deallocate(node->children[i]);
			node->children[i] = NULL;
		}
	}
	StringTreeNode_deallocate(node);
}

void StringTree_deallocate(StringTree tree)
{
	for (int i = 0; i < 95; i++)
	{
		if (tree->children[i] != NULL)
		{
			__StringTree_deallocate(tree->children[i]);
			tree->children[i] = NULL;
		}
	}
	free(tree->children);
	tree->children = NULL;
	free(tree);
}

StringTreeNode __StringTree_insert(StringTreeNode node, char* string, int size, int index)
{
	if (32 > string[index] || string[index] > 126)
	{
		return NULL;
	}

	if (node == NULL)
	{
		node = StringTreeNode_allocate(string[index]);
	}

	index++;
	if (index == size)
	{
		node->count += 1;
	}
	else
	{
		node->children[string[index] - ' '] = __StringTree_insert(node->children[string[index] - ' '], string, size, index);
	}

	return node;
}

void StringTree_insert(StringTree tree, char* string, int size)
{
	tree->children[string[0] - ' '] = __StringTree_insert(tree->children[string[0] - ' '], string, size, 0);
}

void __StringTree_display(StringTreeNode node, DoublyLinkedList linked_list)
{
	DoublyLinkedList_append_tail(linked_list, node->value);
	if (node->count > 0)
	{
		printf("(%d) : ", node->count);
		DoublyLinkedList_display(linked_list);
	}
	for (int i = 0; i < 95; i++)
	{
		if (node->children[i] != NULL)
		{
			__StringTree_display(node->children[i], linked_list);
		}
	}
	DoublyLinkedList_delete_tail(linked_list);
}

void StringTree_display(StringTree tree)
{
	DoublyLinkedList linked_list = DoublyLinkedList_allocate();
	for (int i = 0; i < 95; i++)
	{
		if (tree->children[i] != NULL)
		{
			__StringTree_display(tree->children[i], linked_list);
		}
	}
	DoublyLinkedList_deallocate(linked_list);
}

void __StringTree_visualize(StringTreeNode node, DoublyLinkedList linked_list)
{
	DoublyLinkedList_append_tail(linked_list, node->value);
	DoublyLinkedList_display(linked_list);
	for (int i = 0; i < 95; i++)
	{
		if (node->children[i] != NULL)
		{
			__StringTree_visualize(node->children[i], linked_list);
		}
	}
	DoublyLinkedList_delete_tail(linked_list);
}

void StringTree_visualize(StringTree tree)
{
	DoublyLinkedList linked_list = DoublyLinkedList_allocate();
	for (int i = 0; i < 95; i++)
	{
		if (tree->children[i] != NULL)
		{
			__StringTree_visualize(tree->children[i], linked_list);
		}
	}
	DoublyLinkedList_deallocate(linked_list);
}
