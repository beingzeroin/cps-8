#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "trie.h"
struct trien *createTrieNode()
{
    TNode *newNode=(TNode *)malloc(sizeof(TNode));
    newNode->isEOW=false;
    for(int i=0;i<ALPHABET_SIZE;i++)
        newNode->next[i]=NULL;
    return newNode;
};

bool rinsertWordInTrie(TNode *root, char *word)
{
    if(word[0]=='\0')
    {
        if(root->isEOW==true)
            return false;
        root->isEOW = true;
        return true;
    }
    int idx = word[0]-'a';
    if(root->next[idx]==NULL)
        root->next[idx] = createTrieNode();
    return rinsertWordInTrie(root->next[idx], word+1);
}

bool insertWordInTrie(TNode *root,char *word)
{
    for(int i=0;word[i]!='\0';i++)
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

char str[20];
int top=0;
void printWordsInTrie(TNode *root)
{
    assert(root!=NULL);
    if(root->isEOW)
        printf("%s\n",str);
    for(int i=0;i<ALPHABET_SIZE;i++)
    {
        if(root->next[i])
        {
            str[top]=i+'a';
            top++;
            str[top]='\0';
            printWordsInTrie(root->next[i]);
            top--;
            str[top]='\0';
        }
    }
}

bool isLeaf(TNode *root)
{
    for(int i=0;i<ALPHABET_SIZE;i++)
        if(root->next[i]!=NULL)
            return false;
    return true;
}

bool deleteWordFromTrie(TNode *root, char *word)
{
    if(root==NULL)
        return false;
    if(word[0]=='\0')
    {
        if(root->isEOW==false)
            return false;
        if(isLeaf(root))
        {
            free(root);
            return true;
        }
        else
        {
            root->isEOW = false;
            return false;
        }
    }
    int idx = word[0] - 'a';
    if(deleteWordFromTrie(root->next[idx], word+1))
    {
        root->next[idx] = NULL;
        if(isLeaf(root) && root->isEOW==false)
        {
            free(root);
            return true;
        }
    }
}




