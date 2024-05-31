#ifndef BINARY_SEARCH_TREE_H_INCLUDED
#define BINARY_SEARCH_TREE_H_INCLUDED


Node Node_allocate(int value);

Node Node_deallocate(Node node);

BinarySearchTree BinarySearchTree_allocate();

Node __BinarySearchTree_insert(Node root_node, int value);
void BinarySearchTree_insert(BinarySearchTree tree, int value);

void __BinarySearchTree_display_via_pre_order_traversal(Node root_node);
void BinarySearchTree_display_via_pre_order_traversal(BinarySearchTree tree);

void __BinarySearchTree_display_via_in_order_traversal(Node root_node);
void BinarySearchTree_display_via_in_order_traversal(BinarySearchTree tree);

void __BinarySearchTree_display_via_post_order_traversal(Node root_node);
void BinarySearchTree_display_via_post_order_traversal(BinarySearchTree tree);

void __BinarySearchTree_display_via_depth_first_traversal(Node root_node, int current_height, int target_height);
void BinarySearchTree_display_via_depth_first_traversal(BinarySearchTree tree);

void __BinarySearchTree_to_array_via_pre_order_traversal(Node root_node, int* values, int* index);
int* BinarySearchTree_to_array_via_pre_order_traversal(BinarySearchTree tree);

void __BinarySearchTree_to_array_via_in_order_traversal(Node root_node, int* values, int* index);
int* BinarySearchTree_to_array_via_in_order_traversal(BinarySearchTree tree);

void __BinarySearchTree_to_array_via_post_order_traversal(Node root_node, int* values, int* index);
int* BinarySearchTree_to_array_via_post_order_traversal(BinarySearchTree tree);

void __BinarySearchTree_to_array_via_depth_first_traversal(Node root_node, int current_height, int target_height, int* values, int* index);
int* BinarySearchTree_to_array_via_depth_first_traversal(BinarySearchTree tree);

BinarySearchTree BinarySearchTree_from_array_to_binary_search_tree(int* values, int size);

int __BinarySearchTree_get_height(Node root_node);
int BinarySearchTree_get_height(BinarySearchTree tree);

void __BinarySearchTree_get_node_height(Node root_node, int value, int* height);
int BinarySearchTree_get_node_height(BinarySearchTree tree, int value);

void __BinarySearchTree_clear(Node root_node, int current_height, int target_height);
void BinarySearchTree_clear(BinarySearchTree tree);

void BinarySearchTree_deallocate(BinarySearchTree tree);

Node __BinarySearchTree_delete(Node root_node, int target_value, BinarySearchTree tree);
void BinarySearchTree_delete(BinarySearchTree tree, int target_value);

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


#endif