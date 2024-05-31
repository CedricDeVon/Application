#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <windows.h>

typedef struct node
{
	int value;
	struct node* child_node;
	struct node* next_node;

} *Node;

Node Node_allocate(int value)
{
	Node node = (Node) malloc(sizeof(struct node));
	node->value = value;
	node->child_node = NULL;
	node->next_node = NULL;

	return node;
}

Node Node_deallocate(Node node)
{
	node->value = 0;
	node->child_node = NULL;
	node->next_node = NULL;

	free(node);
	node = NULL;

	return node;
}

typedef struct queue
{
	int size;
	Node head_node;
	Node tail_node;

} *Queue;

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
		Node target_node = current_node;
		current_node = current_node->next_node;
		Node_deallocate(target_node);
	}

	queue->size = 0;
	queue->head_node = NULL;
	queue->tail_node = NULL;

	free(queue);
	queue = NULL;

	return queue;
}

void Queue_enqueue(Queue queue, int value)
{
	Node new_node = Node_allocate(value);
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

int Queue_dequeue(Queue queue)
{
	if (queue->head_node == NULL || queue->tail_node == NULL)
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
		Node temporary_node = queue->head_node;
		queue->head_node = temporary_node->next_node;
		Node_deallocate(temporary_node);
	}

	queue->size--;
	return value;
}

int Queue_first(Queue queue)
{
	return (queue->head_node != NULL) ? queue->head_node->value : -1;
}

int Queue_end(Queue queue)
{
	return (queue->tail_node != NULL) ? queue->tail_node->value : -1;
}

bool Queue_is_empty(Queue queue)
{
	return queue->head_node == NULL || queue->tail_node == NULL;
}

void Queue_flatten(Queue queue, Node head_node)
{
	Queue others = Queue_allocate();
	Node current_node = head_node;
	while (current_node != NULL)
	{
		Queue_enqueue(queue, current_node->value);
		current_node = current_node->next_node;
	}
	current_node = head_node;
	while (current_node != NULL)
	{
		if (current_node->child_node != NULL)
		{
			Queue_flatten(queue, current_node->child_node);
		}

		current_node = current_node->next_node;
	}
	Queue_deallocate(others);
}

void Queue_display(Queue queue)
{
	Node node = queue->head_node;
	while (node != NULL)
	{
		printf("%d", node->value);
		if (node->next_node != NULL)
		{
			printf(" -> ");
		}
		node = node->next_node;
	}
	printf("\n");
}

int main(void)
{
	Node a = Node_allocate(10);
	Node b = Node_allocate(5);
	Node c = Node_allocate(12);
	Node d = Node_allocate(7);
	Node e = Node_allocate(11);

	Node f = Node_allocate(4);
	Node g = Node_allocate(20);
	Node h = Node_allocate(13);

	Node i = Node_allocate(17);
	Node j = Node_allocate(6);

	Node k = Node_allocate(2);
	Node l = Node_allocate(16);

	Node m = Node_allocate(9);
	Node n = Node_allocate(8);

	Node o = Node_allocate(3);

	Node p = Node_allocate(19);
	Node q = Node_allocate(15);

	a->next_node = b;
	b->next_node = c;
	c->next_node = d;
	d->next_node = e;

	f->next_node = g;
	g->next_node = h;

	i->next_node = j;

	m->next_node = n;

	p->next_node = q;



	a->child_node = f;
	d->child_node = i;

	g->child_node = k;
	h->child_node = l;

	i->child_node = m;
	
	l->child_node = o;

	m->child_node = p;

	Queue queue = Queue_allocate();

	Queue_flatten(queue, a);
	Queue_display(queue);

	queue = Queue_deallocate(queue);
	int exit_code = 0;
	scanf("%d", &exit_code);
	return 0;
}