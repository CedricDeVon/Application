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
	AVLTree tree = AVLTree_allocate();
	AVLTree_insert(tree, 80);
	AVLTree_insert(tree, 70);
	AVLTree_insert(tree, 60);
	AVLTree_insert(tree, 90);
	AVLTree_insert(tree, 100);
	AVLTree_insert(tree, 50);
	AVLTree_insert(tree, 65);
	AVLTree_insert(tree, 75);
	AVLTree_insert(tree, 85);
	AVLTree_insert(tree, 83);
	AVLTree_insert(tree, 40);
	AVLTree_insert(tree, 55);
	AVLTree_insert(tree, 54);

	AVLTree_display_via_pre_order_traversal(tree);
	AVLTree_display_via_in_order_traversal(tree);
	AVLTree_display_via_post_order_traversal(tree);

	printf("%d\n", tree->size);

	int exit_code = 0;
	scanf("%d", &exit_code);
	return 0;
}
