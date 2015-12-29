#include "trie.h"
#include <stdlib.h>
#include<cstdio>
char temp[100];
int in;

TNode *createTrieNode()
{
    TNode *t = (TNode *)malloc(sizeof(TNode));
    t->isEOW = false;

    int i;
    for(i=0;i<ALPHABET_SIZE;i++)
        t->next[i] = NULL;

    return t;
}
bool rinsertWordInTrie(TNode * roo,char *word)
{
    return false;

}

bool insertWordInTrie(TNode *root, char *word)
{
    for(int i=0;word[i]!='\0';i++)
    {
        int index=word[i]-'a';
        if(root->next[index]!=NULL)
            root->next[index]=createTrieNode();
        root=root->next[index];
    }
    if(root->isEOW==true)
        return false;
    root->isEOW=true;
    return true;

}

void printWordsInTrie(TNode *root)
{
    if(root->isEOW)
        printf("%s",temp);
    for(int i=0;i<ALPHABET_SIZE;i++)
    {
        if(root->next[i]!=NULL)
        {
            char c=i+'a';
            temp[in]=c;
            temp++;
            temp[in]='\0';
            printWordsInTrie(root->next[i]);
            temp--;
            temp[in]='\0';
        }
    }

}

