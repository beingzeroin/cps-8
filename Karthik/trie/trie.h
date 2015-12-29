#ifndef TRIE_H_INCLUDED
#define TRIE_H_INCLUDED

#define ALPHABET_SIZE 26
#include <stdlib.h>
typedef struct trien TNode;
struct trien
{
    bool isEOW;
    TNode *next[ALPHABET_SIZE];
};
struct trien *createTrieNode();
bool rInsertWordInTrie(TNode *root,char word[]);
bool insertWordInTrie(TNode *root,char *word);
void printWordsInTrie(TNode *root);
bool deleteWordFromTrie(TNode *root,char *word);


#endif // TRIE_H_INCLUDED
