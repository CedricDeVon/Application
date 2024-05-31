#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>
#include <windows.h>

typedef struct node
{
	int value;
	int rank;
	struct node* next_node;

} *Node;

Node Node_allocate(int value, int rank)
{
	Node node = (Node) malloc(sizeof(struct node));
	node->value = value;
	node->rank = rank;
	node->next_node = NULL;

	return node;
}

Node Node_deallocate(Node node)
{
	node->value = 0;
	node->rank = 0;
	node->next_node = NULL;
	free(node);
	node = NULL;

	return node;
}

typedef struct priority_queue
{
	int maximum_size;
	int current_size;
	Node head_node;
	Node tail_node;

} *PriorityQueue;

PriorityQueue PriorityQueue_allocate(int maximum_size)
{
	PriorityQueue queue = (PriorityQueue) malloc(sizeof(struct priority_queue));
	queue->maximum_size = maximum_size;
	queue->current_size = 0;
	queue->head_node = NULL;
	queue->tail_node = NULL;

	return queue;
}

PriorityQueue PriorityQueue_deallocate(PriorityQueue queue)
{
	Node current_node = queue->head_node;
	while (current_node != NULL)
	{
		Node target_node = current_node;
		current_node = current_node->next_node;
		Node_deallocate(target_node);
	}
	queue->maximum_size = 0;
	queue->current_size = 0;
	queue->head_node = NULL;
	queue->tail_node = NULL;
	free(queue);
	queue = NULL;

	return queue;
}

int PriorityQueue_get_head_value(PriorityQueue queue)
{
	return (queue->head_node != NULL) ? queue->head_node->value : -1;
}

int PriorityQueue_get_tail_value(PriorityQueue queue)
{
	return (queue->tail_node != NULL) ? queue->tail_node->value : -1;
}

int PriorityQueue_get_head_rank(PriorityQueue queue)
{
	return (queue->head_node != NULL) ? queue->head_node->rank : -1;
}

int PriorityQueue_get_tail_rank(PriorityQueue queue)
{
	return (queue->tail_node != NULL) ? queue->tail_node->rank : -1;
}

bool PriorityQueue_is_empty(PriorityQueue queue)
{
	return (queue->head_node == NULL || queue->tail_node == NULL);
}

bool PriorityQueue_is_full(PriorityQueue queue)
{
	return queue->current_size == queue->maximum_size;
}

void PriorityQueue_display(PriorityQueue queue)
{
	Node current_node = queue->head_node;
	while (current_node != NULL)
	{
		printf("(%d : %d)", current_node->value, current_node->rank);
		if (current_node->next_node != NULL)
		{
			printf(" -> ");
		}
		current_node = current_node->next_node;
	}
	printf("\n");
}

void PriorityQueue_enqueue(PriorityQueue queue, int value, int rank)
{
	if (PriorityQueue_is_full(queue))
	{
		return;
	}

	Node new_node = Node_allocate(value, rank);
	if (queue->head_node == NULL || queue->tail_node == NULL)
	{
		queue->head_node = new_node;
		queue->tail_node = new_node;
	}
	else if (value < queue->head_node->rank)
	{
		new_node->next_node = queue->head_node;
		queue->head_node = new_node;
	}
	else if (queue->tail_node->rank < rank)
	{
		queue->tail_node->next_node = new_node;
		queue->tail_node = new_node;
	}
	else
	{
		Node current_node = queue->head_node;
		while (!(current_node->rank < rank && rank < current_node->next_node->rank))
		{
			current_node = current_node->next_node;
		}
		Node target_node = current_node->next_node;
		current_node->next_node = new_node;
		new_node->next_node = target_node;
	}

	queue->current_size++;
}

int PriorityQueue_dequeue(PriorityQueue queue)
{
	if (PriorityQueue_is_empty(queue))
	{
		return -1;
	}

	int value = queue->head_node->value;
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
	queue->current_size--;

	return value;
}

int main(void)
{
	PriorityQueue queue = PriorityQueue_allocate(5);
	PriorityQueue_display(queue);
	PriorityQueue_enqueue(queue, 1, 1);
	PriorityQueue_display(queue);
	PriorityQueue_enqueue(queue, 2, 2);
	PriorityQueue_display(queue);
	PriorityQueue_enqueue(queue, 4, 4);
	PriorityQueue_display(queue);
	PriorityQueue_enqueue(queue, 5, 5);
	PriorityQueue_display(queue);
	PriorityQueue_enqueue(queue, 3, 3);
	PriorityQueue_display(queue);
	PriorityQueue_enqueue(queue, 6, 6);
	PriorityQueue_display(queue);
	PriorityQueue_enqueue(queue, 7, 7);
	PriorityQueue_display(queue);

	printf("%d\n", PriorityQueue_get_head_value(queue));
	printf("%d\n", PriorityQueue_get_head_rank(queue));
	printf("%d\n", PriorityQueue_get_tail_value(queue));
	printf("%d\n", PriorityQueue_get_tail_rank(queue));
	printf("%d\n", PriorityQueue_is_empty(queue));
	printf("%d\n", PriorityQueue_is_full(queue));

	PriorityQueue_dequeue(queue);
	PriorityQueue_display(queue);
	PriorityQueue_dequeue(queue);
	PriorityQueue_display(queue);
	PriorityQueue_dequeue(queue);
	PriorityQueue_display(queue);
	PriorityQueue_dequeue(queue);
	PriorityQueue_display(queue);
	PriorityQueue_dequeue(queue);
	PriorityQueue_display(queue);

	printf("%d\n", PriorityQueue_get_head_value(queue));
	printf("%d\n", PriorityQueue_get_head_rank(queue));
	printf("%d\n", PriorityQueue_get_tail_value(queue));
	printf("%d\n", PriorityQueue_get_tail_rank(queue));
	printf("%d\n", PriorityQueue_is_empty(queue));
	printf("%d\n", PriorityQueue_is_full(queue));

	PriorityQueue_deallocate(queue);

	int exit_code = 0;
	scanf("%d", &exit_code);
	return 0;
}
