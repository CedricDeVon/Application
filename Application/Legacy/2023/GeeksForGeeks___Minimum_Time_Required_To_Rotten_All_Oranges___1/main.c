#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <windows.h>

typedef struct node
{
	int x;
	int y;
	struct node* next_node;

} *Node;

typedef struct queue
{
	int size;
	Node head_node;
	Node tail_node;

} *Queue;

Node Node_allocate(int x, int y)
{
	Node node = (Node) malloc(sizeof(struct node));
	node->x = x;
	node->y = y;
	node->next_node = NULL;

	return node;
}

Node Node_deallocate(Node node)
{
	node->x = 0;
	node->y = 0;
	node->next_node = NULL;
	free(node);
	node = NULL;

	return node;
}

Queue Queue_allocate()
{
	Queue queue = (Queue) malloc(sizeof(struct queue));
	queue->size = 0;
	queue->head_node = NULL;
	queue->tail_node = NULL;

	return queue;
}

Queue Queue_deallocate(Queue queue)
{
	Node current_node = queue->head_node;
	while (current_node != NULL)
	{
		Node temporary_node = current_node;
		current_node = current_node->next_node;
		Node_deallocate(temporary_node);
	}
	queue->size = 0;
	queue->head_node = NULL;
	queue->tail_node = NULL;
	free(queue);
	queue = NULL;

	return queue;
}

void Queue_enqueue(Queue queue, int x, int y)
{
	Node new_node = Node_allocate(x, y);
	if (queue->head_node == NULL || queue->tail_node == NULL)
	{
		queue->head_node = new_node;
		queue->tail_node = new_node;
	}
	else
	{
		queue->tail_node->next_node = new_node;
		queue->tail_node = new_node;
	}
	queue->size++;
}

void Queue_dequeue(Queue queue)
{
	if (queue->head_node == queue->tail_node)
	{
		Node_deallocate(queue->head_node);
		queue->head_node = NULL;
		queue->tail_node = NULL;
	}
	else
	{
		Node target_node = queue->head_node;
		queue->head_node = target_node->next_node;
		Node_deallocate(target_node);
	}
	queue->size--;
}

bool Queue_is_empty(Queue queue)
{
	return queue->head_node == NULL && queue->tail_node == NULL;
}

int Queue_get_front_x(Queue queue)
{
	return (queue->head_node != NULL) ? queue->head_node->x : 0;
}

int Queue_get_front_y(Queue queue)
{
	return (queue->head_node != NULL) ? queue->head_node->y : 0;
}

void Queue_display(Queue queue)
{
	Node node = queue->head_node;
	while (node != NULL)
	{
		printf("(%d, %d)", node->x, node->y);
		if (node->next_node != NULL)
		{
			printf(" -> ");
		}
		node = node->next_node;
	}
	printf("\n");
}

typedef struct matrix
{
	int row_size;
	int column_size;
	int** values;

} *Matrix;

Matrix Matrix_allocate(int row_size, int column_size)
{
	Matrix matrix = (Matrix) malloc(sizeof(struct matrix));
	matrix->row_size = row_size;
	matrix->column_size = column_size;
	matrix->values = (int**) malloc(sizeof(int*) * row_size);
	for (int i = 0; i < row_size; i++)
	{
		matrix->values[i] = (int*) malloc(sizeof(int) * column_size);
	}

	return matrix;
}

Matrix Matrix_deallocate(Matrix matrix)
{
	for (int i = 0; i < matrix->row_size; i++)
	{
		free(matrix->values[i]);
		matrix->values[i] = NULL;
	}
	free(matrix->values);
	matrix->values = NULL;
	free(matrix);
	matrix = NULL;

	return matrix;
}

void Matrix_display(Matrix matrix)
{
	for (int i = 0; i < matrix->row_size; i++)
	{
		for (int j = 0; j < matrix->column_size; j++)
		{
			printf("%d ", matrix->values[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

bool is_valid(Matrix matrix, int x, int y)
{
	return (x > -1) && (y > -1) &&
		(x < matrix->row_size) && (y < matrix->column_size) &&
		matrix->values[x][y] == 1;
}

int main(void)
{
	int row_size = 0;
	int column_size = 0;
	scanf("%d %d", &row_size, &column_size);
	Queue queue = Queue_allocate();

	Matrix matrix = Matrix_allocate(row_size, column_size);
	for (int i = 0; i < row_size; i++)
	{
		for (int j = 0; j < column_size; j++)
		{
			scanf("%d", &matrix->values[i][j]);
			if (matrix->values[i][j] == 2)
			{
				Queue_enqueue(queue, i, j);
			}
		}
	}

	int n = 0;
	bool is_changed = false;
	while (!Queue_is_empty(queue))
	{
		int current_size = queue->size;
		for (int i = 0; i < current_size; i++)
		{
			int x = Queue_get_front_x(queue);
			int y = Queue_get_front_y(queue);	
			Queue_dequeue(queue);

			if (is_valid(matrix, x - 1, y))
			{
				matrix->values[x - 1][y] = 2;
				Queue_enqueue(queue, x - 1, y);
				is_changed = true;
			}
			if (is_valid(matrix, x + 1, y))
			{
				matrix->values[x + 1][y] = 2;
				Queue_enqueue(queue, x + 1, y);
				is_changed = true;
			}
			if (is_valid(matrix, x, y - 1))
			{
				matrix->values[x][y - 1] = 2;
				Queue_enqueue(queue, x, y - 1);
				is_changed = true;
			}
			if (is_valid(matrix, x, y + 1))
			{
				matrix->values[x][y + 1] = 2;
				Queue_enqueue(queue, x, y + 1);
				is_changed = true;
			}
		}

		if (!is_changed)
		{
			break;
		}

		is_changed = false;
		n++;
	}

	printf("%d\n", (!Queue_is_empty(queue) || n == 0) ? -1 : n);

	Matrix_deallocate(matrix);
	Queue_deallocate(queue);
	int exit_code = 0;
	scanf("%d", &exit_code);
	return 0;
}

/*
2 1 0 2 1
1 0 1 2 1
1 0 0 2 1
*/
