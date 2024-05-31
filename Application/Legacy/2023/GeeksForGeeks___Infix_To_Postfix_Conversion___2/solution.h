#ifndef SOLUTION_H_INCLUDED
#define SOLUTION_H_INCLUDED

typedef struct character_node
{
	char value;
	struct character_node* next;
	struct character_node* previous;

} *CharacterNode;

typedef struct string
{
	int size;
	CharacterNode head;
	CharacterNode tail;

} *String;

CharacterNode CharacterNode_allocate(char);
void CharacterNode_deallocate(CharacterNode);
String String_allocate();
void String_deallocate(String);
void String_push_front(String, char);
void String_push_back(String, char);
char String_pop_front(String);
char String_pop_back(String);
bool String_is_empty(String);
void String_display(String);
char* String_to_array(String);

typedef struct string_node
{
	String value;
	struct string_node* next;

} *StringNode;

typedef struct stack
{
	int size;
	int sentence_size;
	StringNode head;
	StringNode tail;

} *Stack;

StringNode StringNode_allocate(String);
void StringNode_deallocate(StringNode);
Stack Stack_allocate();
void Stack_deallocate(Stack);
void Stack_push_at_head(Stack, String);
void Stack_push_at_tail(Stack, String);
String Stack_pop(Stack);
String Stack_peak(Stack);
bool Stack_is_empty(Stack);
void Stack_display(Stack);
String Stack_combine(Stack);

bool is_operand(char);
bool is_operator(char);
bool is_opening_bracket(char);
bool is_closing_bracket(char);
int calculate_precedent(char);

String solution(char* infix_expression, int size);

#endif