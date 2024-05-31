#ifndef SOLUTION_H_INCLUDED
#define SOLUTION_H_INCLUDED

typedef struct node
{
	int value;
	struct node* next;

} *Node;

typedef struct stack
{
	int size;
	Node head;

} *Stack;

Node Node_allocate(int);
Stack Stack_allocate();
void Node_deallocate(Node);
void Stack_deallocate(Stack);
void Stack_push(Stack, int);
int Stack_pop(Stack);
int Stack_peak(Stack);
bool Stack_is_empty(Stack);

bool is_an_operand(int);
int calculate_expression(int, char, int);
int solution(char*, int);

#endif