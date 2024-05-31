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

AVLTreeNode AVLTreeNode_allocate(int value)
{
	AVLTreeNode node = (AVLTreeNode) malloc(sizeof(struct avl_tree_node));
	node->value = value;
	node->height = 1;
	node->balance_factor = 0;
	node->left_node = NULL;
	node->right_node = NULL;

	return node;
}

AVLTree AVLTree_allocate()
{
	AVLTree tree = (AVLTree) malloc(sizeof(struct avl_tree));
	tree->size = 0;
	tree->root_node = NULL;

	return tree;
}

int __AVLTree_get_node_height(AVLTreeNode node)
{
	if (node == NULL)
	{
		return 0;
	}

	int left_node_height = (node->left_node != NULL) ? node->left_node->height : 0;
	int right_node_height = (node->right_node != NULL) ? node->right_node->height : 0;

	return ((left_node_height > right_node_height) ? left_node_height : right_node_height) + 1;
}

int __AVLTree_get_node_balance_factor(AVLTreeNode node)
{
	if (node == NULL)
	{
		return 0;
	}

	int left_node_height = (node->left_node != NULL) ? node->left_node->height : 0;
	int right_node_height = (node->right_node != NULL) ? node->right_node->height : 0;

	return left_node_height - right_node_height;
}

bool __AVLTree_is_balanced(AVLTreeNode node)
{
	return -2 < node->balance_factor && node->balance_factor < 2;
}

AVLTreeNode __AVLTree_rotate_left(AVLTreeNode node_x)
{
	AVLTreeNode node_y = node_x->right_node;
	AVLTreeNode node_z	= node_y->left_node;

	node_y->left_node = node_x;
	node_x->right_node = node_z;

	node_x->height = __AVLTree_get_node_height(node_x);
	node_x->balance_factor = __AVLTree_get_node_balance_factor(node_x);
	node_y->height = __AVLTree_get_node_height(node_y);
	node_y->balance_factor = __AVLTree_get_node_balance_factor(node_y);

	return node_y;
}

AVLTreeNode __AVLTree_rotate_right(AVLTreeNode node_x)
{
	AVLTreeNode node_y = node_x->left_node;
	AVLTreeNode node_z	= node_y->right_node;

	node_y->right_node = node_x;
	node_x->left_node = node_z;

	node_x->height = __AVLTree_get_node_height(node_x);
	node_x->balance_factor = __AVLTree_get_node_balance_factor(node_x);
	node_y->height = __AVLTree_get_node_height(node_y);
	node_y->balance_factor = __AVLTree_get_node_balance_factor(node_y);

	return node_y;
}

bool __AVLTree_is_left_of_left(AVLTreeNode node, int value)
{
	return node->balance_factor > 1 && value < node->left_node->value;
}

bool __AVLTree_is_right_of_right(AVLTreeNode node, int value)
{
	return node->balance_factor < -1 && value > node->right_node->value;
}

bool __AVLTree_is_left_of_right(AVLTreeNode node, int value)
{
	return node->balance_factor < -1 && value < node->right_node->value;
}

bool __AVLTree_is_right_of_left(AVLTreeNode node, int value)
{
	return node->balance_factor > 1 && value > node->left_node->value;
}

AVLTreeNode __AVLTree_insert(AVLTreeNode node, int value, bool* pointer_is_unique)
{
	if (node == NULL)
	{
		*pointer_is_unique = true;
		return AVLTreeNode_allocate(value);
	}

	if (value < node->value)
	{
		node->left_node = __AVLTree_insert(node->left_node, value, pointer_is_unique);
	}
	else if (node->value < value)
	{
		node->right_node = __AVLTree_insert(node->right_node, value, pointer_is_unique);
	}
	else
	{
		return node;
	}
	
	node->height = __AVLTree_get_node_height(node);
	node->balance_factor = __AVLTree_get_node_balance_factor(node);

	if (__AVLTree_is_left_of_left(node, value))
	{
		return __AVLTree_rotate_right(node);
	}
	else if (__AVLTree_is_right_of_right(node, value))
	{
		return __AVLTree_rotate_left(node);
	}
	else if (__AVLTree_is_left_of_right(node, value))
	{
		node->right_node = __AVLTree_rotate_right(node->right_node);

		return __AVLTree_rotate_left(node);
	}
	else if (__AVLTree_is_right_of_left(node, value))
	{
		node->left_node = __AVLTree_rotate_left(node->left_node);

		return __AVLTree_rotate_right(node);
	}

	return node;
}

void AVLTree_insert(AVLTree tree, int value)
{
	bool is_unique = false;
	bool* pointer_is_unique = &is_unique;
	tree->root_node = __AVLTree_insert(tree->root_node, value, pointer_is_unique);
	tree->size += is_unique;
}

void __AVLTree_display_via_pre_order_traversal(AVLTreeNode node)
{
	if (node == NULL)
	{
		return;
	}

	printf("(%d : %d) ", node->value, node->balance_factor);
	__AVLTree_display_via_pre_order_traversal(node->left_node);
	__AVLTree_display_via_pre_order_traversal(node->right_node);
}

void __AVLTree_display_via_in_order_traversal(AVLTreeNode node)
{
	if (node == NULL)
	{
		return;
	}

	__AVLTree_display_via_in_order_traversal(node->left_node);
	printf("(%d : %d) ", node->value, node->balance_factor);
	__AVLTree_display_via_in_order_traversal(node->right_node);
}

void __AVLTree_display_via_post_order_traversal(AVLTreeNode node)
{
	if (node == NULL)
	{
		return;
	}

	__AVLTree_display_via_post_order_traversal(node->left_node);
	__AVLTree_display_via_post_order_traversal(node->right_node);
	printf("(%d : %d) ", node->value, node->balance_factor);
}

void AVLTree_display_via_pre_order_traversal(AVLTree tree)
{
	__AVLTree_display_via_pre_order_traversal(tree->root_node);
	printf("\n");
}

void AVLTree_display_via_in_order_traversal(AVLTree tree)
{
	__AVLTree_display_via_in_order_traversal(tree->root_node);
	printf("\n");	
}

void AVLTree_display_via_post_order_traversal(AVLTree tree)
{
	__AVLTree_display_via_post_order_traversal(tree->root_node);
	printf("\n");
}

