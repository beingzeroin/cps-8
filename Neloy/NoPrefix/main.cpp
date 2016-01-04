#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define ALPHABET_SIZE 10
typedef struct trien TNode;
struct trien
{
    bool isEOW;
    struct trien *next[ALPHABET_SIZE];
};

TNode *createTrieNode()
{
    TNode *t = (TNode*)malloc(sizeof(TNode));
    t->isEOW = false;
    int i;
    for(i=0;i<ALPHABET_SIZE;i++)
        t->next[i]=NULL;
    return t;
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
        if(r->isEOW==true)
        {
            return false;
        }
        r=r->next[word[i]-'a'];
    }
    return true;
}

int main()
{
    int n,f=0;
    char s[61];
    TNode *root = createTrieNode();
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",s);
        if(f==1)
            continue;
        if(insertWordInTrie(root,s))
        {
            continue;
        }
        else
        {
            printf("BAD SET\n%s",s);
            f=1;
        }
    }
    if(f==0)
        printf("GOOD SET");
    return 0;
}
