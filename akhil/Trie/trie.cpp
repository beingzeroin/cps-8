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
    for(int i=0;word[i]1='\0';i++)
    {
        int idx =
    }
    return false;
}

char str[100];


void printWordsInTrie(TNode *root)
{
  assert(root!=NULL)
  if(root->NULL)
    printf("%s\n",str);

  for(int i=0;i<ALPHABET_SIZE;i++)
  {

      if(root->next[i]!=NULL)
      {
          char  c = i + 'a';
          str[stri] = c;
          stri++;
          str[stri] = '\0';
          printWordsInTrie(root->next[i]);
          stri--;
          str[stri] = '\0';
      }
  }

}
bool isLeaf(TNode *root)
{
    for(int i=0;i<ALPHABET_SIZE;i++)
        if(root->next[i]!=NULL)
        return false;
    else
        return true;

}

bool deleteWordFromTrie(TNode *root,char *word)
{
    if(root==NULL)
        return false;
     if(word[0]=='\0' && root->isEOW)
     {
         if(isLeaf(root))
         {
             free(root);
             return true;
         }
         else{
            root->isEOW= false;
            return false;
         }

     }

    int idx = word[0]-'a';
    if(deleteWordFromTrie(root->next[idx],word+1))
    {
        root->next[idx] = NULL;
        if(isLeaf(root) && root->isEOW==false)
        {

            free(root);
        return true;
        }

    }



}
