#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include <ctype.h>
#include <limits.h>

#include "solution.h"

int main(void)
{
	char postfix_expression[1000];
	scanf("%[^\n]%*c", postfix_expression);
	BinaryExpressionTree tree = solution(postfix_expression, strlen(postfix_expression));
	BinaryExpressionTree_display_via_pre_order_traversal(tree);
	BinaryExpressionTree_display_via_in_order_traversal(tree);
	BinaryExpressionTree_display_via_post_order_traversal(tree);

	BinaryExpressionTree_deallocate(tree);
	tree = NULL;

	BinaryExpressionTree_display_via_pre_order_traversal(tree);
	BinaryExpressionTree_display_via_in_order_traversal(tree);
	BinaryExpressionTree_display_via_post_order_traversal(tree);

	int exit_code = 0;
	scanf("%d", &exit_code);

	return 0;
}