#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include<string.h>
#define alphabet_size 26
void printCharArray(char s[],int pathlen);

struct trien
{
    bool isEOW;
    struct trien *next[alphabet_size];

};
typedef struct trien TNode;
void printWordsInTrie(TNode *root);
void printRecursiveTrie(TNode *r,char s[],int pathlen);

TNode* createTrieNode()
{
    int i;
    TNode *t=malloc(sizeof(TNode));
    t->isEOW=false;
    for(i=0; i<26; i++)
        t->next[i]=NULL;
    return t;

}
bool isLeaf(TNode *root)
{
    int i;
    if(root==NULL)
        return false;
    for(i=0;i<26;i++)
        if(root->next!=NULL)
        return false;
    return true;
    }
bool deleteWordFromTrie(TNode *root,char *word)
{
    int i;
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
        root->isEOW=false;
        return false;
    }

    }


    int idx=word[0]-'a';
   // TNode *temp=root->next[idx];
    //root->next[idx]=NULL;
    if (deleteWordFromTrie(root->next[idx],word+1))
    {
        root->next[idx]=NULL;
        if(isLeaf(root)&&root->isEOW==false)
        {

            free(root);
            return true;

        }


    }

}
bool rinsertWordInTrie(TNode *root,char *word)
{
    if(word[0]=='\0')
    {
        if(root->isEOW==true)
            return false;
        root->isEOW=true;
        return true;
    }
    int idx=word[0]-'a';
    if(root->next[idx]==NULL)
        root->next[idx]=createTrieNode();
    return rinsertWordInTrie(root->next[idx],word+1);

}
bool insertWordInTrie(TNode *root,char *word)
{
    //  root=createTrieNode();
    int i;
    TNode *temp=root;
    for(i=0; word[i]!='\0'; i++)
    {
        if(temp->next[word[i]-'a']!=NULL)
        {
            temp=temp->next[word[i]-'a'];
            continue;
        }
        temp->next[word[i]-'a']=createTrieNode();
        temp=temp->next[word[i]-'a'];

    }
    if(temp->isEOW==true)
        return false;
    temp->isEOW=true;
    return true;
    // return true;
}
void printWordsInTrie(TNode *root)
{
    char s[100];
    int i;
    for(i=0; i<26; i++)
    {
        if(root->next[i]!=NULL)
        {
            s[0]='a'+i;
            printRecursiveTrie(root->next[i],s,1);
        }
    }
}
void printRecursiveTrie(TNode *r,char s[],int pathlen)
{
    int i;
    if(r==NULL)
        return;
    if(r->isEOW==true)
    {
        printCharArray(s,pathlen);
    }
    for(i=0; i<26; i++)
    {
        if(r->next[i]!=NULL)
        {
            s[pathlen]='a'+i;
            pathlen++;
            printRecursiveTrie(r->next[i],s,pathlen);
            pathlen--;
        }
    }
}


void printCharArray(char s[],int pathlen)
{
    int i;
    for(i=0; i<pathlen; i++)
        printf("%c",s[i]);
    printf("\n");

}
int main()
{
    TNode *root=createTrieNode();
    char word[100];
   insertWordInTrie(root,"apple");
    // insertWordInTrie(root,"pavan");
    rinsertWordInTrie(root,"praveen");
    rinsertWordInTrie(root,"praveen");
    rinsertWordInTrie(root,"pavan");
    rinsertWordInTrie(root,"buffaloe");
    rinsertWordInTrie(root,"cars");
    rinsertWordInTrie(root,"cart");
    rinsertWordInTrie(root,"banana");
    rinsertWordInTrie(root,"dog");
    rinsertWordInTrie(root,"carts");
    rinsertWordInTrie(root,"cardiology");
    printWordsInTrie(root);
    deleteWordFromTrie(root,"cart");
    printf("\nafter deletion\n");
    printWordsInTrie(root);
    /*printf("enter string\n");
    scanf("%s",word);
    if(insertWordInTrie(root,word))
        printf("inserted");*/
    return 0;
}
