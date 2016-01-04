#include "trie.h"
#include <stdlib.h>

TNode *createTrieNode()
{
    TNode *t = malloc(sizeof(TNode));
    t->isEOW = false;
    int i;
    for(i=0; i<ALPHABET_SIZE; i++)
        t->next[i] = NULL;
    return t;
}
bool insertWordInTrie(TNode *root, char *word)
{
    for(i = 0; word[i]!='\0';i++)
    {


    int idx = word[i]-'a';
    if(root->next[idx]==NULL)
        root->next[idx] = createTrieNode();
    root = root->next[idx];
    }
    if(root->isEOW==true)
        return false;
    root->isEOW = true;
    return true;
}
void printWordsInTrie(TNode *t)
{

}
