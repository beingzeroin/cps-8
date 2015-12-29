#include "trie.h"
#include <stdlib.h>

TNode *createTrieNode()
{
    TNode *t = (TNode *)malloc(sizeof(TNode));
    t->isEOW = false;

    int i;
    for(i=0;i<ALPHABET_SIZE;i++)
        t->next[i] = NULL;

    return t;
}

bool insertWordInTrie(TNode *root, char *word)
{
    return false;
}

void printWordsInTrie(TNode *root)
{

}

