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
chr str[100];
int stri;

void printWordsInTrie(TNode *root)
{
    assret(root!=NULL)
    if(root->isEOW)
        printf("%s\n",str);

    for(i=0;i<ALPHABET_SIZE;i++)
    {
        if(root->next!=NULL)
        {
            char c=i+'a';
            str[stri]=c;
            stri++;
            str[stri]='\0';
            printWordsInTrie(root->next[i]);
            stri--;
            str[stri]='\0';
        }

    }

}
bool deleteWordFormTrie(TNode *root,char *word)
{
    if(root==NULL)
        return false;
    int idx=word[0]-'a';
    if(deleteWordFormTrie(root->next[idx],word+1))
    {

        root->next[idx]=NULL;
        if(isLeaf(root))
    }


}

