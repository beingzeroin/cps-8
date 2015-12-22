#include "LLNode.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

LLNode *reverseRecursive1(LLNode *first)
{
   if(first == NULL || first->next == NULL) return first; // list with only one node.

   LLNode *rest = reverseRecursive1(first->next); // recursive call on rest.

   first->next->next= first; // make first; link to the last node in the reversed rest.

   first->next = NULL; // since first is the new last..make its link NULL.

   return rest; // rest now points to the head of the reversed list.
}

LLNode *reverseRecursive(LLNode *h1, LLNode *p)
{
    if(h1==NULL)
        return NULL;
    if(h1->next==NULL)
    {
        h1->next = p;
        return h1;
    }

    LLNode *l = reverseRecursive(h1->next, h1);
    h1->next = p;
    return l;
}


int main()
{
    LLNode *h = NULL;
    int n, v;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &v);
        h = insertInEnd(h, v);
    }

    //h = reverseRecursive(h, NULL);
    h = reverseRecursive(h, NULL);
    traverse(h);

    return 0;

}
