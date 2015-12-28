#include <stdbool.h>
#include <stdlib.h>
#define ALPHABET_SIZE 26
typedef struct trien TNode;
struct trien
{
    bool isEOW;
    TNode *next[ALPHABET_SIZE];
};

struct trien *createTrieNode()
{
    TNode *newNode=(struct trien *)malloc(0);
    //newNode->bool=false;
    //newNode->next=(struct trien *)malloc(sizeof(next));
    return newNode;
};
/*
bool insertWordInTrie(TNode *root,char word[])
{
    TNode *temp=root;

}
*/
