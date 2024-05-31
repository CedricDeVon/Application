#ifndef SOLUTION_H_INCLUDED
#define SOLUTION_H_INCLUDED

typedef struct standard_trie_node
{
	char value;
	bool is_word;
	struct **standard_trie_node values; // 94

} *StandardTrieNode;

typedef struct standard_trie
{
	int size;
	*StandardTrieNode values;

} *StandardTrie;

/*
Allocate Node
Allocate Trie

Insert Word
Delete Word

Display All Combinations
Display All Words

Does Word Exist

Deallocate Node
Deallocate Trie

Clear Trie
Clear Node
*/

#endif