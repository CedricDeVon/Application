#ifndef SOLUTION_H_INCLUDED
#define SOLUTION_H_INCLUDED

typedef struct binary_search_tree_node
{
	char value;
	struct binary_search_tree_node* left_child;
	struct binary_search_tree_node* right_child;

} *BinarySearchTreeNode;

typedef struct binary_search_tree
{
	int size;
	BinarySearchTreeNode root;

} *BinarySearchTree;

BinarySearchTreeNode BinarySearchTreeNode_allocate(char value);
void BinarySearchTreeNode_deallocate(BinarySearchTreeNode node);
BinarySearchTree BinarySearchTree_allocate();
void BinarySearchTree_deallocate(BinarySearchTree tree);
bool BinarySearchTree_is_empty(BinarySearchTree tree);
void __BinarySearchTree_pre_order_traversal(BinarySearchTreeNode node);
void BinarySearchTree_pre_order_traversal(BinarySearchTree tree);
void __BinarySearchTree_in_order_traversal(BinarySearchTreeNode node);
void BinarySearchTree_in_order_traversal(BinarySearchTree tree);
void __BinarySearchTree_post_order_traversal(BinarySearchTreeNode node);
void BinarySearchTree_post_order_traversal(BinarySearchTree tree);

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

StackNode StackNode_allocate(BinarySearchTreeNode tree_node);
void StackNode_deallocate(StackNode node);
Stack Stack_allocate();
void Stack_deallocate(Stack stack);
bool Stack_is_empty(Stack stack);
void Stack_push(Stack stack, BinarySearchTreeNode tree_node);
BinarySearchTreeNode Stack_pop(Stack stack);
BinarySearchTreeNode Stack_peak(Stack stack);
char* Stack_to_array(Stack stack);
bool is_operand(char character);

BinarySearchTree solution(char* expression, int size);
void __reverse_solution(BinarySearchTreeNode node, Stack stack);
char* reverse_solution(BinarySearchTree tree);

#endif