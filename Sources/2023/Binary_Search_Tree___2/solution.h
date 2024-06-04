#ifndef SOLUTION_H
#define SOLUTION_H

typedef struct binary_search_tree_node
{
	char value;
	struct binary_search_tree_node* left;
	struct binary_search_tree_node* right;

} *BinarySearchTreeNode;

typedef struct binary_search_tree
{
	int size;
	BinarySearchTreeNode root;

} *BinarySearchTree;

BinarySearchTreeNode Node_allocate(char value);
BinarySearchTree BinarySearchTree_allocate();
BinarySearchTree BinarySearchTree_allocate_from_parenthetical_notation(char* expression, int size);
BinarySearchTreeNode __BinarySearchTree_insert(BinarySearchTreeNode node, char value);
void BinarySearchTree_insert(BinarySearchTree tree, char value);
BinarySearchTreeNode __BinarySearchTree_delete(BinarySearchTreeNode node, char value);
void BinarySearchTree_delete(BinarySearchTree tree, char value);
void __BinarySearchTree_display_via_pre_order_traversal(BinarySearchTreeNode node);
void BinarySearchTree_display_via_pre_order_traversal(BinarySearchTree tree);
void __BinarySearchTree_display_via_in_order_traversal(BinarySearchTreeNode node);
void BinarySearchTree_display_via_in_order_traversal(BinarySearchTree tree);
void __BinarySearchTree_display_via_post_order_traversal(BinarySearchTreeNode node);
void BinarySearchTree_display_via_post_order_traversal(BinarySearchTree tree);
bool __BinarySearchTree_is_found(BinarySearchTreeNode node, char value);
bool BinarySearchTree_is_found(BinarySearchTree tree, char value);
int __BinarySearchTree_height(BinarySearchTreeNode node);
int BinarySearchTree_height(BinarySearchTree tree);


typedef struct stack_node
{
	BinarySearchTreeNode value;
	struct stack_node* next;

} *StackNode;

typedef struct stack
{
	int size;
	StackNode head;

} *Stack;

StackNode StackNode_allocate(BinarySearchTreeNode value);
BinarySearchTreeNode StackNode_deallocate(StackNode node);
Stack Stack_allocate();
void Stack_deallocate(Stack stack);
bool Stack_is_empty(Stack stack);
void Stack_push(Stack stack, BinarySearchTreeNode node);
BinarySearchTreeNode Stack_pop(Stack stack);
BinarySearchTreeNode Stack_peak(Stack stack);

#endif