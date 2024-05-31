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

int main(void)
{
	// 3 + 2 % 5 ^ 3 / 46 - 12 * 5 + 4 - 8 ^ 7 % 10
	char infix_expression[1000];
	printf("Input: ");
	scanf("%[^\n]%*c", infix_expression);
	BinaryExpressionTree tree = from_infix_expression_to_binary_expression_tree(infix_expression, strlen(infix_expression));
	printf("Pre-order: ");
	BinaryExpressionTree_display_via_pre_order_traversal(tree);
	printf("In-order: ");
	BinaryExpressionTree_display_via_in_order_traversal(tree);
	printf("Post-order: ");
	BinaryExpressionTree_display_via_post_order_traversal(tree);
	printf("Output: %d\n", BinaryExpressionTree_evaluate(tree));

	// BinaryExpressionTree_display(tree);

	BinaryExpressionTree_deallocate(tree);

	int exit_code = 0;
	scanf("%d", &exit_code);

	return 0;
}