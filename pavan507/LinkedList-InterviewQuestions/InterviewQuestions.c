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
    // CODE
    LLNode *c, *p, *n;

    c = h;
    p = NULL;
    n = c->next;

    while(c!=NULL )
    {
        n = c->next;
        c->next=p;
        p=c;
        c=n;
    }

    return p;
}
LLNode *insertSorted(LLNode *h, int data)
{
    return NULL;
}
bool hasCycle(LLNode *h)
{
    LLNode *s,*f;
    f=s=h;
    if(h==NULL)
        return false;
    do{
        if(f->next!=NULL)
        {
            f=f->next;
            if(f->next!=NULL)
                f=f->next;
            else
                return false;
        }
        else
            return false;
        s=s->next;
    }while(f!=s);
    return true;
}
LLNode *findMiddleNode(LLNode *h)//
{
    return NULL;
}
