#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct array_queue
{
	int size;
	int tail;
	int* values;

} *ArrayQueue;

ArrayQueue ArrayQueue_allocate(int size)
{
	ArrayQueue queue = (ArrayQueue) malloc(sizeof(struct array_queue));
	queue->size = size;
	queue->tail = -1;
	queue->values = (int*) malloc(sizeof(int) * queue->size);
	for (int i = 0; i < queue->size; i++)
	{
		queue->values[i] = 0;
	}

	return queue;
}

void ArrayQueue_enqueue(ArrayQueue queue, int value)
{
	if (queue->tail == queue->size - 1)
	{
		return;
	}

	queue->values[++queue->tail] = value;
}

int ArrayQueue_dequeue(ArrayQueue queue)
{
	if (queue->tail == -1)
	{
		return -1;
	}

	int value = queue->values[0];
	for (int i = 0; i < queue->tail; i++)
	{
		queue->values[i] = queue->values[i + 1];
	}
	queue->values[queue->tail--] = 0;

	return value;
}

int ArrayQueue_front(ArrayQueue queue)
{
	return (queue->tail != -1) ? queue->values[0] : -1;
}

int ArrayQueue_back(ArrayQueue queue)
{
	return (queue->tail != -1) ? queue->values[queue->tail] : -1;
}

int ArrayQueue_is_empty(ArrayQueue queue)
{
	return queue->tail == -1;
}

void ArrayQueue_display(ArrayQueue queue)
{
	for (int i = 0; i < queue->size; i++)
	{
		printf("%d ", queue->values[i]);
	}
	printf("\n");
}

int main(void)
{
	ArrayQueue queue = ArrayQueue_allocate(5);
	ArrayQueue_enqueue(queue, 1);
	ArrayQueue_enqueue(queue, 2);
	ArrayQueue_enqueue(queue, 3);
	ArrayQueue_display(queue);

	ArrayQueue_enqueue(queue, 4);
	ArrayQueue_enqueue(queue, 5);
	ArrayQueue_enqueue(queue, 6);
	ArrayQueue_display(queue);

	ArrayQueue_dequeue(queue);
	ArrayQueue_dequeue(queue);
	ArrayQueue_display(queue);

	ArrayQueue_dequeue(queue);
	ArrayQueue_dequeue(queue);
	ArrayQueue_dequeue(queue);
	ArrayQueue_dequeue(queue);


	ArrayQueue_display(queue);

	// ArrayQueue_enqueue(queue, 1);
	// ArrayQueue_enqueue(queue, 2);
	// ArrayQueue_enqueue(queue, 3);



	int exit_code = 0;
	scanf("%d", &exit_code);
	return 0;
}
