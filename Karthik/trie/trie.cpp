#include <stdlib.h>
#include <stdbool.h>
#include "trie.h"
struct trien *createTrieNode()
{
    TNode *newNode=(struct trien *)malloc(sizeof(TNode));
    newNode->isEOW=false;
    newNode->next=(struct trien *)malloc(0);
    return newNode;
};
/*
bool insertWordInTrie(TNode *root,char word[])
{
    TNode *temp=root;

}
*/
