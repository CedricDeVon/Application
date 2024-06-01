#ifndef STACK_C
#define STACK_C

typedef struct node
{
	int value;
	struct node* next_node;

} Node;

typedef struct stack
{
	int maximum_size;
	int current_size;
	Node* tail_node;

} Stack;

Node* Node_allocate(int);
Node* Node_deallocate(Node*);
Stack* Stack_allocate(int);
Stack* Stack_deallocate(Stack*);
void Stack_push(Stack*, int);
void Stack_pop(Stack*);
int Stack_peak(Stack*);
bool Stack_is_empty(Stack*);
bool Stack_is_full(Stack*);
void Stack_display(Stack*);

#endif