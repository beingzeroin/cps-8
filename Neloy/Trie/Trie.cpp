#include "Trie.h"
#include <string.h>

char s[100];
int i=0;

TNode *createTrieNode()
{
    TNode *t = (TNode*)malloc(sizeof(TNode));
    t->isEOW = false;
    int i;
    for(i=0;i<26;i++)
        t->next[i]=NULL;
    return t;
}

bool isLeaf(TNode *r)
{
    for(int i=0;i<26;i++)
    {
        if(r->next[i]!=NULL)
            return false;
    }
    return true;
}

bool insertWordInTrie(TNode *r,char *word)
{
    int i,len = strlen(word);
    TNode *t;
    for(i=0;i<=len;i++)
    {
        if(word[i]=='\0'){
            if(r->isEOW)
                return false;
            r->isEOW=true;
            break;
        }
        if(r->next[word[i]-'a']==NULL)
        {
            t=createTrieNode();
            r->next[word[i]-'a']=t;
        }
        r=r->next[word[i]-'a'];
    }
    return true;
}

bool rinsertWordInTrie(TNode *r,char *word)
{
    if(word[0]=='\0')
    {
        if(r->isEOW)
            return false;
        r->isEOW=true;
        return true;
    }
    int idx = word[0]-'a';
    if(r->next[idx]==NULL)
        r->next[idx]=createTrieNode();
    return rinsertWordInTrie(r->next[idx],word+1);
}

void printWordInTrie(TNode *r)
{
    int j;
    if(r->isEOW)
    {
        s[i]='\0';
        printf("%s\n",s);
    }
    for(j=0;j<ALPHABET_SIZE;j++)
    {
        if(r->next[j]!=NULL)
        {
            s[i]=(char)(j+'a');
            i++;
            //s[i]='\0';
            printWordInTrie(r->next[j]);
            i--;
            //s[i]='\0';
        }
    }
}

bool deleteWordFromTrie(TNode *root, char *word)
{
    if(root==NULL)
        return false;
    int idx = word[0]-'a';
    if(word[0]=='\0')
    {
        if(isLeaf(root)){
            free(root);
            return true;
        }
        else{
            root->isEOW=false;
            return false;
        }
    }
    if(deleteWordFromTrie(root->next[idx],word+1))
    {
        root->next[idx]=NULL;
        if(isLeaf(root)&&!root->isEOW)
        {
            free(root);
            return true;
        }

    }
    return false;
}

bool hasWord(TNode *r, char *word)
{
    int idx = word[0]-'a';
    if(word[0]=='\0'){
        if(r->isEOW==true)
            return true;
        else
            return false;
    }
    if(r->next[idx]!=NULL)
        return hasWord(r->next[idx],word+1);
    else
        return false;
}
