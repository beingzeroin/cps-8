#include <iostream>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

using namespace std;


#define	ALPHABET_SIZE	26
typedef struct tnode TNode;
struct tnode
{
	bool isEOW;
	TNode *next[ALPHABET_SIZE];
};

TNode *createTrieNode()
{
    TNode *newNode = (TNode*)malloc(sizeof(TNode));
    newNode->isEOW = false;
    int i;
    for(i=0;i<26;i++)
        newNode->next[i] = NULL;
    return newNode;
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

void printWordsInTrie(TNode *root, char *w)
{
    if(root==NULL)
        return ;
    if(root->isEOW){
        printf("%s\n", w);
    }

    int i;
    for(i=0;i<26;i++){

        if(root->next[i]!=NULL){

            // Make A Recursive call by adding current char to w
            char c = i + 'a';
            char nw[100];
            strcpy(nw, w);
            nw[strlen(w)] = c;
            nw[strlen(w)+1] ='\0';
            printWordsInTrie(root->next[i], nw);
        }

    }
}

int main()
{
    TNode *root = createTrieNode();
    char word[100];
    int n;
    scanf("%d\n", &n);
    while(n--){
        scanf("%s",word);
        insertWordInTrie(root, word);
    }
    printWordsInTrie(root, "");
    return 0;
}
