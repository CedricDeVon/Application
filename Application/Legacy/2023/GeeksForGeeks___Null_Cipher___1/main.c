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
	struct node* next_node;

} *NODE;

typedef struct linked_list
{
	int size;
	NODE head_node;
	NODE tail_node;

} LINKED_LIST;

NODE NODE_allocate(char value)
{
	NODE node = (NODE) malloc(sizeof(NODE));
	node->value = value;
	node->next_node = NULL;

	return node;
}

NODE NODE_deallocate(NODE node)
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

LINKED_LIST* LINKED_LIST_allocate()
{
	LINKED_LIST* linked_list = (LINKED_LIST*) malloc(sizeof(LINKED_LIST));
	linked_list->size = 0;
	linked_list->head_node = NULL;
	linked_list->tail_node = NULL;

	return linked_list;
}

LINKED_LIST* LINKED_LIST_deallocate(LINKED_LIST* linked_list)
{
	if (linked_list == NULL)
	{
		return NULL;
	}

	NODE node = linked_list->head_node;
	while (node != NULL)
	{
		NODE target_node = node;
		node = node->next_node;
		NODE_deallocate(target_node);
	}

	linked_list->size = 0;
	linked_list->head_node = NULL;
	linked_list->tail_node = NULL;
	free(linked_list);
	linked_list = NULL;

	return linked_list;
}

void LINKED_LIST_insert_at_tail(LINKED_LIST* linked_list, char value)
{
	if (linked_list == NULL)
	{
		return;
	}

	NODE new_node = NODE_allocate(value);
	if (linked_list->head_node == NULL || linked_list->tail_node == NULL)
	{
		linked_list->head_node = new_node;
		linked_list->tail_node = new_node;
	}
	else
	{
		linked_list->tail_node->next_node = new_node;
		linked_list->tail_node = new_node;
	}
	linked_list->size += 1;
}

char* LINKED_LIST_to_character_array(LINKED_LIST* linked_list)
{
	if (linked_list == NULL || linked_list->head_node == NULL || linked_list->tail_node == NULL)
	{
		return NULL;
	}

	char* output = (char*) malloc(sizeof(char) * linked_list->size);
	NODE current_node = linked_list->head_node;
	for (int index = 0; index < linked_list->size; index++)
	{
		output[index] = current_node->value;
		current_node = current_node->next_node;
	}

	return output;
}

void LINKED_LIST_display(LINKED_LIST* linked_list)
{
	if (linked_list == NULL || linked_list->head_node == NULL || linked_list->tail_node == NULL)
	{
		return;
	}

	NODE current_node = linked_list->head_node;
	while (current_node != NULL)
	{
		printf("%c", current_node->value);
		current_node = current_node->next_node;
	}
	printf("\n");
}

int main(void)
{
	LINKED_LIST* linked_list = LINKED_LIST_allocate();
	char text[1000];
	scanf("%[^\n]c", text);

	int size = strlen(text);
	bool is_space_character_found = true;
	for (int index = 0; index < size; index++)
	{
		char character = text[index];
		if (is_space_character_found == true && character != ' ')
		{
			LINKED_LIST_insert_at_tail(linked_list, character);
			is_space_character_found = false;
		}
		else if (is_space_character_found == false && character == ' ')
		{
			is_space_character_found = true;
		}
	}

	LINKED_LIST_display(linked_list);
	LINKED_LIST_deallocate(linked_list);

	int exit_code = 0;
	scanf("%d", &exit_code);
	return 0;
}
