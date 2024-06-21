#ifndef SOLUTION_H_INCLUDED
#define SOLUTION_H_INCLUDED

typedef struct string_node
{
	char value;
	struct string_node* next;
	struct string_node* prev;

} *StringNode;

typedef struct string
{
	int size;
	StringNode head;
	StringNode tail;

} *String;

StringNode StringNode_allocate(char value);
void StringNode_deallocate(StringNode node);
String String_allocate();
void String_deallocate(String string);
bool String_is_empty(String string);
void String_append_at_front(String string, char value);
void String_append_at_back(String string, char value);
char String_remove_at_front(String string);
char String_remove_at_back(String string);
char String_peak_at_front(String string);
char String_peak_at_back(String string);
void String_display(String string);
char* String_to_array(String string);

typedef struct binary_expression_tree_node
{
	String value;
	struct binary_expression_tree_node* left_child;
	struct binary_expression_tree_node* right_child;

} *BinaryExpressionTreeNode;

typedef struct binary_expression_tree
{
	int size;
	BinaryExpressionTreeNode root;

} *BinaryExpressionTree;

BinaryExpressionTreeNode BinaryExpressionTreeNode_allocate();
String BinaryExpressionTreeNode_deallocate(BinaryExpressionTreeNode node);
BinaryExpressionTree BinaryExpressionTree_allocate();
void __BinaryExpressionTree_deallocate(BinaryExpressionTreeNode root);
void BinaryExpressionTree_deallocate(BinaryExpressionTree tree);
bool BinaryExpressionTree_is_empty(BinaryExpressionTree tree);
void __BinaryExpressionTree_display_via_pre_order_traversal(BinaryExpressionTreeNode root);
void BinaryExpressionTree_display_via_pre_order_traversal(BinaryExpressionTree tree);
void __BinaryExpressionTree_display_via_in_order_traversal(BinaryExpressionTreeNode root);
void BinaryExpressionTree_display_via_in_order_traversal(BinaryExpressionTree tree);
void __BinaryExpressionTree_display_via_post_order_traversal(BinaryExpressionTreeNode root);
void BinaryExpressionTree_display_via_post_order_traversal(BinaryExpressionTree tree);

typedef struct stack_node
{
	BinaryExpressionTreeNode value;
	struct stack_node* next;

} *StackNode;

typedef struct stack
{
	int size;
	StackNode head;

} *Stack;

StackNode StackNode_allocate(BinaryExpressionTreeNode value);
void StackNode_deallocate(StackNode node);
Stack Stack_allocate();
void Stack_deallocate(Stack stack);
bool Stack_is_empty(Stack stack);
void Stack_push(Stack stack, BinaryExpressionTreeNode value);
BinaryExpressionTreeNode Stack_pop(Stack stack);
BinaryExpressionTreeNode Stack_peak(Stack stack);

BinaryExpressionTree solution(char* infix_expression, int size);

#endif