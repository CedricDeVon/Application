#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include <ctype.h>
#include <limits.h>

typedef struct node
{
	int value;
	int height;
	struct node* left_node;
	struct node* right_node;

} *Node;

Node Node_allocate(int value)
{
	Node node = (Node) malloc(sizeof(struct node));
	node->value = value;
	node->height = 1;
	node->left_node = NULL;
	node->right_node = NULL;

	return node;
}

Node Node_deallocate(Node node)
{
	node->value = 0;
	node->left_node = NULL;
	node->right_node = NULL;
	free(node);
	node = NULL;

	return node;
}

typedef struct avl_tree
{
	int size;
	Node root_node;

} *AvlTree;

AvlTree AvlTree_allocate()
{
	AvlTree tree = (AvlTree) malloc(sizeof(struct avl_tree));
	tree->size = 0;
	tree->root_node = NULL;

	return tree;
}

void __AvlTree_deallocate(Node node)
{
	if (node == NULL)
	{
		return;
	}

	__AvlTree_deallocate(node->left_node);
	__AvlTree_deallocate(node->right_node);
	Node_deallocate(node);
}

AvlTree AvlTree_deallocate(AvlTree tree)
{
	__AvlTree_deallocate(tree->root_node);

	tree->root_node = NULL;
	tree->size = 0;
	free(tree);
	tree = NULL;

	return tree;
}

int __AvlTree_get_tree_height(Node node)
{
	if (node == NULL)
	{
		return 0;
	}

	int left_node_height = __AvlTree_get_tree_height(node->left_node);
	int right_node_height = __AvlTree_get_tree_height(node->right_node);
	return ((left_node_height > right_node_height) ?
		left_node_height : right_node_height) + 1;
}

int AvlTree_get_tree_height(AvlTree tree)
{
	return __AvlTree_get_tree_height(tree->root_node);
}

int get_max(int x, int y)
{
	return (x > y) ? x : y;
}

int AvlTree_get_height(Node node)
{
	return (node != NULL) ? node->height : 0;
}

void __AvlTree_get_level(Node node, int value, int* level)
{
	if (node == NULL)
	{
		*level = -1;
		return;
	}

	if (value < node->left_node->value)
	{
		*level += 1;
		__AvlTree_get_level(node->left_node, value, level);
	}
	else if (node->right_node->value < value)
	{
		*level += 1;
		__AvlTree_get_level(node->right_node, value, level);
	}
}

int AvlTree_get_level(AvlTree tree, int value)
{
	int level = 0;
	int* pointer_level = &level;
	__AvlTree_get_level(tree->root_node, value, pointer_level);

	return level;
}

int AvlTree_get_balance_factor(Node node)
{
	int left_node_height = AvlTree_get_height(node->left_node);
	int right_node_height = AvlTree_get_height(node->right_node);

	return left_node_height - right_node_height;
}

void __AvlTree_display_via_pre_order_depth_first_traversal(Node node)
{
	if (node == NULL)
	{
		return;
	}

	printf("%d ", node->value);
	__AvlTree_display_via_pre_order_depth_first_traversal(node->left_node);
	__AvlTree_display_via_pre_order_depth_first_traversal(node->right_node);
}

void AvlTree_display_via_pre_order_depth_first_traversal(AvlTree tree)
{
	__AvlTree_display_via_pre_order_depth_first_traversal(tree->root_node);
	printf("\n");
}

void __AvlTree_display_via_in_order_depth_first_traversal(Node node)
{
	if (node == NULL)
	{
		return;
	}

	__AvlTree_display_via_in_order_depth_first_traversal(node->left_node);
	printf("%d ", node->value);
	__AvlTree_display_via_in_order_depth_first_traversal(node->right_node);
}

void AvlTree_display_via_in_order_depth_first_traversal(AvlTree tree)
{
	__AvlTree_display_via_in_order_depth_first_traversal(tree->root_node);
	printf("\n");
}

void __AvlTree_display_via_post_order_depth_first_traversal(Node node)
{
	if (node == NULL)
	{
		return;
	}

	__AvlTree_display_via_post_order_depth_first_traversal(node->left_node);
	__AvlTree_display_via_post_order_depth_first_traversal(node->right_node);
	printf("%d ", node->value);
}

void AvlTree_display_via_post_order_depth_first_traversal(AvlTree tree)
{
	__AvlTree_display_via_post_order_depth_first_traversal(tree->root_node);
	printf("\n");
}

void __AvlTree_display_balance_factor_via_post_order_depth_first_traversal(Node node)
{
	if (node == NULL)
	{
		return;
	}

	__AvlTree_display_balance_factor_via_post_order_depth_first_traversal(node->left_node);
	__AvlTree_display_balance_factor_via_post_order_depth_first_traversal(node->right_node);
	printf("(%d : %d) ", node->value, AvlTree_get_balance_factor(node));
}

void AvlTree_display_balance_factor_via_post_order_depth_first_traversal(AvlTree tree)
{
	__AvlTree_display_balance_factor_via_post_order_depth_first_traversal(tree->root_node);
	printf("\n");
}


Node AvlTree_right_rotate(Node root_node)
{
	Node node_x = root_node->left_node;
	Node node_y = node_x->right_node;

	node_x->right_node = root_node;
	root_node->left_node = node_y;

	root_node->height = get_max(
		AvlTree_get_height(root_node->left_node), AvlTree_get_height(root_node->right_node)) + 1;
	node_x->height = get_max(
		AvlTree_get_height(node_x->left_node), AvlTree_get_height(node_x->right_node)) + 1;

	return node_x;
}

Node AvlTree_left_rotate(Node root_node)
{
	Node node_x = root_node->right_node;
	Node node_y = node_x->left_node;

	node_x->left_node = root_node;
	root_node->right_node = node_y;

	root_node->height = get_max(
		AvlTree_get_height(root_node->left_node), AvlTree_get_height(root_node->right_node)) + 1;
	node_x->height = get_max(
		AvlTree_get_height(node_x->left_node), AvlTree_get_height(node_x->right_node)) + 1;

	return node_x;
}

Node __AvlTree_insert(Node node, int value)
{
	if (node == NULL)
	{
		return Node_allocate(value);
	}

	if (value < node->value)
	{
		node->left_node = __AvlTree_insert(node->left_node, value);
	}
	else if (node->value < value)
	{
		node->right_node = __AvlTree_insert(node->right_node, value);
	}
	else
	{
		return node;
	}

	node->height = get_max(AvlTree_get_height(node->left_node), AvlTree_get_height(node->right_node)) + 1;
	int balance_factor = AvlTree_get_balance_factor(node);

	if (balance_factor > 1 && value < node->left_node->value)
	{
		return AvlTree_right_rotate(node);
	}
	if (balance_factor < -1 && node->right_node->value < value)
	{
		return AvlTree_left_rotate(node);
	}
	if (balance_factor > 1 && node->left_node->value < value)
	{
		node->left_node = AvlTree_left_rotate(node->left_node);
		return AvlTree_right_rotate(node);
	}
	if (balance_factor < -1 && value < node->right_node->value)
	{
		node->right_node = AvlTree_right_rotate(node->right_node);
		return AvlTree_left_rotate(node);
	}

	return node;
}

void AvlTree_insert(AvlTree tree, int value)
{
	tree->root_node = __AvlTree_insert(tree->root_node, value);
	tree->size += 1;
}

int __AvlTree_sum(Node node)
{
	if (node == NULL)
	{
		return 0;
	}

	return __AvlTree_sum(node->left_node) + __AvlTree_sum(node->right_node) + node->value;
}

int AvlTree_sum(AvlTree tree)
{
	return __AvlTree_sum(tree->root_node);
}

int main(void)
{
	// AvlTree tree = AvlTree_allocate();
	// AvlTree_insert(tree, 10);
	// AvlTree_insert(tree, 20);
	// AvlTree_insert(tree, 30);
	// AvlTree_insert(tree, 40);
	// AvlTree_insert(tree, 50);
	// AvlTree_insert(tree, 25);

	// AvlTree_display_via_pre_order_depth_first_traversal(tree);
	// AvlTree_display_via_in_order_depth_first_traversal(tree);
	// AvlTree_display_via_post_order_depth_first_traversal(tree);
	// AvlTree_display_balance_factor_via_post_order_depth_first_traversal(tree);

	// printf("%d\n", AvlTree_sum(tree));

	// AvlTree_deallocate(tree);
	printf("STart \n");
	Sleep(1000);
	printf("End");

	int exit_code = 0;
	scanf("%d", &exit_code);
	return 0;
}
