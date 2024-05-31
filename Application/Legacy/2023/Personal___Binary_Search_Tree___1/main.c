#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <windows.h>

typedef struct node
{
	int value;
	struct node* left_node;
	struct node* right_node;

} *Node;

typedef struct binary_search_tree
{
	int size;
	Node root_node;

} *BinarySearchTree;

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

int __BinarySearchTree_get_height(Node node)
{
	if (node == NULL)
	{
		return 0;
	}

	int left_node_height = __BinarySearchTree_get_height(node->left_node);
	int right_node_height = __BinarySearchTree_get_height(node->right_node);

	return ((left_node_height > right_node_height) ? left_node_height : right_node_height) + 1;
}

int BinarySearchTree_get_height(BinarySearchTree tree)
{
	return __BinarySearchTree_get_height(tree->root_node);
}

Node __BinarySearchTree_insert(Node node, int new_node_value)
{
	if (node == NULL)
	{
		return Node_allocate(new_node_value);
	}
	else if (new_node_value < node->value)
	{
		node->left_node = __BinarySearchTree_insert(node->left_node, new_node_value);
	}
	else if (node->value < new_node_value)
	{
		node->right_node = __BinarySearchTree_insert(node->right_node, new_node_value);
	}

	return node;
}

void BinarySearchTree_insert(BinarySearchTree tree, int new_node_value)
{
	tree->root_node = __BinarySearchTree_insert(tree->root_node, new_node_value);
	tree->size++;
}

void __BinarySearchTree_display_via_pre_order_traversal(Node node)
{
	if (node == NULL)
	{
		return;
	}

	printf("%d ", node->value);
	__BinarySearchTree_display_via_pre_order_traversal(node->left_node);
	__BinarySearchTree_display_via_pre_order_traversal(node->right_node);
}

void BinarySearchTree_display_via_pre_order_traversal(BinarySearchTree tree)
{
	__BinarySearchTree_display_via_pre_order_traversal(tree->root_node);
	printf("\n");
}

void __BinarySearchTree_display_via_in_order_traversal(Node node)
{
	if (node == NULL)
	{
		return;
	}

	__BinarySearchTree_display_via_in_order_traversal(node->left_node);
	printf("%d ", node->value);
	__BinarySearchTree_display_via_in_order_traversal(node->right_node);
}

void BinarySearchTree_display_via_in_order_traversal(BinarySearchTree tree)
{
	__BinarySearchTree_display_via_in_order_traversal(tree->root_node);
	printf("\n");
}

void __BinarySearchTree_display_via_post_order_traversal(Node node)
{
	if (node == NULL)
	{
		return;
	}

	__BinarySearchTree_display_via_post_order_traversal(node->left_node);
	__BinarySearchTree_display_via_post_order_traversal(node->right_node);
	printf("%d ", node->value);
}

void BinarySearchTree_display_via_post_order_traversal(BinarySearchTree tree)
{
	__BinarySearchTree_display_via_post_order_traversal(tree->root_node);
	printf("\n");
}

void __BinarySearchTree_display_via_depth_first_traversal(
	Node node, int current_height, int target_height)
{
	if (node == NULL)
	{
		return;
	}

	if (current_height == target_height)
	{
		printf("%d ", node->value);
	}

	__BinarySearchTree_display_via_depth_first_traversal(
		node->left_node, current_height + 1, target_height);
	__BinarySearchTree_display_via_depth_first_traversal(
		node->right_node, current_height + 1, target_height);

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

void __BinarySearchTree_to_array_via_pre_order_traversal(Node node, int* values, int* index)
{
	if (node == NULL)
	{
		return;
	}

	values[(*index)++] = node->value;
	__BinarySearchTree_to_array_via_pre_order_traversal(node->left_node, values, index);
	__BinarySearchTree_to_array_via_pre_order_traversal(node->right_node, values, index);
}

int* BinarySearchTree_to_array_via_pre_order_traversal(BinarySearchTree tree)
{
	int index = 0;
	int* pointer_index = &index;
	int* values = (int*) malloc(sizeof(int) * tree->size);
	__BinarySearchTree_to_array_via_pre_order_traversal(tree->root_node, values, pointer_index);

	return values;
}

void __BinarySearchTree_to_array_via_in_order_traversal(Node node, int* values, int* index)
{
	if (node == NULL)
	{
		return;
	}

	__BinarySearchTree_to_array_via_in_order_traversal(node->left_node, values, index);
	values[(*index)++] = node->value;
	__BinarySearchTree_to_array_via_in_order_traversal(node->right_node, values, index);
}


int* BinarySearchTree_to_array_via_in_order_traversal(BinarySearchTree tree)
{
	int index = 0;
	int* pointer_index = &index;
	int* values = (int*) malloc(sizeof(int) * tree->size);
	__BinarySearchTree_to_array_via_in_order_traversal(tree->root_node, values, pointer_index);

	return values;
}

void __BinarySearchTree_to_array_via_post_order_traversal(Node node, int* values, int* index)
{
	if (node == NULL)
	{
		return;
	}
	
	__BinarySearchTree_to_array_via_post_order_traversal(node->left_node, values, index);
	__BinarySearchTree_to_array_via_post_order_traversal(node->right_node, values, index);
	values[(*index)++] = node->value;
}

int* BinarySearchTree_to_array_via_post_order_traversal(BinarySearchTree tree)
{
	int index = 0;
	int* pointer_index = &index;
	int* values = (int*) malloc(sizeof(int) * tree->size);
	__BinarySearchTree_to_array_via_post_order_traversal(tree->root_node, values, pointer_index);

	return values;
}

void __BinarySearchTree_to_array_via_depth_first_traversal(
	Node node, int current_height, int target_height, int* values, int* index)
{
	if (node == NULL)
	{
		return;
	}

	if (current_height == target_height)
	{
		values[(*index)++] = node->value;
	}
	__BinarySearchTree_to_array_via_depth_first_traversal(node->left_node, current_height + 1, target_height, values, index);
	__BinarySearchTree_to_array_via_depth_first_traversal(node->right_node, current_height + 1, target_height, values, index);

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
	for (int index = 0; index < size; index++)
	{
		BinarySearchTree_insert(tree, values[index]);
	}

	return tree;
}

void __BinarySearchTree_get_node_height(Node node, int target_value, int* height)
{
	if (node == NULL)
	{
		*height = 0;
		return;
	}

	if (target_value < node->value)
	{
		__BinarySearchTree_get_node_height(node->left_node, target_value, height);
	}
	else if (node->value)
	{
		__BinarySearchTree_get_node_height(node->right_node, target_value, height);
	}

	*height += 1;
}

int BinarySearchTree_get_node_height(BinarySearchTree tree, int target_value)
{
	int height = 0;
	int* pointer_height = &height;
	__BinarySearchTree_get_node_height(tree->root_node, target_value, pointer_height);

	return height;
}

void __BinarySearchTree_clear(Node node, int current_height, int target_height)
{
	if (node == NULL)
	{
		return;
	}

	if (current_height == target_height)
	{
		Node_deallocate(node);
		return;
	}
	__BinarySearchTree_clear(node->left_node, current_height + 1, target_height);
	__BinarySearchTree_clear(node->right_node, current_height + 1, target_height);

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

Node __BinarySearchTree_delete(Node root_node, int target_value, BinarySearchTree tree)
{
	if (root_node == NULL)
	{
		return root_node;
	}

	if (target_value < root_node->value)
	{
		root_node->left_node = __BinarySearchTree_delete(root_node->left_node, target_value, tree);

		return root_node;
	}
	else if (root_node->value < target_value)
	{
		root_node->right_node = __BinarySearchTree_delete(root_node->right_node, target_value, tree);

		return root_node;
	}

	tree->size--;
	if (root_node->left_node == NULL)
	{
		Node temporary_node = root_node->right_node;
		Node_deallocate(root_node);

		return temporary_node;
	}
	else if (root_node->right_node == NULL)
	{
		Node temporary_node = root_node->left_node;
		Node_deallocate(root_node);

		return temporary_node;
	}
	else
	{
		Node node_a = root_node;
		Node node_b = root_node->right_node;
		while (node_b->left_node != NULL)
		{
			node_a = node_b;
			node_b = node_b->left_node;
		}

		if (node_a != root_node)
		{
			node_a->left_node = node_b->right_node;
		}
		else
		{
			node_a->right_node = node_b->right_node;
		}

		root_node->value = node_b->value;
		Node_deallocate(node_b);

		return root_node;
	}

}

void BinarySearchTree_delete(BinarySearchTree tree, int target_value)
{
	tree->root_node = __BinarySearchTree_delete(tree->root_node, target_value, tree);
	tree->size--;
}


// Node __BinarySearchTree_delete(Node node, int target_value, bool* is_found)
// {
// 	if (node == NULL)
// 	{
// 		return node;
// 	}

// 	if (target_value < node->value)
// 	{
// 		node->left_node = __BinarySearchTree_delete(node->left_node, target_value, tree);

// 		return node;
// 	}
// 	else if (node->value < target_value)
// 	{
// 		node->right_node = __BinarySearchTree_delete(node->right_node, target_value, tree);

// 		return node;
// 	}

// 	*is_found = true;
// 	if (node->left_node == NULL)
// 	{
// 		Node temporary_node = node->right_node;
// 		Node_deallocate(node);

// 		return temporary_node;
// 	}
// 	else if (node->right_node == NULL)
// 	{
// 		Node temporary_node = node->left_node;
// 		Node_deallocate(node);

// 		return temporary_node;
// 	}
// 	else
// 	{
// 		Node node_a = node;
// 		Node node_b = node->right_node;
// 		while (node_b->left_node != NULL)
// 		{
// 			node_a = node_b;
// 			node_b = node_b->left_node;
// 		}

// 		if (node_a != node)
// 		{
// 			node_a->left_node = node_b->right_node;
// 		}
// 		else
// 		{
// 			node_a->right_node = node_b->right_node;
// 		}

// 		node->value = node_b->value;
// 		Node_deallocate(node_b);

// 		return node;
// 	}
// }

// void BinarySearchTree_delete(BinarySearchTree tree, int target_value)
// {
// 	bool is_found = false;
// 	bool* pointer_is_found = &is_found;
// 	tree->root_node = __BinarySearchTree_delete(tree->root_node, target_value, pointer_is_found);
// 	tree->size = (is_found) ? tree->size + 1 : tree->size;
// }

void __BinarySearchTree_count_all_nodes(Node node, int* count)
{
	if (node == NULL)
	{
		return;
	}

	*count += 1;
	__BinarySearchTree_count_all_nodes(node->left_node, count);
	__BinarySearchTree_count_all_nodes(node->right_node, count);
}

int BinarySearchTree_count_all_nodes(BinarySearchTree tree)
{
	int count = 0;
	int* pointer_count = &count;
	__BinarySearchTree_count_all_nodes(tree->root_node, pointer_count);

	return count;
}

int __BinarySearchTree_get_indegree_of_node(Node node, int target_value)
{
	if (node == NULL)
	{
		return -1;
	}

	if (target_value < node->value)
	{
		return __BinarySearchTree_get_indegree_of_node(node->left_node, target_value);
	}
	else if (node->value < target_value)
	{
		return __BinarySearchTree_get_indegree_of_node(node->right_node, target_value);
	}

	return 1;
}

int BinarySearchTree_get_indegree_of_node(BinarySearchTree tree, int target_value)
{
	if (target_value == tree->root_node->value)
	{
		return 0;
	}

	return __BinarySearchTree_get_indegree_of_node(tree->root_node, target_value);
}

int __BinarySearchTree_get_outdegree_of_node(Node node, int target_value)
{
	if (node == NULL)
	{
		return -1;
	}

	if (target_value < node->value)
	{
		return __BinarySearchTree_get_outdegree_of_node(node->left_node, target_value);
	}
	else if (node->value < target_value)
	{
		return __BinarySearchTree_get_outdegree_of_node(node->right_node, target_value);
	}

	return (node->left_node != NULL) + (node->right_node != NULL);
}

int BinarySearchTree_get_outdegree_of_node(BinarySearchTree tree, int target_value)
{
	return __BinarySearchTree_get_outdegree_of_node(tree->root_node, target_value);
}

void __BinarySearchTree_count_all_internal_nodes(Node node, int* count)
{
	if (node->left_node != NULL || node->right_node != NULL)
	{
		*count += 1;
		return;
	}

	__BinarySearchTree_count_all_internal_nodes(node->left_node, count);
	__BinarySearchTree_count_all_internal_nodes(node->right_node, count);
}

int BinarySearchTree_count_all_internal_nodes(BinarySearchTree tree)
{
	int count = 0;
	int* pointer_count = &count;
	__BinarySearchTree_count_all_internal_nodes(tree->root_node, pointer_count);

	return count;
}

void __BinarySearchTree_count_all_leaf_nodes(Node node, int* count)
{
	if (node->left_node == NULL && node->right_node == NULL)
	{
		*count += 1;
		return;
	}

	__BinarySearchTree_count_all_leaf_nodes(node->left_node, count);
	__BinarySearchTree_count_all_leaf_nodes(node->right_node, count);
}

int BinarySearchTree_count_all_leaf_nodes(BinarySearchTree tree)
{
	int count = 0;
	int* pointer_count = &count;
	__BinarySearchTree_count_all_leaf_nodes(tree->root_node, pointer_count);

	return count;
}

bool BinarySearchTree_is_a_root_node(BinarySearchTree tree, int target_value)
{
	return tree->root_node != NULL && tree->root_node->value == target_value;
}

bool __BinarySearchTree_is_an_internal_node(Node node, int target_value)
{
	if (node == NULL)
	{
		return false;
	}

	if (target_value < node->value)
	{
		return __BinarySearchTree_is_an_internal_node(node->left_node, target_value);
	}
	else if (node->value < target_value)
	{
		return __BinarySearchTree_is_an_internal_node(node->right_node, target_value);
	}

	return (node->left_node != NULL || node->right_node != NULL);
}

bool BinarySearchTree_is_an_internal_node(BinarySearchTree tree, int target_value)
{
	return __BinarySearchTree_is_an_internal_node(tree->root_node, target_value);
}

bool __BinarySearchTree_is_a_leaf_node(Node node, int value)
{
	if (node == NULL)
	{
		return false;
	}

	if (value < node->value)
	{
		return __BinarySearchTree_is_a_leaf_node(node->left_node, value);
	}
	else if (node->value < value)
	{
		return __BinarySearchTree_is_a_leaf_node(node->right_node, value);
	}

	return (node->left_node == NULL && node->right_node == NULL);
}

bool BinarySearchTree_is_a_leaf_node(BinarySearchTree tree, int target_value)
{
	return __BinarySearchTree_is_a_leaf_node(tree->root_node, target_value);
}

void __BinarySearchTree_display_node_path(Node node, int target_value)
{
	if (node == NULL)
	{
		printf("NULL");
		return;
	}
	else if (node->value == target_value)
	{
		printf("%d", target_value);
		return;
	}

	printf("%d -> ", node->value);
	if (target_value < node->value)
	{
		__BinarySearchTree_display_node_path(node->left_node, target_value);
	}
	else if (node->value < target_value)
	{
		__BinarySearchTree_display_node_path(node->right_node, target_value);
	}
}

void BinarySearchTree_display_node_path(BinarySearchTree tree, int target_value)
{
	__BinarySearchTree_display_node_path(tree->root_node, target_value);
	printf("\n");
}

void __BinarySearchTree_get_node_level(Node node, int* count, int target_value)
{
	if (node == NULL)
	{
		*count = -1;
		return;
	}
	else if (node->value == target_value)
	{
		return;
	}

	*count += 1;
	if (target_value < node->value)
	{
		__BinarySearchTree_get_node_level(node->left_node, count, target_value);
	}
	else if (node->value < target_value)
	{
		__BinarySearchTree_get_node_level(node->right_node, count, target_value);
	}
}

int BinarySearchTree_get_node_level(BinarySearchTree tree, int target_value)
{
	int count = 0;
	int* pointer_count = &count;
	__BinarySearchTree_get_node_level(tree->root_node, pointer_count, target_value);

	return count;
}

bool __BinarySearchTree_is_parent_to_child(Node node, int parent_value, int child_value)
{
	if (node == NULL)
	{
		return false;
	}
	
	if (parent_value < node->value)
	{
		return __BinarySearchTree_is_parent_to_child(
			node->left_node, parent_value, child_value);
	}
	else if (node->value < parent_value)
	{
		return __BinarySearchTree_is_parent_to_child(
			node->right_node, parent_value, child_value);
	}

	return node->value == parent_value &&
		((node->left_node != NULL && node->left_node->value == child_value) ||
		(node->right_node != NULL && node->right_node->value == child_value));
}

bool BinarySearchTree_is_parent_to_child(BinarySearchTree tree, int parent_value, int child_value)
{
	return __BinarySearchTree_is_parent_to_child(tree->root_node, parent_value, child_value);
}

bool __BinarySearchTree_are_both_nodes_siblings(
	Node node, int sibling_value_a, int sibling_value_b)
{
	if (node == NULL)
	{
		return false;
	}
	
	if (sibling_value_a < node->value)
	{
		return __BinarySearchTree_are_both_nodes_siblings(
			node->left_node, sibling_value_a, sibling_value_b);
	}
	else if (node->value < sibling_value_a)
	{
		return __BinarySearchTree_are_both_nodes_siblings(
			node->right_node, sibling_value_a, sibling_value_b);
	}

	return (node->left_node != NULL && node->left_node->value == sibling_value_a) &&
			(node->right_node != NULL && node->right_node->value == sibling_value_b);
}

bool BinarySearchTree_are_both_nodes_siblings(
	BinarySearchTree tree, int sibling_value_a, int sibling_value_b)
{
	return __BinarySearchTree_are_both_nodes_siblings(
		tree->root_node, sibling_value_a, sibling_value_b);
}

int __BinarySearchTree_get_left_child_node_value(Node node, int value)
{
	if (node == NULL)
	{
		return -1;
	}

	if (value < node->value)
	{
		return __BinarySearchTree_get_left_child_node_value(node->left_node, value);
	}
	else if (node->value < value)
	{
		return __BinarySearchTree_get_left_child_node_value(node->right_node, value);
	}

	return (node->left_node != NULL) ? node->left_node->value : -1;
}

int BinarySearchTree_get_left_child_node(BinarySearchTree tree, int target_value)
{
	return __BinarySearchTree_get_left_child_node_value(tree->root_node, target_value);
}

int __BinarySearchTree_get_right_child_node(Node node, int target_value)
{
	if (node == NULL)
	{
		return -1;
	}

	if (target_value < node->value)
	{
		return __BinarySearchTree_get_right_child_node(node->left_node, target_value);
	}
	else if (node->value < target_value)
	{
		return __BinarySearchTree_get_right_child_node(node->right_node, target_value);
	}

	return (node->right_node != NULL) ? node->right_node->value : -1;
}

int BinarySearchTree_get_right_child_node(BinarySearchTree tree, int target_value)
{
	return __BinarySearchTree_get_right_child_node(tree->root_node, target_value);
}

int __BinarySearchTree_display_node_balance_factors(Node node)
{
	if (node == NULL)
	{
		return 0;
	}

	int left_node_height =
		__BinarySearchTree_display_node_balance_factors(node->left_node);
	int right_node_height =
		__BinarySearchTree_display_node_balance_factors(node->right_node);
	printf("(%d : %d)\n", node->value, left_node_height - right_node_height);

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

bool __BinarySearchTree_is_node_found(Node node, int target_value)
{
	if (node == NULL)
	{
		return false;
	}

	if (target_value < node->value)
	{
		return __BinarySearchTree_is_node_found(node->left_node, target_value);
	}
	else if (node->value < target_value)
	{
		return __BinarySearchTree_is_node_found(node->right_node, target_value);
	}

	return true;
}

bool BinarSearchTree_is_node_found(BinarySearchTree tree, int target_value)
{
	return __BinarySearchTree_is_node_found(tree->root_node, target_value);
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

int main(void)
{
	BinarySearchTree tree = BinarySearchTree_allocate();
	BinarySearchTree_insert(tree, 14);
	BinarySearchTree_insert(tree, 7);
	BinarySearchTree_insert(tree, 10);
	BinarySearchTree_insert(tree, 23);
	BinarySearchTree_insert(tree, 56);
	BinarySearchTree_insert(tree, 33);
	BinarySearchTree_insert(tree, 70);
	BinarySearchTree_insert(tree, 66);
	BinarySearchTree_insert(tree, 80);


	// BinarySearchTree_display_via_pre_order_traversal(tree);
	// BinarySearchTree_display_via_in_order_traversal(tree);
	BinarySearchTree_display_via_post_order_traversal(tree);

	BinarySearchTree_delete(tree, 80);
	BinarySearchTree_display_via_post_order_traversal(tree);

	BinarySearchTree_delete(tree, 70);
	BinarySearchTree_display_via_post_order_traversal(tree);

	BinarySearchTree_delete(tree, 14);
	BinarySearchTree_display_via_post_order_traversal(tree);

	BinarySearchTree_deallocate(tree);

	int exit_code = 0;
	scanf("%d", &exit_code);
	return 0;
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

