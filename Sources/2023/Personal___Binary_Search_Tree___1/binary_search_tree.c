#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <windows.h>

#include "binary_search_tree.h"

Node Node_allocate(int value)
{
	Node node = (Node) malloc(sizeof(struct node));
	node->value = value;
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

BinarySearchTree BinarySearchTree_allocate()
{
	BinarySearchTree tree = (BinarySearchTree) malloc(sizeof(struct binary_search_tree));
	tree->size = 0;
	tree->root_node = NULL;

	return tree;
}

Node __BinarySearchTree_insert(Node root_node, int value)
{
	if (root_node == NULL)
	{
		return Node_allocate(value);
	}
	else if (value < root_node->value)
	{
		root_node->left_node = __BinarySearchTree_insert(root_node->left_node, value);
	}
	else if (value > root_node->value)
	{
		root_node->right_node = __BinarySearchTree_insert(root_node->right_node, value);
	}

	return root_node;
}

void BinarySearchTree_insert(BinarySearchTree tree, int value)
{
	tree->root_node = __BinarySearchTree_insert(tree->root_node, value);
	tree->size++;
}

void __BinarySearchTree_display_via_pre_order_traversal(Node root_node)
{
	if (root_node == NULL)
	{
		return;
	}

	printf("%d ", root_node->value);
	__BinarySearchTree_display_via_pre_order_traversal(root_node->left_node);
	__BinarySearchTree_display_via_pre_order_traversal(root_node->right_node);
}

void BinarySearchTree_display_via_pre_order_traversal(BinarySearchTree tree)
{
	__BinarySearchTree_display_via_pre_order_traversal(tree->root_node);
	printf("\n");
}

void __BinarySearchTree_display_via_in_order_traversal(Node root_node)
{
	if (root_node == NULL)
	{
		return;
	}

	__BinarySearchTree_display_via_in_order_traversal(root_node->left_node);
	printf("%d ", root_node->value);
	__BinarySearchTree_display_via_in_order_traversal(root_node->right_node);
}

void BinarySearchTree_display_via_in_order_traversal(BinarySearchTree tree)
{
	__BinarySearchTree_display_via_in_order_traversal(tree->root_node);
	printf("\n");
}

void __BinarySearchTree_display_via_post_order_traversal(Node root_node)
{
	if (root_node == NULL)
	{
		return;
	}

	__BinarySearchTree_display_via_post_order_traversal(root_node->left_node);
	__BinarySearchTree_display_via_post_order_traversal(root_node->right_node);
	printf("%d ", root_node->value);
}

void BinarySearchTree_display_via_post_order_traversal(BinarySearchTree tree)
{
	__BinarySearchTree_display_via_post_order_traversal(tree->root_node);
	printf("\n");
}

void __BinarySearchTree_display_via_depth_first_traversal(Node root_node, int current_height, int target_height)
{
	if (root_node == NULL)
	{
		return;
	}

	if (current_height == target_height)
	{
		printf("%d ", root_node->value);
	}

	__BinarySearchTree_display_via_depth_first_traversal(root_node->left_node, current_height + 1, target_height);
	__BinarySearchTree_display_via_depth_first_traversal(root_node->right_node, current_height + 1, target_height);

}

void BinarySearchTree_display_via_depth_first_traversal(BinarySearchTree tree)
{
	int tree_height = BinarySearchTree_get_height(tree);
	for (int current_height = tree_height; current_height > 0; current_height--)
	{
		__BinarySearchTree_display_via_depth_first_traversal(tree->root_node, 1, current_height);
	}
	printf("\n");
}

void __BinarySearchTree_to_array_via_pre_order_traversal(Node root_node, int* values, int* index)
{
	if (root_node == NULL)
	{
		return;
	}

	values[(*index)++] = root_node->value;
	__BinarySearchTree_to_array_via_pre_order_traversal(root_node->left_node, values, index);
	__BinarySearchTree_to_array_via_pre_order_traversal(root_node->right_node, values, index);
}

int* BinarySearchTree_to_array_via_pre_order_traversal(BinarySearchTree tree)
{
	int index = 0;
	int* pointer_index = &index;
	int* values = (int*) malloc(sizeof(int) * tree->size);
	__BinarySearchTree_to_array_via_pre_order_traversal(tree->root_node, values, pointer_index);

	return values;
}

void __BinarySearchTree_to_array_via_in_order_traversal(Node root_node, int* values, int* index)
{
	if (root_node == NULL)
	{
		return;
	}

	__BinarySearchTree_to_array_via_in_order_traversal(root_node->left_node, values, index);
	values[(*index)++] = root_node->value;
	__BinarySearchTree_to_array_via_in_order_traversal(root_node->right_node, values, index);
}


int* BinarySearchTree_to_array_via_in_order_traversal(BinarySearchTree tree)
{
	int index = 0;
	int* pointer_index = &index;
	int* values = (int*) malloc(sizeof(int) * tree->size);
	__BinarySearchTree_to_array_via_in_order_traversal(tree->root_node, values, pointer_index);

	return values;
}

void __BinarySearchTree_to_array_via_post_order_traversal(Node root_node, int* values, int* index)
{
	if (root_node == NULL)
	{
		return;
	}
	
	__BinarySearchTree_to_array_via_post_order_traversal(root_node->left_node, values, index);
	__BinarySearchTree_to_array_via_post_order_traversal(root_node->right_node, values, index);
	values[(*index)++] = root_node->value;
}

int* BinarySearchTree_to_array_via_post_order_traversal(BinarySearchTree tree)
{
	int index = 0;
	int* pointer_index = &index;
	int* values = (int*) malloc(sizeof(int) * tree->size);
	__BinarySearchTree_to_array_via_post_order_traversal(tree->root_node, values, pointer_index);

	return values;
}

void __BinarySearchTree_to_array_via_depth_first_traversal(Node root_node, int current_height, int target_height, int* values, int* index)
{
	if (root_node == NULL)
	{
		return;
	}

	if (current_height == target_height)
	{
		values[(*index)++] = root_node->value;
	}
	__BinarySearchTree_to_array_via_depth_first_traversal(root_node->left_node, current_height + 1, target_height, values, index);
	__BinarySearchTree_to_array_via_depth_first_traversal(root_node->right_node, current_height + 1, target_height, values, index);

}

int* BinarySearchTree_to_array_via_depth_first_traversal(BinarySearchTree tree)
{
	int index = 0;
	int* pointer_index = &index;
	int* values = (int*) malloc(sizeof(int) * tree->size);
	int tree_height = BinarySearchTree_get_height(tree);
	for (int target_height = tree_height; target_height > 0; target_height--)
	{
		__BinarySearchTree_to_array_via_depth_first_traversal(tree->root_node, 1, target_height, values, pointer_index);
	}
	
	return values;
}

BinarySearchTree BinarySearchTree_from_array_to_binary_search_tree(int* values, int size)
{
	BinarySearchTree tree = BinarySearchTree_allocate();
	for (int i = 0; i < size; i++)
	{
		BinarySearchTree_insert(tree, values[i]);
	}

	return tree;
}

int __BinarySearchTree_get_height(Node root_node)
{
	if (root_node == NULL)
	{
		return 0;
	}

	int a = __BinarySearchTree_get_height(root_node->left_node);
	int b = __BinarySearchTree_get_height(root_node->right_node);

	return ((a > b) ? a : b) + 1;
}

int BinarySearchTree_get_height(BinarySearchTree tree)
{
	return __BinarySearchTree_get_height(tree->root_node);
}

void __BinarySearchTree_get_node_height(Node root_node, int value, int* height)
{
	if (root_node == NULL)
	{
		*height = 0;
		return;
	}

	if (value < root_node->value)
	{
		__BinarySearchTree_get_node_height(root_node->left_node, value, height);
	}
	else if (root_node->value)
	{
		__BinarySearchTree_get_node_height(root_node->right_node, value, height);
	}

	*height += 1;
}

int BinarySearchTree_get_node_height(BinarySearchTree tree, int value)
{
	int height = 0;
	int* p_height = &height;
	__BinarySearchTree_get_node_height(tree->root_node, value, p_height);

	return height;
}

void __BinarySearchTree_clear(Node root_node, int current_height, int target_height)
{
	if (root_node == NULL)
	{
		return;
	}

	if (current_height == target_height)
	{
		Node_deallocate(root_node);
		return;
	}
	__BinarySearchTree_clear(root_node->left_node, current_height + 1, target_height);
	__BinarySearchTree_clear(root_node->right_node, current_height + 1, target_height);

}

void BinarySearchTree_clear(BinarySearchTree tree)
{
	int tree_height = BinarySearchTree_get_height(tree);
	for (int target_height = tree_height; target_height > 0; target_height--)
	{
		__BinarySearchTree_clear(tree->root_node, 1, target_height);
	}
	tree->size = 0;
	tree->root_node = NULL;
}

void BinarySearchTree_deallocate(BinarySearchTree tree)
{
	BinarySearchTree_clear(tree);
	free(tree);
	tree = NULL;
}


void __BinarySearchTree_count_all_nodes(Node root_node, int* count)
{
	if (root_node == NULL)
	{
		return;
	}

	*count += 1;
	__BinarySearchTree_count_all_nodes(root_node->left_node, count);
	__BinarySearchTree_count_all_nodes(root_node->right_node, count);
}

int BinarySearchTree_count_all_nodes(BinarySearchTree tree)
{
	int count = 0;
	int* p_count = &count;
	__BinarySearchTree_count_all_nodes(tree->root_node, p_count);

	return count;
}

int __BinarySearchTree_get_indegree_of_node(Node root_node, int value)
{
	if (root_node == NULL)
	{
		return -1;
	}

	if (value < root_node->value)
	{
		return __BinarySearchTree_get_indegree_of_node(root_node->left_node, value);
	}
	else if (root_node->value < value)
	{
		return __BinarySearchTree_get_indegree_of_node(root_node->right_node, value);
	}

	return 1;
}

int BinarySearchTree_get_indegree_of_node(BinarySearchTree tree, int value)
{
	if (value == tree->root_node->value)
	{
		return 0;
	}

	return __BinarySearchTree_get_indegree_of_node(tree->root_node, value);
}

int __BinarySearchTree_get_outdegree_of_node(Node root_node, int value)
{
	if (root_node == NULL)
	{
		return -1;
	}

	if (value < root_node->value)
	{
		return __BinarySearchTree_get_outdegree_of_node(root_node->left_node, value);
	}
	else if (root_node->value < value)
	{
		return __BinarySearchTree_get_outdegree_of_node(root_node->right_node, value);
	}

	return (root_node->left_node != NULL) + (root_node->right_node != NULL);
}

int BinarySearchTree_get_outdegree_of_node(BinarySearchTree tree, int value)
{
	return __BinarySearchTree_get_outdegree_of_node(tree->root_node, value);
}

void __BinarySearchTree_count_all_internal_nodes(Node root_node, int* count)
{
	if (root_node->left_node != NULL || root_node->right_node != NULL)
	{
		*count += 1;
		return;
	}

	__BinarySearchTree_count_all_internal_nodes(root_node->left_node, count);
	__BinarySearchTree_count_all_internal_nodes(root_node->right_node, count);
}

int BinarySearchTree_count_all_internal_nodes(BinarySearchTree tree)
{
	int count = 0;
	int* p_count = &count;
	__BinarySearchTree_count_all_internal_nodes(tree->root_node, p_count);

	return count;
}

void __BinarySearchTree_count_all_leaf_nodes(Node root_node, int* count)
{
	if (root_node->left_node == NULL && root_node->right_node == NULL)
	{
		*count += 1;
		return;
	}

	__BinarySearchTree_count_all_leaf_nodes(root_node->left_node, count);
	__BinarySearchTree_count_all_leaf_nodes(root_node->right_node, count);
}

int BinarySearchTree_count_all_leaf_nodes(BinarySearchTree tree)
{
	int count = 0;
	int* p_count = &count;
	__BinarySearchTree_count_all_leaf_nodes(tree->root_node, p_count);

	return count;
}

bool BinarySearchTree_is_a_root_node(BinarySearchTree tree, int value)
{
	return tree->root_node != NULL && tree->root_node->value == value;
}

bool __BinarySearchTree_is_an_internal_node(Node root_node, int value)
{
	if (root_node == NULL)
	{
		return false;
	}

	if (value < root_node->value)
	{
		return __BinarySearchTree_is_an_internal_node(root_node->left_node, value);
	}
	else if (root_node->value < value)
	{
		return __BinarySearchTree_is_an_internal_node(root_node->right_node, value);
	}

	return (root_node->left_node != NULL || root_node->right_node != NULL);
}

bool BinarySearchTree_is_an_internal_node(BinarySearchTree tree, int value)
{
	return __BinarySearchTree_is_an_internal_node(tree->root_node, value);
}

bool __BinarySearchTree_is_a_leaf_node(Node root_node, int value)
{
	if (root_node == NULL)
	{
		return false;
	}

	if (value < root_node->value)
	{
		return __BinarySearchTree_is_a_leaf_node(root_node->left_node, value);
	}
	else if (root_node->value < value)
	{
		return __BinarySearchTree_is_a_leaf_node(root_node->right_node, value);
	}

	return (root_node->left_node == NULL && root_node->right_node == NULL);
}

bool BinarySearchTree_is_a_leaf_node(BinarySearchTree tree, int value)
{
	return __BinarySearchTree_is_a_leaf_node(tree->root_node, value);
}

void __BinarySearchTree_display_node_path(Node root_node, int value)
{
	if (root_node == NULL)
	{
		printf("NULL");
		return;
	}
	else if (root_node->value == value)
	{
		printf("%d", value);
		return;
	}

	printf("%d -> ", root_node->value);
	if (value < root_node->value)
	{
		__BinarySearchTree_display_node_path(root_node->left_node, value);
	}
	else if (root_node->value < value)
	{
		__BinarySearchTree_display_node_path(root_node->right_node, value);
	}
}

void BinarySearchTree_display_node_path(BinarySearchTree tree, int value)
{
	__BinarySearchTree_display_node_path(tree->root_node, value);
	printf("\n");
}

void __BinarySearchTree_get_node_level(Node root_node, int* count, int value)
{
	if (root_node == NULL)
	{
		*count = -1;
		return;
	}
	else if (root_node->value == value)
	{
		return;
	}

	*count += 1;
	if (value < root_node->value)
	{
		__BinarySearchTree_get_node_level(root_node->left_node, count, value);
	}
	else if (root_node->value < value)
	{
		__BinarySearchTree_get_node_level(root_node->right_node, count, value);
	}
}

int BinarySearchTree_get_node_level(BinarySearchTree tree, int value)
{
	int count = 0;
	int* p_count = &count;
	__BinarySearchTree_get_node_level(tree->root_node, p_count, value);

	return count;
}

bool __BinarySearchTree_is_parent_to_child(Node root_node, int parent_value, int child_value)
{
	if (root_node == NULL)
	{
		return false;
	}
	
	if (parent_value < root_node->value)
	{
		return __BinarySearchTree_is_parent_to_child(
			root_node->left_node, parent_value, child_value);
	}
	else if (root_node->value < parent_value)
	{
		return __BinarySearchTree_is_parent_to_child(
			root_node->right_node, parent_value, child_value);
	}

	return root_node->value == parent_value &&
		((root_node->left_node != NULL && root_node->left_node->value == child_value) ||
		(root_node->right_node != NULL && root_node->right_node->value == child_value));
}

bool BinarySearchTree_is_parent_to_child(BinarySearchTree tree, int parent_value, int child_value)
{
	return __BinarySearchTree_is_parent_to_child(tree->root_node, parent_value, child_value);
}

bool __BinarySearchTree_are_both_nodes_siblings(
	Node root_node, int sibling_value_a, int sibling_value_b)
{
	if (root_node == NULL)
	{
		return false;
	}
	
	if (sibling_value_a < root_node->value)
	{
		return __BinarySearchTree_are_both_nodes_siblings(
			root_node->left_node, sibling_value_a, sibling_value_b);
	}
	else if (root_node->value < sibling_value_a)
	{
		return __BinarySearchTree_are_both_nodes_siblings(
			root_node->right_node, sibling_value_a, sibling_value_b);
	}

	return (root_node->left_node != NULL && root_node->left_node->value == sibling_value_a) &&
			(root_node->right_node != NULL && root_node->right_node->value == sibling_value_b);
}

bool BinarySearchTree_are_both_nodes_siblings(
	BinarySearchTree tree, int sibling_value_a, int sibling_value_b)
{
	return __BinarySearchTree_are_both_nodes_siblings(
		tree->root_node, sibling_value_a, sibling_value_b);
}

int __BinarySearchTree_get_left_child_node_value(Node root_node, int value)
{
	if (root_node == NULL)
	{
		return -1;
	}

	if (value < root_node->value)
	{
		return __BinarySearchTree_get_left_child_node_value(root_node->left_node, value);
	}
	else if (root_node->value < value)
	{
		return __BinarySearchTree_get_left_child_node_value(root_node->right_node, value);
	}

	return (root_node->left_node != NULL) ? root_node->left_node->value : -1;
}

int BinarySearchTree_get_left_child_node(BinarySearchTree tree, int value)
{
	return __BinarySearchTree_get_left_child_node_value(tree->root_node, value);
}

int __BinarySearchTree_get_right_child_node(Node root_node, int value)
{
	if (root_node == NULL)
	{
		return -1;
	}

	if (value < root_node->value)
	{
		return __BinarySearchTree_get_right_child_node(root_node->left_node, value);
	}
	else if (root_node->value < value)
	{
		return __BinarySearchTree_get_right_child_node(root_node->right_node, value);
	}

	return (root_node->right_node != NULL) ? root_node->right_node->value : -1;
}

int BinarySearchTree_get_right_child_node(BinarySearchTree tree, int value)
{
	return __BinarySearchTree_get_right_child_node(tree->root_node, value);
}

int __BinarySearchTree_display_node_balance_factors(Node root_node)
{
	if (root_node == NULL)
	{
		return 0;
	}

	int left_node_height =
		__BinarySearchTree_display_node_balance_factors(root_node->left_node);
	int right_node_height =
		__BinarySearchTree_display_node_balance_factors(root_node->right_node);
	printf("(%d : %d)\n", root_node->value, left_node_height - right_node_height);

	return ((left_node_height > right_node_height) ? left_node_height : right_node_height) + 1;
}

void BinarySearchTree_display_node_balance_factors(BinarySearchTree tree)
{
	__BinarySearchTree_display_node_balance_factors(tree->root_node);
}

bool BinarySearchTree_are_both_nodes_cousins(
	BinarySearchTree tree, int first_node_value, int second_node_value)
{
	int first_node_height = BinarySearchTree_get_node_height(tree, first_node_value);
	int second_node_height = BinarySearchTree_get_node_height(tree, second_node_value);

	return first_node_height == second_node_height;
}	

bool __BinarySearchTree_is_node_found(Node root_node, int value)
{
	if (root_node == NULL)
	{
		return false;
	}

	if (value < root_node->value)
	{
		return __BinarySearchTree_is_node_found(root_node->left_node, value);
	}
	else if (root_node->value < value)
	{
		return __BinarySearchTree_is_node_found(root_node->right_node, value);
	}

	return true;
}

bool BinarSearchTree_is_node_found(BinarySearchTree tree, int value)
{
	return __BinarySearchTree_is_node_found(tree->root_node, value);
}

bool BinarySearchTree_is_ancestor(
	BinarySearchTree tree, int first_node_value, int second_node_value)
{
	int first_node_height = BinarySearchTree_get_node_height(tree, first_node_value);
	int second_node_height = BinarySearchTree_get_node_height(tree, second_node_value);

	return first_node_height != 0 && second_node_height != 0 &&
		first_node_height < second_node_height &&
		first_node_value < second_node_value;
}	

bool BinarySearchTree_is_descendant(
	BinarySearchTree tree, int first_node_value, int second_node_value)
{
	int first_node_height = BinarySearchTree_get_node_height(tree, first_node_value);
	int second_node_height = BinarySearchTree_get_node_height(tree, second_node_value);

	return first_node_height != 0 && second_node_height != 0 &&
		first_node_height > second_node_height &&
		first_node_value > second_node_value;
}	

// Father Darwin Gitgano Bohol
/*
Binary Trees
/ Node Struct
/ Tree Struct
/ Allocate Node
/ Allocate Tree
/ Deallocate Node
/ Insert Node
/ Display Via Level Pre-Order Traversal
/ Display Via Level In-Order Traversal
/ Display Via Level Post-Order Trav)ersal
/ Display Via Depth-First Traversal
/ To Array Via Pre-Order Traversal
/ To Array Via In-Order Traversal
/ To Array Via Post-Order Traversal
/ To Array Via Depth-First Traversal
/ From Array To Binary Tree
/ Get Node Height
/ Deallocate Tree
/ Clear Tree
/ Delete Node

/ Get Indegree of Node
/ Get Outdegree of Node
/ Is Node A Root Node
/ Is Node An Internal Node
/ Is Node A Leaf Node
/ Get Node Count
/ Get Leaf Node Count
/ Get Internal Node Count
/ Node Path
/ Get Node Level
/ Is X A Child Left Node Of Y
/ Is X A Child Right Node Of Y
/ Are Both Nodes Siblings
/ Is X A Parent Node Of Y
/ Get Balance Factor Of Each Node
/ Are Both Nodes Cousins
/ Is Node Found
/ Is X An Ancestor Node Of Y
/ Is X A Descendant Node Of Y
*/