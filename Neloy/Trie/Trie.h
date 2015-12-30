#ifndef TRIE_H_INCLUDED
#define TRIE_H_INCLUDED

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#define ALPHABET_SIZE 26

typedef struct trien TNode;
struct trien
{
    bool isEOW;
    struct trien *next[ALPHABET_SIZE];
};

TNode *createTrieNode();
bool insertWordInTrie(TNode *root, char *word);
bool rinsertWordInTrie(TNode *r,char *word);
void printWordInTrie(TNode *r);
bool deleteWordFromTrie(TNode *root, char *word);
bool hasWord(TNode *r, char *word);
#endif // TRIE_H_INCLUDED
