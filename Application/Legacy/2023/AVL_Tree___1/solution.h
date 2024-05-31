#ifndef SOLUTION_H_INCLUDED
#define SOLUTION_H_INCLUDED

typedef struct avl_tree_node
{
	int value;
	int height;
	int balance_factor;
	struct avl_tree_node* left_node;
	struct avl_tree_node* right_node;

} *AVLTreeNode;

typedef struct avl_tree
{
	int size;
	AVLTreeNode root_node;

} *AVLTree;

AVLTreeNode AVLTreeNode_allocate(int value);
AVLTree AVLTree_allocate();
int __AVLTree_get_node_height(AVLTreeNode node);
int __AVLTree_get_node_balance_factor(AVLTreeNode node);
bool __AVLTree_is_balanced(AVLTreeNode node);
AVLTreeNode __AVLTree_rotate_left(AVLTreeNode node_x);
AVLTreeNode __AVLTree_rotate_right(AVLTreeNode node_x);
AVLTreeNode __AVLTree_insert(AVLTreeNode node, int value, bool* pointer_is_unique);
bool __AVLTree_is_left_of_left(AVLTreeNode node, int value);
bool __AVLTree_is_right_of_right(AVLTreeNode node, int value);
bool __AVLTree_is_left_of_right(AVLTreeNode node, int value);
bool __AVLTree_is_right_of_left(AVLTreeNode node, int value);
void AVLTree_insert(AVLTree tree, int value);
void __AVLTree_display_via_pre_order_traversal(AVLTreeNode node);
void __AVLTree_display_via_in_order_traversal(AVLTreeNode node);
void __AVLTree_display_via_post_order_traversal(AVLTreeNode node);
void AVLTree_display_via_pre_order_traversal(AVLTree tree);
void AVLTree_display_via_in_order_traversal(AVLTree tree);
void AVLTree_display_via_post_order_traversal(AVLTree tree);

#endif