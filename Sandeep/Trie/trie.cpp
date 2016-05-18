#include "trie.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

TNode *createTrieNode()
{
    TNode *newNode = (TNode*)malloc(sizeof(TNode));
    newNode->isEOW = false;
    int i;
    for(i=0;i<26;i++)
        newNode->next[i] = NULL;
    return newNode;
}

bool rinsertWordInTrie(TNode *root, char *word)
{
    assert(false);
}
bool insertWordInTrie(TNode *root, char *word)
{
    int i;
    for(i=0;word[i]!='\0';i++)
    {
        int idx=word[i]-'a';
        if(root->next[idx]==NULL)
            root->next[idx]=createTrieNode();
        root=root->next[idx];
    }
    if(root->isEOW==true)
        return false;
    root->isEOW=true;
    return true;
}

char str[100];
int stri=0;

void printWordsInTrieInternal(TNode *root)
{
    assert(root!=NULL);
    if(root->isEOW)
        printf("%s\n", str);

    for(int i=0;i<ALPHABET_SIZE;i++)
    {
        if(root->next[i]!=NULL)
        {
            char c = i + 'a';
            str[stri] = c;
            stri++;
            str[stri]='\0';
            printWordsInTrieInternal(root->next[i]);
            stri--;
            str[stri]='\0';
        }

    }

}
void printWordsInTrie(TNode *root)
{
    stri=0;
    printWordsInTrieInternal(root);
}

bool deleteWordFromTrie(TNode *root,char *word)
{
    assert(false);
}

bool isLeaf(TNode *root)
{
    for(int i=0;i<ALPHABET_SIZE;i++)
        if(root->next[i]!=NULL)
            return false;
    return true;
}
















