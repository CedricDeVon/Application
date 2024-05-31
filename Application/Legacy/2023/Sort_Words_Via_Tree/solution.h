#ifndef SOLUTION_H
#define SOLUTION_H

typedef struct doubly_linked_list_node
{
	char value;
	struct doubly_linked_list_node* next;
	struct doubly_linked_list_node* prev;

} *DoublyLinkedListNode;

DoublyLinkedListNode DoublyLinkedListNode_allocate(char value);
void DoublyLinkedListNode_deallocate(DoublyLinkedListNode node);

typedef struct doubly_linked_list
{
	int size;
	DoublyLinkedListNode head;
	DoublyLinkedListNode tail;

} *DoublyLinkedList;

DoublyLinkedList DoublyLinkedList_allocate();
void DoublyLinkedList_deallocate(DoublyLinkedList linked_list);
bool DoublyLinkedList_is_empty(DoublyLinkedList linked_list);
void DoublyLinkedList_display(DoublyLinkedList linked_list);
void DoublyLinkedList_append_head(DoublyLinkedList doubly_linked_list, char value);
void DoublyLinkedList_append_tail(DoublyLinkedList doubly_linked_list, char value);
char DoublyLinkedList_delete_head(DoublyLinkedList linked_list);
char DoublyLinkedList_delete_tail(DoublyLinkedList linked_list);
char DoublyLinkedList_peak_head(DoublyLinkedList linked_list);
char DoublyLinkedList_peak_tail(DoublyLinkedList linked_list);

typedef struct string_tree_node
{
	char value;
	int count;
	struct string_tree_node** children;

} *StringTreeNode;

StringTreeNode StringTreeNode_allocate(char value);
void StringTreeNode_deallocate(StringTreeNode node);

typedef struct string_tree
{
	StringTreeNode* children;

} *StringTree;

StringTree StringTree_allocate();
void __StringTree_deallocate(StringTreeNode node);
void StringTree_deallocate(StringTree tree);
StringTreeNode __StringTree_insert(StringTreeNode node, char* string, int size, int index);
void StringTree_insert(StringTree tree, char* string, int size);
void __StringTree_display(StringTreeNode node, DoublyLinkedList linked_list);
void StringTree_display(StringTree tree);
void __StringTree_visualize(StringTreeNode node, DoublyLinkedList linked_list);
void StringTree_visualize(StringTree tree);

#endif