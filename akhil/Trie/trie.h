#ifndef TRIE_H_INCLUDED
#define TRIE_H_INCLUDED

#include <stdlib.h>

#define	ALPHABET_SIZE	26
typedef struct tnode TNode;
struct tnode
{
	bool isEOW;
	TNode *next[ALPHABET_SIZE];
};

TNode *createTrieNode();
bool insertWordInTrie(TNode *root, char *word);
void printWordsInTrie(TNode *root);


#endif // TRIE_H_INCLUDED
