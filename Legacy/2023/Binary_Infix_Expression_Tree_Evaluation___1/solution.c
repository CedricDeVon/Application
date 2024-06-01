#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <windows.h>
#include <limits.h>

#include "solution.h"

BinaryExpressionTreeNode BinaryExpressionTreeNode_allocate()
{
	BinaryExpressionTreeNode node = (BinaryExpressionTreeNode) malloc(sizeof(struct binary_expression_tree_node));
	node->operand_value = 0;
	node->operator_value = 0;
	node->left = NULL;
	node->right = NULL;

	return node;
}

BinaryExpressionTreeNode BinaryExpressionTreeNode_allocate_operand(int value)
{
	BinaryExpressionTreeNode node = (BinaryExpressionTreeNode) malloc(sizeof(struct binary_expression_tree_node));
	node->operand_value = value;
	node->operator_value = 0;
	node->left = NULL;
	node->right = NULL;

	return node;
}

BinaryExpressionTreeNode BinaryExpressionTreeNode_allocate_operator(char value)
{
	BinaryExpressionTreeNode node = (BinaryExpressionTreeNode) malloc(sizeof(struct binary_expression_tree_node));
	node->operand_value = 0;
	node->operator_value = value;
	node->left = NULL;
	node->right = NULL;

	return node;
}

void BinaryExpressionTreeNode_deallocate(BinaryExpressionTreeNode node)
{
	node->left = NULL;
	node->right = NULL;
	free(node);
}

void BinaryExpressionTreeNode_display(BinaryExpressionTreeNode node)
{
	if (node->operator_value == 0)
	{
		printf("%d ", node->operand_value);
	}
	else
	{
		printf("%c ", node->operator_value);
	}
}

StackNode StackNode_allocate(BinaryExpressionTreeNode value)
{
	StackNode node = (StackNode) malloc(sizeof(struct stack_node));
	node->value = value;
	node->next = NULL;

	return node;
}

void StackNode_deallocate(StackNode node)
{
	node->next = NULL;
	free(node);
}

Stack Stack_allocate()
{
	Stack stack = (Stack) malloc(sizeof(struct stack));
	stack->size = 0;
	stack->head = NULL;

	return stack;
}

void Stack_deallocate(Stack stack)
{
	StackNode current_node = stack->head;
	while (current_node != NULL)
	{
		StackNode target_node = current_node;
		current_node = current_node->next;
		StackNode_deallocate(target_node);
	}
	stack->head = NULL;
	free(stack);
}

bool Stack_is_empty(Stack stack)
{
	return stack->head == NULL;
}

void Stack_push(Stack stack, BinaryExpressionTreeNode value)
{
	StackNode new_node = StackNode_allocate(value);
	new_node->next = stack->head;
	stack->head = new_node;
	stack->size++;
}

BinaryExpressionTreeNode Stack_pop(Stack stack)
{
	if (Stack_is_empty(stack))
	{
		return NULL;
	}

	BinaryExpressionTreeNode value = stack->head->value;
	if (stack->head->next == NULL)
	{
		StackNode_deallocate(stack->head);
		stack->head = NULL;
	}
	else
	{
		StackNode target_node = stack->head;
		stack->head = target_node->next;
		StackNode_deallocate(target_node);
	}
	stack->size--;

	return value;
}

BinaryExpressionTreeNode Stack_peak(Stack stack)
{
	return (!Stack_is_empty(stack)) ? stack->head->value : NULL;
}

BinaryExpressionTree BinaryExpressionTree_allocate()
{
	BinaryExpressionTree tree = (BinaryExpressionTree) malloc(sizeof(struct binary_expression_tree));
	tree->size = 0;
	tree->root = NULL;

	return tree;
}

void __BinaryExpressionTree_deallocate(BinaryExpressionTreeNode node)
{
	if (node == NULL)
	{
		return;
	}

	__BinaryExpressionTree_deallocate(node->left);
	__BinaryExpressionTree_deallocate(node->right);
	BinaryExpressionTreeNode_deallocate(node);
}

void BinaryExpressionTree_deallocate(BinaryExpressionTree tree)
{
	__BinaryExpressionTree_deallocate(tree->root);
	tree->root = NULL;
	free(tree);
}

void __BinaryExpressionTree_display_via_pre_order_traversal(BinaryExpressionTreeNode node)
{
	if (node == NULL)
	{
		return;
	}

	BinaryExpressionTreeNode_display(node);
	__BinaryExpressionTree_display_via_pre_order_traversal(node->left);
	__BinaryExpressionTree_display_via_pre_order_traversal(node->right);
}

void BinaryExpressionTree_display_via_pre_order_traversal(BinaryExpressionTree tree)
{
	__BinaryExpressionTree_display_via_pre_order_traversal(tree->root);
	printf("\n");
}

void __BinaryExpressionTree_display_via_in_order_traversal(BinaryExpressionTreeNode node)
{
	if (node == NULL)
	{
		return;
	}

	__BinaryExpressionTree_display_via_in_order_traversal(node->left);
	BinaryExpressionTreeNode_display(node);
	__BinaryExpressionTree_display_via_in_order_traversal(node->right);
}

void BinaryExpressionTree_display_via_in_order_traversal(BinaryExpressionTree tree)
{
	__BinaryExpressionTree_display_via_in_order_traversal(tree->root);
	printf("\n");
}

void __BinaryExpressionTree_display_via_post_order_traversal(BinaryExpressionTreeNode node)
{
	if (node == NULL)
	{
		return;
	}

	__BinaryExpressionTree_display_via_post_order_traversal(node->left);
	__BinaryExpressionTree_display_via_post_order_traversal(node->right);
	BinaryExpressionTreeNode_display(node);
}

void BinaryExpressionTree_display_via_post_order_traversal(BinaryExpressionTree tree)
{
	__BinaryExpressionTree_display_via_post_order_traversal(tree->root);
	printf("\n");
}

bool is_opening_bracket(char character)
{
	return character == '(' || character == '[';
}

bool is_closing_bracket(char character)
{
	return character == ')' || character == ']';
}

bool is_operand(char character)
{
	return (('0' - 1) < character && character < ('9' + 1));
}

bool is_operator(char character)
{
	return character == '+' || character == '-'||
		character == '*' || character == '/' || character == '%' ||
		character == '^';
}

int calculate_pemdas(char character)
{
	switch (character)
	{
		case '+' : return 1;
		case '-' : return 1;
		case '*' : return 2;
		case '/' : return 2;
		case '%' : return 2;
		case '^' : return 3;	
	}

	return 0;
}

int evaluate_expression(int a, char operator, int b)
{
	switch (operator)
	{
	case '+' : return a + b;
	case '-' : return a - b;
	case '*' : return a * b;
	case '/' : return a / b;
	case '%' : return a % b;
	case '^' : return pow(a, b);
	}

	return 0;
}

BinaryExpressionTree from_infix_expression_to_binary_expression_tree(char* infix_expression, int size)
{
	Stack operands = Stack_allocate();
	Stack operators = Stack_allocate();
	BinaryExpressionTree tree = BinaryExpressionTree_allocate();
	Stack_push(operands, BinaryExpressionTreeNode_allocate());
	for (int index = 0; index < size; index++)
	{
		char character = infix_expression[index];
		BinaryExpressionTreeNode operand = Stack_peak(operands);
		if (character == ' ')
		{
			Stack_push(operands, BinaryExpressionTreeNode_allocate());
		}
		else if (is_opening_bracket(character))
		{
			Stack_push(operators, BinaryExpressionTreeNode_allocate_operator(character));
		}
		else if (is_closing_bracket(character))
		{
			while (!Stack_is_empty(operators) &&
				!is_opening_bracket(Stack_peak(operators)->operator_value))
			{
				BinaryExpressionTreeNode root = Stack_pop(operators);
				root->right = Stack_pop(operands);
				root->left = Stack_pop(operands);
				Stack_push(operands, root);
			}
			Stack_pop(operators);
		}
		else if (character == '-' && is_operand(infix_expression[index + 1]))
		{
			operand->operand_value = -(infix_expression[++index] - '0');
		}
		else if (is_operand(character))
		{
			operand->operand_value *= 10;
			operand->operand_value += (operand->operand_value < 0) ? -(character - '0') : character - '0';
		}
		else if (is_operator(character))
		{
			BinaryExpressionTreeNode new_operator = Stack_pop(operands);
			new_operator->operator_value = character;
			while (!Stack_is_empty(operators) &&
				calculate_pemdas(character) <= calculate_pemdas(Stack_peak(operators)->operator_value))
			{
				BinaryExpressionTreeNode root = Stack_pop(operators);
				root->right = Stack_pop(operands);
				root->left = Stack_pop(operands);
				Stack_push(operands, root);
			}
			Stack_push(operators, new_operator);
		}
	}
	while (!Stack_is_empty(operators))
	{
		BinaryExpressionTreeNode root = Stack_pop(operators);
		root->right = Stack_pop(operands);
		root->left = Stack_pop(operands);
		Stack_push(operands, root);
	}

	tree->root = Stack_pop(operands);
	return tree;
}

int __BinaryExpressionTree_evaluate(BinaryExpressionTreeNode node)
{
	if (node->left == NULL && node->right == NULL)
	{
		return node->operand_value;
	}

	int left_value = __BinaryExpressionTree_evaluate(node->left);
	int right_value = __BinaryExpressionTree_evaluate(node->right);

	return evaluate_expression(left_value, node->operator_value, right_value);
}

int BinaryExpressionTree_evaluate(BinaryExpressionTree tree)
{
	return __BinaryExpressionTree_evaluate(tree->root);
}

void __BinaryExpressionTree_display(BinaryExpressionTreeNode node, int level)
{
	if (node == NULL)
	{
		return;
	}

	printf("\n");
	for (int i = 0; i < level; i++)
	{
		printf("├─");
	}
	BinaryExpressionTreeNode_display(node);
	__BinaryExpressionTree_display(node->right, level + 1);
	__BinaryExpressionTree_display(node->left, level + 1);
	// printf("\n");
	// for (int i = 0; i < level; i++)
	// {
	// 	printf("| ");
	// }
	// printf("-"); ├───
	// printf("\n");
}

void BinaryExpressionTree_display(BinaryExpressionTree tree)
{
	__BinaryExpressionTree_display(tree->root, 1);
	printf("\n");
}
