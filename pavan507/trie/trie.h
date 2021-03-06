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
bool rinsertWordInTrie(TNode *root, char *word);
bool deleteWordFromTrie(TNode *root, char *word);
#endif // TRIE_H_INCLUDED
