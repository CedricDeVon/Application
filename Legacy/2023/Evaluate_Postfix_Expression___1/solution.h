#ifndef SOLUTION_INCLUDED
#define SOLUTION_INCLUDED

typedef struct node
{
	int value;
	struct node* next_node;

} *Node;

typedef struct stack
{
	int size;
	Node head_node;

} *Stack;

Node Node_allocate(int);
void Node_deallocate(Node);
Stack Stack_allocate();
void Stack_deallocate(Stack);
bool Stack_is_empty(Stack);
void Stack_push(Stack, int);
int Stack_pop(Stack);
int Stack_peak(Stack);
int solution(char[]);

#endif