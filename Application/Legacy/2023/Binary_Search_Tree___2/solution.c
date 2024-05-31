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

BinarySearchTreeNode BinarySearchTreeNode_allocate(char value)
{
	BinarySearchTreeNode node = (BinarySearchTreeNode) malloc(sizeof(struct binary_search_tree_node));
	node->value = value;
	node->left = NULL;
	node->right = NULL;

	return node;
}

void BinarySearchTreeNode_deallocate(BinarySearchTreeNode node)
{
	node->value = 0;
	node->left = NULL;
	node->right = NULL;
	free(node);
}

BinarySearchTree BinarySearchTree_allocate()
{
	BinarySearchTree tree = (BinarySearchTree) malloc(sizeof(struct binary_search_tree));
	tree->size = 0;
	tree->root = NULL;

	return tree;
}

BinarySearchTreeNode __BinarySearchTree_insert(BinarySearchTreeNode node, char value)
{
	if (node == NULL)
	{
		return BinarySearchTreeNode_allocate(value);
	}

	if (value < node->value)
	{
		node->left = __BinarySearchTree_insert(node->left, value);
		return node;
	}
	else if (value > node->value)
	{
		node->right = __BinarySearchTree_insert(node->right, value);
		return node;
	}
	else
	{
		return node;
	}
}

void BinarySearchTree_insert(BinarySearchTree tree, char value)
{
	tree->root = __BinarySearchTree_insert(tree->root, value);
	tree->size++;
}

BinarySearchTreeNode __BinarySearchTree_delete(BinarySearchTreeNode node, char value)
{
	if (node == NULL)
	{
		return node;
	}

	if (value < node->value)
	{
		node->left = __BinarySearchTree_delete(node->left, value);
		return node;
	}
	else if (value > node->value)
	{
		node->right = __BinarySearchTree_delete(node->right, value);
		return node;
	}

	if (node->left == NULL && node->right == NULL)
	{
		BinarySearchTreeNode_deallocate(node);

		return NULL;
	}
	else if (node->left == NULL)
	{
		BinarySearchTreeNode temp = node->right;
		BinarySearchTreeNode_deallocate(node);

		return temp;
	}
	else if (node->right == NULL)
	{
		BinarySearchTreeNode temp = node->left;
		BinarySearchTreeNode_deallocate(node);

		return temp;
	}
	else
	{	
		BinarySearchTreeNode node_a = node;
		BinarySearchTreeNode node_b = node->left;
		while (node_b->right != NULL)
		{
			node_a = node_b;
			node_b = node_b->right;
		}

		if (node_a != node)
		{
			node_a->right = node_b->left;
		}
		else
		{
			node_a->left = node_b->left;
		}

		node->value = node_b->value;
		BinarySearchTreeNode_deallocate(node_b);

		return node;	
	}
}

void BinarySearchTree_delete(BinarySearchTree tree, char value)
{
	tree->root = __BinarySearchTree_delete(tree->root, value);
	tree->size--;
}

void __BinarySearchTree_display_via_pre_order_traversal(BinarySearchTreeNode node)
{
	if (node == NULL)
	{
		return;
	}

	printf("%c ", node->value);
	__BinarySearchTree_display_via_pre_order_traversal(node->left);
	__BinarySearchTree_display_via_pre_order_traversal(node->right);
}

void BinarySearchTree_display_via_pre_order_traversal(BinarySearchTree tree)
{
	__BinarySearchTree_display_via_pre_order_traversal(tree->root);
	printf("\n");
}

void __BinarySearchTree_display_via_in_order_traversal(BinarySearchTreeNode node)
{
	if (node == NULL)
	{
		return;
	}

	__BinarySearchTree_display_via_in_order_traversal(node->left);
	printf("%c ", node->value);
	__BinarySearchTree_display_via_in_order_traversal(node->right);
}

void BinarySearchTree_display_via_in_order_traversal(BinarySearchTree tree)
{
	__BinarySearchTree_display_via_in_order_traversal(tree->root);
	printf("\n");
}

void __BinarySearchTree_display_via_post_order_traversal(BinarySearchTreeNode node)
{
	if (node == NULL)
	{
		return;
	}

	__BinarySearchTree_display_via_post_order_traversal(node->left);
	__BinarySearchTree_display_via_post_order_traversal(node->right);
	printf("%c ", node->value);
}

void BinarySearchTree_display_via_post_order_traversal(BinarySearchTree tree)
{
	__BinarySearchTree_display_via_post_order_traversal(tree->root);
	printf("\n");
}

bool __BinarySearchTree_is_found(BinarySearchTreeNode node, char value)
{
	if (node == NULL)
	{
		return false;
	}

	if (value < node->value)
	{
		return __BinarySearchTree_is_found(node->left, value);
	}
	else if (value > node->value)
	{
		return __BinarySearchTree_is_found(node->right, value);
	}

	return true;
}

bool BinarySearchTree_is_found(BinarySearchTree tree, char value)
{
	return __BinarySearchTree_is_found(tree->root, value);
}

int __BinarySearchTree_height(BinarySearchTreeNode node)
{
	if (node == NULL)
	{
		return 0;
	}

	int height_a = __BinarySearchTree_height(node->left);
	int height_b = __BinarySearchTree_height(node->right);

	return ((height_a > height_b) ? height_a : height_b) + 1;
}

int BinarySearchTree_height(BinarySearchTree tree)
{
	return __BinarySearchTree_height(tree->root);
}

StackNode StackNode_allocate(BinarySearchTreeNode value)
{
	StackNode node = (StackNode) malloc(sizeof(struct stack_node));
	node->value = value;
	node->next = NULL;

	return node;
}

BinarySearchTreeNode StackNode_deallocate(StackNode node)
{
	BinarySearchTreeNode value = node->value;
	free(node);

	return value;
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
		StackNode temporary_node = current_node;
		current_node = current_node->next;
		StackNode_deallocate(temporary_node);
	}
	stack->size = 0;
	stack->head = NULL;
	free(stack);
}

bool Stack_is_empty(Stack stack)
{
	return stack->head == NULL;
}

void Stack_push(Stack stack, BinarySearchTreeNode node)
{
	StackNode new_node = StackNode_allocate(node);
	new_node->next = stack->head;
	stack->head = new_node;
	stack->size++;
}

BinarySearchTreeNode Stack_pop(Stack stack)
{
	if (Stack_is_empty(stack))
	{
		return NULL;
	}

	BinarySearchTreeNode value = stack->head->value;
	if (stack->head->next == NULL)
	{
		StackNode_deallocate(stack->head);
		stack->head = NULL;
	}
	else
	{
		StackNode temporary_node = stack->head;
		stack->head = temporary_node->next;
		StackNode_deallocate(temporary_node);
	}
	stack->size--;
	
	return value;
}

BinarySearchTreeNode Stack_peak(Stack stack)
{
	return (stack->head != NULL) ? stack->head->value : NULL;
}

bool is_an_operand(char character)
{
	return (('a' - 1) < character && character < ('z' + 1)) || character == '(' || character == '-';
}

BinarySearchTree BinarySearchTree_allocate_from_parenthetical_notation(char* expression, int size)
{
	BinarySearchTree tree = BinarySearchTree_allocate();
	Stack stack = Stack_allocate();
	for (int index = 0; index < size; index++)
	{
		char character = expression[index];
		if (is_an_operand(character))
		{
			Stack_push(stack, BinarySearchTreeNode_allocate(character));
		}
		else if (character == ')')
		{
			BinarySearchTreeNode right_node = Stack_pop(stack);
			BinarySearchTreeNode left_node = Stack_pop(stack);
			BinarySearchTreeNode root_node = Stack_pop(stack);
			if (left_node->value == '-')
			{
				BinarySearchTreeNode_deallocate(left_node);
				BinarySearchTreeNode_deallocate(root_node);
				left_node = NULL;
				root_node = Stack_pop(stack);
			}
			else if (left_node->value == '(')
			{
				BinarySearchTreeNode_deallocate(left_node);
				left_node = right_node;
				right_node = NULL;
			}
			else
			{
				BinarySearchTreeNode_deallocate(root_node);
				root_node = Stack_pop(stack);
			}

			root_node->left = left_node;
			root_node->right = right_node;
			Stack_push(stack, root_node);
		}
	}
	tree->root = Stack_pop(stack);
	
	return tree;
}
