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

StringNode StringNode_allocate(char value)
{
	StringNode node = (StringNode) malloc(sizeof(struct string_node));
	node->value = value;
	node->next = NULL;
	node->prev = NULL;

	return node;
}

void StringNode_deallocate(StringNode node)
{
	node->value = ' ';
	node->next = NULL;
	node->prev = NULL;
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
	StringNode current_node = string->head;
	while (current_node != NULL)
	{
		StringNode target_node = current_node;
		current_node = current_node->next;
		StringNode_deallocate(target_node);
	}
	string->size = 0;
	string->head = NULL;
	string->tail = NULL;
	free(string);
}

bool String_is_empty(String string)
{
	return string->head == NULL || string->tail == NULL;
}

void String_append_at_front(String string, char value)
{
	StringNode new_node = StringNode_allocate(value);
	if (string->head == NULL || string->tail == NULL)
	{
		string->head = new_node;
		string->tail = new_node;
	}
	else
	{
		new_node->next = string->head;
		string->head->prev = new_node;
		string->head = new_node;
	}
	string->size++;
}

void String_append_at_back(String string, char value)
{
	StringNode new_node = StringNode_allocate(value);
	if (string->head == NULL || string->tail == NULL)
	{
		string->head = new_node;
		string->tail = new_node;
	}
	else
	{
		string->tail->next = new_node;
		new_node->prev = string->tail;
		string->tail = new_node;
	}
	string->size++;
}

char String_remove_at_front(String string)
{
	if (String_is_empty(string))
	{
		return ' ';
	}

	char value = string->head->value;
	if (string->head == string->tail)
	{
		StringNode_deallocate(string->head);
		string->head = NULL;
		string->tail = NULL;
	}
	else
	{
		StringNode target_node = string->head;
		string->head = target_node->next;
		string->head->prev = NULL;
		StringNode_deallocate(target_node);
	}
	string->size--;

	return value;
}

char String_remove_at_back(String string)
{
	if (String_is_empty(string))
	{
		return ' ';
	}

	char value = string->tail->value;
	if (string->head == string->tail)
	{
		StringNode_deallocate(string->tail);
		string->tail = NULL;
		string->tail = NULL;
	}
	else
	{
		StringNode target_node = string->tail;
		string->tail = target_node->prev;
		string->tail->next = NULL;
		StringNode_deallocate(target_node);
	}
	string->size--;

	return value;
}

char String_peak_at_front(String string)
{
	return (!String_is_empty(string)) ? string->head->value : ' ';
}

char String_peak_at_tail(String string)
{
	return (!String_is_empty(string)) ? string->tail->value : ' ';
}

void String_display(String string)
{
	StringNode current_node = string->head;
	while (current_node != NULL)
	{
		printf("%c", current_node->value);
		current_node = current_node->next;
	}
}

char* String_to_array(String string)
{
	int index = 0;
	char* array = (char*) malloc(sizeof(char) * string->size);
	StringNode current_node = string->tail->next;
	while (current_node != NULL)
	{
		array[index++] = current_node->value;
		current_node = current_node->next;
	}

	return array;
}

BinaryExpressionTreeNode BinaryExpressionTreeNode_allocate()
{
	BinaryExpressionTreeNode node = (BinaryExpressionTreeNode) malloc(sizeof(struct binary_expression_tree_node));
	node->value = String_allocate();
	node->left_child = NULL;
	node->right_child = NULL;

	return node;
}

String BinaryExpressionTreeNode_deallocate(BinaryExpressionTreeNode node)
{
	String value = node->value;
	node->value = NULL;
	node->left_child = NULL;
	node->right_child = NULL;
	free(node);

	return value;
}

BinaryExpressionTree BinaryExpressionTree_allocate()
{
	BinaryExpressionTree tree = (BinaryExpressionTree) malloc(sizeof(struct binary_expression_tree));
	tree->size = 0;
	tree->root = NULL;

	return tree;
}

void __BinaryExpressionTree_deallocate(BinaryExpressionTreeNode root)
{
	if (root == NULL)
	{
		return;
	}

	__BinaryExpressionTree_deallocate(root->left_child);
	__BinaryExpressionTree_deallocate(root->right_child);

	String_deallocate(BinaryExpressionTreeNode_deallocate(root));
}

void BinaryExpressionTree_deallocate(BinaryExpressionTree tree)
{
	__BinaryExpressionTree_deallocate(tree->root);
	tree->root = NULL;
	tree->size = 0;
	free(tree);
}

bool BinaryExpressionTree_is_empty(BinaryExpressionTree tree)
{
	return tree->root == NULL;
}

void __BinaryExpressionTree_display_via_pre_order_traversal(BinaryExpressionTreeNode root)
{
	if (root == NULL)
	{
		return;
	}

	String_display(root->value);
	printf(" ");
	__BinaryExpressionTree_display_via_pre_order_traversal(root->left_child);
	__BinaryExpressionTree_display_via_pre_order_traversal(root->right_child);
}

void BinaryExpressionTree_display_via_pre_order_traversal(BinaryExpressionTree tree)
{
	if (tree == NULL)
	{
		return;
	}

	__BinaryExpressionTree_display_via_pre_order_traversal(tree->root);
	printf("\n");
}

void __BinaryExpressionTree_display_via_in_order_traversal(BinaryExpressionTreeNode root)
{
	if (root == NULL)
	{
		return;
	}

	__BinaryExpressionTree_display_via_in_order_traversal(root->left_child);
	String_display(root->value);
	printf(" ");
	__BinaryExpressionTree_display_via_in_order_traversal(root->right_child);
}

void BinaryExpressionTree_display_via_in_order_traversal(BinaryExpressionTree tree)
{
	if (tree == NULL)
	{
		return;
	}

	__BinaryExpressionTree_display_via_in_order_traversal(tree->root);
	printf("\n");
}

void __BinaryExpressionTree_display_via_post_order_traversal(BinaryExpressionTreeNode root)
{
	if (root == NULL)
	{
		return;
	}

	__BinaryExpressionTree_display_via_post_order_traversal(root->left_child);
	__BinaryExpressionTree_display_via_post_order_traversal(root->right_child);
	String_display(root->value);
	printf(" ");
}

void BinaryExpressionTree_display_via_post_order_traversal(BinaryExpressionTree tree)
{
	if (tree == NULL)
	{
		return;
	}

	__BinaryExpressionTree_display_via_post_order_traversal(tree->root);
	printf("\n");
}

StackNode StackNode_allocate(BinaryExpressionTreeNode value)
{
	StackNode node = (StackNode) malloc(sizeof(struct stack_node));
	node->value = value;
	node->next = NULL;

	return node;
}

void StackNode_deallocate(StackNode node)
{
	node->value = NULL;
	node->next = NULL;
	free(node);
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
	StackNode current_node = stack->head;
	while (current_node != NULL)
	{
		StackNode target_node = current_node;
		current_node = current_node->next;
		StackNode_deallocate(target_node);
	}
	stack->size = 0;
	stack->head = NULL;
	free(stack);
}

bool Stack_is_empty(Stack stack)
{
	return stack->head == NULL;
}

void Stack_push(Stack stack, BinaryExpressionTreeNode value)
{
	StackNode new_node = StackNode_allocate(value);
	new_node->next = stack->head;
	stack->head = new_node;
	stack->size++;
}

BinaryExpressionTreeNode Stack_pop(Stack stack)
{
	BinaryExpressionTreeNode value = stack->head->value;
	StackNode target_node = stack->head;
	stack->head = target_node->next;
	StackNode_deallocate(target_node);
	stack->size--;

	return value;
}

BinaryExpressionTreeNode Stack_peak(Stack stack)
{
	return (!Stack_is_empty(stack)) ? stack->head->value : NULL;
}

bool is_operator(char character)
{
	return character == '+' || character == '-' ||
		character == '*' || character == '/' ||
		character == '%' || character == '^';
}

bool is_operand(char character)
{
	return (('0' - 1) < character && character < ('9' + 1)) ||
		(('a' - 1) < character && character < ('z' + 1)) ||
		(('A' - 1) < character && character < ('Z' + 1)) ||
		character == '.';
}

BinaryExpressionTree solution(char* postfix_expression, int size)
{
	Stack nodes = Stack_allocate();
	Stack_push(nodes, BinaryExpressionTreeNode_allocate());
	for (int index = 0; index < size; index++)
	{
		char character = postfix_expression[index];
		if (character == ' ')
		{
			Stack_push(nodes, BinaryExpressionTreeNode_allocate());
		}
		else if (character == '-' && is_operand(postfix_expression[index + 1]))
		{
			String_append_at_back(Stack_peak(nodes)->value, '-');
		}
		else if (is_operand(character))
		{
			String_append_at_back(Stack_peak(nodes)->value, character);
		}
		else if (is_operator(character))
		{
			BinaryExpressionTreeNode root_node = Stack_pop(nodes);
			BinaryExpressionTreeNode right_child = Stack_pop(nodes);
			BinaryExpressionTreeNode left_child = Stack_pop(nodes);
			String_append_at_back(root_node->value, character);
			root_node->left_child = left_child;
			root_node->right_child = right_child;
			Stack_push(nodes, root_node);
		}
	}
	BinaryExpressionTree tree = BinaryExpressionTree_allocate();
	tree->root = Stack_pop(nodes);
	Stack_deallocate(nodes);

	return tree;
}
