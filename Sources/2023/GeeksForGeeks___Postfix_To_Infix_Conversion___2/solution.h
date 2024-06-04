#ifndef SOLUTION_H_INCLUDED
#define SOLUTION_H_INCLUDED

typedef struct node
{
	int value;
	struct node* next;

} *Node;

typedef struct queue
{
	int size;
	Node head;
	Node tail;

} *Queue;

typedef struct stack
{
	int size;
	Node head;

} *Stack;

Node Node_allocate(int);
void Node_deallocate(Node);

Queue Queue_allocate();
void Queue_deallocate(Queue);
void Queue_enqueue(Queue, int);
int Queue_dequeue(Queue);
int Queue_front(Queue);
bool Queue_is_empty(Queue);

Stack Stack_allocate();
void Stack_deallocate(Stack);
void Stack_push(Stack, int);
int Stack_pop(Stack);
int Stack_peak(Stack);
bool Stack_is_empty(Stack);

char* solution(char* infix_expression, int size);

#endif