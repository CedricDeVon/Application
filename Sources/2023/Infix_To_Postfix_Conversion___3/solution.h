#ifndef INFIX_TO_POSTFIX_CONVERSION_H_INCLUDED
#define INFIX_TO_POSTFIX_CONVERSION_H_INCLUDED

typedef struct node
{
	char value;
	struct node* next;

} *Node;

typedef struct circular_singly_linked_list
{
	int size;
	Node head;
	Node tail;

} *CircularSinglyLinkedList;

Node Node_allocate(char value);
void Node_deallocate(Node node);
CircularSinglyLinkedList CircularSinglyLinkedList_allocate();
void CircularSinglyLinkedList_deallocate(CircularSinglyLinkedList linked_list);
void CircularSinglyLinkedList_add_head(CircularSinglyLinkedList linked_list, char value);
void CircularSinglyLinkedList_add_tail(CircularSinglyLinkedList linked_list, char value);
char CircularSinglyLinkedList_remove_head(CircularSinglyLinkedList linked_list);
char CircularSinglyLinkedList_remove_tail(CircularSinglyLinkedList linked_list);
char CircularSinglyLinkedList_peak_head(CircularSinglyLinkedList linked_list);
char CircularSinglyLinkedList_peak_tail(CircularSinglyLinkedList linked_list);
bool CircularSinglyLinkedList_is_empty(CircularSinglyLinkedList linked_list);
char* CircularSinglyLinkedList_to_array(CircularSinglyLinkedList linked_list);
void CircularSinglyLinkedList_display(CircularSinglyLinkedList linked_list);

bool is_opening_bracket(char value);
bool is_closing_bracket(char value);
bool is_operator(char value);
bool is_operand(char value);
int calculate_operator_precedence(char value);

CircularSinglyLinkedList solution(char* infix_expression, int size);

#endif