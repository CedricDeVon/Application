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
	node->left_child = NULL;
	node->right_child = NULL;

	return node;
}

void BinarySearchTreeNode_deallocate(BinarySearchTreeNode node)
{
	node->value = ' ';
	node->left_child = NULL;
	node->right_child = NULL;
	free(node);
}

BinarySearchTree BinarySearchTree_allocate()
{
	BinarySearchTree tree = (BinarySearchTree) malloc(sizeof(struct binary_search_tree));
	tree->size = 0;
	tree->root = NULL;

	return tree;
}

void BinarySearchTree_deallocate(BinarySearchTree tree)
{
	tree->size = 0;
	tree->root = NULL;
	free(tree);
}

bool BinarySearchTree_is_empty(BinarySearchTree tree)
{
	return tree->root == NULL;
}

void __BinarySearchTree_pre_order_traversal(BinarySearchTreeNode node)
{
	if (node == NULL)
	{
		return;
	}

	printf("%c ", node->value);
	__BinarySearchTree_pre_order_traversal(node->left_child);
	__BinarySearchTree_pre_order_traversal(node->right_child);
}

void BinarySearchTree_pre_order_traversal(BinarySearchTree tree)
{
	__BinarySearchTree_pre_order_traversal(tree->root);
	printf("\n");
}

void __BinarySearchTree_in_order_traversal(BinarySearchTreeNode node)
{
	if (node == NULL)
	{
		return;
	}

	__BinarySearchTree_in_order_traversal(node->left_child);
	printf("%c ", node->value);
	__BinarySearchTree_in_order_traversal(node->right_child);
}

void BinarySearchTree_in_order_traversal(BinarySearchTree tree)
{
	__BinarySearchTree_in_order_traversal(tree->root);
	printf("\n");
}

void __BinarySearchTree_post_order_traversal(BinarySearchTreeNode node)
{
	if (node == NULL)
	{
		return;
	}

	__BinarySearchTree_post_order_traversal(node->left_child);
	__BinarySearchTree_post_order_traversal(node->right_child);
	printf("%c ", node->value);
}

void BinarySearchTree_post_order_traversal(BinarySearchTree tree)
{
	__BinarySearchTree_post_order_traversal(tree->root);
	printf("\n");
}

StackNode StackNode_allocate(BinarySearchTreeNode tree_node)
{
	StackNode node = (StackNode) malloc(sizeof(struct stack_node));
	node->value = tree_node;
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

void Stack_push(Stack stack, BinarySearchTreeNode tree_node)
{
	StackNode new_node = StackNode_allocate(tree_node);
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
		StackNode target_node = stack->head;
		stack->head = target_node->next;
		StackNode_deallocate(target_node);
	}
	stack->size--;

	return value;
}

BinarySearchTreeNode Stack_peak(Stack stack)
{
	return (!Stack_is_empty(stack)) ? stack->head->value : NULL;
}

char* Stack_to_array(Stack stack)
{
	char* values = (char*) malloc(sizeof(char) * stack->size);
	int index = stack->size - 1;
	while (!Stack_is_empty(stack))
	{
		values[index--] = Stack_pop(stack)->value;
	}

	return values;
}

bool is_operand(char character)
{
	return (('0' - 1) < character && character < ('9' + 1)) ||
		(('a' - 1) < character && character < ('z' + 1)) ||
		(('A' - 1) < character && character < ('Z' + 1));
}

BinarySearchTree solution(char* expression, int size)
{
	Stack tree_nodes = Stack_allocate();
	BinarySearchTree tree = BinarySearchTree_allocate();
	for (int index = 0; index < size; index++)
	{
		char character = expression[index];
		if (is_operand(character))
		{
			Stack_push(tree_nodes, BinarySearchTreeNode_allocate(character));
			tree->size++;
		}
		else if (character == '(' || character == '-')
		{
			Stack_push(tree_nodes, BinarySearchTreeNode_allocate(character));
		}
		else if (character == ')')
		{
			BinarySearchTreeNode root_node = NULL;
			BinarySearchTreeNode child_node = Stack_pop(tree_nodes);
			if (Stack_peak(tree_nodes)->value == '(')
			{
				BinarySearchTreeNode_deallocate(Stack_pop(tree_nodes));
				root_node = Stack_pop(tree_nodes);
				root_node->left_child = child_node;
				root_node->right_child = NULL;
			}
			else if (Stack_peak(tree_nodes)->value == '-')
			{
				BinarySearchTreeNode_deallocate(Stack_pop(tree_nodes));
				BinarySearchTreeNode_deallocate(Stack_pop(tree_nodes));
				root_node = Stack_pop(tree_nodes);
				root_node->left_child = NULL;
				root_node->right_child = child_node;
			}
			else
			{
				BinarySearchTreeNode left_child = Stack_pop(tree_nodes);
				BinarySearchTreeNode_deallocate(Stack_pop(tree_nodes));
				root_node = Stack_pop(tree_nodes);
				root_node->left_child = left_child;
				root_node->right_child = child_node;
			}
			Stack_push(tree_nodes, root_node);
		}
	}
	tree->root = Stack_pop(tree_nodes);
	Stack_deallocate(tree_nodes);

	return tree;
}

void __reverse_solution(BinarySearchTreeNode node, Stack stack)
{
	if (node == NULL)
	{
		return;
	}

	Stack_push(stack, BinarySearchTreeNode_allocate(node->value));
	if (node->left_child != NULL || node->right_child != NULL)
	{
		Stack_push(stack, BinarySearchTreeNode_allocate('('));
		if (node->left_child == NULL)
		{
			Stack_push(stack, BinarySearchTreeNode_allocate('-'));
			__reverse_solution(node->right_child, stack);
		}
		else if (node->right_child == NULL)
		{
			__reverse_solution(node->left_child, stack);
		}
		else
		{
			__reverse_solution(node->left_child, stack);
			__reverse_solution(node->right_child, stack);	
		}
		Stack_push(stack, BinarySearchTreeNode_allocate(')'));
	}
}

char* reverse_solution(BinarySearchTree tree)
{
	Stack stack = Stack_allocate();
	__reverse_solution(tree->root, stack);

	char* values = Stack_to_array(stack);
	Stack_deallocate(stack);

	return values;
}
