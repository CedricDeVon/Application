#ifndef SOLUTION_H
#define SOLUTION_H

typedef struct binary_expression_tree_node
{
	int operand_value;
	char operator_value;
	struct binary_expression_tree_node* left;
	struct binary_expression_tree_node* right;

} *BinaryExpressionTreeNode;

BinaryExpressionTreeNode BinaryExpressionTreeNode_allocate();
BinaryExpressionTreeNode BinaryExpressionTreeNode_allocate_operand(int value);
BinaryExpressionTreeNode BinaryExpressionTreeNode_allocate_operator(char value);
void BinaryExpressionTreeNode_deallocate(BinaryExpressionTreeNode node);

typedef struct stack_node
{
	BinaryExpressionTreeNode value;
	struct stack_node* next;

} *StackNode;

StackNode StackNode_allocate(BinaryExpressionTreeNode value);
void StackNode_deallocate(StackNode node);

typedef struct stack
{
	int size;
	StackNode head;

} *Stack;

Stack Stack_allocate();
void Stack_deallocate(Stack stack);
bool Stack_is_empty(Stack stack);
void Stack_push(Stack stack, BinaryExpressionTreeNode value);
BinaryExpressionTreeNode Stack_pop(Stack stack);
BinaryExpressionTreeNode Stack_peak(Stack stack);
void BinaryExpressionTreeNode_display(BinaryExpressionTreeNode node);

typedef struct binary_expression_tree
{
	int size;
	BinaryExpressionTreeNode root;

} *BinaryExpressionTree;

BinaryExpressionTree BinaryExpressionTree_allocate();
void __BinaryExpressionTree_deallocate(BinaryExpressionTreeNode node);
void BinaryExpressionTree_deallocate(BinaryExpressionTree tree);
void __BinaryExpressionTree_display_via_pre_order_traversal(BinaryExpressionTreeNode node);
void BinaryExpressionTree_display_via_pre_order_traversal(BinaryExpressionTree tree);
void __BinaryExpressionTree_display_via_in_order_traversal(BinaryExpressionTreeNode node);
void BinaryExpressionTree_display_via_in_order_traversal(BinaryExpressionTree tree);
void __BinaryExpressionTree_display_via_post_order_traversal(BinaryExpressionTreeNode node);
void BinaryExpressionTree_display_via_post_order_traversal(BinaryExpressionTree tree);

bool is_opening_bracket(char character);
bool is_closing_bracket(char character);
bool is_operand(char character);
bool is_operator(char character);
int calculate_pemdas(char character);

BinaryExpressionTree from_infix_expression_to_binary_expression_tree(char* infix_expression, int size);
int __BinaryExpressionTree_evaluate(BinaryExpressionTreeNode node);
int BinaryExpressionTree_evaluate(BinaryExpressionTree tree);

void __BinaryExpressionTree_display(BinaryExpressionTreeNode node, int level);
void BinaryExpressionTree_display(BinaryExpressionTree tree);

#endif
