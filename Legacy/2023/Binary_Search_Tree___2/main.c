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

	BinarySearchTree tree = BinarySearchTree_allocate_from_parenthetical_notation(expression, strlen(expression));
	// BinarySearchTree tree = BinarySearchTree_allocate();
	// BinarySearchTree_insert(tree, 14);
	// BinarySearchTree_insert(tree, 7);
	// BinarySearchTree_insert(tree, 10);
	// BinarySearchTree_insert(tree, 23);
	// BinarySearchTree_insert(tree, 56);
	// BinarySearchTree_insert(tree, 33);
	// BinarySearchTree_insert(tree, 70);
	// BinarySearchTree_insert(tree, 66);
	// BinarySearchTree_insert(tree, 80);
	
	BinarySearchTree_display_via_pre_order_traversal(tree);
	BinarySearchTree_display_via_in_order_traversal(tree);
	BinarySearchTree_display_via_post_order_traversal(tree);

	// BinarySearchTree_delete(tree, 7);
	// BinarySearchTree_delete(tree, 10);
	// BinarySearchTree_delete(tree, 14);

	// BinarySearchTree_display_via_pre_order_traversal(tree);
	// BinarySearchTree_display_via_in_order_traversal(tree);
	// BinarySearchTree_display_via_post_order_traversal(tree);

	// printf("14 : %d\n", BinarySearchTree_is_found(tree, 14));
	// printf("10 : %d\n", BinarySearchTree_is_found(tree, 10));
	// printf("80 : %d\n", BinarySearchTree_is_found(tree, 80));
	// printf("99 : %d\n", BinarySearchTree_is_found(tree, 99));
	printf("%d \n", BinarySearchTree_height(tree));

	int exit_code = 0;
	scanf("%d", &exit_code);

	return 0;
}
