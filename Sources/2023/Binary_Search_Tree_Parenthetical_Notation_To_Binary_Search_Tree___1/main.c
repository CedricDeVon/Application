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
	char expression[1000];
	scanf("%[^\n]%*c", expression);

	BinarySearchTree tree = solution(expression, strlen(expression));
	BinarySearchTree_pre_order_traversal(tree);
	BinarySearchTree_in_order_traversal(tree);
	BinarySearchTree_post_order_traversal(tree);
	
	printf("%s\n", reverse_solution(tree));

	int exit_code = 0;
	scanf("%d", &exit_code);

	return 0;
}
