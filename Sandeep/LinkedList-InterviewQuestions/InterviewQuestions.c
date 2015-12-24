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
    // TODO:  Implement this Function
    return NULL;
}

LLNode *reverseLinkedList(LLNode *h)
{
<<<<<<< HEAD

    LLNode *c,*p,*n;
    if(h==NULL || h->next==NULL)
        return h;
    c=h;
    p=NULL;
    n=h->next;
    while(c!=NULL)
    {

        c->next=p;
        p=c;
        c=c->next;
        if(n==NULL)
            break;
        n=c->next;
    }
=======
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

<<<<<<< HEAD
LLNode *reverseLinkedList(LLNode *h)
{

=======
>>>>>>> f32f847bdaedc490da3af20f218f3ddacad191e1
    return p;
>>>>>>> 00d6df4058f28121513b4bd11a320bbf6faa8cfe
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
LLNode *findMiddleNode(LLNode *h)
{
    return NULL;
}
