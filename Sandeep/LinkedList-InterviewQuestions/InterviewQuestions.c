#include "LLNode.h"
#include <stdlib.h>
#include <stdbool.h>

LLNode *findIntersectionPoint(LLNode *h1, LLNode *h2)
{
    // TODO:  Implement This Function
    return NULL;

}

LLNode *getKthNodeFromEnd(LLNode *h, int k)
{
    int i;
    LLNode *f=h,*s=h;
   //if(h==NULL)
    //return NULL;
    for(i=1;i<k;i++)
    {
        f=f->next;
        if(f==NULL)
           return NULL;
    }

    while(f->next!=NULL)
    {
        f=f->next;
        s=s->next;
    }
// TODO:  Implement this Function
    return s;
}

LLNode *reverseLinkedList(LLNode *h)
{
    return NULL;
}
LLNode *insertSorted(LLNode *h, int data)
{
    return NULL;
}
bool hasCycle(LLNode *h)
{
    return false;
}
LLNode *findMiddleNode(LLNode *h)//
{
    return NULL;
}
